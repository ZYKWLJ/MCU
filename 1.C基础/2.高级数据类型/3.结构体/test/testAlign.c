#include <stdio.h>
struct Example4//供16位大小
{
    char a;//1+3(对齐填充的)
    int b;//4
    double c;//8
};
# pragma pack(push,2)//设置2字节对齐
struct Example1//供14位大小
{
    char a;//1+1(对齐填充的)
    int b;//4
    double c;//8
};
# pragma pack()//取消对齐

int main()
{
    printf("默认的4字节对齐:\n");
    struct Example4 ex4;
    printf("size of char:%zu\taddress=%p\n", sizeof(ex4.a),&ex4.a);
    printf("size of int:%zu\taddress=%p\n", sizeof(ex4.b),&ex4.b);
    printf("size of double:%zu\taddress=%p\n", sizeof(ex4.c),&ex4.c);
    printf("size of ex4ample:%zu\taddress=%p\n", sizeof(ex4),&ex4);
    printf("自定义1字节对齐:\n");

    struct Example1 ex1;
    printf("size of char:%zu\taddress=%p\n", sizeof(ex1.a),&ex1.a);
    printf("size of int:%zu\taddress=%p\n", sizeof(ex1.b),&ex1.b);
    printf("size of double:%zu\taddress=%p\n", sizeof(ex1.c),&ex1.c);
    printf("size of ex1ample:%zu\taddress=%p\n", sizeof(ex1),&ex1);
    return 0;
}