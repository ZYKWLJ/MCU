#include <stdio.h>
#include <string.h>
int main()
{
    char chars[100] = "page       1      ";
    // 这是标准使用！先token，再NULL！
    char *ptr = strtok(chars, " ");//返回当前的指针,一旦找到分隔符，就把它替换成字符串结束符 '\0'。
    while (ptr)
    {
        printf("%s\n", ptr);
        ptr= strtok(NULL, " ");//设置NULL，以便于从上次分割的位置继续处理！
    }
    printf("\n\nchars==%s\n\n",chars);//输出page.原字符串已被更改

    char str[10]="123456789";
    str[3]='\0';
    printf("str==%s\n\n",str);//这个事实证明printf打印的函数的截止是'\0'！
    return 0;
}