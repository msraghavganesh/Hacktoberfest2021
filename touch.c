#include <config.h>
#include <stdio.h>
#include <getopt.h>
#include <sys/types.h>
#include <assert.h>
#include "system.h"
#include "argmatch.h"
#include "die.h"
#include "error.h"
#include "fd-reopen.h"
#include "parse-datetime.h"
#include "posixtm.h"
#include "posixver.h"
#include "quote.h"
#include "stat-time.h"
#include "utimens.h"
#define PROGRAM_NAME "touch"

#define CH_ATIME 1
#define CH_MTIME 2
static int change_times;
static bool no_create;
static bool use_ref;
static bool no_dereference;
static bool amtime_now;
static struct timespec newtime[2];
static char *ref_file;
enum
{
  TIME_OPTION = CHAR_MAX + 1
};

static struct option const longopts[] =
{
  {"time", required_argument, NULL, TIME_OPTION},
  {"no-create", no_argument, NULL, 'c'},
  {"date", required_argument, NULL, 'd'},
  {"reference", required_argument, NULL, 'r'},
  {"no-dereference", no_argument, NULL, 'h'},
  {GETOPT_HELP_OPTION_DECL},
  {GETOPT_VERSION_OPTION_DECL},
  {NULL, 0, NULL, 0}
};
static char const* const time_args[] =
{
  "atime", "access", "use", "mtime", "modify", NULL
};
static int const time_masks[] =
{
  CH_ATIME, CH_ATIME, CH_ATIME, CH_MTIME, CH_MTIME
};

static void get_reldate (struct timespec *result, char const *flex_date, struct timespec const *now)
{
  if (! parse_datetime (result, flex_date, now))
    die (EXIT_FAILURE, 0, _("invalid date format %s"), quote (flex_date));
}

static bool touch (char const *file)
{
  bool ok;
  int fd = -1;
  int open_errno = 0;
  struct timespec const *t = newtime;
  if (STREQ (file, "-"))
    fd = STDOUT_FILENO;
  else if (! (no_create || no_dereference))
    {
      fd = fd_reopen (STDIN_FILENO, file, O_WRONLY | O_CREAT | O_NONBLOCK | O_NOCTTY, MODE_RW_UGO);
      if (fd == -1 && errno != EISDIR && errno != EINVAL && errno != EPERM)
        open_errno = errno;
    }

  if (change_times != (CH_ATIME | CH_MTIME))
    {
      if (change_times == CH_MTIME)
        newtime[0].tv_nsec = UTIME_OMIT;
      else
        {
          assert (change_times == CH_ATIME);
          newtime[1].tv_nsec = UTIME_OMIT;
        }
    }

  if (amtime_now)
    {
      /* Pass NULL to futimens so it will not fail if we have
         write access to the file, but don't own it.  */
      t = NULL;
    }

  ok = (fdutimensat (fd, AT_FDCWD, (fd == STDOUT_FILENO ? NULL : file), t,
                     (no_dereference && fd == -1) ? AT_SYMLINK_NOFOLLOW : 0)
        == 0);

  if (fd == STDIN_FILENO)
    {
      if (close (STDIN_FILENO) != 0)
        {
          error (0, errno, _("failed to close %s"), quoteaf (file));
          return false;
        }
    }
  else if (fd == STDOUT_FILENO)
    {
      if (!ok && errno == EBADF && no_create)
        return true;
    }

  if (!ok)
    {
      if (open_errno)
        {
          error (0, open_errno, _("cannot touch %s"), quoteaf (file));
        }
      else
        {
          if (no_create && errno == ENOENT)
            return true;
          error (0, errno, _("setting times of %s"), quoteaf (file));
        }
      return false;
    }

  return true;
}

void usage (int status)
{
  if (status != EXIT_SUCCESS)
    emit_try_help ();
  else
    {
      printf (_("Usage: %s [OPTION]... FILE...\n"), program_name);
      fputs (_("\
Update the access and modification times of each FILE to the current time.\n\
\n\
A FILE argument that does not exist is created empty, unless -c or -h\n\
is supplied.\n\
\n\
A FILE argument string of - is handled specially and causes touch to\n\
change the times of the file associated with standard output.\n\
"), stdout);

      emit_mandatory_arg_note ();

      fputs (_("\
  -a                     change only the access time\n\
  -c, --no-create        do not create any files\n\
  -d, --date=STRING      parse STRING and use it instead of current time\n\
  -f                     (ignored)\n\
"), stdout);
      fputs (_("\
  -h, --no-dereference   affect each symbolic link instead of any referenced\n\
                         file (useful only on systems that can change the\n\
                         timestamps of a symlink)\n\
  -m                     change only the modification time\n\
"), stdout);
      fputs (_("\
  -r, --reference=FILE   use this file's times instead of current time\n\
  -t STAMP               use [[CC]YY]MMDDhhmm[.ss] instead of current time\n\
      --time=WORD        change the specified time:\n\
                           WORD is access, atime, or use: equivalent to -a\n\
                           WORD is modify or mtime: equivalent to -m\n\
"), stdout);
      fputs (HELP_OPTION_DESCRIPTION, stdout);
      fputs (VERSION_OPTION_DESCRIPTION, stdout);
      fputs (_("\
\n\
Note that the -d and -t options accept different time-date formats.\n\
"), stdout);
      emit_ancillary_info (PROGRAM_NAME);
    }
  exit (status);
}

