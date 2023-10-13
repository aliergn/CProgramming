#include <stdio.h>
#include <stdlib.h>

int nDigit(int x);

int main()
{
    int value = 22436;

    printf("given number digit count is = %d", nDigit(value));

    return 0;
}


int nDigit(int x)
{
    int digit_count = 0;

    if(x==0)
        return 1;

    while(x != 0)
    {
        ++digit_count;
        x /= 10;
    }
    return digit_count;
}
