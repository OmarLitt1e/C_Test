///////////////6.16-18/////////////////
#include <stdio.h>
#include <float.h>

int main(void)
{
    const int Dunbar=150;
    int RabnudsFriend=5;
    int i;
    for(i=1;RabnudsFriend<Dunbar;i++)
    {
        RabnudsFriend=(RabnudsFriend-i)*2;
    }
    printf("%d\n",--i);


    return 0;
}

/////////////////6.16-17/////////////////
//#include <stdio.h>
//#include <float.h>
//int main(void)
//{
//    char i;
//    float a=100.0;
//    for(i=1; FLT_EPSILON < a;i++)
//    {
//        a=a*1.08-10;
//    }
//    printf("%d\n",--i);
////    printf("%.7f\t%.7f\n",FLT_EPSILON,FLT_MIN);
//
//    return 0;
//}

/////////////////6.16-16/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    float Daphne,Deirdre;
//    Daphne=Deirdre=100.0;
//    int i;
//    for( i=1;(Daphne+=10.0*i) > (Deirdre*=1.05) ;i++)
//        ;
//    printf("%d\n",i);
//
//    return 0;
//}

/////////////////6.16-15/////////////////
//#include <stdio.h>
//#include <string.h>
//int main(void)
//{
//    char a[255];
//    char i=0;
//
//    while(1==scanf("%c",&a[i++]) && i<255 && '\n'!=a[i]);
//    for(i=strlen(a);i>0;i--)
//        printf("%c  ",a[i-1]);
//
//
//
//    return 0;
//}

/////////////////6.16-14/////////////////
//#include <stdio.h>
//int main(void)
//{
//    double a[8],b[8];
//    char i;
//    printf("Enter 8 numbers\n");
//    for(i=0;i<8;i++)
//    {
//        scanf("%lf",&a[i]);
//        printf("a[%d] = %f  ",i,a[i]);
//    }
//    printf("\n");
//    for(b[0]=a[0],printf("b[%d] = %f  ",0,b[0]),
//        i=1;i<8;i++)
//    {
//        b[i]=a[i]+b[i-1];
//        printf("b[%d] = %f  ",i,b[i]);
//    }
//    printf("\n");
//
//
//    return 0;
//}

/////////////////6.16-13/////////////////
//#include <stdio.h>
//int main(void)
//{
//    int a[8];
//    char i,j;
//    for(i=0;i<8;i++)
//    {
//        a[i]=2;
//        for(j=i;j>0;j--)
//            a[i]*=2;
//    }
//    i=0;
//    do
//    {
//        printf("%d\n",a[i]);
//    }while(++i<8);
//
//    return 0;
//}


/////////////////6.16-12/////////////////
//#include <stdio.h>
//#include <math.h>
//void Result(unsigned int times,double sum1,double sum2);
//int main(void)
//{
//    unsigned int times;
//    double sum1,sum2;
//    sum1=sum2=1.0;
//    printf("Enter the compute times\n");
//    scanf("%d",&times);
//    do{
//        Result(times,sum1,sum2);
//    }while(1==scanf("%d",&times));
//
//    return 0;
//}
//void Result(unsigned int times,double sum1,double sum2)
//{
//    double denom=1.0;
//    char i;
//    for(i=0;i<times-1;i++)
//    {
//        sum1+=1.0/(denom+i+1.0);
//        sum2+=pow(-1,i+1)*1.0/(denom+i+1.0);
//    }
//    printf("sum1= %e\tsum2=%e\n",sum1,sum2);
//
//}

/////////////////6.16-11/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    int a[8];
//    char i;
//    for(i=0;i<8;i++)
//        scanf("%d",&a[i]);
//    for(i=7;i>=0;i--)
//        printf("%d  ",a[i]);
//    printf("\n");
//
//    return 0;
//}


/////////////////6.16-10/////////////////
//#include <stdio.h>
//#include <string.h>
//void Result(int High,int Low);
//int main(void)
//{
//    int High,Low;
//    printf("Enter High num and Low num\n");
//    scanf("%d%d",&High,&Low);
//    do{
//        Result( High, Low);
//    }while(2==scanf("%d%d",&High,&Low) && High>Low);
//
//
//    return 0;
//}
//void Result(int High,int Low)
//{
//    char i;
//    int sum=0;
//    for(i=Low;i<High+1;i++)
//        sum+=i*i;
//    printf("The sums of the squares from %d to %d is %d",High,Low,sum);
//}

/////////////////6.16-9/////////////////
//#include <stdio.h>
//#include <string.h>
//void Result(float a,float b);
//int main(void)
//{
//    float a,b;
//    printf("Enter 2 float num\n");
//    scanf("%f%f",&a,&b);
//    do{
//        Result(a,b);
//    }while(2==scanf("%f%f",&a,&b));
//
//    return 0;
//}
//void Result(float a,float b)
//{
//    printf("Result:%f\n",(a-b)/(a*b));
//}

/////////////////6.16-8/////////////////
//#include <stdio.h>
//#include <string.h>
//int main(void)
//{
//    float a,b;
//    printf("Enter 2 float num\n");
//    scanf("%f%f",&a,&b);
//    do{
//        printf("Result:%f\n",(a-b)/(a*b));
//    }while(2==scanf("%f%f",&a,&b));
//
//    return 0;
//}

/////////////////6.16-7/////////////////
//#include <stdio.h>
//#include <string.h>
//int main(void)
//{
//    unsigned char ch[100];
//    char i;
//    printf("Enter a word\n");
//    scanf("%s",ch);
//    for(i=strlen(ch)-1;i>=0;i--)
//        printf("%c",ch[i]);
//
//
//    return 0;
//}

/////////////////6.16-6/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    int i;
//    int HighLimit,LowLimit;
//    printf("Enter a high low limit in integer:\n");
//    scanf("%d%d",&HighLimit,&LowLimit);
//
//    for(i=0;LowLimit+i<HighLimit+1;i++){
//        printf("The integer:\t%d\n",LowLimit+i);
//        printf("Square is:\t%d\n",(LowLimit+i)*(LowLimit+i));
//        printf("Cube is:\t%d\n",(LowLimit+i)*(LowLimit+i)*(LowLimit+i));
//    }
//
//
//    return 0;
//}

/////////////////6.16-5/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    unsigned char i;
//    char j;
//    unsigned char t=0;
//    unsigned char Pyr;
//    printf("Enter a capital letter to form a pyramid:\n");
//    scanf("%c",&Pyr);
//    for(i=0;i<Pyr-'A'+1;i++){
//        for(j=0;j<i+1;j++){
//            printf("%c",'A'+j);
//        }
//        j--;
//        for(--j;j>=0;j--){
//            printf("%c",'A'+j);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}

/////////////////6.16-4/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    unsigned char i,j;
//    unsigned char t=0;
//    for(i=0;i<6;i++){
//        for(t=t+i,j=0;j<i+1;j++){
//            printf("%c",'A'+t+j);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}


/////////////////6.16-3/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    unsigned char i,j;
//    for(i=0;i<6;i++){
//        for(j=0;j<i+1;j++){
//            printf("%c",'F'-j);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}

/////////////////6.16-2/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    unsigned char i,j;
//    for(i=0;i<5;i++){
//        for(j=0;j<i+1;j++){
//            printf("$");
//        }
//        printf("\n");
//    }
//
//    return 0;
//}


/////////////////6.16-1/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    unsigned char word[26];
//    unsigned char i;
//    for(i=0;word[i]='a'+i,i<26;i++)
//        printf("%c  ",word[i]);
//
//
//
//    return 0;
//}

