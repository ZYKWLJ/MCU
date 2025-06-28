#include <complex.h>  // 引入复数运算支持（含虚数单位 I）
#include <stdio.h>

int main() {
    // 1. 定义纯虚数（实部为 0）
    double _Imaginary img = 5.0 * I;  // 等价于数学中的 `5i`
    printf("虚数: %f%+fi\n", creal(img), cimag(img));  
    // 输出: 虚数: 0.000000+5.000000i（creal 获取实部，cimag 获取虚部）

    // 2. 虚数参与运算（与复数、实数混合计算）
    double _Complex z = 3.0 + 4.0*I;  // 复数 `3+4i`（_Complex 是复数类型）
    double _Imaginary result = cimag(z) * img;  // 取 z 的虚部（4）与 img（5i）相乘
    printf("运算结果: %f%+fi\n", creal(result), cimag(result));  
    // 输出: 运算结果: 0.000000+20.000000i（4*5i = 20i）

    return 0;
}