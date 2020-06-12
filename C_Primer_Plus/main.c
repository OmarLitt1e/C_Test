

/////////////8.11-8////////////
#include <stdio.h>
#include <float.h>

int main(void)
{
    char ch;
    float a,b,c;
    printf("Enter the calculation category:\n"
           "1) addition         2) subtraction\n"
           "3) multiplication   4) division\n"
           "q) quit\n");
    while((ch=getchar())!=EOF)
    {
        if(ch=='\n')
            continue;
        if(ch=='1' || ch=='2' || ch=='3' || ch=='4')
        {
            printf("Enter 2 num for calculation, 'q' for quit\n");
            while(2==scanf("%f%f",&a,&b))
            {
                switch(ch)
                {
                    case '1':
                        c=a+b;
                        break;
                    case '2':
                        c=a-b;
                        break;
                    case '3':
                        c=a*b;
                        break;
                    case '4':
                        while(b<=FLT_EPSILON && b>=-FLT_EPSILON)
                        {
                            printf("Divisor can not be 0!\n"
                                   "Enter another divisor"
                                   " or input q to quit this calculation\n");
                            if(1==scanf("%f",&b))
                                ;
                            else
                                printf("Wrong format, enter again!\n");

                        }
                        c=a/b;
                        break;
                    default:
                        ;
                }
            }
            printf("%f\n",c);
        }
    }

    return 0;
}


///////////////8.11-7////////////
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
//           "q)quit\n");
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
//        else if(Option=='q')
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


///////////////8.11-6////////////
//#include <stdio.h>
//
//char get_first(void);
//
//int main(void)
//{
//
//    putchar(get_first());
//
//    return 0;
//}
//char get_first(void)
//{
//    int ch;
//    while ((ch=getchar()) == ' ' || ch =='\n')
//        continue;
//    return ch;
//}

///////////////8.11-5////////////
//#include <stdio.h>
//
//int main(void)
//{
//    int guess = 50;
//    char ch;
//    printf("Pick an integer from 1 to 100. I will try to guess ");
//    printf("it.\nRespond with a y if my guess is right, with");
//    printf("\na b if it is bigger,with a s if it is smallar .\n");
//    printf("Uh...is your number %d?\n", guess);
//    while ((ch=getchar()) != 'y')
//    {
//        if(ch=='\n')
//            continue;
//        if(ch=='b')
//        {
//            printf("Is it %d?\n",guess/=2);
//        }
//        else if(ch=='s')
//            printf("Is it %d?\n",guess=(100+guess)/2);
//        else
//            printf("Enter the right answer! y b or s\n");
//    }
//
//    return 0;
//}

///////////////8.11-4////////////
//#include <stdio.h>
//#include <ctype.h>
//
//int main(void)
//{
//    char ch;
//    unsigned char InWord,Counter;
//    InWord=Counter=0;
//    while((ch=getchar())!=EOF)
//    {
//        if(ch=='\n')
//            continue;
//
//        if(ch==' ' && InWord==1)
//        {
//            printf("%u\n",Counter);
//            Counter=0;
//        }
//        (ch!=' ') ? (InWord=1) : (InWord=0);
//        if(InWord==1)
//            Counter++;
//
//    }
//
//    return 0;
//}

///////////////8.11-3////////////
//#include <stdio.h>
//#include <ctype.h>
//
//int main(void)
//{
//    char ch;
//    unsigned char Counter_Upper,Counter_Lower;
//    Counter_Upper=Counter_Lower=0;
//    while((ch=getchar())!=EOF)
//    {
//        if(ch<'A' || (ch>'Z' && ch<'a') || ch>'z')
//            continue;
//        if(isupper(ch))
//            Counter_Upper++;
//        else if(islower(ch))
//            Counter_Lower++;
//
//    }
//    printf("Num of Upper is %u\n"
//           "Num of Lower is %u\n",
//           Counter_Upper,Counter_Upper);
//
//
//
//    return 0;
//}

///////////////8.11-2////////////
//#include <stdio.h>
//
//
//int main(void)
//{
//    char ch;
//    unsigned char i=0;
//    while((ch=getchar())!=EOF)
//    {
//        if(i++==10)
//            putchar('\n');
//        switch(ch)
//        {
//            case ' ':
//                printf("Space %d ",ch);
//                break;
//            case '\n':
//                putchar('\\');
//                printf("n %d ",ch);
//                break;
//            case '\t':
//                putchar('\\');
//                printf("t %d ",ch);
//                break;
//            default:
//                printf("%c %d ",ch,ch);
//        }
//    }
//    return 0;
//}

///////////////FuXiTi-3 && 8.11-1////////////
//#include <stdio.h>
//
//
//int main(void)
//{
//    char ch;
//    unsigned char Counter=0;
//    while((ch=getchar())!=EOF)
//    {
//        if(ch!=' ' && ch!='\n')
//            Counter++;
//    }
//    printf("There are %u characters in file essay\n",Counter);
//    return 0;
//}


///////////////8.8////////////
//#include <stdio.h>
//
//char get_choice(void);
//char get_first(void);
//int get_int(void);
//void count(void);
//
//int main(void)
//{
//    int choice;
//    while ((choice = get_choice()) != 'q')
//    {
//        switch (choice)
//        {
//            case 'a': printf("Buy low, sell high.\n");
//            break;
//            case 'b': putchar('\a'); /* ANSI */
//            break;
//            case 'c': count();
//            break;
//            default: printf("Program error!\n");
//            break;
//        }
//    }
//    printf("Bye.\n");
//
//    return 0;
//}
//
//void count(void)
//{
//    int n, i;
//    printf("Count how far? Enter an integer:\n");
//    n = get_int();
//    for (i = 1; i <= n; i++)
//        printf("%d\n", i);
//    while (getchar() != '\n')
//        continue;
//}
//
//char get_choice(void)
//{
//    int ch;
//    printf("Enter the letter of your choice:\n");
//    printf("a. advice b. bell\n");
//    printf("c. count q. quit\n");
//    ch = get_first();
//    while ((ch < 'a' || ch > 'c') && ch != 'q')
//    {
//        printf("Please respond with a, b, c, or q.\n");
//        ch = get_first();
//    }
//    return ch;
//}
//
//char get_first(void)
//{
//    int ch;
//    while ((ch=getchar()) == '\n')
//        ;
////    ch = getchar();
//    while (getchar() != '\n')
//        continue;
//    return ch;
//}
//int get_int(void)
//{
//    int input;
//    char ch;
//    while (scanf("%d", &input) != 1)
//    {
//        while ((ch = getchar()) != '\n')
//            putchar(ch); // ¥¶¿Ì¥ÌŒÛ ‰≥ˆ
//        printf(" is not an integer.\nPlease enter an ");
//        printf("integer value, such as 25, -178, or 3: ");
//    }
//    return input;
//}
//




