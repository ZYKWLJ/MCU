#include <stdio.h>
#include <stdlib.h>
struct person_
{
    char name[20];
    char **subject;
} *person;
void print_person(struct person_ *person)
{
    printf("name: %s\n", person->name);
    for (int i = 0; i < 3; i++)
    {
        printf("subject[%d]: %s\n", i, person->subject[i]);
    }
    puts("");
}
int main(void)
{
    person = (struct person_ *)malloc(sizeof(struct person_));
    sprintf(person->name, "%s", "Ethan");

    person->subject = (char **)malloc(sizeof(char *) * 3);
#if 1
    {
        /**
         * data descp: 方式1:使用.rodata地址,这是比较好的！
         */
        person->subject[0] = "Math"; // 利用的是.rodata的地址
        person->subject[1] = "English";
        person->subject[2] = "Chinese";
    }
#else
    {
        /**
         * data descp: 方式2:使用malloc开辟空间
         */
        for (int i = 0; i < 3; i++)
        {
            person->subject[i] = (char *)malloc(sizeof(char) * 10);
            sprintf(person->subject[i], "%s-%d", "subject", i);
        };
    }
#endif
    print_person(person);
    return 0;
}