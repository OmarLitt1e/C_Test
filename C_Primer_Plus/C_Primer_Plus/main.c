

/////////////////////10.14/////////////////
//#include <stdio.h>
//#include <stdint.h>
//void arr_Process(int Hang,int Lie,double Src[Hang][Lie]);
//double Average,Average_0,Average_1,Average_2,MaxValue=0.0;
//
//int main()
//{
//    printf("Enter 3 groups double type data: \n");
//    uint8_t i;
//    double Src[3][5];
//    for(i=0;i<3;i++)
//    {
//        while(1==scanf("%lf%lf%lf%lf%lf",&Src[i][0],&Src[i][1],&Src[i][2],&Src[i][3],&Src[i][4]))
//            ;
//    }
//    arr_Process(3,5,Src);
//    return 0;
//}
//void arr_Process(int Hang,int Lie,double Src[Hang][Lie])
//{
//    unsigned char i,j;
//    double Sum=0.0,Sum_0=0.0,Sum_1=0.0,Sum_2=0.0;
//
//    for(i=0;i<Hang;i++)
//    {
//        for(j=0;j<Lie;j++)
//        {
//            Sum+=Src[i][j];
//            if (MaxValue<Src[i][j])
//                MaxValue=Src[i][j];
//            if (j==Lie-1 && i==0)
//            {
//                Sum_0=Sum;
//                Average_0=Sum_0/Lie;
//                printf("Average_0 is %f \n",Average_0);
//            }
//            else if(j==Lie-1 && i==1)
//            {
//                Sum_1=Sum-Sum_0;
//                Average_1=Sum_1/Lie;
//                printf("Average_1 is %f \n",Average_1);
//            }
//            else if(j==Lie-1 && i==2)
//            {
//                Sum_2=Sum-Sum_0-Sum_1;
//                Average_2=Sum_2/Lie;
//                printf("Average_2 is %f \n",Average_2);
//            }
//        }
//    }
//    printf("Average is %f \n",Sum/(Hang*Lie));
//    printf("Max Value is %f \n",MaxValue);
//}


/////////////////////10.13/////////////////
//#include <stdio.h>
//#include <stdint.h>
//void arr_Process(int Hang,double Src[][5]);
//double Average,Average_0,Average_1,Average_2,MaxValue=0.0;
//
//int main()
//{
//    printf("Enter 3 groups double type data: \n");
//    uint8_t i;
//    double Src[3][5];
//    for(i=0;i<3;i++)
//    {
//        while(1==scanf("%lf%lf%lf%lf%lf",&Src[i][0],&Src[i][1],&Src[i][2],&Src[i][3],&Src[i][4]))
//            ;
//    }
//    arr_Process(3,Src);
//    return 0;
//}
//void arr_Process(int Hang,double Src[][5])
//{
//    unsigned char i,j;
//    double Sum=0.0,Sum_0=0.0,Sum_1=0.0,Sum_2=0.0;
//
//    for(i=0;i<Hang;i++)
//    {
//        for(j=0;j<5;j++)
//        {
//            Sum+=Src[i][j];
//            if (MaxValue<Src[i][j])
//                MaxValue=Src[i][j];
//            if (j==4 && i==0)
//            {
//                Sum_0=Sum;
//                Average_0=Sum_0/5.0;
//                printf("Average_0 is %f \n",Average_0);
//            }
//            else if(j==4 && i==1)
//            {
//                Sum_1=Sum-Sum_0;
//                Average_1=Sum_1/5.0;
//                printf("Average_1 is %f \n",Average_1);
//            }
//            else if(j==4 && i==2)
//            {
//                Sum_2=Sum-Sum_0-Sum_1;
//                Average_2=Sum_2/5.0;
//                printf("Average_2 is %f \n",Average_2);
//            }
//        }
//    }
//    printf("Average is %f \n",Sum/15.0);
//    printf("Max Value is %f \n",MaxValue);
//}

/////////////////////10.12/////////////////
//#include <stdio.h>
//
//void copyANDprint_arr(double target1[][4], double source[][4], int Hang);
//int main()
//{
//    double source[3][4] = { {0.1,0.2,0.3,0.4},
//                            {1.1,1.2,1.3,1.4},
//                            {2.1,2.2,2.3,2.4}
//                            };
//    double Rcv[3][4];
//    copyANDprint_arr(Rcv,source,3);
//
//    return 0;
//}
//void copyANDprint_arr(double target1[][4], double source[][4], int Hang)
//{
//    unsigned char i,j;
//    for(i=0;i<Hang;i++)
//    {
//        for(j=0;j<4;j++)
//        {
//            target1[i][j]=source[i][j];
//        }
//    }
//    for(i=0;i<Hang;i++)
//    {
//        for(j=0;j<4;j++)
//        {
//            printf("%f ",target1[i][j]);
//            if (j==3)
//                printf("\n");
//        }
//    }
//
//}



