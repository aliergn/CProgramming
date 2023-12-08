#include <stdio.h>
#include <stdlib.h>


void myPrintf(float fVal);

int main()
{
    float value;
    printf("give a number = ");
    scanf("%f",&value);
    myPrintf(value);
    return 0;
}




void myPrintf(float fVal)
{
    char result[10];
    int dVal, dec, i;


    fVal += 0.00005;

    dVal = fVal;
    dec = (int)(fVal * 10000) % 10000;

    memset(result, 0, 10);
    result[0] = (dec % 10) + '0';
    result[1] = ((dec / 10)%10) + '0';
    result[2] = ((dec / 100)%10) + '0';
    result[3] = ((dec / 1000)%10) + '0';
    result[4] = '.';

    i = 5;
    while (dVal > 0)
    {
        result[i] = (dVal % 10) + '0';
        dVal /= 10;
        i++;
    }

    for (i=strlen(result)-1; i>=0; i--)
        putc(result[i], stdout);
}
