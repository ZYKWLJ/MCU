#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = arr;
    printf("len=%zu\n", sizeof(arr) / sizeof(arr[0]));
    const char *ptr1 = "hello world";
    char ptr2[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '1'};
    // 初始化指针时，一般要给它赋一个有效的内存地址，像字符串字面量的地址或者动态分配内存的地址。
    // 为什么可以把字面量赋值给指针？因为字面量也代表地址，别无他意！
    // 但是不能把数组赋值给指针！因为数组名代表的是数组的首地址，而不是数组本身！
    printf("len=%zu\n", sizeof(ptr1) / sizeof(ptr1[0]));
    printf("len=%zu\n", sizeof(ptr2) / sizeof(ptr2[0]));
    // 指针的大小是固定的，无论指向什么类型，指针的大小都是一样的。但是p[0]代表了*p,即第一个元素大小，为4B，所以下面是2！
    printf("len=%zu\n", sizeof(p) / sizeof(p[0]));
    const char *arr2[] = {
        "hello",
        "world",
        NULL // 本质上，arr2是一个指针数组，每个元素都是一个指向字符串的指针。
        // 最后一个元素是一个空指针，用于表示数组的结束。
        // 如果不加，就会报错，因为并不想字符串一样，不会自动在结尾添加'\0'！
    };
    // 记住一句话，一维是线，二维面！
    printf("len=%zu\n", sizeof(arr2) / sizeof(arr2[0]));
    for (int i = 0; arr2[i]; i++)
    {
        puts(arr2[i]);
        for (int j = 0; arr2[i][j]; j++)
        {
            printf("arr2[%d][%d]=%c--%p\n", i, j, arr2[i][j], &arr2[i][j]);
        }
    }
    const char *arr3 = {
        "hello" // 本质上，arr2是一个字符串数组，但是因为字符串数组整体又代表的是数组的首地址，所以可以赋值给我指针！
        // 自动在结尾添加'\0'！
    };
    // 记住一句话，一维是线，二维面！
    // 指针大小为8，字符大小为1，所以下面是8！
    printf("len=%zu\n", sizeof(arr3) / sizeof(arr3[0]));

    for (int i = 0; arr3[i]; i++) // 每一个字符都有一个地址，所以下面是地址！
    {
        putchar(arr3[i]);
        printf("--%p--%p\n", arr3 /*本身就是地址!*/, &arr3[i]);
    }
    const char *sub_arr1[] = {
        "hello",
        "world",
        NULL};

    const char *sub_arr2[] = {
        "good",
        "morning",
        NULL};

    const char **arr4[] = {
        sub_arr1, // 指针
        sub_arr2, // 指针(所以这是二维指针！)
        NULL};

    printf("len=%zu\n", sizeof(arr4) / sizeof(arr4[0]));
    for (int i = 0; arr4[i]; i++)
    {
        for (int j = 0; arr4[i][j]; j++)
        {
            puts(arr4[i][j]);
            for (int k = 0; arr4[i][j][k]; k++)
            {

                printf("arr4[%d][%d][%d]=%c--%p\n", i, j, k, arr4[i][j][k], &arr4[i][j][k]);
            }
        }
    }

    char *str1="hello";
    char *str11="world";
    char *str2[]={
        str1,
        str11,
        NULL
    };
    char *str22[]={
        str11,
        str1,
        NULL
    };
    char **str3[]={
        str2,
        str22,
        NULL
    };
    char **str33[]={
        str22,
        str2,
        NULL
    };
    char ***str4[]={
        str3,
        str33,
        NULL
    };
    char ***str44[]={
        str33,
        str3,
        NULL
    };
    char ****str5[]={
        str4,
        str44,
        NULL
    };

    for (int  i = 0; str5[i]; i++)
    {
        for (int j = 0; str5[i][j]; j++)
        {
            for (int k = 0; str5[i][j][k]; k++){
                for (int l = 0; str5[i][j][k][l]; l++){
                    puts(str5[i][j][k][l]);
                    for (int m = 0; str5[i][j][k][l][m]; m++){
                        printf("str5[%d][%d][%d][%d][%d]-----%c--%p\n",i,j,k,l,m,str5[i][j][k][l][m],&str5[i][j][k][l][m]);
                    }
                }
            }
        }
    }
    return 0;
}