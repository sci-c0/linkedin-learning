
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef
struct Position
{
    int row;
    int col;
}
pos_t;

char *directions[] = {
    "NO MOVE",
    "UP",
    "UP RIGHT",
    "RIGHT",
    "RIGHT DOWN",
    "DOWN",
    "DOWN LEFT",
    "LEFT",
    "LEFT UP"
};  

void print_board(pos_t pos)
{
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            printf((pos.row == i && pos.col == j) ? "K " : ". ");
        }
        printf("\n");
    }
}

void move_king(int dir, pos_t *curpos)
{
    switch (dir)
    {
    case 1: /* TOP */
        curpos->row--;
        break;
    
    case 2: /* TOP RIGHT */
        curpos->row--;
        curpos->col++;
        break;

    case 3: /* RIGHT */
        curpos->col++;
        break;

    case 4: /* BOTTOM RIGHT */
        curpos->col++;
        curpos->row++;
        break;

    case 5: /* BOTTOM */
        curpos->row++;
        break;

    case 6: /* BOTTOM LEFT */
        curpos->row++;
        curpos->col--;
        break;

    case 7: /* LEFT */
        curpos->col--;
        break;

    case 8: /* TOP LEFT */
        curpos->col--;
        curpos->row--;
        break;

    default:
        break;
    }
}

int main()
{
    const int DIRS = 9;
    const pos_t START = {3, 4};

    int dir = 0, moves = 0;
    pos_t curpos = START;

    srand((unsigned int)time(NULL));

    while(curpos.row < 8 && curpos.col < 8 && curpos.row >= 0 && curpos.col >= 0)
    {
        move_king(dir, &curpos);
        printf("\nMove #%d: %s\n", moves, directions[dir]);
        print_board(curpos);

        dir = rand() % DIRS;
        moves++;
    }

    printf("The King wandered off in %d Moves\n", moves);

    return 0;
}