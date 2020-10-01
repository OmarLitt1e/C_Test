
////////////////////////////////////////////
//////////////11.13.16//////////////////////
//////////////////////////////////////////
#include <stdio.h>
#include <string.h> // strcmp()函数的原型在该头文件中
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

char * My_toupper(char *str);
char * My_tolower(char *str);
int main(int argc,char **argv)
{
    char  Command_1[3]="-p";
    char  Command_2[3]="-u";
    char  Command_3[3]="-l";

    char str[40];
    puts("Enter a string");
    gets(str);
//    puts("Choose what you want to do with it");
//    puts("-p : Print as source");
//    puts("-u : turn string character to upper");
//    puts("-l : turn string character to lower");

    if(strcmp(Command_1,argv[1])==0)
        puts(str);
    else if(strcmp(Command_2,argv[1])==0)
        puts(My_toupper(str));
    else if(strcmp(Command_3,argv[1])==0)
        puts(My_tolower(str));

    return 0;
}
char * My_toupper(char *str)
{
    unsigned char i=0;
    while(*(str+i)!='\0')
    {
        *(str+i)=toupper(*(str+i));
        i++;
    }
    return str;
}
char * My_tolower(char *str)
{
    unsigned char i=0;
    while(*(str+i)!='\0')
    {
        *(str+i)=tolower(*(str+i));
        i++;
    }
    return str;
}

//////////////////////////////////////////////
////////////////11.13.15//////////////////////
////////////////////////////////////////////
//#include <stdio.h>
//#include <string.h> // strcmp()函数的原型在该头文件中
//#include <ctype.h>
//#include <stdint.h>
//#include <stdlib.h>
//#include <math.h>
//int My_atoi(char *str);
//int main(void)
//{
//    char str[40];
//    puts("Enter a number string");
//    gets(str);
//    printf("%d\n",My_atoi(str));
//    return 0;
//}
//int My_atoi(char *str)
//{
//    unsigned char i,k;
//    int Result=0;
//    int MiddleValue=0;
//    unsigned char Lenth=0;
//    Lenth=strlen(str);
//    char ForSearch[10]={'0','1','2','3','4','5','6','7','8','9'};
//    int ForAssign[10]={0,1,2,3,4,5,6,7,8,9};
//    if(Lenth>10)
//        return 0;   //too big for int
//    for(i=0;i<Lenth;i++)
//    {
//        if(isdigit(*(str+i))==0)
//            return 0;
//        else
//        {
//            MiddleValue=ForAssign[(strchr(ForSearch,*(str+i))-ForSearch)];
//            for(k=i;k<Lenth-1;k++)
//            {
//                MiddleValue*=10;
//            }
//        }
//        Result+=MiddleValue;
//    }
//    return Result;
//}


//////////////////////////////////////////////
////////////////11.13.14//////////////////////
////////////////////////////////////////////
//#include <stdio.h>
//#include <string.h> // strcmp()函数的原型在该头文件中
//#include <ctype.h>
//#include <stdint.h>
//#include <stdlib.h>
//#include <math.h>
//int main(int argc,char *argv[])
//{
//    unsigned char i;
//    double base=0.0,result=1.0;
//    int power=0;
//    base=atof(argv[1]);
//    power=atoi(argv[2]);
//    for(i=0;i<power;i++)
//        result*=base;
//    printf("%f\n",result);
//    return 0;
//}

//////////////////////////////////////////////
////////////////11.13.13//////////////////////
////////////////////////////////////////////
//#include <stdio.h>
//#include <string.h> // strcmp()函数的原型在该头文件中
//#include <ctype.h>
//#include <stdint.h>
//
//int main(int argc,char *argv[])
//{
//    unsigned char i;
//    for(i=argc-1;i>0;i--)
//        printf("%s ",argv[i]);
//    return 0;
//}