/////////////////////10.11/////////////////
//#include <stdio.h>
//#include <stdint.h>
//#include <ctype.h>
//void print_arr(unsigned char Hang, double SrcArr[][5]);
//void double_arr(unsigned char Hang, double SrcArr[][5]);
//
//int main()
//{
//    double source[3][5] = {
//        {0.0,0.1,0.2,0.3,0.4},
//        {1.0,1.1,1.2,1.3,1.4},
//        {2.0,2.1,2.2,2.3,2.4}
//    };
//    print_arr(3,source);
//    double_arr(3,source);
//    print_arr(3,source);
//
//
//    return 0;
//}
//
//void print_arr(unsigned char Hang, double SrcArr[][5])
//{
//    uint8_t i,j;
//    for(i=0;i<Hang;i++)
//    {
//        for(j=0;j<5;j++)
//        {
//            printf("%f ",SrcArr[i][j]);
//            if (j==5-1)
//            {
//                printf("\n");
//            }
//        }
//    }
//}
//void double_arr(unsigned char Hang, double SrcArr[][5])
//{
//    uint8_t i,j;
//    for(i=0;i<Hang;i++)
//    {
//        for(j=0;j<5;j++)
//        {
//            SrcArr[i][j]*=2.0;
//        }
//    }
//}



/////////////////////10.10/////////////////
//#include <stdio.h>
//#include <stdint.h>
//void add_arr(unsigned char x, double add_1[x],double add_2[x],double Result[x]);
//
//int main()
//{
//    double add_1[5] = {0.0,0.1,0.2,0.3,0.4};
//    double add_2[5] = {1.0,1.1,1.2,1.3,1.4};
//    double Result[5];
//    add_arr(5,add_1,add_2,Result);
//    uint8_t i;
//    for(i=0;i<5;i++)
//    {
//        printf("%f ",Result[i]);
//        if (i==4)
//            printf("\n");
//    }
//
//    return 0;
//}
//
//void add_arr(unsigned char x, double add_1[x],double add_2[x],double Result[x])
//{
//    uint8_t i;
//    for(i=0;i<x;i++)
//    {
//        Result[i]=add_1[i]+add_2[i];
//    }
//}


/////////////////////10.9/////////////////
//#include <stdio.h>
//#include <stdint.h>
//void copy_arr(unsigned char x, unsigned char y, double Rcv[x][y],double Src[x][y]);
//void print_arr(unsigned char x, unsigned char y, double arr_1[x][y],double arr_2[x][y]);
//int main()
//{
//    double source[3][5] = {
//        {0.0,0.1,0.2,0.3,0.4},
//        {1.0,1.1,1.2,1.3,1.4},
//        {2.0,2.1,2.2,2.3,2.4}
//    };
//
//    double Rcv[3][5];
//    unsigned char i,j;
//    copy_arr(3,5,Rcv,source);
//    print_arr(3,5,Rcv,source);
//
//    return 0;
//}
//
//void copy_arr(unsigned char x, unsigned char y, double Rcv[x][y],double Src[x][y])
//{
//    uint8_t i,j;
//    for(i=0;i<x;i++)
//    {
//        for(j=0;j<y;j++)
//            Rcv[i][j]=Src[i][j];
//    }
//}
//void print_arr(unsigned char x, unsigned char y, double arr_1[x][y],double arr_2[x][y])
//{
//    uint8_t i,j;
//    for(i=0;i<x;i++)
//    {
//        for(j=0;j<y;j++)
//        {
//            printf("%f ",arr_1[i][j]);
//            if (j==y-1)
//                printf("\n");
//        }
//    }
//    for(i=0;i<x;i++)
//    {
//        for(j=0;j<y;j++)
//        {
//            printf("%f ",arr_2[i][j]);
//            if (j==y-1)
//                printf("\n");
//        }
//    }
//}

/////////////////////10.8/////////////////
//#include <stdio.h>
//
//void copy_arr(double target1[], double source[], int num);
//int main()
//{
//    double source[7] = {0.0,1.0,2.0,3.0,4.0,5.0,6.0};
//
//    double Rcv[3];
//    unsigned char i,j;
//    for(i=0;i<3;i++)
//    {
//        copy_arr(Rcv,source+2,3);
//    }
//    for(i=0;i<3;i++)
//    {
//
//            printf("%f ",Rcv[i]);
//            if (i==3)
//                printf("\n");
//
//
//    }
//
//    return 0;
//}
//void copy_arr(double target1[], double source[], int num)
//{
//    unsigned char i;
//    for(i=0;i<num;i++)
//        target1[i]=source[i];
//}


/////////////////////10.7/////////////////
//#include <stdio.h>
//
//void copy_arr(double target1[], double source[], int num);
//int main()
//{
//    double source[3][4] = { {0.1,0.2,0.3,0.4},
//                            {1.1,1.2,1.3,1.4},
//                            {2.1,2.2,2.3,2.4}
//                            };
//    double Rcv[3][4];
//    unsigned char i,j;
//    for(i=0;i<3;i++)
//    {
//        copy_arr(Rcv[i],source[i],4);
//    }
//    for(i=0;i<3;i++)
//    {
//        for(j=0;j<4;j++)
//        {
//            printf("%f ",Rcv[i][j]);
//            if (j==3)
//                printf("\n");
//        }
//
//    }
//
//    return 0;
//}
//void copy_arr(double target1[], double source[], int num)
//{
//    unsigned char i;
//    for(i=0;i<num;i++)
//        target1[i]=source[i];
//}



