///////////////////////////////////////////
//////////////Practice 16.7///////////////
/////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <math.h>
#include <limits.h> // �ṩ CHAR_BIT �Ķ��壬CHAR_BIT ��ʾÿ�ֽ� ��λ��
#include <stdbool.h> // C99������bool��true��false
#include <stdarg.h>

void show_array(const double ar[], int n);
double * new_d_array(int n, ...);
int main(void)
{
    double * p1;
    double * p2;
    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);
    return 0;

}
void show_array(const double ar[], int n)
{
    uint8_t i;
    for(i=0;i<n;i++)
    {
        printf("%f  ",ar[i]);
    }
    puts("");
}
double * new_d_array(int n, ...)
{
    va_list ap;
    double *p;
    p=malloc(n*sizeof(double));
    int i;
    va_start(ap,n);
    for(i=0;i<n;i++)
    {
        p[i]=va_arg(ap,double);
    }
    return p;
}


/////////////////////////////////////////////
////////////////Practice 16.6///////////////
///////////////////////////////////////////
///* qsorter.c -- �� qsort()����һ������ */
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//struct names {
//    char first[40];
//    char last[40];
//};
//void showarray(struct names staff[], int n);
//int comp(const void * p1, const void * p2);
//int main(void)
//{
//    struct names staff[5]={
//        {"zhang","huajian"},
//        {"han","yuan"},
//        {"li","san"},
//        {"wang","er"},
//        {"liu","si"}
//    };
//    qsort(staff, 5, sizeof(struct names), comp);
//    puts("\nSorted list:");
//    showarray(staff, 5);
//
//    return 0;
//}
//void showarray(struct names staff[], int n)
//{
//    int index;
//    for (index = 0; index < n; index++)
//    {
//        printf("%s %s\n", staff[index].first,staff[index].last);
//    }
//}
//int comp(const void * p1, const void * p2) /* �ú�������ʽ���������� */
//{
//    /* �õ���ȷ���͵�ָ�� */
//    const struct names *ps1 = (const struct names *) p1;
//    const struct names *ps2 = (const struct names *) p2;
//    int res;
//    res = strcmp(ps1->last, ps2->last); /* �Ƚ��� */
//    if (res != 0)
//        return res;
//    else /* ���ͬ�գ���Ƚ��� */
//        return strcmp(ps1->first, ps2->first);
//}


/////////////////////////////////////////////
////////////////Practice 16.5///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // �ṩ CHAR_BIT �Ķ��壬CHAR_BIT ��ʾÿ�ֽ� ��λ��
//#include <stdbool.h> // C99������bool��true��false
//
//void PrintRandom(int *Array,uint8_t Size,uint8_t HowMuch);
//int main(void)
//{
//    int Src[10]={1,2,3,4,5,6,7,8,9,10};
//    PrintRandom(Src,10,10);
//
//    return 0;
//
//}
//void PrintRandom(int *Array,uint8_t Size,uint8_t HowMuch)
//{
//    time_t t;
//    srand((unsigned) time(&t));
//    uint8_t i;
//    int Result,Former=0;
//    for(i=0;i<HowMuch;i++)
//    {
//        Result=Array[rand()%Size];
//        if(Former==Result && i!=0)
//        {
//            i-=1;
//            continue;
//        }
//        else
//        {
//            Former=Array[rand()%Size];
//            printf("%d  ",Result);
//        }
//
//    }
//
//
//}



/////////////////////////////////////////////
////////////////Practice 16.4///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // �ṩ CHAR_BIT �Ķ��壬CHAR_BIT ��ʾÿ�ֽ� ��λ��
//#include <stdbool.h> // C99������bool��true��false
//
//void Delay_s(double Delay_s);
//int main(void)
//{
//    double Delay=2.1;
//    Delay_s(Delay);
//    puts("delay success");
//
//
//    return 0;
//
//}
//void Delay_s(double Delay_s)
//{
//    double T1,T2;
//    T1=(double)clock();
//    T2=(double)clock();
//    while((T2-T1)/CLOCKS_PER_SEC < Delay_s)
//        T2=(double)clock();
//}


