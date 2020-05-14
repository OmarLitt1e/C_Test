

#include <stdio.h>
//#include <stdlib.h>

int main()
{
    unsigned int   i;      //counter
    float cCelsius;
    float cFah=0;

    for(i=0;i<16;i++)
    {
        cCelsius=(5.0*(cFah-32.0)/9.0);
        printf("%.0f\t\t%6f\n",cFah,cCelsius);
        cFah=cFah+20;
    }
    return 0;
}

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
//        printf("%d\t\t%4d\n",cFah,cCelsius);
//        cFah=cFah+20;
//    }
//    return 0;
//}




////answer
//#include <stdio.h>
////#include <stdlib.h>
//
//int main()
//{
//
//    int fahr, celsius;
//    int lower,upper,step;
//
//    lower=0;
//    upper=300;
//    step=20;
//
//    fahr=lower;
//    while(fahr<=upper)
//    {
//        celsius=5*(fahr-32)/9;
//        printf("%d\t%d\n",fahr,celsius);
//        fahr=fahr+step;
//    }
//
//
//    return 0;
//}



