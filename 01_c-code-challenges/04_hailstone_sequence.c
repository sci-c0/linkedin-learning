#include <stdio.h>

void hailstone_sequence(int start)
{
    int count = 0;

    printf("Hailstone Sequence starting at %d:\n\t", start);
    while(start != 1)
    {
        printf("%d, ", start);

        switch(start % 2)
        {
            case 1: start = (3 * start) + 1;
                    break;

            case 0: start /= 2;
                    break;
        }

        count++;
    }

    printf("1\n");
    printf("Sequence Length: %d\n", count);
}

int main()
{
    int start = 0;
    printf("Enter starting number: ");
    scanf("%d", &start);

    hailstone_sequence(start);

    return 0;
}