/////////////////////////////////////////////
////////////////Practice 16.3///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // �ṩ CHAR_BIT �Ķ��壬CHAR_BIT ��ʾÿ�ֽ� ��λ��
//#include <stdbool.h> // C99������bool��true��false
//
//typedef struct polar_v {
//    double magnitude;
//    double angle;
//}Polar_V;
//typedef struct rect_v{
//    double x;
//    double y;
//}Rect_V;
//Rect_V polar_to_rect(Polar_V pv);
//
//int main(void)
//{
//    Rect_V result;
//    Polar_V input;
//    while (scanf("%lf %lf", &input.magnitude, &input.angle) == 2)
//    {
//        result = polar_to_rect(input);
//        printf("x = %0.2f, y = %0.2f\n", result.x, result.y);
//    }
//    puts("Bye.");
//
//    return 0;
//
//}
//Rect_V polar_to_rect(Polar_V pv)
//{
//    Rect_V rv;
//
//    rv.x=pv.magnitude*cos(pv.angle*3.14/180.0);
//    rv.y=pv.magnitude*sin(pv.angle*3.14/180.0);
//
//
//    return rv;
//}


/////////////////////////////////////////////
////////////////Practice 16.2///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // �ṩ CHAR_BIT �Ķ��壬CHAR_BIT ��ʾÿ�ֽ� ��λ��
//#include <stdbool.h> // C99������bool��true��false
//
//#define HARMONIC(X,Y)  1.0/( ( (1.0/(X))+(1.0/(Y)) ) / 2.0 )
//int main(void)
//{
//    int a=2,b=3;
//    printf("%f\n",HARMONIC(a,b));
//
//
//    return 0;
//
//}





/*
1.
a. ��Ч
b. plort=FEET*FEET+FEET;
c. nex==6;
d. y=y+5;
    berg=berg+5*lob;
    est=berg+5/y+5;
    nilp=lob*-berg+5;

2.
#define NEW(X) ((X)+5)

3.
#define Min(x,y) ( (x) < (y) ? (x) : (y))

4.
#define EVEN_GT(X,Y) ( ((X)%2==0 && (X)>(Y)) ? 1 : 0)

5.
#define Print

6.
#define  NORMAL 25
#define SPACE ' '
#define PS() printf(" ")
#define BIG(X) ((X)+3)
#define SUMSQ(X,Y) ((X)*(X)+(Y)*(Y))

7.
#define INFO(X) printf("name: "#X";value: %d;address: %p\n",X,&X)

8.
#define FOR_DEBUG
#ifdef FOR_DEBUG


#endif // FOR_DEBUG

9.
#ifdef PR_DATE

    printf("The date is %s.\n", __DATE__);

#endif // PR_DATE

10.
��һ��û�е��ú�����ʡ�˵���ʱ��ռ���˿ռ�
�ڶ��ֵ��þ����ⲿ���ӵĺ���
�����ֵ������ⲿ��������Ϊû��static

11.
#define MYTYPE(X) _Generic((X),\
                           _Bool: "boolean",\
                           default: "not boolean"\
                           )

12.
#include <math.h>
return 0;

13.

qsort(scores, 1000, sizeof(int), mycomp);

//int mycomp(const void * p1, const void * p2)
//{
//    /* Ҫʹ��ָ��double��ָ��������������ֵ */
//    const double * a1 = (const double *) p1;
//    const double * a2 = (const double *) p2;
//    if (*a1 < *a2)
//        return -1;
//    else if (*a1 == *a2)
//        return 0;
//    else
//        return 1;
//}

//14.
//memcpy(data1,data2,100*sizeof(double));
//memcmp(data1,data2+200,100*sizeof(double));


