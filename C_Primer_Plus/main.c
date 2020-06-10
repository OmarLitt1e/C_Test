/////////////7.12-11////////////
#include <stdio.h>
#include <float.h>
#define ArtichPrice 2.05
#define BeetPrice   1.15
#define CarotaPrice 1.09
#define Ship5P      6.5
#define Ship5to20P  14
#define Ship20P     0.5

int main(void)
{
    unsigned char Choice;
    float a,b,c,ArtichWgt,BeetWgt,CarotaWgt,GrossWgt;
    float VegeCost,Discount,ShipCost;
    ArtichWgt=BeetWgt=CarotaWgt=Discount=ShipCost=0;
    while((Choice=getchar())!='q')
    {
        if(Choice=='\n')
            continue;
        switch(Choice)
        {
        case 'a':
            printf("Enter the weight you want for Artichoke:\n");
            scanf("%f",&a);
            ArtichWgt+=a;
            break;
        case 'b':
            printf("Enter the weight you want for Beet:\n");
            scanf("%f",&b);
            BeetWgt+=b;
            break;
        case 'c':
            printf("Enter the weight you want for Carota:\n");
            scanf("%f",&c);
            CarotaWgt+=c;
            break;
        default:
            ;
        }

    }
    if((VegeCost=ArtichWgt*ArtichPrice+BeetWgt*BeetPrice+CarotaWgt*CarotaPrice)>100.0)
        Discount=VegeCost*0.05;
    if((GrossWgt=ArtichWgt+BeetWgt+CarotaWgt)<=5.0)
        ShipCost=Ship5P;
    else if(GrossWgt>5.0 && GrossWgt<=20)
        ShipCost=Ship5to20P;
    else
        ShipCost=Ship5to20P+(GrossWgt-20.0)*0.5;
    printf("Here's your shopping list:\n");
    printf("Vegetable\tWeight\tCost\n");
    printf("Artichoke:\t%.2f\t%.3f\n",ArtichWgt,ArtichPrice*ArtichWgt);
    printf("Beet:     \t%.2f\t%.3f\n",BeetWgt,BeetPrice*BeetWgt);
    printf("Carota:   \t%.2f\t%.3f\n",CarotaWgt,CarotaPrice*CarotaWgt);
    printf("Vegetable cost: %.3f\n",VegeCost);
    printf("Discount: %.3f\n",Discount);
    printf("Shipment cost: %.3f\n",ShipCost);
    printf("Gross cost: %.3f\n",VegeCost-Discount+ShipCost);
    return 0;
}

///////////////7.12-10////////////
//#include <stdio.h>
//#include <float.h>
//#define BaseForSingle 17850.0
//#define BaseForHsholder 23900.0
//#define BaseForMarried 29750.0
//#define BaseForDivorced 14875.0
//
//int main(void)
//{
//    unsigned char Status;
//    float Salary;
//
//    printf("Enter your status and you salary:\n"
//           "A single    B householder\n"
//           "C married   D divorced\n");
//   while(2==scanf("%c%f",&Status,&Salary))
//   {
//       switch(Status)
//       {
//            case 'A':
//               if(Salary-BaseForSingle<FLT_EPSILON)
//                    printf("Your taxes is %.2f\n",Salary*0.15);
//               else
//                    printf("Your taxes is %.2f\n",0.15*BaseForSingle+(Salary-BaseForSingle)*0.28);
//               break;
//            case 'B':
//               if(Salary-BaseForHsholder<FLT_EPSILON)
//                    printf("Your taxes is %.2f\n",Salary*0.15);
//               else
//                    printf("Your taxes is %.2f\n",0.15*BaseForHsholder+(Salary-BaseForHsholder)*0.28);
//               break;
//            case 'C':
//               if(Salary-BaseForMarried<FLT_EPSILON)
//                    printf("Your taxes is %.2f\n",Salary*0.15);
//               else
//                    printf("Your taxes is %.2f\n",0.15*BaseForMarried+(Salary-BaseForMarried)*0.28);
//               break;
//            case 'D':
//               if(Salary-BaseForDivorced<FLT_EPSILON)
//                    printf("Your taxes is %.2f\n",Salary*0.15);
//               else
//                    printf("Your taxes is %.2f\n",0.15*BaseForDivorced+(Salary-BaseForDivorced)*0.28);
//               break;
//            default:
//                ;
//
//       }
//   }
//    return 0;
//}

