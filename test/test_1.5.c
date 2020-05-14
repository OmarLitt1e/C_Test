

///////////////test 1.5/////////////////////
#include <stdio.h>
//#include <stdlib.h>

int main()
{
    int Fah;

    for(Fah=300;Fah>=0;Fah=Fah-20)
        printf("%-3d\t\t%6.1f\n",Fah,(5.0*(Fah-32.0)/9.0));

    return 0;
}
