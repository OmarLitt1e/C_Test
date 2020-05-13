//#include <stdio.h>
////#include <stdlib.h>
//
//int main()
//{
//    unsigned int   i;      //counter
//    int cCelsius;
//    int cFah=0;
//
//    for(i=0;i<16;i++)
//    {
//        cCelsius=(int)(5*(cFah-32)/9);
//        printf("%d\t\t%d\n",cFah,cCelsius);
//        cFah=cFah+20;
//    }
//    return 0;
//}



//answer
#include <stdio.h>
//#include <stdlib.h>

int main()
{

    int fahr, celsius;
    int lower,upper,step;

    lower=0;
    upper=300;
    step=20;

    fahr=lower;
    while(fahr<=upper)
    {
        celsius=5*(fahr-32)/9;
        printf("%d\t%d\n",fahr,celsius);
        fahr=fahr+step;
    }


    return 0;
}



