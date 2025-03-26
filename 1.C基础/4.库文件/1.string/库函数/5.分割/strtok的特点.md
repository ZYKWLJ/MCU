# strtok
### 标准使用
str：要进行分割的字符串。`首次`调用 strtok 时，需要`传入待分割的字符串`；

`后续`调用时，该参数应设为 `NULL`，以便函数继续从`上次分割`的位置继续处理。

delim：一个`包含分隔符`的`字符串`，strtok 会根据这些分隔符来分割字符串。
注意是`包含分隔符`的字符串！所以可以是多个字符！只要包含其中一个字符，就会分割！

返回值：返回分割后的`子字符串`。如果没有找到分隔符，返回 `NULL`。

注意：strtok 会修改原始字符串，将分隔符替换为字符串结束符 `'\0'`。

```c
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
    printf("\n\nchars==%s\n\n",chars);//输出123.原字符串已被更改
    return 0;
}
```