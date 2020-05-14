
///////////////test 1.3/////////////////////
#include <stdio.h>
//#include <stdlib.h>

int main()
{
    unsigned int   i;      //counter
    float cCelsius;
    float cFah=0;


    printf("Celsius And Fahr Comparison Table\n\n");

    printf("Celsius\t\t Fahr\n");

    for(i=0;i<16;i++)
    {
        cCelsius=(5.0*(cFah-32.0)/9.0);
        printf("%.0f\t\t%6.1f\n",cFah,cCelsius);
        cFah=cFah+20;
    }
    return 0;
}
