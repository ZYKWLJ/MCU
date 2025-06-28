#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    /**
     * data descp: 测试指针数组
     */
    printf("pointer_array_init:\n");
    int *pointer_array[5];
    /**
     * data descp: 使用动态初始化方式完成指针初始化
     */
    for (int i = 0; i < 5; i++)
    {
        pointer_array[i] = (int *)malloc(sizeof(int));
        *pointer_array[i] = i;
    }
    printf("pointer_array_print:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *pointer_array[i]);
    }
    /**
     * data descp: 测试数组指针
     */
    printf("\n\narray_pointer_init:\n");
    /**
     * data descp: 使用动态初始化方式完成指针初始化
     */
    int (*array_pointer)[5] = (int (*)[5])malloc(sizeof(int) * 5); /*开辟的存放的5个元素的数组，指针指向这块地址*/
    int arr[5] = {6, 7, 8, 9, 0};
    array_pointer = &arr;
    printf("array_pointer_print:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", (*array_pointer)[i]); /*(*arr)代表这块内存的内容，[i]代表索引*/
    }
    return 0;
}