#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0
/**写法1
 * data descp:传统的结构体写法
 */

struct person_
{
    char name[20];
    int age;
    char *hobby[20]; /*这是一个数组，而非指针*/
};

struct person_ person;

/*
其中，person_是结构体标签，要求和struct一起用，表明这是一个结构体类型，例如声明一个变量：struct person_ p
后面的person是一个结构体实例，这是一种简便写法。
*/

/**写法2
 * data descp: 简洁写法1-变量紧贴类型后
 */

struct person_
{
    char name[20];
    int age;
    char *hobby[20]; /*这是一个数组，而非指针*/
} person;            /*这是一个变量，类型是struct person_
                      */
/*可以看到，这样写，就省略了在单独来一次struct person_ person，方便了一些*/

/**写法3
 * data descp: 简洁写法2-变量紧贴类型后，并初始化
 */
struct person_
{
    char name[20];
    int age;
    char *hobby[20]; /*这是一个数组，而非指针*/
} person =
    {
        "EthanYankang",
        100,
        {"run", "cycle", "code", NULL},
};
#endif
/*当然了，你也可以混着写，如下*/
struct person_
{
    char name[20];
    int age;
    char *hobby[20]; /*这是一个数组，而非指针*/
} person =
    {
        "EthanYankang",
        100,
        {"run", "cycle", "code"},
},
  person1, *person2,
  person3 = {
      .age = 23,
      .name = "Alice",
      .hobby = {"writting", "take photos"}
},person4[3]={
    {.age=1,.name="A",.hobby={"h1","h2"}},
    {.age=2,.name="B",.hobby={"h3","h4"}},
    {.age=3,.name="C",.hobby={"h5","h6"}}};

#if 0

/**写法4
 * data descp: 写法3——简化类型名
 */

/*注意到，我们前面要声明一个结构体，都必须使用struct person_这样的写法，是不是有时候太麻烦了？能不能像int a一样，仅仅使用一个标签就声明了呢？当然可以。*/
/*注意到，这里使用struct person_是因为struct是一个变类型大小的数据类型，不同的结构体有不同的大小，所以为了区分是哪一个结构体，必须在后面紧跟一个标签，例如struct person_表明，这是人结构体，大小为20B。int a可以成功的声明的原因是所有int都是4字节大小的，没有歧义。*/
/*我们通过typedef定义类型，将struct person_打包带走。声明P_person person就等同于struct person_,怎么样，是不是方便了很多！*/

// /*另外，还可以使用指针的方式，更加灵活，如下.事实上，这也是我们最多的时候使用的！*/
// typedef struct person_
// {
//     char name[20];
//     int age;
//     char *hobby[20]; /*这是一个数组，而非指针*/
// } *P_person;
// P_person person;


typedef struct person_
{
    char name[20];
    int age;
    char *hobby[20]; /*这是一个数组，而非指针*/
} P_person;
P_person person;
#endif

void print(struct person_ person)
{
    printf("size:%d\n", sizeof(person));
    printf("name:%s\n", person.name);
    printf("age:%d\n", person.age);
    for (int i = 0; person.hobby[i] && i < 20; i++)
    {
        printf("%s\n", person.hobby[i]);
    }
    printf("\n");
}
int main()
{
#if 1
    person1.age = 100;
    sprintf(person1.name, "%s", "EthanYankang");
    for (int i = 0; i < 20; i++)
    {
        /*为每一个指针分配100个字节，完全足够了*/
        person1.hobby[i] = (char *)malloc(sizeof(char) * 100);
        sprintf(person1.hobby[i], "%s%d", "hobby-", i);
    }
    // person1.hobby=
    /**
     * data descp: 这里一定要为person2分配内存，因为指针没有指向的内容，是野指针。！(那为什么char*arr="NULL"可以呢？因为这是指向的rodate段里面的数据地址！)
     */
    person2 = (struct person_ *)malloc(sizeof(struct person_));
    person2->age = 20;
    sprintf(person2->name, "%s", "NIUMA");
    // person2->hobby = {"A", "B", "C"}; /*数组除了初始化之外，不可以直接赋值！只能采用元素遍历的方式！这个你又别忘记了！*/
    person2->hobby[0] = "NIUMA";
    // person2->name = strdup("NIUMA");

#endif
    print(person);
    print(person1);
    print(*person2);

struct
{
    int price;
    char *name;
} phone = {
    8000,
    "HUAWEI",
},p={
    .price=3000,
    .name="XIAOMI"
};
    printf("price:%s,name:%s\n", phone.name, phone.name);

    struct person_ person;
    person.age = 12;
    sprintf(person.name, "%s", "Alice");
    sprintf(person.hobby[0], "eating");
    sprintf(person.hobby[1], "running");
    struct person_ person1 = {.age = 12, .name = "Alice", .hobby = {"eating", "running"}};

    // person = {12, "Alice", {"eating", "running"}};
    // person={.age=}

}