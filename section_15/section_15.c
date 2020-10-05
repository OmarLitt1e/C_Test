/////////////////////////////////////////////
////////////////Practice 15.7///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节 的位数
//#include <stdbool.h> // C99定义了bool、true、false
//
//void PrintType(uint32_t *p);
//void SetFrontSize(uint32_t *p);
//void eatline(void);
//int main(void)
//{
//    uint32_t TypeFace,*p;
//    p=&TypeFace;
//    TypeFace=0x010c0000;
//    PrintType(p);
//    SetFrontSize(p);
//    PrintType(p);
//    puts("Bye!");
//
//    return 0;
//
//}
//void SetFrontSize(uint32_t *p)
//{
//    puts("Enter front size (0-127):");
//    uint32_t temp,i;
//    if(scanf("%u",&temp)!=1)
//    {
//        puts("error input");
//        exit(EXIT_FAILURE);
//    }
//    (*p)&=0xff00ffff;
////    for(i=0;i<8;i++)
////    {
////        if(temp&(0x01<<i))
////            (*p)|=01<<(16+i);
////    }
////
//
//}
//void PrintType(uint32_t *p)
//{
//    puts("ID    SIZE    ALIGNMENT   B     I      U");
//    printf("%u     %u",(*p)>>24,(*p)>>16 & 0x000000ff);
//    switch((*p)>>3 & 0x00000003)
//    {
//        case 0:
//            printf("        left");
//            break;
//        case 1:
//            printf("    mid");
//            break;
//        case 2:
//            printf("    right");
//            break;
//        default:
//            break;
//    }
//    if(((*p)>>2 & 0x00000001)==1)
//        printf("     on");
//    else
//        printf("     off");
//    if(((*p)>>1 & 0x00000001)==1)
//        printf("    on");
//    else
//        printf("    off");
//    if(((*p) & 0x00000001)==1)
//        printf("    on");
//    else
//        printf("    off");
//    puts("");
//    puts("f)change front   s)change size   a)change alignment");
//    puts("b)toggle bold   i)toggle italic   u)toggle underline");
//    puts("q)quit");
//
//}
//void eatline(void)
//{
//    while (getchar() != '\n')
//        continue;
//}




///////////////////////////////////////////
//////////////Practice 15.7///////////////
/////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <math.h>
#include <limits.h> // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节 的位数
#include <stdbool.h> // C99定义了bool、true、false

void PrintType(uint32_t *p);
void SetAlignment(uint32_t *p);
void SetFrontSize(uint32_t *p);
void SetItalic(uint32_t *p);
void eatline(void);
int main(void)
{
    uint32_t TypeFace,*p;
    p=&TypeFace;
    TypeFace=0x010c0000;
    PrintType(p);
    char Choose;
    while(scanf("%c",&Choose)==1 && Choose!='q')
    {
        if(Choose=='\n')
            continue;
        eatline();
        switch(Choose)
        {
            case 's':
                SetFrontSize(p);
                break;
            case 'a':
                SetAlignment(p);
                break;
            case 'i':
                SetItalic(p);
                break;
            default:
                break;

        }

        PrintType(p);
    }
    puts("Bye!");

    return 0;

}
void SetItalic(uint32_t *p)
{
    if((*p)&0x00000002)
        (*p)&=0xfffffffd;
    else
        (*p)|=0x00000002;
}
void SetFrontSize(uint32_t *p)
{
    puts("Enter front size (0-127):");
    uint32_t temp,i;
    if(scanf("%u",&temp)!=1)
    {
        puts("error input");
        exit(EXIT_FAILURE);
    }
    (*p)&=0xff00ffff;
    for(i=0;i<8;i++)
    {
        if(temp&(0x01<<i))
            (*p)|=01<<(16+i);
    }


}
void SetAlignment(uint32_t *p)
{
    puts("Select alignment:");
    puts("l)left    c)center    r)right");
    char Choose1;
    if(scanf("%c",&Choose1)!=1)
    {
        puts("error input");
        exit(EXIT_FAILURE);
    }
    switch(Choose1)
    {
        case 'l':
            (*p)&=0xffffff07;
            break;
        case 'c':
            (*p)&=0xffffff07;
            (*p)|=0x00000008;
            break;
        case 'r':
            (*p)&=0xffffff07;
            (*p)|=0x00000018;
            break;
        default:
            break;

    }
}
void PrintType(uint32_t *p)
{
    puts("ID    SIZE    ALIGNMENT   B     I      U");
    printf("%u     %u",(*p)>>24,(*p)>>16 & 0x000000ff);
    switch((*p)>>3 & 0x00000003)
    {
        case 0:
            printf("        left");
            break;
        case 1:
            printf("    mid");
            break;
        case 2:
            printf("    right");
            break;
        default:
            break;
    }
    if(((*p)>>2 & 0x00000001)==1)
        printf("     on");
    else
        printf("     off");
    if(((*p)>>1 & 0x00000001)==1)
        printf("    on");
    else
        printf("    off");
    if(((*p) & 0x00000001)==1)
        printf("    on");
    else
        printf("    off");
    puts("");
    puts("f)change front   s)change size   a)change alignment");
    puts("b)toggle bold   i)toggle italic   u)toggle underline");
    puts("q)quit");

}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}




