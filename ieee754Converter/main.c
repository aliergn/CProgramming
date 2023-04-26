#include <stdio.h>
#include <stdlib.h>

#define NTH_BIT(b, n) ((b >> n) & 0x1)

void floattoString(float value, char *array);
long long int stringtoInt(char *array);
double unpack754_64( long long int floatingToIntValue );

 typedef union UnFloatingPointIEEE754
 {
 struct
  {
   unsigned long long int mantissa : 52;
   unsigned long long int exponent : 11;
   unsigned long long int sign : 1;
  } raw;
double f;
} UFloatingPointIEEE754;

int main()
{
    float val = 500.50;
    printf("set value : ");
    scanf("%f",&val);
    char str[65];
    double retVal;
    floattoString(val,str);
    printf("\nieee754 : %s",str);
    unsigned long long int n = stringtoInt(str);
    retVal = unpack754_64(n);
    printf("\nfloat = %f",retVal);
    return 0;
}

void floattoString(float value, char *array)
{
    sprintf(array,"%llx",value);
}

 double unpack754_64( long long int floatingToIntValue )
 {
   UFloatingPointIEEE754 ieee754;
   unsigned long long int mantissa = 0;
   unsigned long long int exponent = 0 ;
   unsigned long long int sign = 0;

   sign = NTH_BIT(floatingToIntValue, 63);
   for( int ix=0; ix<11; ix++)
    exponent = (exponent | (NTH_BIT(floatingToIntValue, (62-ix))))<<1;
   exponent = exponent>>1;
   for( int ix=0; ix<52; ix++)
    mantissa = (mantissa | (NTH_BIT(floatingToIntValue, (51-ix))))<<1;
   mantissa = mantissa >> 1;

   ieee754.raw.sign = sign;
   ieee754.raw.exponent = exponent;
   ieee754.raw.mantissa = mantissa;
   return ieee754.f;
 }


long long int stringtoInt(char *array)
{
    long long int value=0;
    long long int i;
    long long int tempval;
    for(i=0;i<16;i++)
    {
        if(array[15-i]<58 && array[15-i]>47)
            tempval = array[15-i]-48;
        else if(array[15-i]<71 && array[15-i]>64)
            tempval = array[15-i]-55;
        else if(array[15-i]<103 && array[15-i]>96)
            tempval = array[15-i]-87;

        value += tempval<<(4*i);
    }
    return value;
}
