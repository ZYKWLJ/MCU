#include <stdio.h>
typedef enum
{
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
} DAY;
int main()
{
    DAY day = THU;
    printf("%d\n", day);
    return 1;
}