//////////////////////////////////////////////
////////////////11.13.12//////////////////////
////////////////////////////////////////////
//#include <stdio.h>
//#include <string.h> // strcmp()函数的原型在该头文件中
//#include <ctype.h>
//#include <stdint.h>
//
//int main(void)
//{
//    char c;
//    unsigned char WordsNum=0,UpperNum=0,LowerNum=0,PuncNum=0,NumberNum=0,WordBegin=0,WordTail=0;
//
//    while((c=getchar())!=EOF)
//    {
//        if(ispunct(c))
//            PuncNum++;
//        else if(isupper(c))
//            UpperNum++;
//        else if(islower(c))
//            LowerNum++;
//        else if(isdigit(c))
//            NumberNum++;
//        if(isalpha(c)!=0 && WordBegin==0)
//        {
//            WordBegin=1;
//            WordsNum++;
//        }
//        else if(isalpha(c)==0)
//        {
//            WordBegin=0;
//        }
//    }
//    printf("There are %d Words, %d upper ,%d lower,%d punc, %d digit\n",WordsNum,UpperNum,LowerNum,PuncNum,NumberNum);
//
//    return 0;
//}


//////////////////////////////////////////////
////////////////11.13.11//////////////////////
////////////////////////////////////////////
//#include <stdio.h>
//#include <string.h> // strcmp()函数的原型在该头文件中
//#include <ctype.h>
//#include <stdint.h>
//void FindMaxAndPrint(char s1[][40],unsigned char str_nums);
//void FindMaxLenthAndPrint(char s1[][40],unsigned char str_nums);
//void FindLongestFirstWordAndPrint(char s1[][40],unsigned char str_nums);
//unsigned char GetFirstWordsLenth(char *str);
//int main(void)
//{
//    char strArray[10][40];
//    puts("Enter 10 strings");
//    unsigned char i,str_nums=0;
//    char c;
//    for(i=0;i<10;i++)
//    {
//        if(gets(*(strArray+i))==NULL)
//            break;
//        str_nums=i+1;
//    }
//    printf("There's %d strings you put in\n",str_nums);
//    puts("What do you want to do with them? Enter your choice");
//    puts("a : print them");
//    puts("b : print them in ASCII order");
//    puts("c : print them in the lenth of string");
//    puts("d : print them in the lenth of first word in string");
//    puts("q : quit");
//    while((c=getchar())!=EOF)
//    {
//        while(getchar()!='\n')
//            ;
//        if(c=='q')
//            break;
//        switch (c)
//        {
//            case 'a':
//                for(i=0;i<str_nums;i++)
//                        puts(*(strArray+i));
//                break;
//            case 'b':
//                FindMaxAndPrint(strArray,str_nums);
//                break;
//            case 'c':
//                FindMaxLenthAndPrint(strArray,str_nums);
//                break;
//            case 'd':
//                FindLongestFirstWordAndPrint(strArray,str_nums);
//                break;
//            default:
//                break;
//        }
//    }
//    return 0;
//}
//void FindMaxAndPrint(char s1[][40],unsigned char str_nums)
//{
//    char temp[str_nums][40];
//    char *temp1[str_nums];
//    char *temp2;
//    unsigned char i,j;
//    for(i=0;i<str_nums;i++)
//    {
//        strcpy(*(temp+i),*(s1+i));
//        temp1[i]=temp[i];
//    }
//
//
//    for(i=0;i<str_nums;i++)
//    {
//        for(j=i+1;j<str_nums;j++)
//        {
//            if(strcmp(*(temp+i),*(temp+j))<0)
//            {
//                temp2=temp1[i];
//                temp1[i]=temp1[j];
//                temp1[j]=temp2;
//            }
//        }
//    }
//    for(i=0;i<str_nums;i++)
//        puts(temp1[i]);
//}
//void FindMaxLenthAndPrint(char s1[][40],unsigned char str_nums)
//{
//    char temp[str_nums][40];
//    char *temp1[str_nums];
//    char *temp2;
//    unsigned char i,j;
//    for(i=0;i<str_nums;i++)
//    {
//        strcpy(*(temp+i),*(s1+i));
//        temp1[i]=temp[i];
//    }
//
//
//    for(i=0;i<str_nums;i++)
//    {
//        for(j=i+1;j<str_nums;j++)
//        {
//            if(strlen(*(temp+i))<strlen(*(temp+j)))
//            {
//                temp2=temp1[i];
//                temp1[i]=temp1[j];
//                temp1[j]=temp2;
//            }
//        }
//    }
//    for(i=0;i<str_nums;i++)
//        puts(temp1[i]);
//}
//void FindLongestFirstWordAndPrint(char s1[][40],unsigned char str_nums)
//{
//    char temp[str_nums][40];
//    char *temp1[str_nums];
//    char *temp2;
//    unsigned char i,j;
//    for(i=0;i<str_nums;i++)
//    {
//        strcpy(*(temp+i),*(s1+i));
//        temp1[i]=temp[i];
//    }
//
//
//    for(i=0;i<str_nums;i++)
//    {
//        for(j=i+1;j<str_nums;j++)
//        {
//            if(GetFirstWordsLenth(*(temp+i))<GetFirstWordsLenth(*(temp+j)))
//            {
//                temp2=temp1[i];
//                temp1[i]=temp1[j];
//                temp1[j]=temp2;
//            }
//        }
//    }
//    for(i=0;i<str_nums;i++)
//        puts(temp1[i]);
//}
//unsigned char GetFirstWordsLenth(char *str)
//{
//    unsigned char Lenth,i=0;
//
//    while(*(str+i)!=' ' && *(str+i)!='\0')
//        Lenth=++i;
//    return Lenth;
//}
//
//////////////////////////////////////////////
////////////////11.13.9//////////////////////
////////////////////////////////////////////
//#include <stdio.h>
//#include <string.h> // strcmp()函数的原型在该头文件中
//#include <ctype.h>
//#include <stdint.h>
//
//char *reverse_string(char *s1);
//int main(void)
//{
//    char s1[40];
//    puts("enter a string");
//    gets(s1);
//
//    puts(reverse_string(s1));
//
//
//    return 0;
//}
//char *reverse_string(char *s1)
//{
//    char temp;
//    unsigned char Lenth=strlen(s1);
//    unsigned char i=0;
//    while(i<Lenth/2)
//    {
//        temp=*(s1+i);
//        *(s1+i)=*(s1+Lenth-1-i);
//        *(s1+Lenth-1-i)=temp;
//        i++;
//    }
//
//    return s1;
//}


