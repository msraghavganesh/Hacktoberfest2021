#include <stdio.h>
void encrypt(char *name)
{
    char *ptr = name;

    while (*ptr != '\0')
    {
        *ptr += 1;
        *ptr++;
    }
}
int main()
{
    char name[200];
    puts("Enter some words you want to encrypt");
    gets(name);
    encrypt(name);
    printf("converting word...\n");
    printf("%s", name);
    return 0;
}
