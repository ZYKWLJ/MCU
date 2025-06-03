#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person_
{
    char *name;
    int age;
};
void print_struct(struct person_ *person)
{
    printf("addr=%p,addr_name=%p,addr_age=%p\t\tname:%s\t\tage:%d\n", person, person->name, &person->age, person->name, person->age);
}
void shallow_dup(struct person_ person_dest, struct person_ person_src)
{
}
void deep_dup(struct person_ person_dest, struct person_ person_src)
{
    person_dest.name = strdup(person_src.name); // 单独开辟一块空间了，内层本质是malloc
    person_dest.age = person_src.age;
}

int main()
{
#if 0
    /*结构体赋值是结构体成员的赋值，结构体本身的地址还是在原地的，只不过成员如果有指针，那么结构体的指针会指向赋值的结构体的内存地址，但不新开辟空间，其余变量依旧是占用原来结构体的内存*/
    /*总的来说，结构体的赋值唯一的看点就是结构体是不是有指针成员，有的话，就发生浅拷贝，结构体本身的地址不变(显然如此，因为这是一块已经存在磁盘上的资源了)*/
    /**
     * data descp: 值赋值
     */
    printf("value assign\n\n");
    printf("before value assign\n");

    struct person_ person1 = {"A", 1};
    struct person_ person2 = {"B", 2};
    print_struct(&person1);
    print_struct(&person2);
    printf("after value assign\n");

    person1 = person2;
    print_struct(&person1);
    print_struct(&person2);
#endif
#if 1
    /**
     * data descp: 指针赋值
     */
    struct person_ *person1_pointer = (struct person_ *)malloc(sizeof(struct person_));
    struct person_ *person2_pointer = (struct person_ *)malloc(sizeof(struct person_));
    person1_pointer->name = (char *)malloc(sizeof(char) * 100);
    person2_pointer->name = (char *)malloc(sizeof(char) * 100);
    sprintf(person1_pointer->name, "%s", "A");
    sprintf(person2_pointer->name, "%s", "B");
    person1_pointer->age = 1;
    person2_pointer->age = 2;
    printf("\n\npointer assign\n");
    printf("before pointer assign\n");

    print_struct(person1_pointer);
    print_struct(person2_pointer);
    printf("after pointer assign\n");
    person1_pointer = person2_pointer;
    print_struct(person1_pointer);
    print_struct(person2_pointer);
#endif
    return 0;
}

/*编译器优化导致地址相同*/
// 编译器优化导致地址相同，详见下文
// 编译器可能将相邻的全局结构体变量优化为 同一地址（或因结构体大小紧凑，地址重叠显示为相同）。