//*/


///////////////////////////////////////////////
//////////////////QingDan 16.21///////////////
/////////////////////////////////////////////
//
////varargs.c -- use variable number of arguments
//#include <stdio.h>
//#include <stdarg.h>
//double sum(int, ...);
//int main(void)
//{
//    double s, t;
//    s = sum(3, 1.1, 2.5, 13.3);
//    t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
//    printf("return value for " "sum(3, 1.1, 2.5, 13.3): %g\n", s);
//    printf("return value for " "sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1): %g\n", t);
//    return 0;
//}
//double sum(int lim, ...)
//{
//    va_list ap; // ����һ�����󴢴����
//    double tot = 0;
//    int i;
//    va_start(ap, lim); // ��ap��ʼ��Ϊ�����б�
//    for (i = 0; i < lim; i++)
//        tot += va_arg(ap, double); // ���ʲ����б��е�ÿһ��
//    va_end(ap); // ������
//    return tot;
//}


///////////////////////////////////////////////
//////////////////QingDan 16.20///////////////
/////////////////////////////////////////////
//
//// mems.c -- ʹ�� memcpy() �� memmove()
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define SIZE 10
//void show_array(const int ar [], int n);
//// �����������֧��C11��_Static_assert������ע�͵���������
//_Static_assert(sizeof(double) == 2 * sizeof(int), "double not twice int size");
//int main(void)
//{
//    int values[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int target[SIZE];
//    double curious[SIZE / 2] = { 2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30 };
//    puts("memcpy() used:");
//    puts("values (original data): ");
//    show_array(values, SIZE);
//    memcpy(target, values, SIZE * sizeof(int));
//    puts("target (copy of values):");
//    show_array(target, SIZE);
//    puts("\nUsing memmove() with overlapping ranges:");
//    memmove(values + 2, values, 5 * sizeof(int));
//    puts("values -- elements 0-4 copied to 2-6:");
//    show_array(values, SIZE);
//    puts("\nUsing memcpy() to copy double to int:");
//    memcpy(target, curious, (SIZE / 2) * sizeof(double));
//    puts("target -- 5 doubles into 10 int positions:");
//    show_array(target, SIZE / 2);
//    show_array(target + 5, SIZE / 2);
//
//    return 0;
//}
//void show_array(const int ar [], int n)
//{
//    int i;
//    for (i = 0; i < n; i++)
//        printf("%d ", ar[i]);
//    putchar('\n');
//}


///////////////////////////////////////////////
//////////////////QingDan 16.19///////////////
/////////////////////////////////////////////
//
//// statasrt.c
//#include <stdio.h>
//#include <limits.h>
//_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");
//int main(void)
//{
//    puts("char is 16 bits.");
//
//
//    return 0;
//}



///////////////////////////////////////////////
//////////////////QingDan 16.18///////////////
/////////////////////////////////////////////
//
///* assert.c -- ʹ�� assert() */
//#include <stdio.h>
//#include <math.h>
//#include <assert.h>
//int main(void)
//{
//    double x, y, z;
//    puts("Enter a pair of numbers (0 0 to quit): ");
//    while (scanf("%lf%lf", &x, &y) == 2 && (x != 0 || y != 0))
//    {
//        z = x * x - y * y; /* Ӧ���� + */
//        assert(z >= 0);
//        printf("answer is %f\n", sqrt(z));
//        puts("Next pair of numbers: ");
//    }
//    puts("Done");
//    return 0;
//}