///////////////////10.6/////////////////
//#include <stdio.h>
//double ReturnDiff(double foo[], unsigned char num);
//int main()
//{
//    double a[5]={1.0,2.0,3.0,5.0,4.0};
//    printf("%f\n",ReturnDiff(a,5));
//    return 0;
//}
//double ReturnDiff(double foo[], unsigned char num)
//{
//    double Max=foo[0];
//    double Min=foo[0];
//    unsigned char i;
//    for(i=1;i<num;i++)
//        if(Max<foo[i])
//            Max=foo[i];
//    for(i=1;i<num;i++)
//        if(Min>foo[i])
//            Min=foo[i];
//    return Max-Min;
//}

///////////////////10.5/////////////////
//#include <stdio.h>
//double ReturnDiff(double foo[], unsigned char num);
//int main()
//{
//    double a[5]={1.0,2.0,3.0,5.0,4.0};
//    printf("%f\n",ReturnDiff(a,5));
//    return 0;
//}
//double ReturnDiff(double foo[], unsigned char num)
//{
//    double Max=foo[0];
//    double Min=foo[0];
//    unsigned char i;
//    for(i=1;i<num;i++)
//        if(Max<foo[i])
//            Max=foo[i];
//    for(i=1;i<num;i++)
//        if(Min>foo[i])
//            Min=foo[i];
//    return Max-Min;
//}

///////////////////10.4/////////////////
//#include <stdio.h>
//int ReturnMax(double foo[], unsigned char num);
//int main()
//{
//    double a[5]={1.0,2.0,3.0,5.0,4.0};
//    printf("%d\n",ReturnMax(a,5));
//    return 0;
//}
//int ReturnMax(double foo[], unsigned char num)
//{
//    double Max=foo[0];
//    int Max_Sub=0;
//    unsigned char i;
//    for(i=1;i<num;i++)
//        if(Max<foo[i])
//        {
//            Max=foo[i];
//            Max_Sub=i;
//        }
//
//    return Max_Sub;
//}

///////////////////10.3/////////////////
//#include <stdio.h>
//int ReturnMax(int foo[], unsigned char num);
//int main()
//{
//    int a[5]={1,2,3,5,4};
//    printf("%d\n",ReturnMax(a,5));
//    return 0;
//}
//int ReturnMax(int foo[], unsigned char num)
//{
//    int Max=foo[0];
//    unsigned char i;
//    for(i=1;i<num;i++)
//        if(Max<foo[i])
//            Max=foo[i];
//    return Max;
//}


///////////////////10.2/////////////////
//#include <stdio.h>
//
//void copy_arr(double target1[], double source[], int num);
//void copy_ptr(double *target2,double *source, int num);
//void copy_ptrs(double *target3, double *source, double *source_5);
//int main()
//{
//    unsigned char j;
//    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
//    double target1[5];
//    double target2[5];
//    double target3[5];
//
//    copy_arr(target1,source,5);
//    copy_ptr(target2,source,5);
//    copy_ptrs(target3,source,source+5);
//
//    for(j=0;j<5;j++)
//        printf("%f  %f  %f\n",target1[j],target2[j],target3[j]);
//
//    return 0;
//}
//void copy_arr(double target1[], double source[], int num)
//{
//    unsigned char i;
//    for(i=0;i<num;i++)
//        target1[i]=source[i];
//}
//void copy_ptr(double *target2,double *source, int num)
//{
//    unsigned char i;
//    for(i=0;i<num;i++)
//        *(target2+i)=*(source+i);
//}
//void copy_ptrs(double *target3, double *source, double *source_5)
//{
//    unsigned char i;
//    for(i=0;source<source_5;i++)
//        *(target3+i)=*(source+i);
//
//}


///////////////////10.1/////////////////
//#include <stdio.h>
//
//#define MONTHS 12 // 一年的月份数
//#define YEARS 5 // 年数
//
//int main()
//{
//    const float rain[YEARS][MONTHS] = {
//        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
//        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
//        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
//        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
//        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }};
//
//    int year, month;
//    float subtot, total;
//    printf(" YEAR RAINFALL (inches)\n");
//    for (year = 0, total = 0; year < YEARS; year++)
//    { // 每一年，各月的降水量总和
//        for (month = 0, subtot = 0; month < MONTHS; month++)
//            subtot += *(*(rain+year)+month);
//        printf("%5d %15.1f\n", 2010 + year, subtot);
//        total += subtot; // 5年的总降水量
//    }
//    printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
//    printf("MONTHLY AVERAGES:\n\n");
//    printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct ");
//    printf(" Nov Dec\n");
//
//    for (month = 0; month < MONTHS; month++)
//    { // 每个月，5年的总降水量
//        for (year = 0, subtot = 0; year < YEARS; year++)
//            subtot += *(*(rain+year)+month);
//        printf("%4.1f ", subtot / YEARS);
//    }
//
//    printf("\n");
//
//
//
//    return 0;
//}
