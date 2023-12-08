#include <stdio.h>
#include <stdlib.h>

#define REFVOLT 5.0
#define R0  100
#define ADCResolution 4096
//y = 0,3869x + 100,04

float getVoltage(int ADCValue);
float getResistance(float Voltage);
float getTemperature(float Resist);


int main()
{
    int adcRaw = 2250;
    float adcVoltage=getVoltage(adcRaw);
    float adcResist = getResistance(adcVoltage);
    float adcTemp = getTemperature(adcResist);
    printf("%d adc value voltage is = %f, resist is = %f, temp = %f",adcRaw,adcVoltage,adcResist,adcTemp);


    return 0;
}

float getVoltage(int ADCValue)
{
    float voltage;

    voltage = REFVOLT*ADCValue/ADCResolution;

    return voltage;
}


float getResistance(float Voltage)
{
    float Resist;
    float Ia = (REFVOLT-Voltage)/R0;
    Resist = Voltage/Ia;

    return Resist;
}

float getTemperature(float Resist)
{
    float Temp;
    if(Resist>100)
       Temp = (2.5846*Resist) - 258.46;

    return Temp;
}
