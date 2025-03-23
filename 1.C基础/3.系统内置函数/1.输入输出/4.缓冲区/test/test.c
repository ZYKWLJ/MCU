#include <stdio.h>

// 自定义函数用于清空输入缓冲区
void clear_input_buffer() {
    int c;
    // 循环读取输入缓冲区的字符，直到遇到换行符
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char ch;
    char ch1;

    // 读取第一个字符
    ch = getchar();
    printf("first:%c\n", ch);

    // 调用自定义函数清空输入缓冲区
    clear_input_buffer();

    // 读取第二个字符
    ch1 = getchar();
    printf("second:%c\n", ch1);

    return 0;
}    