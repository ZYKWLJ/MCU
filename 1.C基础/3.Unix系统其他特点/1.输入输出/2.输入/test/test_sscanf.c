# include <stdio.h>
int main(){
    char str[100]="hello world";
    printf("str==%s\n\n",str);
    sscanf(str,"%s",str);//这个就可以用来提取第一个单词！
    printf("str==%s\n",str);
    return 0;
}