//////////////////////////////////////////////
////////////////11.13.8//////////////////////
////////////////////////////////////////////
//#include <stdio.h>
//#include <string.h> // strcmp()函数的原型在该头文件中
//#include <ctype.h>
//#include <stdint.h>
//
//char *string_in(char *s1,char *s2);
//int main(void)
//{
//    char s1[40];
//    char s2[40];
//    puts("enter 2 string");
//    gets(s1);
//    gets(s2);
//
//    puts(string_in(s1,s2));
//
//
//    return 0;
//}
//char *string_in(char *s1,char *s2)
//{
//    return strstr(s1,s2);
//}



//////////////////////////////////////////////
////////////////11.13.7//////////////////////
////////////////////////////////////////////
//#include <stdio.h>
//#include <string.h> // strcmp()函数的原型在该头文件中
//#include <ctype.h>
//#include <stdint.h>
//
//char *MyStrncpy(char *s1,char *s2,unsigned char n);
//int main(void)
//{
//    char s1[]="aa";
//    char s2[]="xxx";
//    puts(MyStrncpy(s1,s2,3));
//
//
//    return 0;
//}
//char *MyStrncpy(char s1[],char s2[],unsigned char n)
//{
//    unsigned char i=0;
//    while(i<n)
//    {
//        if(s1[i]!='\0')
//        {
//            if(s2[i]=='\0')
//            {
//                while(s1[i]!='\0' && i<n)
//                    s1[i++]='\0';
//                break;
//            }
//            else
//                s1[i]=s2[i];
//        }
//        else
//        {
//            puts("The source string is not big enough");
//            break;
//        }
//        i++;
//    }
//
//    return s1;
//
//}