/////////////////////////////////////////////
////////////////Practice 15.6///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节 的位数
//#include <stdbool.h> // C99定义了bool、true、false
//
//struct TYPEFACE{
//    uint32_t TypeID : 8;
//    uint32_t TypeSize : 7;
//    uint32_t  : 1;
//    uint32_t Align : 2;
//    uint32_t Overstriking : 1;
//    uint32_t Italic : 1;
//    uint32_t Underline : 1;
//    uint32_t  : 11;
//};
//void PrintType(struct TYPEFACE Prnt);
//void SetAlignment(struct TYPEFACE *p);
//void SetFrontSize(struct TYPEFACE *p);
//void SetItalic(struct TYPEFACE *p);
//void eatline(void);
//int main(void)
//{
//    struct TYPEFACE Prnt={1,12,0,0,0,0};
//    struct TYPEFACE *p;
//    p=&Prnt;
//    PrintType(Prnt);
//    char Choose;
//    while(scanf("%c",&Choose)==1 && Choose!='q')
//    {
//        if(Choose=='\n')
//            continue;
//        eatline();
//        switch(Choose)
//        {
//            case 's':
//                SetFrontSize(p);
//                break;
//            case 'a':
//                SetAlignment(p);
//                break;
//            case 'i':
//                SetItalic(p);
//                break;
//            default:
//                break;
//
//        }
//        PrintType(Prnt);
//
//    }
//    puts("Bye!");
//    return 0;
//
//}
//void SetItalic(struct TYPEFACE *p)
//{
//    p->Italic=~p->Italic;
//}
//void SetFrontSize(struct TYPEFACE *p)
//{
//    puts("Enter front size (0-127):");
//    uint32_t temp;
//    if(scanf("%u",&temp)!=1)
//    {
//        puts("error input");
//        exit(EXIT_FAILURE);
//    }
//    //temp<<=16;
//    p->TypeSize&=0x00;
//    p->TypeSize|=temp;
//}
//void SetAlignment(struct TYPEFACE *p)
//{
//    puts("Select alignment:");
//    puts("l)left    c)center    r)right");
//    char Choose1;
//    if(scanf("%c",&Choose1)!=1)
//    {
//        puts("error input");
//        exit(EXIT_FAILURE);
//    }
//    switch(Choose1)
//    {
//        case 'l':
//            p->Align=0;
//            break;
//        case 'c':
//            p->Align=1;
//            break;
//        case 'r':
//            p->Align=2;
//            break;
//        default:
//            break;
//
//    }
//}
//void PrintType(struct TYPEFACE Prnt)
//{
//    puts("ID    SIZE    ALIGNMENT   B     I      U");
//    printf("%u     %u",Prnt.TypeID,Prnt.TypeSize);
//    switch(Prnt.Align)
//    {
//        case 0:
//            printf("        left");
//            break;
//        case 1:
//            printf("    mid");
//            break;
//        case 2:
//            printf("    right");
//            break;
//        default:
//            break;
//    }
//    if(Prnt.Overstriking==1)
//        printf("     on");
//    else
//        printf("     off");
//    if(Prnt.Italic==1)
//        printf("    on");
//    else
//        printf("    off");
//    if(Prnt.Underline==1)
//        printf("    on");
//    else
//        printf("    off");
//    puts("");
//    puts("f)change front   s)change size   a)change alignment");
//    puts("b)toggle bold   i)toggle italic   u)toggle underline");
//    puts("q)quit");
//
//}
//void eatline(void)
//{
//    while (getchar() != '\n')
//        continue;
//}