///////////////////////////////////////////////
//////////////////QingDan 16.17///////////////
/////////////////////////////////////////////
//
///* qsorter.c -- �� qsort()����һ������ */
//#include <stdio.h>
//#include <stdlib.h>
//#define NUM 40
//void fillarray(double ar [], int n);
//void showarray(const double ar [], int n);
//int mycomp(const void * p1, const void * p2);
//int main(void)
//{
//    double vals[NUM];
//    fillarray(vals, NUM);
//    puts("Random list:");
//    showarray(vals, NUM);
//    qsort(vals, NUM, sizeof(double), mycomp);
//    puts("\nSorted list:");
//    showarray(vals, NUM);
//
//    return 0;
//}
//void fillarray(double ar [], int n)
//{
//    int index;
//    for (index = 0; index < n; index++)
//        ar[index] = (double) rand() / ((double) rand() + 0.1);
//}
//void showarray(const double ar [], int n)
//{
//    int index;
//    for (index = 0; index < n; index++)
//    {
//        printf("%9.4f ", ar[index]);
//        if (index % 6 == 5)
//            putchar('\n');
//    }
//    if (index % 6 != 0)
//        putchar('\n');
//}
///* ����С�����˳������ */
//int mycomp(const void * p1, const void * p2)
//{
//    /* Ҫʹ��ָ��double��ָ��������������ֵ */
//    const double * a1 = (const double *) p1;
//    const double * a2 = (const double *) p2;
//    if (*a1 < *a2)
//        return -1;
//    else if (*a1 == *a2)
//        return 0;
//    else
//        return 1;
//}

///////////////////////////////////////////////
//////////////////QingDan 16.16///////////////
/////////////////////////////////////////////
//
///* byebye.c -- atexit()ʾ�� */
//#include <stdio.h>
//#include <stdlib.h>
//void sign_off(void);
//void too_bad(void);
//int main(void)
//{
//    int n;
//    atexit(sign_off); /* ע�� sign_off()���� */
//    puts("Enter an integer:");
//    if (scanf("%d", &n) != 1)
//    {
//        puts("That's no integer!");
//        atexit(too_bad); /* ע�� too_bad()���� */
//        exit(EXIT_FAILURE);
//    }
//    printf("%d is %s.\n", n, (n % 2 == 0) ? "even" : "odd");
//
//    return 0;
//}
//void sign_off(void)
//{
//    puts("Thus terminates another magnificent program from");
//    puts("SeeSaw Software!");
//}
//void too_bad(void)
//{
//    puts("SeeSaw Software extends its heartfelt condolences");
//    puts("to you upon the failure of your program.");
//}

///////////////////////////////////////////////
//////////////////QingDan 16.15///////////////
/////////////////////////////////////////////
//
//// generic.c -- ���巺�ͺ�
//#include <stdio.h>
//#include <math.h>
//#define RAD_TO_DEG (180/(4 * atanl(1)))
//// ����ƽ��������
//#define SQRT(X) _Generic((X),\
//                         long double: sqrtl, \
//                         default: sqrt, \
//                         float: sqrtf)(X)
//// �������Һ������Ƕȵĵ�λΪ��
//#define SIN(X) _Generic((X),\
//                        long double: sinl((X)/RAD_TO_DEG),\
//                        default: sin((X)/RAD_TO_DEG),\
//                        float: sinf((X)/RAD_TO_DEG)\
//                        )
//int main(void)
//{
//    float x = 45.0f;
//    double xx = 45.0;
//    long double xxx = 45.0L;
//    long double y = SQRT(x);
//    long double yy = SQRT(xx);
//    long double yyy = SQRT(xxx);
//    printf("%.17Lf\n", y); // ƥ�� float
//    printf("%.17Lf\n", yy); // ƥ�� default
//    printf("%.17Lf\n", yyy); // ƥ�� long double
//    int i = 45;
//    yy = SQRT(i); // ƥ�� default
//    printf("%.17Lf\n", yy);
//    yyy = SIN(xxx); // ƥ�� long double
//    printf("%.17Lf\n", yyy);
//
//    return 0;
//}



