#include <stdio.h>
#include <stdlib.h>

int sum_digit(int val)
{
    int sum = 0;

        while(val!=0)
        {
            sum+=val%10;
            val/=10;
        }

    return sum;
}
int main()
{
    int x;
    printf("bir tam sayi giriniz : ");
    scanf("%d",&x);
    printf("%d sayisinin basamaklarinin toplami = %d",x,sum_digit(x));
    return 0;
}
