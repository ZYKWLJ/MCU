#include <stdio.h>

int main(void)
{
    int a = 0;
    switch (a)
    {
    case 0:
        printf("a=0\n");
        break;
    case 1:
        printf("a=1\n");
        break;
    case 2:
        printf("a=2\n");
        break;
    case 3:
        printf("a=3\n");
    default:
        printf("a=other\n");
        break;
    }
    return 0;
}