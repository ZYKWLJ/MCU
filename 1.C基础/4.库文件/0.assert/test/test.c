#include <stdio.h>
#include <assert.h>
void test_assert(int a){
    assert(a>0);//assert传入一个表达式！
}
int main(){
    int a=1;
    int b=-1;
    test_assert(a);
    test_assert(b);
    puts("Over~");
    return 0;
}