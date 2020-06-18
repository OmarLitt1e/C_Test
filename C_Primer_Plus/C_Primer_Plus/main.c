/////////////9.11-11////////////
#include <stdio.h>
#include <float.h>
unsigned long Fibonacci(unsigned n);
int main(void)
{
    unsigned n;
    scanf("%u",&n);
    printf("%lu\n",Fibonacci(n));
    return 0;
}
unsigned long Fibonacci(unsigned n)
{
    unsigned i;
    unsigned long Prio1,Prio2,num;
    Prio1=Prio2=1;
    if (n > 2)
    {
        for(i=3;i<n+1;i++)
        {
            num=Prio1+Prio2;
            Prio2=Prio1;
            Prio1=num;
        }
        return num;
    }
    else
        return 1;
}

///////////////9.11-10////////////
//#include <stdio.h>
//#include <float.h>
//
//void to_binary(unsigned long n);
//void to_octonary(unsigned long n);
//void to_hexadecimal(unsigned long n);
//int main(void)
//{
//    unsigned long number=1;
//    unsigned char Format;
//    while (scanf("%lu%u", &number,&Format) == 2)
//    {
//        switch(Format)
//        {
//            case 2:
//                to_binary(number);
//                break;
//            case 8:
//                to_octonary(number);
//                break;
//            case 16:
//                to_hexadecimal(number);
//                break;
//            default:
//                ;
//        }
//        putchar('\n');
//    }
//    return 0;
//}
//void to_binary(unsigned long n)
//{
//    int r;
//    r = n % 2;
//    if (n >= 2)
//        to_binary(n / 2);
//    putchar(r == 0 ? '0' : '1');
//    return;
//}
//void to_octonary(unsigned long n)
//{
//    int r;
//    r = n % 8;
//    if (n >= 8)
//        to_octonary(n / 8);
//    putchar(r == 0 ? '0' : '1');
//    return;
//}
//void to_hexadecimal(unsigned long n)
//{
//    int r;
//    r = n % 16;
//    if (n >= 16)
//        to_hexadecimal(n / 16);
//    putchar(r == 0 ? '0' : '1');
//    return;
//}


///////////////9.11-9////////////
//#include <stdio.h>
//#include <float.h>
//
//double power(double a,int exp);
//int main(void)
//{
//    double a;
//    int exp;
//    while(2==scanf("%lf%d",&a,&exp))
//    {
//        if(a==0)
//        {
//            printf("Any power of 0 is 0\n");
//            continue;
//        }
//        if(exp==0)
//        {
//            printf("Any number's power for 0 is 1\n");
//            continue;
//        }
//        printf("%f\n",power(a,exp));
//
//    }
//    return 0;
//}
//double power(double a,int exp)
//{
//
//    if(exp==0)
//        return 1.0;
//    else
//        return a*power(a,exp-1);
//}






