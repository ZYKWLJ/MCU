# include <stdio.h>
typedef int (*add)(int,int);

int add1(int a,int b){
    return a+b;
}
int add2(int a,int b){
    return a+2*b;
}
int op(int a,int b,add func){//C语言中的，指定接口，通过不同实现！就是使用函数指针实现的！
    return func(a,b);
}   
int main(){
    printf("%d\n",op(1,2,add1));
    printf("%d\n",op(1,2,add2));
    return 0;
}