//////////////////////////////////////////////
////////////////11.13.6//////////////////////
////////////////////////////////////////////
//#include <stdio.h>
//#include <string.h> // strcmp()函数的原型在该头文件中
//#include <ctype.h>
//#include <stdint.h>
//
//char Is_Within(const char *str,char charc);
//int main(void)
//{
//    const char *string="ZhangHuaJian love HanYuan";
//    char c;
//    puts("Enter a character for search");
//    while((c=getchar())!=EOF)
//    {
//        printf("%d\n",Is_Within(string,c));
//        while(getchar()!='\n')
//            ;
//    }
//
//
//
//    return 0;
//}
//char Is_Within(const char *str,char charc)
//{
//    if((strchr(str,charc))!=NULL)
//        return 1;
//    else
//        return 0;
//}



//////////////////////////////////////////////
////////////////11.13.5//////////////////////
////////////////////////////////////////////
//#include <stdio.h>
//#include <string.h> // strcmp()函数的原型在该头文件中
//#include <ctype.h>
//#include <stdint.h>
//
//char * SearchWord(const char *str,char charc);
//int main(void)
//{
//    const char *string="ZhangHuaJian love HanYuan";
//    char c;
//    puts("Enter a character for search");
//    while((c=getchar())!=EOF)
//        puts(SearchWord(string,c));
//
//
//    return 0;
//}
//char * SearchWord(const char *str,char charc)
//{
//    char *p;
//    if((p=strchr(str,charc))!=NULL)
//        return p;
//    else
//        return NULL;
//}



//////////////////////////////////////////////
////////////////11.13.1//////////////////////
////////////////////////////////////////////
//#include <stdio.h>
//#include <string.h> // strcmp()函数的原型在该头文件中
//#include <ctype.h>
//#include <stdint.h>
//
//char * GetSave(int n);
//int main(void)
//{
//    char * str;
//    str=GetSave(5);
//    printf("%s\n",str);
//    return 0;
//}
//char * GetSave(int n)
//{
//    char str[n+1],i=0,* p,c;
//    while((c=getchar()!=EOF))
//    {
//        *(str+i)=c;
//        if(i++==n)
//        {
//            *(str+i+1)='\0';
//            break;
//        }
//
//    }
//    p=str;
//    return p;
//}


/////////////////////////////////////////////
////////////////Practice 11.13////////////////
/////////////////////////////////////////////
//#include <stdio.h>
//#include <string.h> // strcmp()函数的原型在该头文件中
//#include <ctype.h>
//#include <stdint.h>
//#define ANSWER "Grant"
//#define SIZE 40
//char * s_gets(char * st, int n);
//char * s_gets(char * st, int n);
//int main(void)
//{
//    char try[SIZE];
//    puts("Who is buried in Grant's tomb?");
//    s_gets(try, SIZE);
//    uint8_t i;
//    for(i=0;i<strlen(try);i++)
//    {
//        if (i==0)
//        {
//            *try=toupper(*try);
//        }
//        else
//        {
//            *(try+i)=tolower(*(try+i));
//        }
//    }
//    while (strcmp(try, ANSWER) != 0)
//    {
//        puts("No, that's wrong. Try again.");
//        s_gets(try, SIZE);
//        for(i=0;i<strlen(try);i++)
//        {
//            if (i==0)
//            {
//                *try=toupper(*try);
//            }
//            else
//            {
//                *(try+i)=tolower(*(try+i));
//            }
//        }
//    }
//    puts("That's right!");
//    return 0;
//}
//char * s_gets(char * st, int n)
//{
//    char * ret_val;
//    char * LineBreak;
//    ret_val = fgets(st, n, stdin);
//
//    if (ret_val) // 即，ret_val != NULL
//    {
//        while((LineBreak=strchr(st,'\n'))!=NULL)
//            *LineBreak='\0';
//        while (getchar() != '\n')
//            ;
//    }
//    return ret_val;
//}



