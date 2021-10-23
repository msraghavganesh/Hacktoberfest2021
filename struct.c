#include <stdio.h>
#include <string.h>

struct student
{
    char name[21];
};

main()
{
    struct student person1;

    strcpy(person1.name, "John");

    printf("\n %s \n", person1.name);
}
