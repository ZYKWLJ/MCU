#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100] = "Hello, World!";
    char str2[100] = "Good Morning!\n";
    memcpy(str1, strcat(str1, str2), strlen(str1) + strlen(str2));
    printf("%s", str1);
    return 0;
}