///////////////////////////////////////////////
//////////////////QingDan 16.14///////////////
/////////////////////////////////////////////
//
///* rect_pol.c -- ��ֱ������ת��Ϊ������ */
//#include <stdio.h>
//#include <math.h>
//#define RAD_TO_DEG (180/(4 * atan(1)))
//typedef struct polar_v {
//    double magnitude;
//    double angle;
//}Polar_V;
//typedef struct rect_v{
//    double x;
//    double y;
//}Rect_V;
//Polar_V rect_to_polar(Rect_V);
//int main(void)
//{
//    Rect_V input;
//    Polar_V result;
//    puts("Enter x and y coordinates; enter q to quit:");
//    while (scanf("%lf %lf", &input.x, &input.y) == 2)
//    {
//        result = rect_to_polar(input);
//        printf("magnitude = %0.2f, angle = %0.2f\n", result.magnitude, result.angle);
//    }
//    puts("Bye.");
//
//    return 0;
//}
//Polar_V rect_to_polar(Rect_V rv)
//{
//    Polar_V pv;
//    pv.magnitude = sqrt(rv.x * rv.x + rv.y * rv.y);
//    if (pv.magnitude == 0)
//        pv.angle = 0.0;
//    else
//        pv.angle = RAD_TO_DEG * atan2(rv.y, rv.x);
//    return pv;
//}



///////////////////////////////////////////////
//////////////////QingDan 16.13///////////////
/////////////////////////////////////////////
//
//// mytype.c
//#include <stdio.h>
//#define MYTYPE(X) _Generic((X),\
//                           int: "int",\
//                           float : "float",\
//                           double: "double",\
//                           default: "other"\
//                           )
//int main(void)
//{
//    int d = 5;
//    printf("%s\n", MYTYPE(d)); // d ��int����
//    printf("%s\n", MYTYPE(2.0*d)); // 2.0 * d ��double����
//    printf("%s\n", MYTYPE(3L)); // 3L��long����
//    printf("%s\n", MYTYPE(&d)); // &d �������� int *
//
//    return 0;
//}




///////////////////////////////////////////////
//////////////////QingDan 16.12///////////////
/////////////////////////////////////////////
//
//// predef.c -- Ԥ������Ԥ�����ʶ��
//#include <stdio.h>
//void why_me();
//int main(void)
//{
//    printf("The file is %s.\n", __FILE__);
//    printf("The date is %s.\n", __DATE__);
//    printf("The time is %s.\n", __TIME__);
//    printf("The version is %ld.\n", __STDC_VERSION__);
//    printf("This is line %d.\n", __LINE__);
//    printf("This function is %s\n", __func__);
//    why_me();
//
//    return 0;
//}
//void why_me()
//{
//    printf("This function is %s\n", __func__);
//    printf("This is line %d.\n", __LINE__);
//}
//

///////////////////////////////////////////////
//////////////////QingDan 16.11///////////////
/////////////////////////////////////////////
//
//// doubincl.c -- ����ͷ�ļ�����
//#include <stdio.h>
//#include "names.h"
//#include "names.h" // ��С�ĵ�2�ΰ���ͷ�ļ�
//int main(void)
//{
//    names winner = { "Less", "Ismoor" };
//    printf("The winner is %s %s.\n", winner.first, winner.last);
//    return 0;
//}



///////////////////////////////////////////////
//////////////////QingDan 16.9///////////////
/////////////////////////////////////////////
///* ifdef.c -- ʹ���������� */
//#include <stdio.h>
//#define JUST_CHECKING
//#define LIMIT 4
//int main(void)
//{
//    int i;
//    int total = 0;
//    for (i = 1; i <= LIMIT; i++)
//    {
//        total += 2 * i*i + 1;
//        #ifdef JUST_CHECKING
//            printf("i=%d, running total = %d\n", i, total);
//        #endif
//    }
//    printf("Grand total = %d\n", total);
//
//    return 0;
//}



