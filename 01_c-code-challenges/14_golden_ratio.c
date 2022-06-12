#include <stdio.h>

double golden_ratio(int recurse_depth)
{
    if(recurse_depth == 0)
    {
        return 1.0;
    }

    return 1.0 + (1.0 / golden_ratio(recurse_depth - 1));
}

int main()
{
    int depth;
    printf("Recursion Depth: ");

    scanf("%d", &depth);
    printf("\nCalculated Golden Ratio: %55.54lf\n\n", golden_ratio(depth));

    return 0;
}