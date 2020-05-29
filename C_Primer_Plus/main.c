///////////3.11-8//////////////
#include <stdio.h>

int main(void)
{

    float Cup;

    printf("Enter the cup:  ");
    scanf("%f\n",&Cup);
    printf("The pint number of cup is %f\n",Cup*2.0);
    printf("The Ounce number of cup is %f\n",Cup/8.0);
    printf("The SoupLadle number of cup is %f\n",(Cup/8.0)*2.0);
    printf("The Teaspoon number of cup is %f\n",(Cup/8.0)*2.0/3.0);
    return 0;
}

/////////////3.11-7//////////////
//#include <stdio.h>
//
//int main(void)
//{
//
//    float CMPerInch=2.54;
////    unsigned char Stature_Inch;
////    printf("Enter your stature in inch:  ");
////    scanf("%u\n",&Stature_Inch);
//    float Stature_Inch;
//    printf("Enter your stature in inch:  ");
//    scanf("%f\n",&Stature_Inch);
//    printf("Your stature in CM is %f\n",Stature_Inch*CMPerInch);
//    return 0;
//}

/////////////3.11-6//////////////
//#include <stdio.h>
//
//int main(void)
//{
//
//    float H2OMole_PerQuart=950.0/(3.0e-23);
//    unsigned char Quart;
//    printf("Enter the number of H2O quart:  ");
//    scanf("%u\n",&Quart);
//    printf("The number of H2O molecules correspond to H2O quart is %f\n",H2OMole_PerQuart*Quart);
//    return 0;
//}

/////////////3.11-5//////////////
//#include <stdio.h>
//
//int main(void)
//{
//
//    float SecOfYear=3.156e7;
//    float age;
//    printf("Enter your age:  ");
//    scanf("%f\n",&age);
//    printf("The Seconds correspond to your age is %f\n",age*SecOfYear);
//    return 0;
//}

/////////////3.11-4//////////////
//#include <stdio.h>
//
//int main(void)
//{
//    float a;
//    printf("Enter a floating-point value:  ");
//    scanf("%f\n",&a);
//    printf("fixed-point notation:  %f\n",a);
//    printf("exponential notation:  %e\n",a);
//    //printf("p notation:  %a\n",a);
//    return 0;
//}

/////////////3.11-3//////////////
//#include <stdio.h>
//
//int main(void)
//{
//    char cBell=0x07;
//    printf("%c",cBell);
//    printf("Startled by the sudden sound, Sally shouted,\n");
//    printf("\"By the Great Pumpkin, what was that!\"\n");
//    return 0;
//}
/////////////3.11-2//////////////
//#include <stdio.h>
//
//int main(void)
//{
//    char ch;
//    printf("Enter a decimal value of ASCII\n");
//    scanf("%d\n",&ch);
//    printf("The input ASCII is %c\n",ch);
//
//    return 0;
//}

/////////////3.11-1//////////////
//#include <stdio.h>
//
//int main(void)
//{
//    float a;
//    double b;
////    unsigned char b;
////    b=sizeof(float);
//    a=2.000003;
//    b=22222.000003;
//    printf("%f\t%f\n",a,b);
//
//    return 0;
//}
