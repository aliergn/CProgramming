#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
int main()
{
    unsigned int number,sum=0,max=0,min=0xffffffff,count =0,ch;
    float avg =0;
    while(1)
    {
        printf("bir sayi girecek misiniz ? ");
        while((ch = toupper(_getch())) != 'E' && ch != 'H');
        printf("%c\n",ch);
        if(ch == 'H')
            break;
        printf("Tam sayi giriniz : ");
        scanf("%d",&number);
        sum+=number;
        if(max<number)
            max=number;
        if(min>number)
            min = number;
        count++;


    }
    avg = sum/count;
    printf("given number count is = %d\n",count);
    printf("sum of given numbers = %d\n",sum);
    printf("max of given numbers = %d\n",max);
    printf("min of given numbers = %d\n",min);
    printf("avg of given numbers = %f\n",avg);

    return 0;
}