///////////////////////////////////////////////
//////////////////QingDan 16.8///////////////
/////////////////////////////////////////////
//
//// useheader.c -- ʹ�� names_st �ṹ
//#include <stdio.h>
//#include "names_st.h" // ��סҪ���� names_st.c
//int main(void)
//{
//    names candidate;
//    get_names(&candidate);
//    printf("Let's welcome ");
//    show_names(&candidate);
//    printf(" to this program!\n");
//    return 0;
//}




///////////////////////////////////////////////
//////////////////QingDan 16.5///////////////
/////////////////////////////////////////////
//
//
//// variadic.c -- ��κ�
//#include <stdio.h>
//#include <math.h>
//#define PR(X, ...) printf("Message " #X ": " __VA_ARGS__)
//int main(void)
//{
//    double x = 48;
//    double y;
//    y = sqrt(x);
//    PR(1, "x = %g\n", x);
//    PR(2, "x = %.2f, y = %.4f\n", x, y);
//
//    return 0;
//}
//

///////////////////////////////////////////////
//////////////////QingDan 16.4///////////////
/////////////////////////////////////////////
//
///* subst.c -- ���ַ������滻 */
//// glue.c -- ʹ��##�����
//#include <stdio.h>
//#define XNAME(n) x ## n
//#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n);
//int main(void)
//{
//    int XNAME(1) = 14; // ��� int x1 = 14;
//    int XNAME(2) = 20; // ��� int x2 = 20;
//    int x3 = 30;
//    PRINT_XN(1); // ��� printf("x1 = %d\n", x1);
//    PRINT_XN(2); // ��� printf("x2 = %d\n", x2);
//    PRINT_XN(3); // ��� printf("x3 = %d\n", x3);
//
//    return 0;
//}




///////////////////////////////////////////////
//////////////////QingDan 16.3///////////////
/////////////////////////////////////////////
//
///* subst.c -- ���ַ������滻 */
//#include <stdio.h>
//#define PSQR(x) printf("The square of " #x " is %d.\n",((x)*(x)))
//int main(void)
//{
//    int y = 5;
//    PSQR(y);
//    PSQR(2 + 4);
//
//    return 0;
//}



///////////////////////////////////////////////
//////////////////QingDan 16.2///////////////
/////////////////////////////////////////////
//
///* mac_arg.c -- �������ĺ� */
//#include <stdio.h>
//#define SQUARE(X) X*X
//#define PR(X) printf("The result is %d.\n", X)
//
//int main(void)
//{
//    int x = 5;
//    int z;
//    printf("x = %d\n", x);
//    z = SQUARE(x);
//    printf("Evaluating SQUARE(x): ");
//    PR(z);
//    z = SQUARE(2);
//    printf("Evaluating SQUARE(2): ");
//    PR(z);
//    printf("Evaluating SQUARE(x+2): ");
//    PR(SQUARE(x + 2));
//    printf("Evaluating 100/SQUARE(2): ");
//    PR(100 / SQUARE(2));
//    printf("x is %d.\n", x);
//    printf("Evaluating SQUARE(++x): ");
//    PR(SQUARE(++x));
//    printf("After incrementing, x is %x.\n", x);
//    return 0;
//}


///////////////////////////////////////////////
//////////////////QingDan 16.1///////////////
/////////////////////////////////////////////
///* preproc.c -- �򵥵�Ԥ����ʾ�� */
//#include <stdio.h>
//#define TWO 2 /* ����ʹ��ע�� */
//#define OW "Consistency is the last refuge of the unimagina\
//tive.- Oscar Wilde" /* ��б�ܰѸö�����������һ�� */
//#define FOUR TWO*TWO
//#define PX printf("X is %d.\n", x)
//#define FMT "X is %d.\n"
//int main(void)
//{
//    int x = TWO;
//    PX;
//    x = FOUR;
//    printf(FMT, x);
//    printf("%s\n", OW);
//    printf("TWO: OW\n");
//    return 0;
//}
