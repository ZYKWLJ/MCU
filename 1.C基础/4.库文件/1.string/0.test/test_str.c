#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define String_Manipulation_Functions
#define STRCPY
#define STRNCPY
#define STRCAT
#define STRNCAT
#define STRDUP
#define STRNDUP

#define String_Search_Functions
#define STRSTR
#define STRCHR
#define STRRCHR
#define STRCASESTR
#define STRTOK
#define STRLEN

int main()
{
#ifdef STRCPY
    printf("Test STRCPY :\n\n");
    {
        char dest[20] = "hello";
        printf("Before Copied string dest=: %s\n", dest);
        char src[20] = "world11111";
        char *p = strcpy(dest, src);
        printf("After Copied string dest=: %s\n", dest);
        printf("%p\n%p\n", p, dest);
        printf("After Copied string return=: %s\n", p);
        printf("After src string src=: %s\n", src);
        printf("测试是不是深复制:\n");
        src[0] = 'a';
        printf("%s深复制\n", dest[0] != src[0] ? "是" : "不是");
        printf("After src string src=: %s\n", src);
        printf("After Copied string dest=: %s\n", dest);
        printf("After Copied string return=: %s\n", p);
    }
    
#endif

#ifdef STRNCPY
    printf("\nTest STRNCPY :\n\n");
    {
        char dest[20] = "hello11";
        printf("Before Copied string dest=: %s\n", dest);
        char src[20] = "world11111";
        char *p = strncpy(dest, src, 5);
        printf("After Copied string dest=: %s\n", dest);
        printf("%p\n%p\n", p, dest);
        printf("After Copied string return=: %s\n", p);
        printf("After src string src=: %s\n", src);
        printf("测试是不是深复制:\n");
        src[0] = 'a';
        printf("%s深复制\n", dest[0] != src[0] ? "是" : "不是");
        printf("After src string src=: %s\n", src);
        printf("After Copied string dest=: %s\n", dest);
        printf("After Copied string return=: %s\n", p);
    }

#endif
#ifdef STRCAT
    printf("\nTest STRCAT :\n\n");
    {
        char dest[20] = "hello";
        printf("Before Copied string dest=: %s\n", dest);
        char src[20] = "world11111";
        char *p = strcat(dest, src);
        printf("After Copied string dest=: %s\n", dest);
        printf("%p\n%p\n", p, dest);
        printf("After Copied string return=: %s\n", p);
        printf("After src string src=: %s\n", src);
        printf("测试是不是深复制:\n");
        src[0] = 'a';
        printf("%s深复制\n", dest[0] != src[0] ? "是" : "不是");
        printf("After src string src=: %s\n", src);
        printf("After Copied string dest=: %s\n", dest);
        printf("After Copied string return=: %s\n", p);
    }

#endif
#ifdef STRNCAT
    printf("\nTest STRNCAT :\n\n");
    {
        char dest[20] = "hello";
        printf("Before Copied string dest=: %s\n", dest);
        char src[20] = "world11111";
        char *p = strncat(dest, src + 5, 3);
        printf("After Copied string dest=: %s\n", dest);
        printf("%p\n%p\n", p, dest);
        printf("After Copied string return=: %s\n", p);
        printf("After src string src=: %s\n", src);
        printf("测试是不是深复制:\n");
        src[0] = 'a';
        printf("%s深复制\n", dest[0] != src[0] ? "是" : "不是");
        printf("After src string src=: %s\n", src);
        printf("After Copied string dest=: %s\n", dest);
        printf("After Copied string return=: %s\n", p);
    }

#endif

#ifdef STRDUP
    printf("\nTest STRDUP :\n\n");
    char *p1;
    {
        char *dupstr = strdup("hello,world");
        printf("After Copied string dupstr=: %s\n", dupstr);
        printf("%p\n", dupstr);
        p1 = dupstr;
    }
    printf("测试是不是深复制：%s\n", strcmp(p1, "hello,world") == 0 ? "是" : "不是");
    free(p1);
    printf("测试是不是在堆中存储：%s\n", strcmp(p1, "hello,world") != 0 ? "是" : "不是");

#endif
#ifdef STRNDUP
    printf("\nTest STRNDUP :\n\n");
    char *p2;
    {
        char *dupstr = strndup("hello,world" + 4, 4);
        printf("After Copied string dupstr=: %s\n", dupstr);
        printf("%p\n", dupstr);
        p2 = dupstr;
    }
    printf("测试是不是深复制：%s\n", strcmp(p2, "hello,world") != 0 ? "是" : "不是");
    free(p2);
    printf("测试是不是在堆中存储：%s\n", strcmp(p2, "o,wo") != 0 ? "是" : "不是");

#endif

#ifdef String_Search_Functions
#ifdef STRCHR
    {
        printf("\nTest STRCHR:\n\n");
        char str1[] = "hello,world";
        char *p = strchr(str1, 'l');
        printf("the first find pos=%ld\n", p - str1);
    }

#endif

#ifdef STRRCHR
    {
        printf("\nTest STRRCHR:\n\n");
        char str[] = "hello,world";
        char *p = strrchr(str, 'l');
        printf("the first find pos=%ld\n", p - str);
        printf("char next=%c\n", *(p + 1));
    }

#endif

#ifdef STRSTR
    {
        printf("\nTest STRSTR:\n\n");
        char str[] = "hello,world";
        printf("Before Copied string str=: %s\n", str);
        char *p = strstr(str, "world");
        printf("After Copied string str=: %s\n", str);
        printf("After Copied string p=: %s\n", p);
        printf("After Copied string return=: %s\n", p);
        printf("测试是不是深复制:\n");
        str[0] = 'a';
        printf("%s深复制\n", str[0] != p[0] ? "是" : "不是");
        printf("After str string str=: %s\n", str);
        printf("After Copied string p=: %s\n", p);
        printf("After Copied string return=: %s\n", p);
    }

#endif

#ifdef STRCASESTR

    {
        printf("\nTest STRCASESTR:\n\n");
        char str[] = "hello,world";
        char *p = strcasestr(str, "wO");
        printf("the first find pos=%ld\n", p - str);
        printf("char next=%c\n", *(p + 1));
    }

#endif

#ifdef STRTOK
    {
        printf("\nTest STRTOK:\n\n");
        char str[] = "hello,world";
        char *p = strtok(str, ",r");
        while (p != NULL)
        {
            printf("%s\n", p);
            p = strtok(NULL, ",r");
        }
        printf("strtok会不会影响原字符串： %s\n", strcmp(str, "hello,world") == 0 ? "不会" : "会");
    }
#endif

#ifdef STRLEN
    {
        printf("\nTest STRLEN:\n\n");
        char str[] = "hello,world";
        printf("strlen=%ld\n", strlen(str));
        str[4] = '\0';
        printf("strlen=%ld\n", strlen(str));
        printf("strlen的原理：找到第一个空字符\\0，返回空字符的位置.\n");
    }
#endif
#endif

    return 0;
}