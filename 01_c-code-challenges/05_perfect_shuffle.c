
#include <stdio.h>
#include <string.h>

#define DECKLEN     26

void shuffle(const char *curdeck, char *newdeck);

int perfect_shuffle()
{
    char *start = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char shuffled[DECKLEN + 1] = "", temp[DECKLEN + 1] = "";

    int shuffles = 0;

    strncpy(temp, start, strlen(start));
    do
    {
        shuffle(temp, shuffled);
        strncpy(temp, shuffled, strlen(shuffled));
        shuffles++;

        printf("Shuffle #%02d: %s\n", shuffles, shuffled);
    }
    while(strncmp(start, shuffled, strlen(shuffled)) != 0);

    return shuffles;
}

void shuffle(const char *curdeck, char *newdeck)
{
    int i = 0;

    for(i = 0; i < DECKLEN/2; i += 1)
    {
        newdeck[2*i] = curdeck[i];
        newdeck[2*i + 1] = curdeck[i + DECKLEN/2];
    }
}

int main()
{
    int n = 0;
    n = perfect_shuffle();

    printf("\nThe perfect shuffle can be done in %d moves\n\n", n);

    return 0;
}
