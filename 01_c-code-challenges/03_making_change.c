#include<stdio.h>

void print_change(float value)
{
    int quarters = 0, dime = 0, nickel = 0, penny = 0, ival = value * 100;
    const int q = 25, d = 10, n = 5, p = 1;

    quarters = ival / q;
    ival %= q;

    dime = ival / d;
    ival %= d;

    nickel = ival / n;
    ival %= n;

    penny += ival / p;

    printf("$%3.2f: %d quarters, %d dimes, %d nickels, %d pennies\n", value, quarters, dime, nickel, penny);
}

int main()
{
    float values[] = {0.49, 1.27, 0.75, 1.31, 0.83};

    for(int i = 0; i < 5; i++)
    {
        print_change(values[i]);
    }

    return 0;
}