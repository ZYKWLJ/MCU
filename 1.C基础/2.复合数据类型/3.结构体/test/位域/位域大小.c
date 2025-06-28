#include <stdio.h>

int main(void)
{
    struct
    {
        int name : 10;
    } person;
    printf("Size of person:%d B", sizeof(person.name));
    return 0;
}