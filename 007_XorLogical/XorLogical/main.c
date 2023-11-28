#include <stdio.h>
#include <stdlib.h>

int main()
{
int x,y;

printf("ik tam sayi girin: ");
scanf("%d%d",&x,&y);

printf("%d xor %d = %d",x,y,!!x != !!y);

}
