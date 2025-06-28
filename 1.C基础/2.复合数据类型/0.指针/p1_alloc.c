#include <stdio.h>
#include <stdlib.h>
void assign_and_print(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n\n");
}
void only_print(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n\n");
}
int main(void)
{
    printf("use malloc:\n");
    int *p1 = (int *)malloc(10 * sizeof(int));
    assign_and_print(p1, 10);
    printf("use calloc:\n");
    int *p2 = (int *)calloc(10, sizeof(int));
    assign_and_print(p2, 10);
    printf("use realloc:\n");
    int *p3 = (int *)realloc(p1, 20 * sizeof(int)); /*注意这里是字节大小！只能填20 * sizeof(int)，不能填20*/
    only_print(p3, 20);
    assign_and_print(p3, 20);
    // free(p1); 注意这里不能释放p1，因为p1传入了realloc，就被返回的p3接管了，所以这里不能释放p1,只能释放p3！
    free(p2);
    free(p3);
    return 0;
}