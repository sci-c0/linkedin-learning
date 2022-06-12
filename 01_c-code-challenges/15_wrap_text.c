#include <stdio.h>
#include <time.h>

#define W_MAX 100
#define W_MIN 16
#define W_DEFAULT 40


void somedelay(void)
{
    for(int j = 0; j < 500000000;)
    {
        ++j;
    }
}

void printsubstr(const char *text, int start, int end)
{
    for(int i = start; i <= end; i++)
    {
        putchar(text[i]);
    }
    fflush(stdout);
    // somedelay();
}

void wraptext(int width, const char *text)
{
    int wordstart = 0;
    int i = 0, linelen = 0;

    while(text[i])
    {
        if(linelen > width)
        {
            linelen = i - wordstart;

            /* Handle very long words */
            if(linelen >= width)
            {
                printsubstr(text, wordstart, wordstart + width - 1);
                wordstart += width;
                linelen -= width;
            }
            printf("\n");
        }

        if(text[i] == ' ' || text[i] == '\n')
        {
            printsubstr(text, wordstart, i);
            wordstart = i + 1;

            if(text[i] == '\n')
            {
                linelen = 0;
            }
        }
        ++linelen;
        ++i;
    }
    if(wordstart != i)
    {
        printsubstr(text, wordstart, i);
    }
}

void horiz_bar(int width)
{
    for(int i = 0; i < width; ++i)
        putchar('-');
    putchar('\n');
}

int main(int argc, char *argv[])
{
	/* Shakespear's 18th Sonnet */
	static char *text = "Shall I compare thee to a summer's day? \
Thou art more lovely and more temperate:\n\
Rough winds do shake the darling buds of May, \
And summer's lease hath all too short a date;\n\
Sometime too hot the eye of heaven shines, \
And often is his gold complexion dimm'd;\n\
And every fair from fair sometime declines, \
By chance or nature's changing course untrimm'd;\n\
But thy eternal summer shall not fade, \
Nor lose possession of that fair thou ow'st;\n\
Nor shall death brag thou wander'st in his shade, \
When in eternal lines to time thou grow'st:\n\
So long as men can breathe or eyes can see, \
So long lives this, and this gives life to thee.";

    int width = W_DEFAULT;
    if(argc == 2)
    {
        int w;
        sscanf(argv[1], "%d", &w);

        if(w <= W_MAX && w >= W_MIN)
        {
            width = w;
        }
    }

    printf("Text before wrapping:\n");
    horiz_bar(width);
    printf(text);
    printf("\n");
    horiz_bar(width);

    printf("\n\nText after wrapping (at %d):\n", width);
    horiz_bar(width);
    wraptext(width, text);
    printf("\n");
    horiz_bar(width);

	return(0);
}
