#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    char str[200];

    printf("bir sayi giriniz: ");

    while(1)
    {
        int retval = scanf("%d",&x);
        if(retval == 1)
            break;
        if(retval == EOF)
        {
            printf("bir giris yapilmadi... tekrar deneyin.");
            continue;
        }
        scanf("%s",str);
        printf("\n%s gecerli bir tam sayi degil, tekrar deneyin\n",str);
    }
    printf("giris basarili alinan deger %d",x);
    return 0;
}
