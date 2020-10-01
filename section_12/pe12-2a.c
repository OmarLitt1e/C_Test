#include "pe12-2a.h"
#include <stdio.h>

double get_Distance(void)
{
    double Distance;
    puts("Enter how long you drive");
    scanf("%lf",&Distance);
    return Distance;
}
double get_Fuel(void)
{
    double Fuel;
    puts("Enter how many fuel you consume");
    scanf("%lf",&Fuel);
    return Fuel;
}
void show_info(int mode1, double Distance,double Fuel)
{
    puts("The oil consumption is:");
    if(mode1==0)
    {
        printf("%f mile/gallon\n",Fuel/Distance);

    }
    else
    {
        printf("%f L/100km\n",Fuel/(Distance*100.0));
    }


}
