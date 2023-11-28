#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int isleap(int y);

int main()
{
    int year;
    printf("yil giriniz = ");
    scanf("%d",&year);

    if(isleap(year))
    {
        printf("girilen yil artik yildir");
    }
    else
    {
        printf("girilen yil artik yil degildir.");
    }
    return 0;
}

int isleap(int y)
{
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}
