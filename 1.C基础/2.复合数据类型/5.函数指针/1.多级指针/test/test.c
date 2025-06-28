#include <stdio.h>
int main(){
    const char* strs[20]={"i","am","EthanYankang"};
    printf("str[0]=%s\t\tAddress=%p\n",strs[0],strs[0]); 
    printf("str[1]=%s\t\tAddress=%p\n",strs[1],strs[1]); 
    printf("str[2]=%s\tAddress=%p\n",strs[2],strs[2]); 
    return 0;
}