#include <stdio.h>

int main() {
    if (sizeof(void*) == 4) {
        printf("32-bit env\n");
    } else if (sizeof(void*) == 8) {
        printf("64-bit env\n");
    } else {
        printf("unknown architect\n");
    }
    return 0;
}