/////////////////////////////////////////////
////////////////Practice 15.5///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节 的位数
//#include <stdbool.h> // C99定义了bool、true、false
//
//uint8_t Rotate_1(uint8_t Value,uint8_t Position);
//int main(void)
//{
//
//    printf("%u\n",Rotate_1(7,4));
//    return 0;
//
//}
//uint8_t Rotate_1(uint8_t Value,uint8_t Position)
//{
//    uint8_t i;
//    for(i=0;i<Position;i++)
//    {
//        if(Value&0x80)
//        {
//            Value<<=1;
//            Value|=0x01;
//        }
//        else
//            Value<<=1;
//    }
//    return Value;
//
//}



/////////////////////////////////////////////
////////////////Practice 15.4///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节 的位数
//#include <stdbool.h> // C99定义了bool、true、false
//
//uint8_t ReadPosition(int32_t Value,int32_t Position);
//int main(void)
//{
//
//    printf("%u\n",ReadPosition(17,4));
//    return 0;
//
//}
//uint8_t ReadPosition(int32_t Value,int32_t Position)
//{
//    int32_t Temp=01;
//    if(Value&(Temp<<(Position-1)))
//        return 1;
//    else
//        return 0;
//}



/////////////////////////////////////////////
////////////////Practice 15.3///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节 的位数
//#include <stdbool.h> // C99定义了bool、true、false
//
//uint8_t BackOpen(int32_t Para);
//int main(void)
//{
//
//    printf("%u\n",BackOpen(17));
//    return 0;
//
//}
//uint8_t BackOpen(int32_t Para)
//{
//    uint8_t Counter=0,i;
//    for(i=0;i<32;i++)
//    {
//        if(Para&0x01)
//            Counter++;
//        Para>>=1;
//    }
//    return Counter;
//}


/////////////////////////////////////////////
////////////////Practice 15.2///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节 的位数
//#include <stdbool.h> // C99定义了bool、true、false
//
//int32_t Str2Binary(char *str);
//void Binary2Str(int32_t BinaryValue,char BinaryString[]);
//void PrintResult(char *str1,char *str2);
//void eatline(void);
//int main(int argc,char * argv[])
//{
//    PrintResult(argv[1],argv[2]);
//    return 0;
//
//}
//void PrintResult(char *str1,char *str2)
//{
//    char StrNegation1[33],StrNegation2[33],StrAND[33],StrOR[33],StrXOR[33];
//
//    int32_t Value1=0,Value2=0;
//    Value1=Str2Binary(str1);
//    Value2=Str2Binary(str2);
//
//    Binary2Str(~Value1,StrNegation1);
//    Binary2Str(~Value2,StrNegation2);
//    Binary2Str(Value1&Value2,StrAND);
//    Binary2Str(Value1|Value2,StrOR);
//    Binary2Str(Value1^Value2,StrXOR);
//
//    puts("Value after ~");
//    printf("Value1: %s Value2: %s\n",StrNegation1,StrNegation2);
//    puts("Value after &");
//    printf("%s\n",StrAND);
//    puts("Value after |");
//    printf("%s\n",StrOR);
//    puts("Value after ^");
//    printf("%s\n",StrXOR);
//}
//void Binary2Str(int32_t BinaryValue,char BinaryString[])
//{
//    int8_t i;
//    for(i=31;i>-1;i--)
//    {
//        if(BinaryValue&0x00000001)
//            BinaryString[i]='1';
//        else
//            BinaryString[i]='0';
//        BinaryValue>>=1;
//    }
//    BinaryString[32]='\0';
//}
//int32_t Str2Binary(char *str)
//{
//    if(strlen(str)>32)
//    {
//        puts("too big");
//        return -1;
//    }
//    int32_t temp=0;
//    int8_t i;
//    for(i=0;i<strlen(str);i++)
//    {
//        if(str[i]=='1')
//            temp|=1;
//        if(i!=strlen(str)-1)
//            temp<<=1;
//    }
//    return temp;
//}
//void eatline(void)
//{
//    while (getchar() != '\n')
//        continue;
//}
//


