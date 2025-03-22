#include <stdio.h>
int a = 1;
int b = 2;
void addTwo();
int main()
{
    printf("调用外部文件之前，a=%d\tb=%d\n", a, b);
    addTwo();
    printf("调用外部文件之后，a=%d\tb=%d\n", a, b);
    return 0;
}