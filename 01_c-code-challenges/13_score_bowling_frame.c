#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_row1(int ball1, int score);

void print_frame(int ball1, int score)
{
    print_row1(ball1, score);
    printf("\n|%3d |\n", score);
}

void print_row1(int ball1, int score)
{
    int ball2 = score - ball1;

    if(score == 10 && ball1 == 10)
    {
        printf("|  |X|");
    }
    else if(score == 10 && ball1 == 0)
    {
        printf("| -|/|");
    }
    else if(score == 10)
    {
        printf("|%2d|/|", ball1);
    }
    else if(score == 0 && ball1 == 0)
    {
        printf("| -|-|");
    }
    else if(ball1 == 0)
    {
        printf("| -|%d|", ball2);
    }
    else if(ball1 == score)
    {
        printf("|%2d|-|", ball1);
    }
    else
    {
        printf("|%2d|%d|", ball1, ball2);
    }
}

int main()
{
    int score, ball1;
    srand((unsigned int)time(NULL));

    score = rand() % 101;
    ball1 = rand() % (score + 1);

    /* Increase the probability of Strike (and Spare) for testing as it is Rare */
    if(score > 50)
    {
        score = 10;
    }
    else
    {
        score /= 5;
    }

    if(ball1 > 50)
    {
        ball1 = 10;
    }
    else
    {
        ball1 /= 5;
    }

    print_frame(ball1, score);

    return 0;
}