/////////////////////////////////////////////
////////////////Practice 15.1///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节 的位数
//#include <stdbool.h> // C99定义了bool、true、false
//
//int32_t Str2Binary(char *str);
//void eatline(void);
//int main(void)
//{
//    char BinaryStr[33];
//    puts("enter a serial binary string,enter q to over");
//    while(scanf("%s",BinaryStr)==1 && BinaryStr[0]!='q')
//    {
//        if(BinaryStr[0]=='\n')
//            continue;
//        printf("the corresponding value is %d\n",Str2Binary(BinaryStr));
//        eatline();
//        puts("enter a serial binary string,enter q to over");
//    }
//
//    return 0;
//
//}
//int32_t Str2Binary(char *str)
//{
//    if(strlen(str)>32)
//    {
//        puts("too big");
//        return -1;
//    }
//    int32_t temp=0;
//    int8_t i;
//    for(i=0;i<strlen(str);i++)
//    {
//        if(str[i]=='1')
//            temp|=1;
//        if(i!=strlen(str)-1)
//            temp<<=1;
//    }
//    return temp;
//}
//void eatline(void)
//{
//    while (getchar() != '\n')
//        continue;
//}

/*
///////////////////////////////////////////
/////////////////FuXiTi///////////////////
/////////////////////////////////////////

5.
0b01111111
127
177
7f

6.
*2和<<=1一样，+=和|=不一样

7.
a.
struct TinkerBell{
    uint8_t SWDriverNum : 2;
    uint8_t           : 1;
    uint8_t CDDriverNum : 2;
    uint8_t           : 1;
    uint8_t HDDriverNum : 2;
};
b.
struct KlinkerBell{
    uint8_t HDDriverNum : 2;
    uint8_t           : 2;
    uint8_t CDDriverNum : 2;
    uint8_t           : 2;
    uint8_t SWDriverNum : 2;
};
*/


/////////////////////////////////////////////
////////////////QingDan 15.5///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节 的位数
//#include <stdbool.h> // C99定义了bool、true、false
//
//// align.c -- 使用 _Alignof 和 _Alignas （C11）
//int main(void)
//{
//    double dx;
//    char ca;
//    char cx;
//    double dz;
//    char cb;
//    char _Alignas(double) cz;
//    printf("char alignment: %zd\n", _Alignof(char));
//    printf("double alignment: %zd\n", _Alignof(double));
//    printf("&dx: %p\n", &dx);
//    printf("&ca: %p\n", &ca);
//    printf("&cx: %p\n", &cx);
//    printf("&dz: %p\n", &dz);
//    printf("&cb: %p\n", &cb);
//    printf("&cz: %p\n", &cz);
//    return 0;
//
//}




