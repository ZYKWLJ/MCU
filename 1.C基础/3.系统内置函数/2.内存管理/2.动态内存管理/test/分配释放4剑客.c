# include<stdio.h>
#include<stdlib.h>
int main(){
    // test malloc
    int *arr=(int*)malloc(10*sizeof(int));
    printf("Byte size of arr=%zu\n",sizeof(arr));
    *arr=1;
    *(arr+9)=10;
    for(int i=0;i<10;i++){
        printf("time %d: %d\n",i,*(arr+i));
    }

    // test calloc
    int *arr1=(int*)calloc(sizeof(int),10);
    printf("\nByte size of arr1=%zu\n",sizeof(arr1));
    *arr1=1;
    *(arr1+9)=10;
    for(int i=0;i<10;i++){
        printf("time %d: %d\tAddress=%p\n",i,*(arr1+i),&*(arr1+i));
    }

    // test realloc
    int *arr2=(int*)realloc(arr1,10*sizeof(int));
    printf("\nByte size of arr2=%zu\n",sizeof(arr2));
    *arr2=100;
    *(arr2+9)=10000;
    for(int i=0;i<10;i++){
        printf("time %d: %d\tAddress=%p\n",i,*(arr2+i),&*(arr2+i));
    }

    // test free
    free(&*(arr2));//尝试释放内存，后面再次打印(注意这里只需要释放这个内存块的地址内存，而不是每一个元素的地址)
    for(int i=0;i<10;i++){
        printf("time %d: %d\tAddress=%p\n",i,*(arr2+i),&*(arr2+i));
    }
    return 0;
}
/*结果
Byte size of arr=8
time 0: 1
time 1: 0
time 2: 0
time 3: 0
time 4: 0
time 5: 0
time 6: 0
time 7: 0
time 8: 0
time 9: 10

Byte size of arr1=8
time 0: 1       Address=0x5555555596e0
time 1: 0       Address=0x5555555596e4
time 2: 0       Address=0x5555555596e8
time 3: 0       Address=0x5555555596ec
time 4: 0       Address=0x5555555596f0
time 5: 0       Address=0x5555555596f4
time 6: 0       Address=0x5555555596f8
time 7: 0       Address=0x5555555596fc
time 8: 0       Address=0x555555559700
time 9: 10      Address=0x555555559704

Byte size of arr2=8
time 0: 100     Address=0x5555555596e0
time 1: 0       Address=0x5555555596e4
time 2: 0       Address=0x5555555596e8
time 3: 0       Address=0x5555555596ec
time 4: 0       Address=0x5555555596f0
time 5: 0       Address=0x5555555596f4
time 6: 0       Address=0x5555555596f8
time 7: 0       Address=0x5555555596fc
time 8: 0       Address=0x555555559700
time 9: 10000   Address=0x555555559704
*/