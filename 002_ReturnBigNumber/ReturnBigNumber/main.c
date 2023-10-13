#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);

int main()
{
    int num1 = 10;
    int num2 = 20;
    int bigNumber = 0;

    bigNumber = max(num1,num2);
    printf("biggest one = %d",bigNumber);

    return 0;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}
