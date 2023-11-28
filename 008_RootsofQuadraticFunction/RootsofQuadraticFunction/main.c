#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int a,b,c;

    printf("2. derece denklemin katsayilarini(ax2 + bx + c) girin: ");
    scanf("%d%d%d",&a,&b,&c);

    int delta = (b*b) -(4*a*c);
    double sqrtDelta;
    if (delta > 0)
    {
        printf("denkleminizin iki gercek koku var. \n");
        sqrtDelta=sqrt(delta);
        printf("1. kok = %f",((-1*b)-sqrtDelta)/(2*a));
        printf("2. kok = %f",((-1*b)+sqrtDelta)/(2*a));
    }
    else if (delta == 0)
    {
        b *= -1;
        a *= 2;
        float result = (float)b/a;
        printf("denkelminizin tek gercek koku var : %f",result);
    }
    else
    {
        printf("denkleminizin gercek kokleri yok!");
    }

    return 0;
}
