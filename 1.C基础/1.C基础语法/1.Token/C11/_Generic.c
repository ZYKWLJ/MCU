#include <stdio.h>

// 根据参数类型选择不同的实现
#define PRINT(x) _Generic((x), \
    int: print_int,            \
    double: print_double,      \
    char *: print_chars,       \
    default: print_unknown)(x)

void print_int(int x) { printf("int: %d\n", x); }
void print_double(double x) { printf("double: %f\n", x); }
void print_chars(char *x) { printf("char*:%s\n", x); }
void print_unknown(void *x) { printf("unknown type\n"); }

int main()
{
    PRINT(42);      // 调用 print_int
    PRINT(3.14);    // 调用 print_double
    PRINT("hello"); // 调用 print_unknown（字符串常量是 char*）
    return 0;
}