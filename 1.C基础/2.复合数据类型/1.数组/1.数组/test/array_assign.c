#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void only_print(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n\n");
}
void only_print_char(char *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c ", p[i]);
    }
    printf("\n\n");
}
int main(void)
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 10};
    printf("before assign:\n");
    only_print(arr1, 5);
    only_print(arr2, 5);
    // arr1=arr2;错误语法
    
    /**
     * data descp: 数组赋值方式1——遍历
     */
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
    {
        arr1[i] = arr2[i];
    }
    printf("before assign:\n");
    only_print(arr1, 5);
    only_print(arr2, 5);

    /**
     * data descp: 数组赋值方式2——memcpy
     */
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
    {
        memcpy(&arr1[i], &arr2[i], sizeof(arr1[i])); // 注意这里是单个元素字节大小！只能填sizeof(arr1[i])，不能填sizeof(arr1)
    }
    /**
     * data descp: 数组赋值方式3——sprintf(专为char打造)
     */
    char arr3[5] = {'1', '2', '3', '4', '5'};
    char arr4[5] = {'6', '7', '8', '9', '0'};
    printf("before assign:\n");

    only_print_char(arr3, 5);
    only_print_char(arr4, 5);
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
    {
        sprintf(arr3 + i, "%c", arr4[i]); // 注意只能是char类型！
    }
    printf("after assign:\n");

    only_print_char(arr3, 5);
    only_print_char(arr4, 5);
    return 0;
}