///////////////7.12-9////////////
//#include <stdio.h>
//
//
//
//int main(void)
//{
//    int PosiInteger;
//    unsigned int i,j;
//    unsigned char PrimeFlag=0;
//
//    printf("Enter a positive integer:\n");
//    while(1==scanf("%d",&PosiInteger)  && PosiInteger>0)
//    {
//        if(PosiInteger==1 || PosiInteger==2 || PosiInteger==3 )
//            printf("%d\n",PosiInteger);
//        else
//        {
//            for(i=4;i<=PosiInteger;i++)
//            {
//                for(j=2;j<i;j++)
//                {
//                    if(i%j==0)
//                    {
//                        PrimeFlag=0;
////                        printf("It's not prime number, enter anothers\n");
//                        break;
//                    }
//                    else
//                    {
//                        PrimeFlag=1;
//                    }
//                }
//                if(1==PrimeFlag)
//                    printf("%d  ",i);
//            }
//        }
//    }
//
//    return 0;
//}

///////////////7.12-8////////////
//#include <stdio.h>
//#define FirstOption 8.75
//#define SecondOption 9.33
//#define ThirdOption 10.00
//#define ForthOption 11.20
//#define FifthOption quit
//
//int main(void)
//{
//    float GrossSalary,Taxes;
//    float SalaryInHour;
//    unsigned char Option;
//    unsigned char WorkHour;
//
//    printf("******************************\n");
//    printf("Enter the number corresponding to the desired pay rate or action:\n");
//    printf("1)$8.75/hr\t\t2)$9.33/hr\n"
//           "3)$10.00/hr\t\t4)$11.20/hr\n"
//           "5)quit\n");
//    printf("******************************\n");
//    while((Option=getchar())!='#')
//    {
//        if(Option=='\n')
//            continue;
//        if(Option=='1' || Option=='2' || Option=='3' || Option=='4')
//        {
//            switch(Option)
//            {
//                case '1':
//                    SalaryInHour=FirstOption;
//                    break;
//                case '2':
//                    SalaryInHour=SecondOption;
//                    break;
//                case '3':
//                    SalaryInHour=ThirdOption;
//                    break;
//                case '4':
//                    SalaryInHour=ForthOption;
//                    break;
//                default:
//                    ;
//            }
//            printf("Enter your work hour:\n");
//            scanf("%u",&WorkHour);
//            if(40>=WorkHour)
//                GrossSalary=SalaryInHour*WorkHour;
//            else
//                GrossSalary=SalaryInHour*40.0+SalaryInHour*1.5*(WorkHour-40);
//            if(GrossSalary<=300.0)
//                Taxes=0.15*GrossSalary;
//            else if(GrossSalary>300 && GrossSalary<=450)
//                Taxes=0.15*300+(GrossSalary-300)*0.2;
//            else if(GrossSalary>450)
//                Taxes=0.15*300+0.2*150+(GrossSalary-450)*0.25;
//            printf("Your gross salary is %.2f\n"
//                   "Your Taxes is %.2f\n"
//                   "Your net income is %.2f\n"
//                   ,GrossSalary,Taxes,GrossSalary-Taxes);
//        }
//        else if(Option=='5')
//        {
//            printf("quit\n");
//            break;
//        }
//        else
//            printf("Please enter the right action\n");
//    }
//
//
//    return 0;
//}


