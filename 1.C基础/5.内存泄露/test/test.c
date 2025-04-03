#include <stdlib.h>

int main() {
    // 分配内存但忘记释放
    int* array = (int*)malloc(10 * sizeof(int));
    return 0;
}