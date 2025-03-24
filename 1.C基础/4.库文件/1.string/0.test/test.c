#include <stdio.h>
#include <string.h>

int main() {
    const char* str = "Hello, World!";
    int c = 'o';
    size_t n = strlen(str);

    // 使用 memchr 函数查找字符 'o'
    char *result = (char *)memchr(str, c, n);

    if (result != NULL) {
        printf("字符 '%c' 首次出现在位置 %ld。\n", c, result - str);
    } else {
        printf("未找到字符 '%c'。\n", c);
    }

    return 0;
}    