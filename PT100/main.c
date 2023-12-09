#include <stdio.h>
#include <stdlib.h>

#define POW(A) (A*A)
#define REFVOLT 5.0
#define R0  100
#define ADCResolution 4096

// Temperature (Celsius) = - 245,3 + 2,349 Resistance (ohms) + 0,001043 Resistance (ohms)^2

float getVoltage(int ADCValue);
float getResistance(float Voltage);
float getTemperature(float Resist);


int main()
{
    int adcRaw = 1958;
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
    float Temperature = -245.3 + (2.349* Resist) + (POW(Resist)*0.001043);

    return Temperature;
}
