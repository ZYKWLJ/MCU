#include <stdio.h>

int main(void)
{
    char a[] = "hello";
    int len_a = sizeof(a) / sizeof(a[0]);
    printf("len = %d\n", len_a);
    char *b = "hello";
    int len_b = sizeof(b) / sizeof(b[0]);
    printf("len = %d\n", len_b);
    return 0;
}