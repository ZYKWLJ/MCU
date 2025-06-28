#include <stdio.h>
#include <complex.h>  // 添加复数相关的头文件

int main(void) {
    double _Complex z = 3.0 + 4.0*I;  // 定义复数 3+4i
    double  _Complex y = 2.0*I;       // 定义纯虚数 2i
    double  _Complex result = z + y;  // 复数加法运算

    // 输出原始复数和计算结果
    printf("z = %.2f + %.2fi\n", creal(z), cimag(z));
    printf("y = %.2f + %.2fi\n", creal(y), cimag(y));
    printf("z + y = %.2f + %.2fi\n", creal(result), cimag(result));

    return 0;
}