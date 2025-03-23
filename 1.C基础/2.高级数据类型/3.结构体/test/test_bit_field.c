#include <stdio.h>
typedef struct
{
   unsigned int T:1;//防止符号位扩展，只能使用unsigned int
   unsigned int F:1;
}TF;
int main(){
    TF tf;
    tf.T=1;
    tf.F=0;
    printf("tf.T=%d\n",tf.T);
    // 意思是 sizeof 运算符的操作数不能是位域（bit field）。位域是一种特殊的数据类型，它允许在一个字节中存储多个二进制位。
    // 很显然，因为位域是位大小的额级别，而sizeof是字节大小的级别，所以不能使用位域作为sizeof的操作数。
    // 那么取地址也不行了！
    return 0;
}