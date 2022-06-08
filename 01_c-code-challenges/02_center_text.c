#include <stdio.h>
#include <string.h>

void print_blanks(int n);

void center_text(int width, char *text)
{
    int indent = 0, len = strlen(text), printed = 0;

    while(1)
    {
        if(len >= width)
        {
            char tmp[width + 1];

            strncpy(tmp, text + printed, width);
            tmp[width] = 0;

            printf("%s\n", tmp);
            len -= width;
            printed += width;
        }

        else
        {
            indent = (width - len) / 2;
            print_blanks(indent);
            printf("%s\n", text + printed);
            break;
        }
    }
}

void print_blanks(int n)
{
    for(int i = n; i > 0; i--)
    {
        printf(" ");
    }
}

int main()
{
	char *title[] = {
	   "March Sales",
	   "My First Project",
	   "Centering output is so much fun!",
	   "This title is very long, just to see whether the code can handle such a long title"
	};
	int x;

	for( x=0; x<4; x++ )
	{
		center_text( 80, title[x] );
	}

	return(0);
}
