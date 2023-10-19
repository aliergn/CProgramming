#include <stdio.h>
#include <stdlib.h>

int scientificNot2int(char *array);

int main()
{
    char val1[15] = "1.025800e+04";
    char val2[15] = "1.160000e+03";
    char val3[15] = "-6.630000e+02";
    char val4[15] = "-2.481000e+03";
    char val5[15] = "-1.092000e+04";

    printf("\n%d",scientificNot2int(val1));
    printf("\n%d",scientificNot2int(val2));
    printf("\n%d",scientificNot2int(val3));
    printf("\n%d",scientificNot2int(val4));
    printf("\n%d",scientificNot2int(val5));

    return 0;
}

int scientificNot2int(char *array)
{
    int sign = 0;
    if(array[0]=='-')
        sign = 1;

    double returnValFloat;
    returnValFloat += (double)array[sign]-48;
    int index = 2;
    index+=sign;
    double multiplier = 0.1;
    while(array[index]!='e')
    {
        returnValFloat += (double)(array[index]-48)*multiplier;
        multiplier /= 10;
        index++;
    }
    index+=3;
    int pow = array[index]-48;
    for(index = 0; index<pow;index++)
    {
        returnValFloat*=10;
    }
    int returnValInt;
    returnValInt = (int)returnValFloat;

    if(sign)
    {
        return returnValInt*-1;
    }
    else
        return returnValInt;

}
