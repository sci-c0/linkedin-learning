#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PSIZE 20
#define REPEATAFTER 15

_Bool contains(int *arr, size_t size, int val)
{
    for(size_t i = 0; i < size; i++)
    {
        if(arr[i] == val)
        {
            return 1;
        }
    }

    return 0;
}


int main()
{
	char *playlist[PSIZE] = {
		"Like a Rolling Stone", "Satisfaction", "Imagine",
		"What's Going On", "Respect", "Good Vibrations",
		"Johnny B. Goode", "Hey Jude", "What'd I Say",
		"Smells Like Teen Spirit", "My Generation",
		"Yesterday", "Blowin' in the Wind", "Purple Haze",
		"London Calling", "I Want to Hold Your Hand",
		"Maybellene", "Hound Dog", "Let It Be",
		"A Change Is Gonna Come"
	};
	int frequency[PSIZE];
	int x,r,count;
    int last[REPEATAFTER];

	/* initialize */
    memset(last, 0xFF, REPEATAFTER * sizeof(last[0]));

	srand((unsigned)time(NULL));
	for(x = 0; x < PSIZE; x++)
    {
		frequency[x] = 0;
    }

	/* run through the playlist randomly */
	puts("Playlist:");
	count = 0;
	while(count < 100)
	{
		r = rand() % PSIZE;		/* random value */

        if(contains(last, REPEATAFTER, r))
        {
            continue;
        }

        last[count % REPEATAFTER] = r;

		printf("%3d: Now Playing '%s'\n", count + 1, playlist[r]);
		frequency[r]++;
		count++;
	}

	puts("Song frequency:");
	for(x = 0; x < PSIZE; x++)
    {
		printf("%s: %d\n", playlist[x], frequency[x]);
    }

	return 0;
}