///////////////7.12-7////////////
//#include <stdio.h>
//#define BaseSalary 1000.0
//int main(void)
//{
//    float GrossSalary,Taxes;
//    unsigned char WorkHour=0;
//    printf("Enter you work hours:\n");
//    scanf("%u",&WorkHour);
//    if(40>=WorkHour)
//        GrossSalary=BaseSalary*WorkHour;
//    else
//        GrossSalary=BaseSalary*40.0+BaseSalary*1.5*(WorkHour-40);
//    if(GrossSalary<=300.0)
//        Taxes=0.15*GrossSalary;
//    else if(GrossSalary>300 && GrossSalary<=450)
//        Taxes=0.15*300+(GrossSalary-300)*0.2;
//    else if(GrossSalary>450)
//        Taxes=0.15*300+0.2*150+(GrossSalary-450)*0.25;
//
//    printf("Your gross salary is %.2f\n"
//           "Your Taxes is %.2f\n"
//           "Your net income is %.2f\n"
//           ,GrossSalary,Taxes,GrossSalary-Taxes);
//
//    return 0;
//}

///////////////7.12-6////////////
//#include <stdio.h>
//int main(void)
//{
//    char ch;
//    char i;
//    unsigned char record;
//    unsigned char eiNum=0;
//    while((ch=getchar())!='#')
//    {
//        printf("%c",ch);
//        if('e'==ch)
//            record=1;
//        if(1==record)
//        {
//            if('i'==ch)
//                eiNum++;
//        }
//    }
//    printf("\nei occur %u times\n",eiNum);
//    return 0;
//}

///////////////7.12-5////////////
//#include <stdio.h>
//int main(void)
//{
//    char ch;
//    char i;
//    while((ch=getchar())!='#')
//    {
//        switch (ch)
//        {
//            case ',':
//                ch='!';
//                i++;
//                printf("%c",ch);
//                break;
//            case '!':
//                i++;
//                printf("%c",ch);
//                printf("%c",ch);
//                break;
//            default:
//                printf("%c",ch);
//        }
//    }
//    printf("\n");
//    printf("Taken place happened %d times\n",i);
//    return 0;
//}

///////////////7.12-4////////////
//#include <stdio.h>
//int main(void)
//{
//    char ch;
//    char i;
//    while((ch=getchar())!='#')
//    {
//        if(','==ch)
//        {
//            ch='!';
//            i++;
//            printf("%c",ch);
//        }
//        else if('!'==ch)
//        {
//            i++;
//            printf("%c",ch);
//            printf("%c",ch);
//        }
//        else
//        {
//            printf("%c",ch);d
//        }
//    }
//    printf("\n");
//    printf("Taken place happened %d times\n",i);
//    return 0;
//}

///////////////7.12-3////////////
//#include <stdio.h>
//int main(void)
//{
//    char ch;
//    char OddNum,EvenNum;
//    int OddSum,EvenSum;
//    OddSum=0;
//    EvenSum=0;
//    while((ch=getchar())!='0')
//    {
//        if(ch=='\n')
//            continue;
//        if(ch%2==0)
//        {
//            EvenNum++;
//            EvenSum+=ch;
//        }
//        else
//        {
//            OddNum++;
//            OddSum+=ch;
//        }
//    }
//    printf("Num of Even is %d,average num of Even is %.2f\n"
//           "Num of Odd is %d,average num of Odd is %.2f\n",
//           EvenNum,((double)EvenSum/(double)EvenNum)-48.0,OddNum,((double)OddSum/(double)OddNum)-48.0);
//    return 0;
//}

///////////////7.12-2////////////
//#include <stdio.h>
//int main(void)
//{
//    char ch;
//    char chCounter=0;
//    while((ch=getchar())!='#')
//    {
//        if(ch=='\n')
//            continue;
//        if(0==chCounter++ % 8)
//            printf("\n");
//        printf("%c%d ",ch,ch);
//    }
//
//    return 0;
//}

///////////////7.12-1////////////
//#include <stdio.h>
//int main(void)
//{
//    char ch;
//    int SpaceNum=0;
//    int LFNum=0;
//    int OtherNum=0;
//    while((ch=getchar())!='#')
//    {
//        if(ch=='\n')
//            LFNum++;
//        else if(ch==' ')
//            SpaceNum++;
//        else
//            OtherNum++;
//    }
//    printf("SpaceNum is %d\nLFNum is %d\nOtherNum is %d\n",SpaceNum,LFNum,OtherNum);
//
//    return 0;
//}

