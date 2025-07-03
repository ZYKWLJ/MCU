#include <stdio.h>

int main(void)
{
    int a = 0;
    if (0 == a)//这是优良习惯，避免=与==混用
    {
        printf("a=%d\n", a);
    }
    return 0;
}