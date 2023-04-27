#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct CommandData{
  char head[2];
  char objIndex[4];
  char objSubIndex[2];
  char value[16];
  int  objSubIndexInt;
};

void OHCommandParser(char *data,struct CommandData *outData);


int main()
{
    char stringData[] = "OH.3163[12]=4079000000000000;";
    char stringData2[] = "OH.32C8[1]=42FA0000;";
    char stringData3[] = "OH.3085[1]=FFFF;";

    struct CommandData parsedData;

    OHCommandParser(stringData,&parsedData);
    printf("\n%s",parsedData.head);
    printf("\n%s",parsedData.objIndex);
    printf("\n%s",parsedData.objSubIndex);
    printf("\n%d",parsedData.objSubIndexInt);
    printf("\n%s",parsedData.value);
    printf("\n------------------\n");
    OHCommandParser(stringData2,&parsedData);
    printf("\n%s",parsedData.head);
    printf("\n%s",parsedData.objIndex);
    printf("\n%s",parsedData.objSubIndex);
    printf("\n%d",parsedData.objSubIndexInt);
    printf("\n%s",parsedData.value);
    printf("\n------------------\n");
    OHCommandParser(stringData3,&parsedData);
    printf("\n%s",parsedData.head);
    printf("\n%s",parsedData.objIndex);
    printf("\n%s",parsedData.objSubIndex);
    printf("\n%d",parsedData.objSubIndexInt);
    printf("\n%s",parsedData.value);

    return 0;
}

void OHCommandParser(char *data,struct CommandData *outData)
{
    int valStartPoint;
    char *e;
    int index;

    printf("%s",data);
    outData->head[0] = data[0];
    outData->head[1] = data[1];
    memcpy(outData->objIndex,&data[3],4);
    if(data[7]=='['&&data[9]==']')
    {
        outData->objSubIndex[1] = data[8];
        outData->objSubIndex[0] = '0';
        valStartPoint = 11;
    }
    else if(data[7]=='[' && data[10]==']')
    {
        outData->objSubIndex[0] = data[8];
        outData->objSubIndex[1] = data[9];
        valStartPoint = 12;
    }
    outData->objSubIndexInt = atoi(outData->objSubIndex);

    e = strchr(data, ';');
    index = (int)(e - data);
    memcpy(outData->value,&data[valStartPoint],index-valStartPoint);

}
