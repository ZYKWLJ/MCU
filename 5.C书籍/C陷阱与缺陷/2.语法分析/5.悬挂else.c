#include <stdio.h>

int main(void)
{
    int a = 1;
    int b = 1;
    if (1 == a)
    {
        if (1 != b)
        {
            printf("a==1&&b!=1\n");
        }
    }
    else
    {
        printf("a!=1\n");
    }
    return 0;
}

// #include <stdio.h>

// int main(void)
// {
//     int a = 1;
//     int b = 1;
//     if (1 == a)
//         if (1 != b)
//             printf("a==1&&b!=1\n");
//     else{
//         printf("a!=1\n");
//     }
//     return 0;
// }