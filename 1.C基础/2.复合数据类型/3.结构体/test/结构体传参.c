#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person_
{
    char *name;
    int age;
};
/**
 * func descp: 通过值传递结构体，会进行值拷贝，也就是在内存(栈)中会重新开辟一块空间，将传入的参数复制一遍再在里面进行操作，不是本体
 */
void print_struct_by_value(struct person_ person)
{
    printf("deep_copy of poniter:%p\n", &person);
    printf("addr=%p,addr_name=%p,addr_age=%p\t\tname:%s\t\tage:%d\n", &person, &person.name, &person.age, person.name, person.age);
}
/**
 * func descp: 通过指针传递，始终是使用的一个结构体对象，避免无用的复制开销。
 */
void print_struct_by_pointer(struct person_ *person)
{
    printf("deep_copy of args:%p\n", &person);
    printf("addr=%p,addr_name=%p,addr_age=%p\t\tname:%s\t\tage:%d\n", person, &person->name, &person->age, person->name, person->age);
}

int main()
{
    struct person_ person1 = {"Mike", 15};
    printf("value as args\n\n");
    printf("print object info out args\n");
    printf("addr=%p,addr_name=%p,addr_age=%p\t\tname:%s\t\tage:%d\n\n", &person1, &person1.name, &person1.age, person1.name, person1.age);
    printf("print object info as value args\n");
    print_struct_by_value(person1);
    printf("\n\npointter as args\n");
    printf("print object info out args\n");
    printf("addr=%p,addr_name=%p,addr_age=%p\t\tname:%s\t\tage:%d\n\n", &person1, &person1.name, &person1.age, person1.name, person1.age);
    printf("print object info as poniter args\n");
    print_struct_by_pointer(&person1);
    return 0;
}