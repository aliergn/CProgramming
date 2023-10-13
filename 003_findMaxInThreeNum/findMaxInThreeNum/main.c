#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c);

int main()
{
    int num1 = 10;
    int num2 = 20;
    int num3 = 25;
    int bigNumber = 0;

    bigNumber = max(num1,num2,num3);
    printf("biggest one = %d",bigNumber);

    return 0;
}

int max(int a, int b, int c)
{
    int max = a;
    if(b > max)
        max = b;
    if(c > max)
        max = c;
    return max;
}
