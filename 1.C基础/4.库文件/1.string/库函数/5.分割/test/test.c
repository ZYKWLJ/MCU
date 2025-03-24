#include <stdio.h>
#include <string.h>
int main()
{
    char chars[100] = "123,dsg,,43,;';',-=][],qwe";
    // 这是标准使用！先token，再NULL！
    // str：要进行分割的字符串。首次调用 strtok 时，需要传入待分割的字符串；
    // 后续调用时，该参数应设为 NULL，以便函数继续从上次分割的位置继续处理。
    // delim：一个`包含分隔符`的字符串，strtok 会根据这些分隔符来分割字符串。

    char *ptr = strtok(chars, "/,n");//返回当前的指针,一旦找到分隔符，就把它替换成字符串结束符 '\0'。
    while (ptr)
    {
        printf("%s\n", ptr);
        ptr= strtok(NULL, "/,n");//设置NULL，以便于从上次分割的位置继续处理！
    }
    printf("\n\nchars==%s\n\n",chars);//输出123.原字符串已被更改

    return 0;
}