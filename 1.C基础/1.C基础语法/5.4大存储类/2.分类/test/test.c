#include <stdio.h>
int main(){
    // 在 ISO C++17 标准中，register 存储类说明符已被弃用
    // 移除 register 关键字不会影响代码的功能，因为现代编译器已经能够自动进行寄存器分配优化。
    register int a=1;
    printf("%d\n%p",a,&a); 
    return 0;
}