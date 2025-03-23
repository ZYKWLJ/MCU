# define ONE 1
# define ADD(a,b) a \
+b
#include <stdio.h>
int main(){
    int a = 100;
    printf("%d\n%d\n",ONE,ADD(a,ONE));
    return 0;
}