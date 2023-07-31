#include <stdio.h>
#include <stdlib.h>

int isPrime(int value)
 {
     if(value == 0 || value == 1)
     {
         return 0;
     }
     if(value % 2 == 0)
     {
         return value == 2;
     }
          if(value % 3 == 3 )
     {
         return value == 3;
     }
          if(value % 5 == 0)
     {
         return value == 5;
     }
     for (int i = 7;i*i< value;i += 2)
     {
         if(value % i == 0)
         {
             return 0;
         }
     }
 }
int main()
{
    int low, high;
    int temp;
    int primeCount = 0;

    printf("enter a low and high number\n");
    scanf("%d",&low);
    scanf("%d",&high);

    if(low>high)
    {
        temp = low;
        low = high;
        high = temp;
    }

    for(int i = low; i<high; i++)
    {
        if(isPrime(i))
        {
            printf("%d\n",i);
            primeCount++;
        }
    }
    printf("%d numbers are prime",primeCount);

    return 0;
}
