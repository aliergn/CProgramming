#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b);

int main()
{
    int num1 = 10;
    int num2 = 20;
    int sumOfNumber = 0;

    sumOfNumber = sum(num1,num2);

    printf("Sum Of Number = %d",sumOfNumber);

    return 0;
}

int sum(int a, int b)
{
    return a + b;
}
