#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i = 0; i<128; i++)
    {
        if(iscntrl(i))
            printf("%3d   KONTROL KARAKTERI\n",i);
        else
            printf("%3d   %c\n",i,i);
    }
    return 0;
}
