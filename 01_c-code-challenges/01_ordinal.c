#include <stdio.h>

char *ordinal(int v)
{
    if(v / 10 != 1)
    {
        switch(v % 10)
        {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        }
    }    
    return "th";
}


int main()
{
	int c;

	for( c=1; c<=20; c++ )
	{
		printf("%2d%s%8d%s%8d%s%8d%s%8d%s\n",
				c, ordinal(c),
				c + 20, ordinal(c + 20),
				c + 40, ordinal(c + 40),
				c + 60, ordinal(c + 60),
				c + 80, ordinal(c + 80)
			  );
	}
	return(0);
}
