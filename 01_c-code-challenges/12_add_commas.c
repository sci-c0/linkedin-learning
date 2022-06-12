#include <stdio.h>

void add_commas(char *formatted, int val)
{
    char numstr[20] = "";
    int temp = val, digs = 0, j = 0;
    while(temp)
    {
        numstr[digs++] = temp % 10 + '0';
        temp /= 10;
    } 

    for(int i = 0; i < digs; ++i)
    {
        int pos = digs - i - 1;
        formatted[j++] = numstr[pos];
        if(pos && pos % 3 == 0)
        {
            formatted[j++] = ',';
        }
    }
    formatted[j] = 0;
}


int main()
{
	int values[10] = {
		123, 1899, 48266, 123456, 9876543,
		10100100, 5, 500000, 99000111, 83
	};

    char formatted[20];

    for(int i = 0; i < 10; i++)
    {
        add_commas(formatted, values[i]);
        printf("%10d: %15s\n", values[i], formatted);
    }

	return(0);
}