/////////////////////////////////////////////
////////////////Practice 11.12////////////////
/////////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdint.h>
//#include <string.h>
//char * CaptureSpace(char *str);
//char * s_gets(char * st, int n);
//int main(void)
//{
//    char string[40];
//    s_gets(string,20);
//    printf("%s\n",string);
//    printf("%s\n",CaptureSpace(string));
//    return 0;
//}
//char * CaptureSpace(char *str)
//{
//    char * temp;
//    temp=strchr(str,' ');
//    if (temp!=NULL)
//        return temp;
//    else
//        return NULL;
//}
//char * s_gets(char * st, int n)
//{
//    char * ret_val;
//    char * LineBreak;
//    ret_val = fgets(st, n, stdin);
//
//    if (ret_val) // 即，ret_val != NULL
//    {
//        while((LineBreak=strchr(st,'\n'))!=NULL)
//            *LineBreak='\0';
//        while (getchar() != '\n')
//            ;
//    }
//    return ret_val;
//}

/////////////////////////////////////////////
////////////////Practice 11.11////////////////
/////////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdint.h>
//#include <string.h>
//uint8_t strlenth(char *str);
//char * s_gets(char * st, int n);
//int main(void)
//{
//    char string[20];
//    s_gets(string,10);
//    printf("%s\n",string);
//    printf("%u\n",strlenth(string));
//    return 0;
//}
//uint8_t strlenth(char *str)
//{
//    char * temp;
//    uint8_t Lenth=0;
//    temp=str;
//    while(*(temp++)!='\0')
//        Lenth++;
//    return Lenth;
//}
//char * s_gets(char * st, int n)
//{
//    char * ret_val;
//    char * LineBreak;
//    ret_val = fgets(st, n, stdin);
//
//    if (ret_val) // 即，ret_val != NULL
//    {
//        while((LineBreak=strchr(st,'\n'))!=NULL)
//            *LineBreak='\0';
//        while (getchar() != '\n')
//            ;
//    }
//    return ret_val;
//}


/////////////////////////////////////////////
////////////////Practice 11.10////////////////
/////////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdint.h>
//uint8_t strlenth(char *str);
//char * s_gets(char * st, int n);
//int main(void)
//{
//    char string[20];
//    s_gets(string,10);
//    printf("%s\n",string);
//    printf("%u\n",strlenth(string));
//    return 0;
//}
//uint8_t strlenth(char *str)
//{
//    char * temp;
//    uint8_t Lenth=0;
//    temp=str;
//    while(*(temp++)!='\0')
//        Lenth++;
//    return Lenth;
//}
//char * s_gets(char * st, int n)
//{
//    char * ret_val;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val) // 即，ret_val != NULL
//    {
//        while (*(st++) != '\n' && *(st++) != '\0')
//            ;
//        if (*st == '\n')
//            *st = '\0';
//        else
//            while (getchar() != '\n')
//                ;
//    }
//    return ret_val;
//}
//


///////////////////////////////////////////
//////////////Practice 11.9////////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdint.h>
//char * s_gets(char * st, int n);
//int main(void)
//{
//    char string[20];
//    s_gets(string,10);
//    printf("%s\n",string);
//    return 0;
//}
//char * s_gets(char * st, int n)
//{
//    char * ret_val;
//
//    ret_val = fgets(st, n, stdin);
//    if (ret_val) // 即，ret_val != NULL
//    {
//        while (*(st++) != '\n' && *(st++) != '\0')
//            ;
//        if (*st == '\n')
//            *st = '\0';
//        else
//            while (getchar() != '\n')
//                ;
//    }
//    return ret_val;
//}

////////////////////////////////////////////
//////////////FuXiTi 11////////////////////
//////////////////////////////////////////
/*

字符串末尾是\0

2.
See you at the snack bar.\n
ee you at the snack bar.\n
See yo\n
e yo\n

3.
y
my
mmy
ummy
yummy

4.
I read part of it all 

5.
Ho Ho Ho!
char *
x=str
*--pc object is pointer pc
--*pc object is value of *pc
printf str forward and reverse
print 1 '\0' not 2
make sure str end of '\0'

6.
16bytes, 4bytes, 16bytes

7.
How are ya, sweetie?
"How are ya, sweetie?"
Beat the clock.
eat the clock.
Beat the clock. Win a toy.
Beat
chat
t
at
"How are ya, sweetie?"

8.
faavrhee
*le*on*sm

*/