/////////////////////////////////////////////
////////////////QingDan 15.4///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节 的位数
//#include <stdbool.h> // C99定义了bool、true、false
//
///* 位字段符号常量 */
///* 线的样式 */
//#define SOLID 0
//#define DOTTED 1
//#define DASHED 2
///* 三原色 */
//#define BLUE 4
//#define GREEN 2
//#define RED 1
///* 混合色 */
//#define BLACK 0
//#define YELLOW (RED | GREEN)
//#define MAGENTA (RED | BLUE)
//#define CYAN (GREEN | BLUE)
//#define WHITE (RED | GREEN | BLUE)
///* 按位方法中用到的符号常量 */
//#define OPAQUE 0x1
//#define FILL_BLUE 0x8
//#define FILL_GREEN 0x4
//#define FILL_RED 0x2
//#define FILL_MASK 0xE
//#define BORDER 0x100
//#define BORDER_BLUE 0x800
//#define BORDER_GREEN 0x400
//#define BORDER_RED 200
//#define BORDER_MASK 0xE00
//#define B_SOLID 0
//#define B_DOTTED 0x1000
//#define B_DASHED 0x2000
//#define STYLE_MASK 3000
//
//const char * colors[8] =
//    { "black", "red", "green", "yellow", "blue", "magenta", "cyan", "white" };
//struct box_props{
//    bool opaque : 1; // 或者 unsigned int （C99以前）
//    unsigned int fill_color : 3;
//    unsigned int : 4;
//    bool show_border : 1; // 或者 unsigned int （C99以前）
//    unsigned int border_color : 3;
//    unsigned int border_style : 2;
//    unsigned int : 2;
//};
//union Views /* 把数据看作结构或unsigned short类型的变量 */{
//    struct box_props st_view;
//    unsigned short us_view;
//};
//void show_settings(const struct box_props * pb);
//void show_settings1(unsigned short);
//char * itobs(int n, char * ps);
//int main(void)
//{
//    /* 创建Views联合，并初始化initialize struct box view */
//    union Views box ={
//        { true, YELLOW, true, GREEN, DASHED }
//    };
//    char bin_str[8 * sizeof(unsigned int) + 1];
//    printf("Original box settings:\n");
//    show_settings(&box.st_view);
//    printf("\nBox settings using unsigned int view:\n");
//    show_settings1(box.us_view);
//    printf("bits are %s\n", itobs(box.us_view, bin_str));
//    box.us_view &= ~FILL_MASK; /* 把表示填充色的位 清0 */
//    box.us_view |= (FILL_BLUE | FILL_GREEN); /* 重置填充色 */
//    box.us_view ^= OPAQUE; /* 切换是否透明的位 */
//    box.us_view |= BORDER_RED; /* 错误的方法 */
//    box.us_view &= ~STYLE_MASK; /* 把样式的位清0 */
//    box.us_view |= B_DOTTED; /* 把样式设置为点 */
//    printf("\nModified box settings:\n");
//    show_settings(&box.st_view);
//    printf("\nBox settings using unsigned int view:\n");
//    show_settings1(box.us_view);
//    printf("bits are %s\n", itobs(box.us_view, bin_str));
//
//    return 0;
//}
//void show_settings1(unsigned short us)
//{
//    printf("box is %s.\n", (us & OPAQUE) == OPAQUE ? "opaque" : "transparent");
//    printf("The fill color is %s.\n", colors[(us >> 1) & 07]);
//    printf("Border %s.\n", (us & BORDER) == BORDER ? "shown" : "not shown");
//    printf("The border style is ");
//    switch (us & STYLE_MASK)
//    {
//        case B_SOLID : printf("solid.\n"); break;
//        case B_DOTTED : printf("dotted.\n"); break;
//        case B_DASHED : printf("dashed.\n"); break;
//        default : printf("unknown type.\n");
//    }
//    printf("The border color is %s.\n", colors[(us >> 9) & 07]);
//}
//void show_settings(const struct box_props * pb)
//{
//    printf("Box is %s.\n", pb->opaque == true ? "opaque" : "transparent");
//    printf("The fill color is %s.\n", colors[pb->fill_color]);
//    printf("Border %s.\n", pb->show_border == true ? "shown" : "not shown");
//    printf("The border color is %s.\n", colors[pb->border_color]);
//    printf("The border style is ");
//    switch (pb->border_style)
//    {
//        case SOLID: printf("solid.\n"); break;
//        case DOTTED: printf("dotted.\n"); break;
//        case DASHED: printf("dashed.\n"); break;
//        default: printf("unknown type.\n");
//    }
//}
//char * itobs(int n, char * ps)
//{
//    int i;
//    const static int size = CHAR_BIT * sizeof(int);
//    for (i = size - 1; i >= 0; i--, n >>= 1)
//        ps[i] = (01 & n) + '0';
//    ps[size] = '\0';
//    return ps;
//}
//


/////////////////////////////////////////////
////////////////QingDan 15.3///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节 的位数
//#include <stdbool.h> // C99定义了bool、true、false
//
///* 线的样式 */
//#define SOLID 0
//#define DOTTED 1
//#define DASHED 2
///* 三原色 */
//#define BLUE 4
//#define GREEN 2
//#define RED 1
///* 混合色 */
//#define BLACK 0
//#define YELLOW (RED | GREEN)
//#define MAGENTA (RED | BLUE)
//#define CYAN (GREEN | BLUE)
//#define WHITE (RED | GREEN | BLUE)
//
//const char * colors[8] =
//    { "black", "red", "green", "yellow", "blue", "magenta", "cyan", "white" };
//struct box_props{
//    bool opaque : 1; // 或者 unsigned int （C99以前）
//    unsigned int fill_color : 3;
//    unsigned int : 4;
//    bool show_border : 1; // 或者 unsigned int （C99以前）
//    unsigned int border_color : 3;
//    unsigned int border_style : 2;
//    unsigned int : 2;
//};
//void show_settings(const struct box_props * pb);
//int main(void)
//{
//    /* 创建并初始化 box_props 结构 */
//    struct box_props box = {
//        true,
//        YELLOW,
//        true,
//        GREEN,
//        DASHED
//    };
//    printf("Original box settings:\n");
//    show_settings(&box);
//    box.opaque = false;
//    box.fill_color = WHITE;
//    box.border_color = MAGENTA;
//    box.border_style = SOLID;
//    printf("\nModified box settings:\n");
//    show_settings(&box);
//    return 0;
//}
//void show_settings(const struct box_props * pb)
//{
//    printf("Box is %s.\n", pb->opaque == true ? "opaque" : "transparent");
//    printf("The fill color is %s.\n", colors[pb->fill_color]);
//    printf("Border %s.\n", pb->show_border == true ? "shown" : "not shown");
//    printf("The border color is %s.\n", colors[pb->border_color]);
//    printf("The border style is ");
//    switch (pb->border_style)
//    {
//        case SOLID: printf("solid.\n"); break;
//        case DOTTED: printf("dotted.\n"); break;
//        case DASHED: printf("dashed.\n"); break;
//        default: printf("unknown type.\n");
//    }
//}


