#include <stdio.h>

void addArraysWithoutRestrict(int *src1, int *src2, int *dest, int len)
{
    for (int i = 0; i < len; i++)
    {
        // 因为没 restrict 修饰，编译器得假设这几个指针指向的内存
        // 可能存在重叠，会做一些额外检查或限制优化，避免出错
        dest[i] = src1[i] + src2[i];
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7, 8};
    int result[4] = {0};
    int length = sizeof(arr1) / sizeof(arr1[0]);

    addArraysWithoutRestrict(arr1, arr2, result, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}

// 用处：修饰指针，承诺 `“该指针是访问对应内存的唯一方式”`，让编译器更激进优化，
// 编译器基于这个承诺，就可以更大胆地去优化代码，比如可能会把循环展开得更高效、
// 调整指令执行顺序等，让加法操作跑得更快，因为不用担心不同指针操作同一块内存而出现数据混乱的问题。