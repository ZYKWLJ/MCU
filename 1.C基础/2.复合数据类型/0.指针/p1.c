#include <stdio.h>

int main(void)
{
    int *p = NULL;
    int a = 5;
    p = &a;
    printf("%d\n", *p);
    return 0;
}