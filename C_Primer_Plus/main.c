///////////////5.11-9/////////////////
#include <stdio.h>
void Temperatures(double Fahr);
const double Cels2Fahr_Para1=5.0/9.0;
const double Cels2Fahr_Para2=32.0;
const double Kelv2Cels=273.16;
int main(void)
{
    double Fahr;

    printf("Enter the temperature in Fahr:\n");

    while(1==(scanf("%lf",&Fahr)) && Fahr>0)
        Temperatures(Fahr);
    return 0;
}
void Temperatures(double Fahr)
{
    printf("Temperature in Celsius is %f\n",Cels2Fahr_Para1*(Fahr-Cels2Fahr_Para2));
    printf("Temperature in Kelvin is %f\n",Cels2Fahr_Para1*(Fahr-Cels2Fahr_Para2)+Kelv2Cels);
    printf("Enter the temperature in Fahr:\n");
}

/////////////////5.11-8/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    int SecondPara;
//    int FirstPara;
//
//    printf("Enter the second parameter:\n");
//    scanf("%d",&SecondPara);
//    printf("Enter the first parameter\n");
//    scanf("%d",&FirstPara);
//    while(FirstPara>0)
//    {
//        printf("Modulus operation result is %d\n",FirstPara/SecondPara);
//        printf("Enter the first parameter\n");
//        scanf("%d",&FirstPara);
//    }
//    return 0;
//}


/////////////////5.11-7/////////////////
//#include <stdio.h>
//void Cube(double num);
//int main(void)
//{
//    double num;
//    printf("Enter a double number:\n");
//    scanf("%lf",&num);
//    Cube(num);
//    return 0;
//}
//void Cube(double num)
//{
//    printf("the cube of num is %f\n",num*num*num);
//}
/////////////////5.11-6/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    unsigned char DayNum;
//    unsigned int count, Money;
//    count = 0;
//    Money = 0;
//    printf("Enter days number:\n");
//    scanf("%u",&DayNum);
//    while (++count< (int)DayNum+1)
//        Money = Money + count*count;
//    printf("Money in %u is = %u\n",DayNum, Money);
//
//    return 0;
//}

/////////////////5.11-5/////////////////
//#include <stdio.h>
//#include <float.h>
//const float CMPerInch=2.54;
//int main(void)
//{
//    unsigned char DayNum;
//    unsigned int count, Money;
//    count = 0;
//    Money = 0;
//    printf("Enter days number:\n");
//    scanf("%u",&DayNum);
//    while (count< (int)DayNum+1)
//        Money = Money + (count++);
//    printf("Money in %u is = %u\n",DayNum, Money);
//
//    return 0;
//}

/////////////////5.11-4/////////////////
//#include <stdio.h>
//#include <float.h>
//const float CMPerInch=2.54;
//int main(void)
//{
//    float Stature;
//    printf("Enter your stature in CM:\n");
//    scanf("%f",&Stature);
//    while(Stature> FLT_EPSILON)
//    {
//        printf("Your stature in CM is %.1f in Inch is %.1f\n",Stature,Stature/CMPerInch);
//        printf("Enter your stature in CM:\n");
//        scanf("%f",&Stature);
//    }
//
//    return 0;
//}

/////////////////5.11-3/////////////////
//#include <stdio.h>
//const unsigned int DaysOfWeek=7;
//int main(void)
//{
//    int NumOfDay;
//    printf("Enter day number:\n");
//    scanf("%d",&NumOfDay);
//    while(NumOfDay>0)
//    {
//        printf("%d days are %d weeks, %d days\n",NumOfDay,NumOfDay/DaysOfWeek,NumOfDay%DaysOfWeek);
//        printf("Enter day number:\n");
//        scanf("%d",&NumOfDay);
//    }
//
//    return 0;
//}

/////////////////5.11-2/////////////////
//#include <stdio.h>
//int main(void)
//{
//    unsigned char i=0;
//    int Num;
//    scanf("%d",&Num);
//    while(i<11)
//        printf("%d\n",Num+(i++));
//
//    return 0;
//}

/////////////////5.11-1/////////////////
//#include <stdio.h>
//const int SecPerMin=60;
//int main(void)
//{
//    unsigned int TimeInMin;
//    scanf("%d",&TimeInMin);
//    while(TimeInMin>0)
//    {
//        printf("Hour: %d\tMinute: %d\n",TimeInMin/SecPerMin,TimeInMin%SecPerMin);
//        scanf("%d",&TimeInMin);
//    }
//
//    return 0;
//}