/////////////////////////////////////////////
////////////////QingDan 15.2///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节 的位数
//
//char * itobs(int, char *);
//void show_bstr(const char *);
//int invert_end(int num, int bits);
//int main(void)
//{
//    char bin_str[CHAR_BIT * sizeof(int) + 1];
//    int number;
//    puts("Enter integers and see them in binary.");
//    puts("Non-numeric input terminates program.");
//    while (scanf("%d", &number) == 1)
//    {
//        itobs(number, bin_str);
//        printf("%d is\n", number);
//        show_bstr(bin_str);
//        putchar('\n');
//        number = invert_end(number, 4);
//        printf("Inverting the last 4 bits gives\n");
//        show_bstr(itobs(number, bin_str));
//        putchar('\n');
//    }
//    puts("Bye!");
//    return 0;
//}
//char * itobs(int n, char * ps)
//{
//    int i;
//    const static int size = CHAR_BIT * sizeof(int);
//    for (i = size - 1; i >= 0; i--, n >>= 1)
//        ps[i] = (01 & n) + '0';
//    ps[size] = '\0';
//    return ps;
//}
///*4位一组显示二进制字符串 */
//void show_bstr(const char * str)
//{
//    int i = 0;
//    while (str[i]) /* 不是一个空字符 */
//    {
//        putchar(str[i]);
//        if (++i % 4 == 0 && str[i])
//            putchar(' ');
//    }
//}
//int invert_end(int num, int bits)
//{
//    int mask = 0;
//    int bitval = 1;
//    while (bits-- > 0)
//    {
//        mask |= bitval;
//        bitval <<= 1;
//    }
//    return num ^ mask;
//}



/////////////////////////////////////////////
////////////////QingDan 15.1///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#include <math.h>
//#include <limits.h> // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节 的位数
//void eatline(void);
//char * s_gets(char * st, int n);
//char * itobs(int, char *);
//void show_bstr(const char *);
//int main(void)
//{
//    char bin_str[CHAR_BIT * sizeof(int) + 1];
//    int number;
//    puts("Enter integers and see them in binary.");
//    puts("Non-numeric input terminates program.");
//    while (scanf("%d", &number) == 1)
//    {
//        itobs(number, bin_str);
//        printf("%d is ", number);
//        show_bstr(bin_str);
//        putchar('\n');
//    }
//    puts("Bye!");
//    return 0;
//}
//char * itobs(int n, char * ps)
//{
//    int i;
//    const static int size = CHAR_BIT * sizeof(int);
//    for (i = size - 1; i >= 0; i--, n >>= 1)
//        ps[i] = (01 & n) + '0';
//    ps[size] = '\0';
//    return ps;
//}
///*4位一组显示二进制字符串 */
//void show_bstr(const char * str)
//{
//    int i = 0;
//    while (str[i]) /* 不是一个空字符 */
//    {
//        putchar(str[i]);
//        if (++i % 4 == 0 && str[i])
//            putchar(' ');
//    }
//}
//void eatline(void)
//{
//    while (getchar() != '\n')
//        continue;
//}
//char * s_gets(char * st, int n)
//{
//    char * ret_val;
//    char * find;
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        find = strchr(st, '\n'); // 查找换行符
//        if (find) // 如果地址不是 NULL,
//            *find = '\0'; // 在此处放置一个空字符
//        else
//            while (getchar() != '\n')
//                continue; // 处理输入行的剩余字符
//    }
//    return ret_val;
//}
//
