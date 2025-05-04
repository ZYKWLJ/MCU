#include <stdio.h>
#include <string.h>
// #define MEMCPY
// #define MEMMOVE
// #define MEMSET_MEMMOVE
#define MEMSET
int main()
{
    char *str = "Hello, World!";
#ifdef MEMCPY
    // 目的地
    char dest[20];
    memcpy(dest, str + 1, 20);
    // 在目的地的末尾添加一个空字符
    dest[20] = '\0';
    printf("Copied string: %s\n", dest);
    for (int i = 0; i < 20; i++)
    {
        printf("%c--%d\n", dest[i], i);
    }
    dest[4] = '\0';
    /**
     * data descp: printf会一直打印直到遇到\0为止，所以我们需要在目的地的末尾添加一个空字符，否则会一直打印到内存的末尾。
     */
    printf("%s\n", dest);
#endif

#ifdef MEMMOVE
    char dest[20];
    memmove(dest, str + 1, 20);
    // 在目的地的末尾添加一个空字符
    dest[20] = '\0';
    printf("Copied string: %s\n", dest);
    for (int i = 0; i < 20; i++)
    {
        printf("%c--%d\n", dest[i], i);
    }
    dest[4] = '\0';
    printf("%s\n", dest);
#endif

#ifdef MEMSET_MEMMOVE
    {
        char dest[20] = "1234";
        memcpy(dest + 2, dest, strlen(dest));
        // 在目的地的末尾添加一个空字符
        dest[strlen(dest)] = '\0';
        printf("Copied string: %s\n", dest);
    }
    {
        char dest[] = "1234";
        memmove(dest + 2, dest, strlen(dest));
        // 在目的地的末尾添加一个空字符
        dest[strlen(dest)] = '\0';
        printf("Copied string: %s\n", dest);
    }
    {
        char str[] = "GNU/Linux";
        memmove(str + 4, str, 5); // 将 "GNU/" 移动到 "Linux" 前
        printf("%s\n", str);      // 输出: GNUGNU/L
    }
#endif

#ifdef MEMSET
    {
        char dest[20] = "1234";
        memset(dest + 4, 'A', 20);
        // 在目的地的末尾添加一个空字符
        dest[19] = '\0';
        printf("Copied string: %s\n", dest);
        printf("Copied string: %s\n", memset(dest + 4, 'A', 20));
    }
#endif
    return 0;
}