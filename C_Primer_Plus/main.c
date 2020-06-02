///////////////4.8-8/////////////////
#include <stdio.h>
#include <float.h>

int main(void)
{
    float mile;
    float gallon;

    printf("Enter mile and gas gallon\n");
    scanf("%f%f",&mile,&gallon);
    printf("mile per gallon is %.1f\n",mile/gallon);
    printf("kilometer per litre is %.1f\n",(mile*1.609)/(gallon*3.785));

    return 0;
}

/////////////////4.8-7/////////////////
//#include <stdio.h>
//#include <float.h>
//
//int main(void)
//{
//    double a=1.0/3.0;
//    float b=1.0/3.0;
//
//    printf("%.6f\t%.6f\n",a,b);
//    printf("%.12f\t%.12f\n",a,b);
//    printf("%.16f\t%.16f\n",a,b);
//    printf("FLT_DIG is %d\nDBL_DIG is %d\n",FLT_DIG,DBL_DIG);
//    return 0;
//}

/////////////////4.8-6/////////////////
//#include <stdio.h>
//#include <string.h>
//int main(void)
//{
//    float rate;
//    float size;
//    char FirstName[10];
//    char LastName[10];
//    printf("Enter your first name\n");
//    scanf("%s",FirstName);
//    printf("Enter your last name\n");
//    scanf("%s",LastName);
//    printf("%s %s\n",LastName,FirstName);
//    printf("%d\t%d\n",(unsigned char)strlen(LastName),(unsigned char)strlen(FirstName));
//
//    printf("%-s\t%-s\n",LastName,FirstName);
//    printf("%-d\t%-d\n",(unsigned char)strlen(LastName),(unsigned char)strlen(FirstName));
//
//    return 0;
//}

/////////////////4.8-5/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    float rate;
//    float size;
//
//    printf("Enter rate and size\n");
//    scanf("%f%f",&rate,&size);
//    printf("At %.2f megabits per second, a file of %.2f megabytes"
//    " downloads in %.2f seconds\n",
//    rate,size,size*8.0/rate);
//
//    return 0;
//}

/////////////////4.8-4/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    float stature;
//    char name[20];
//    printf("Enter your stature and name\n");
//    scanf("%f%s",&stature,name);
//    printf("%s, you are %.3f feet tall\n",name,stature);
//
//    return 0;
//}

/////////////////4.8-3/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    float a;
//
//    scanf("%f",&a);
//    printf("%e\n",a);
//    printf("%+f\n",a);
//
//    return 0;
//}

/////////////////4.8-2/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    char Name[20];
//
//    printf("Enter your name\n");
//    scanf("%s",Name);
//    printf("\"%20s\"\n",Name);
//    printf("\"%15s\"\n",Name);
//    //printf("\"%s%s\"\n",FirstName,LastName);
//
//
//    return 0;
//}

/////////////////4.8-1/////////////////
//#include <stdio.h>
//
//int main(void)
//{
//    char FirstName[20];
//    char LastName[20];
//    printf("Enter your first name and last name\n");
//    scanf("%s%s",FirstName,LastName);
//    printf("Your name is \"%s,%s\"\n",FirstName,LastName);
//    return 0;
//}