int main (int argc, char **argv)
{
  int c;
  bool date_set = false;
  bool ok = true;
  char const *flex_date = NULL;

  initialize_main (&argc, &argv);
  set_program_name (argv[0]);
  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEDIR);
  textdomain (PACKAGE);

  atexit (close_stdout);

  change_times = 0;
  no_create = use_ref = false;

  while ((c = getopt_long (argc, argv, "acd:fhmr:t:", longopts, NULL)) != -1)
    {
      switch (c)
        {
        case 'a':
          change_times |= CH_ATIME;
          break;

        case 'c':
          no_create = true;
          break;

        case 'd':
          flex_date = optarg;
          break;

        case 'f':
          break;

        case 'h':
          no_dereference = true;
          break;

        case 'm':
          change_times |= CH_MTIME;
          break;

        case 'r':
          use_ref = true;
          ref_file = optarg;
          break;

        case 't':
          if (! posixtime (&newtime[0].tv_sec, optarg,
                           PDS_LEADING_YEAR | PDS_CENTURY | PDS_SECONDS))
            die (EXIT_FAILURE, 0, _("invalid date format %s"),
                 quote (optarg));
          newtime[0].tv_nsec = 0;
          newtime[1] = newtime[0];
          date_set = true;
          break;

        case TIME_OPTION:	/* --time */
          change_times |= XARGMATCH ("--time", optarg,
                                     time_args, time_masks);
          break;

        case_GETOPT_HELP_CHAR;

        case_GETOPT_VERSION_CHAR (PROGRAM_NAME, AUTHORS);

        default:
          usage (EXIT_FAILURE);
        }
    }

  if (change_times == 0)
    change_times = CH_ATIME | CH_MTIME;

  if (date_set && (use_ref || flex_date))
    {
      error (0, 0, _("cannot specify times from more than one source"));
      usage (EXIT_FAILURE);
    }

  if (use_ref)
    {
      struct stat ref_stats;
      if (no_dereference ? lstat (ref_file, &ref_stats) : stat (ref_file, &ref_stats))
        die (EXIT_FAILURE, errno, _("failed to get attributes of %s"), quoteaf (ref_file));
      newtime[0] = get_stat_atime (&ref_stats);
      newtime[1] = get_stat_mtime (&ref_stats);
      date_set = true;
      if (flex_date)
        {
          if (change_times & CH_ATIME)
            get_reldate (&newtime[0], flex_date, &newtime[0]);
          if (change_times & CH_MTIME)
            get_reldate (&newtime[1], flex_date, &newtime[1]);
        }
    }
  else
    {
      if (flex_date)
        {
          struct timespec now;
          gettime (&now);
          get_reldate (&newtime[0], flex_date, &now);
          newtime[1] = newtime[0];
          date_set = true;
          if (change_times == (CH_ATIME | CH_MTIME) && newtime[0].tv_sec == now.tv_sec && newtime[0].tv_nsec == now.tv_nsec)
            {
              struct timespec notnow, notnow1;
              notnow.tv_sec = now.tv_sec ^ 1;
              notnow.tv_nsec = now.tv_nsec;
              get_reldate (&notnow1, flex_date, &notnow);
              if (notnow1.tv_sec == notnow.tv_sec && notnow1.tv_nsec == notnow.tv_nsec)
                date_set = false;
            }
        }
    }
  if (!date_set && 2 <= argc - optind && posix2_version () < 200112 && posixtime (&newtime[0].tv_sec, argv[optind], PDS_TRAILING_YEAR | PDS_PRE_2000))
    {
      newtime[0].tv_nsec = 0;
      newtime[1] = newtime[0];
      date_set = true;
      if (! getenv ("POSIXLY_CORRECT"))
        {
          struct tm const *tm = localtime (&newtime[0].tv_sec);
          if (tm)
            error (0, 0, _("warning: 'touch %s' is obsolete; use " "'touch -t %04ld%02d%02d%02d%02d.%02d'"), argv[optind], tm->tm_year + 1900L, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
        }
      optind++;
    }
  if (!date_set)
    {
      if (change_times == (CH_ATIME | CH_MTIME))
        amtime_now = true;
      else
        newtime[1].tv_nsec = newtime[0].tv_nsec = UTIME_NOW;
    }

  if (optind == argc)
    {
      error (0, 0, _("missing file operand"));
      usage (EXIT_FAILURE);
    }

  for (; optind < argc; ++optind)
    ok &= touch (argv[optind]);

  return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
