
#include <stdio.h>

_Bool leapyear(int year)
{
    _Bool mul4 = !(year % 4);
    _Bool mul100 = !(year % 100);
    _Bool mul400 = !(year % 400);

    return (mul4 && !mul100) || mul400;
}

int main()
{
    int year;
    printf("\nYear: ");
    scanf("%d", &year);

    printf("Year %d is ", year);

    if(!leapyear(year))
    {
        printf("NOT ");
    }

    printf("a leap Year!!\n");

    return 0;
}