#include <stdio.h>
#include <string.h>

char buf[80];

char *mid(char *s, int offset, int len);

char *left(char *s, int len)
{
    return mid(s, 0, len);
}

char *right(char *s, int len)
{
    int offset = strlen(s) - len;
    return mid(s, offset > 0 ? offset : 0, len);
}

char *mid(char *s, int offset, int len)
{
    int i = offset, j = 0;
    for( ; i < (len + offset) && s[i]; i++, j++)
    {
        buf[j] = s[i];
    }

    buf[j] = 0;
    return buf;
}

int main()
{
	char string[] = "Once upon a time, there was a string";

	printf("Original string: \"%s\"\n",string);
	printf("Left %d characters: \"%s\"\n",16,left(string,360));
	printf("Right %d characters: \"%s\"\n",18,right(string,180));
	printf("Middle %d characters: \"%s\"\n",11,mid(string,13,110));

	return 0;
}
