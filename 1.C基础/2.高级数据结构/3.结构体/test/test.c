# include<stdio.h>
typedef struct 
{
    char name[20];
    int age;
} people;

int main(){
    people Alice={"Alice",20};
    printf("hello,this %s, of age %d\n",Alice.name,Alice.age);
    return 0;
}