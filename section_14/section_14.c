///////////////////////////////////////////
//////////////Practice 14.11///////////////
/////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <math.h>
void eatline(void);
char * s_gets(char * st, int n);
double add(double Src);
double Sub(double Src);
void transform(double *Src,double *Des,int32_t Size,double (*sin)(double Src));
int main(void)
{
    double Src[3]={1.1,2.2,3.3};
    double Des[3];
    double (*p[4])(double);
    p[0]=add;
    p[1]=Sub;
    p[2]=sin;
    p[3]=cos;
    uint8_t i;
    for(i=0;i<4;i++)
    {
        transform(Src,Des,3,*p[i]);
    }

    return 0;
}
double add(double Src)
{
    return Src+1.0;
}
double Sub(double Src)
{
    return Src-1.0;
}
void transform(double *Src,double *Des,int32_t Size,double (*sin)(double Src))
{
    int32_t i;
    for(i=0;i<Size;i++)
    {
        Des[i]=(*sin)(Src[i]);
    }
    printf("%f %f %f\n",Des[0],Des[1],Des[2]);
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find) // 如果地址不是 NULL,
            *find = '\0'; // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue; // 处理输入行的剩余字符
    }
    return ret_val;
}




/////////////////////////////////////////////
////////////////Practice 14.10///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//
//void eatline(void);
//char * s_gets(char * st, int n);
//void ShowList(void);
//void a(void);
//void b(void);
//void c(void);
//void d(void);
//int main(void)
//{
//    void (*p[4])(void);
//    p[0]=a;
//    p[1]=b;
//    p[2]=c;
//    p[3]=d;
//
//    ShowList();
//    char Choice=8;
//    while(scanf("%c",&Choice)==1 && Choice!='q')
//    {
//        if(Choice=='\n')
//            continue;
//        switch(Choice)
//        {
//            case 'a':
//                p[0]();
//                break;
//            case 'b':
//                p[1]();
//                break;
//            case 'c':
//                p[2]();
//                break;
//            case 'd':
//                p[3]();
//                break;
//            default:
//                break;
//        }
//        ShowList();
//    }
//    return 0;
//}
//void a(void)
//{
//    puts("a");
//}
//void b(void)
//{
//    puts("b");
//}
//void c(void)
//{
//    puts("c");
//}
//void d(void)
//{
//    puts("d");
//}
//void ShowList(void)
//{
//    puts("choose what you want to do");
//    puts("a) print a");
//    puts("b) print b");
//    puts("c) print c");
//    puts("d) print d");
//
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



/////////////////////////////////////////////
////////////////Practice 14.9///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//
//struct BOOK{
//    uint8_t SeatNum;
//    uint8_t If_Booked;
//    char First[10];
//    char Last[10];
//};
//struct PLANE{
//    uint16_t PlaneNum;
//    struct BOOK Book_Group[12];
//};
//void eatline(void);
//char * s_gets(char * st, int n);
//void ShowList(void);
//void Show_NumOfEmpty(struct BOOK *p);
//void Show_ListOfEmpty(struct BOOK *p);
//void Show_AlphaOrderOfSeat(struct BOOK *p);
//void AssignCustomer(struct BOOK *p);
//void DeleteCustomer(struct BOOK *p);
//void ShowPlane(void);
//int main(void)
//{
//    struct PLANE Plane[4];
//    struct BOOK *p;
//    uint8_t i,j;
//    Plane[0].PlaneNum=102;
//    Plane[1].PlaneNum=311;
//    Plane[2].PlaneNum=444;
//    Plane[3].PlaneNum=519;
//
//    for(j=0;j<4;j++)
//    {
//        for(i=0;i<12;i++)
//        {
//            Plane[j].Book_Group[i].SeatNum=i;
//            Plane[j].Book_Group[i].If_Booked=0;
//            strcpy(Plane[j].Book_Group[i].First," ");
//            strcpy(Plane[j].Book_Group[i].Last," ");
//        }
//    }
//    uint8_t PlaneChoice=8;
//    ShowPlane();
//    while(scanf("%u",&PlaneChoice)==1 && PlaneChoice!=9)
//    {
//        printf("Plane %u\n",Plane[PlaneChoice].PlaneNum);
//        eatline();
//        p=&Plane[PlaneChoice].Book_Group[0];
//        ShowList();
//        char Choice=' ';
//        while(scanf("%c",&Choice)==1 && Choice!='f')
//        {
//            if(Choice=='\n')
//                continue;
//            switch(Choice)
//            {
//                case 'a':
//                    Show_NumOfEmpty(p);
//                    break;
//                case 'b':
//                    Show_ListOfEmpty(p);
//                    break;
//                case 'c':
//                    Show_AlphaOrderOfSeat(p);
//                    break;
//                case 'd':
//                    AssignCustomer(p);
//                    break;
//                case 'e':
//                    DeleteCustomer(p);
//                    break;
//                default :
//                    break;
//            }
//            ShowList();
//        }
//        ShowPlane();
//    }
//    return 0;
//}
//void ShowPlane(void)
//{
//    puts("choose a plane");
//    puts("0) 102");
//    puts("1) 311");
//    puts("2) 444");
//    puts("3) 519");
//    puts("9) quit");
//}
//void DeleteCustomer(struct BOOK *p)
//{
//    struct BOOK Delete;
//    puts("enter a seat num you want delete assignment");
//    while(scanf("%u",&Delete.SeatNum)==1 && (p+Delete.SeatNum)->If_Booked==0)
//        puts("seat unbooked,choose another");
//    Delete.If_Booked=0;
//    strcpy(Delete.First," ");
//    strcpy(Delete.First," ");
//    *(p+Delete.SeatNum)=Delete;
//}
//void AssignCustomer(struct BOOK *p)
//{
//    struct BOOK Add;
//    puts("which seat you want");
//    while(scanf("%u",&Add.SeatNum)==1 && (p+Add.SeatNum)->If_Booked==1)
//        puts("seat booked,choose another");
//    Add.If_Booked=1;
//    eatline();
//    puts("Enter your first name");
//    s_gets(Add.First,10);
//    puts("Enter your last name");
//    s_gets(Add.Last,10);
//    *(p+Add.SeatNum)=Add;
//
//}
//void Show_AlphaOrderOfSeat(struct BOOK *p)
//{
//    uint8_t AlphaOrder[12],i,j,temp;
//    for(i=0;i<12;i++)
//        AlphaOrder[i]=i;
//    for(i=0;i<12;i++)
//    {
//        for(j=i+1;j<12;j++)
//        {
//            if(strcmp((p+i)->First,(p+j)->First)<0)
//            {
//                temp=AlphaOrder[i];
//                AlphaOrder[i]=AlphaOrder[j];
//                AlphaOrder[j]=temp;
//            }
//        }
//    }
//    puts("seat list in alphabetical order");
//    for(i=0;i<12;i++)
//        printf("Seat Num: %u If Booked: %u First Name %s Last Name %s\n",
//               (p+AlphaOrder[i])->SeatNum,(p+AlphaOrder[i])->If_Booked,
//               (p+AlphaOrder[i])->First,(p+AlphaOrder[i])->Last);
//}
//void Show_ListOfEmpty(struct BOOK *p)
//{
//    puts("empty seats list:");
//    uint8_t i;
//    for(i=0;i<12;i++)
//    {
//        if((p+i)->If_Booked==0)
//            printf("%u ",(p+i)->SeatNum);
//    }
//    puts("");
//}
//void Show_NumOfEmpty(struct BOOK *p)
//{
//    uint8_t EmptyCounter=0,i=0;
//    for(i=0;i<12;i++)
//        if((p+i)->If_Booked==0)
//            EmptyCounter++;
//    printf("There're %u empty seats\n",EmptyCounter);
//}
//void ShowList(void)
//{
//    puts("To choose a function, enter its letter label:");
//    puts("a) Show number of empty seats");
//    puts("b) Show list of empty seats");
//    puts("c) Show alphabetical list of seats");
//    puts("d) Assign a customer to a seat assignment");
//    puts("e) Delete a seat assignment");
//    puts("f) Quit");
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




/////////////////////////////////////////////
////////////////Practice 14.8///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//
//struct BOOK{
//    uint8_t SeatNum;
//    uint8_t If_Booked;
//    char First[10];
//    char Last[10];
//};
//void eatline(void);
//char * s_gets(char * st, int n);
//void ShowList(void);
//void Show_NumOfEmpty(struct BOOK *p);
//void Show_ListOfEmpty(struct BOOK *p);
//void Show_AlphaOrderOfSeat(struct BOOK *p);
//void AssignCustomer(struct BOOK *p);
//int main(void)
//{
//    struct BOOK Book_Group[12];
//    struct BOOK *p;
//    p=&Book_Group[0];
//    uint8_t i;
//    for(i=0;i<12;i++)
//    {
//        Book_Group[i].SeatNum=i;
//        Book_Group[i].If_Booked=0;
//        strcpy(Book_Group[i].First," ");
//        strcpy(Book_Group[i].Last," ");
//    }
//
//    ShowList();
//    char Choice=' ';
//    while(scanf("%c",&Choice)==1 && Choice!='f')
//    {
//        switch(Choice)
//        {
//            case 'a':
//                Show_NumOfEmpty(p);
//                break;
//            case 'b':
//                Show_ListOfEmpty(p);
//                break;
//            case 'c':
//                Show_AlphaOrderOfSeat(p);
//                break;
//            case 'd':
//                AssignCustomer(p);
//                break;
//            case 'e':
//                DeleteCustomer(p);
//                break;
//            default :
//                break;
//        }
//        ShowList();
//    }
//    return 0;
//}
//void DeleteCustomer(struct BOOK *p)
//{
//    struct BOOK Delete;
//    puts("enter a seat num you want delete assignment");
//    while(scanf("%u",&Delete.SeatNum)==1 && (p+Delete.SeatNum)->If_Booked==0)
//        puts("seat unbooked,choose another");
//    Delete.If_Booked=0;
//    strcpy(Delete.First," ");
//    strcpy(Delete.First," ");
//    *(p+Delete.SeatNum)=Delete;
//}
//void AssignCustomer(struct BOOK *p)
//{
//    struct BOOK Add;
//    puts("which seat you want");
//    while(scanf("%u",&Add.SeatNum)==1 && (p+Add.SeatNum)->If_Booked==1)
//        puts("seat booked,choose another");
//    Add.If_Booked=1;
//    eatline();
//    puts("Enter your first name");
//    s_gets(Add.First,10);
//    puts("Enter your last name");
//    s_gets(Add.Last,10);
//    *(p+Add.SeatNum)=Add;
//
//}
//void Show_AlphaOrderOfSeat(struct BOOK *p)
//{
//    uint8_t AlphaOrder[12],i,j,temp;
//    for(i=0;i<12;i++)
//        AlphaOrder[i]=i;
//    for(i=0;i<12;i++)
//    {
//        for(j=i+1;j<12;j++)
//        {
//            if(strcmp((p+i)->First,(p+j)->First)<0)
//            {
//                temp=AlphaOrder[i];
//                AlphaOrder[i]=AlphaOrder[j];
//                AlphaOrder[j]=temp;
//            }
//        }
//    }
//    puts("seat list in alphabetical order");
//    for(i=0;i<12;i++)
//        printf("Seat Num: %u If Booked: %u First Name %s Last Name %s\n",
//               (p+AlphaOrder[i])->SeatNum,(p+AlphaOrder[i])->If_Booked,
//               (p+AlphaOrder[i])->First,(p+AlphaOrder[i])->Last);
//}
//void Show_ListOfEmpty(struct BOOK *p)
//{
//    puts("empty seats list:");
//    uint8_t i;
//    for(i=0;i<12;i++)
//    {
//        if((p+i)->If_Booked==0)
//            printf("%u ",(p+i)->SeatNum);
//    }
//    puts("");
//}
//void Show_NumOfEmpty(struct BOOK *p)
//{
//    uint8_t EmptyCounter=0,i=0;
//    for(i=0;i<12;i++)
//        if((p+i)->If_Booked==0)
//            EmptyCounter++;
//    printf("There're %u empty seats\n",EmptyCounter);
//}
//void ShowList(void)
//{
//    puts("To choose a function, enter its letter label:");
//    puts("a) Show number of empty seats");
//    puts("b) Show list of empty seats");
//    puts("c) Show alphabetical list of seats");
//    puts("d) Assign a customer to a seat assignment");
//    puts("e) Delete a seat assignment");
//    puts("f) Quit");
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



/////////////////////////////////////////////
////////////////Practice 14.7///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#define CSIZE 4
//struct PLAYER{
//    uint8_t PlayerNum;
//    char First[10];
//    char Last[10];
//    int GameTime;
//    int HitTime;
//    int GoTime;
//    int Dot;
//    float RB_Rate;
//    uint8_t If_Deleted;
//};
//void eatline(void);
//char * s_gets(char * st, int n);
//void GetPlayerInfo(FILE *fp,struct PLAYER *p,uint8_t *p_CurrentPlayer);
//void Delete(struct PLAYER *p,uint8_t LineNum,uint8_t *p_CurrentPlayer);
//void WriteBack(FILE *fp,struct PLAYER *p,uint8_t *p_CurrentPlayer);
//void Add(FILE *fp,struct PLAYER *p,uint8_t *p_CurrentPlayer);
//int main(void)
//{
//    struct PLAYER PlayerGroup[19];
//    struct PLAYER *p;
//    uint8_t CurrentPlayer=0;
//    uint8_t *p_CurrentPlayer;
//    p_CurrentPlayer=&CurrentPlayer;
//    FILE *fp;
//    p=&PlayerGroup[0];
//    if((fp=fopen("PlayerInfo.txt","r+b"))==NULL)
//    {
//        puts("cannot open file");
//        exit(EXIT_FAILURE);
//    }
//    uint8_t i;
//    for(i=0;i<19;i++)
//    {
//        PlayerGroup[i].GameTime=0;
//        PlayerGroup[i].HitTime=0;
//        PlayerGroup[i].GoTime=0;
//        PlayerGroup[i].Dot=0;
//        PlayerGroup[i].RB_Rate=0.0;
//        PlayerGroup[i].If_Deleted=0;
//    }
//    GetPlayerInfo(fp,p,p_CurrentPlayer);
//    for(i=0;i<CurrentPlayer;i++)
//    {
//        printf("Number %u info: %s %s %d %d %d %d %f\n",
//               PlayerGroup[i].PlayerNum,PlayerGroup[i].First,
//               PlayerGroup[i].Last,PlayerGroup[i].GameTime,
//               PlayerGroup[i].HitTime,PlayerGroup[i].GoTime,
//               PlayerGroup[i].Dot,PlayerGroup[i].RB_Rate);
//    }
//    puts("enter \"x\" to deleted line x record");
//    uint8_t LineDeleted;
//    if(scanf("%u",&LineDeleted)==1)
//    {
//        rewind(fp);
//        Delete(p,LineDeleted,p_CurrentPlayer);
//        GetPlayerInfo(fp,p,p_CurrentPlayer);
//        WriteBack(fp,p,p_CurrentPlayer);
//        for(i=0;i<CurrentPlayer;i++)
//        {
//            printf("Number %u info: %s %s %d %d %d %d %f\n",
//                   PlayerGroup[i].PlayerNum,PlayerGroup[i].First,
//                   PlayerGroup[i].Last,PlayerGroup[i].GameTime,
//                   PlayerGroup[i].HitTime,PlayerGroup[i].GoTime,
//                   PlayerGroup[i].Dot,PlayerGroup[i].RB_Rate);
//        }
//    }
//    puts("enter add to add line");
//    eatline();
//    char ForAdd[40];
//    if(fgets(ForAdd,40,stdin)==NULL)
//    {
//        puts("error input");
//        exit(EXIT_FAILURE);
//    }
//    if(strcmp(ForAdd,"add\n")==0)
//    {
//        Add(fp,p,p_CurrentPlayer);
//    }
//    fclose(fp);
//    return 0;
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
//void GetPlayerInfo(FILE *fp,struct PLAYER *p,uint8_t *p_CurrentPlayer)
//{
//    char Info[40];
//    char *p_Front,*p_Ref;
//    p_Ref=Info;
//    uint8_t i=0,CurrentPlayer=0;
//    rewind(fp);
//    uint8_t ForSearch=0;
//    while(fgets(Info,40,fp)!=NULL && strcmp(Info," end\n")!=0)
//    {
//        if((p+ForSearch++)->If_Deleted==1)
//            continue;
//        (p+CurrentPlayer)->PlayerNum=Info[0]-48;
//        p_Front=strchr(p_Ref,' ');
//        for(i=0;*(p_Front+1+i)!=' ';i++)
//        {
//            ((p+CurrentPlayer)->First)[i]=*(p_Front+1+i);
//        }
//        ((p+CurrentPlayer)->First)[i]='\0';
//        p_Front=p_Front+i+2;
//        for(i=0;*(p_Front+i)!=' ';i++)
//        {
//            ((p+CurrentPlayer)->Last)[i]=*(p_Front+i);
//        }
//        ((p+CurrentPlayer)->Last)[i]='\0';
//        p_Front=p_Front+i;
//        (p+CurrentPlayer)->GameTime=p_Front[1]-48;
//        (p+CurrentPlayer)->HitTime=p_Front[3]-48;
//        (p+CurrentPlayer)->GoTime=p_Front[5]-48;
//        (p+CurrentPlayer)->Dot=p_Front[7]-48;
//        (p+CurrentPlayer)->RB_Rate=
//            (((p+CurrentPlayer)->HitTime*1.0)/(p+CurrentPlayer)->GameTime);
//        CurrentPlayer++;
//    }
//    *p_CurrentPlayer=CurrentPlayer;
//}
//void WriteBack(FILE *fp,struct PLAYER *p,uint8_t *p_CurrentPlayer)
//{
//    uint8_t i;
//    rewind(fp);
//    for(i=0;i<*p_CurrentPlayer;i++)
//    {
//        if(i==*p_CurrentPlayer-1)
//            fprintf(fp,"%u %s %s %d %d %d %d",
//                (p+i)->PlayerNum,(p+i)->First,
//                (p+i)->Last,(p+i)->GameTime,
//                (p+i)->HitTime,(p+i)->GoTime,
//                (p+i)->Dot);
//        else
//            fprintf(fp,"%u %s %s %d %d %d %d\n",
//                (p+i)->PlayerNum,(p+i)->First,
//                (p+i)->Last,(p+i)->GameTime,
//                (p+i)->HitTime,(p+i)->GoTime,
//                (p+i)->Dot);
//    }
//    fseek(fp,0L,SEEK_CUR);
//    fprintf(fp,"\n end\n");
//
//}
//void Delete(struct PLAYER *p,uint8_t LineNum,uint8_t *p_CurrentPlayer)
//{
//    (p+LineNum-1)->If_Deleted=1;
//    *p_CurrentPlayer-=1;
//}
//void Add(FILE *fp,struct PLAYER *p,uint8_t *p_CurrentPlayer)
//{
//    rewind(fp);
//
//    struct PLAYER ForAdd;
//    uint8_t DeletedLineNum=0,CurrentPlayer,i;
//    CurrentPlayer=*p_CurrentPlayer;
//    for(i=0;i<CurrentPlayer;i++)
//    {
//        if((p+i)->If_Deleted==1)
//        {
//            DeletedLineNum=i+1;
//            break;
//        }
//    }
//    GetPlayerInfo(fp,p,p_CurrentPlayer);
//
//    puts("PlayerNum First Last GameTime HitTime GoTime Dot");
//    if(DeletedLineNum!=0)
//    {
//        if(scanf("%u %s %s %d %d %d %d",
//                &(p+DeletedLineNum-1)->PlayerNum,(p+DeletedLineNum-1)->First,
//                (p+DeletedLineNum-1)->Last,&(p+DeletedLineNum-1)->GameTime,
//                &(p+DeletedLineNum-1)->HitTime,&(p+DeletedLineNum-1)->GoTime,
//                &(p+DeletedLineNum-1)->Dot
//           )!=7
//           )
//        {
//            puts("Error input");
//            exit(EXIT_FAILURE);
//        }
//        (p+DeletedLineNum-1)->If_Deleted=0;
//    }
//    else
//    {
//        if(scanf("%u %s %s %d %d %d %d",
//                &(p+CurrentPlayer)->PlayerNum,(p+CurrentPlayer)->First,
//                (p+CurrentPlayer)->Last,&(p+CurrentPlayer)->GameTime,
//                &(p+CurrentPlayer)->HitTime,&(p+CurrentPlayer)->GoTime,
//                &(p+CurrentPlayer)->Dot
//           )!=7
//           )
//        {
//            puts("Error input");
//            exit(EXIT_FAILURE);
//        }
//        (p+CurrentPlayer)->If_Deleted=0;
//        *p_CurrentPlayer+=1;
//    }
//    WriteBack(fp,p,p_CurrentPlayer);
//}
//


/////////////////////////////////////////////
////////////////Practice 14.6///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdint.h>
//#define CSIZE 4
//struct PLAYER{
//    char First[10];
//    char Last[10];
//    int GameTime;
//    int HitTime;
//    int GoTime;
//    int Dot;
//    float RB_Rate;
//};
//void eatline(void);
//char * s_gets(char * st, int n);
//void GetPlayerInfo(FILE *fp,struct PLAYER *p,int PlayerNum[19]);
//int main(void)
//{
//    struct PLAYER PlayerGroup[19];
//    struct PLAYER *p;
//    int PlayerNum[19];
//    FILE *fp;
//    p=&PlayerGroup[0];
//    if((fp=fopen("PlayerInfo.txt","r"))==NULL)
//    {
//        puts("cannot open file");
//        exit(EXIT_FAILURE);
//    }
//    uint8_t i;
//    for(i=0;i<19;i++)
//    {
//        PlayerGroup[i].GameTime=0;
//        PlayerGroup[i].HitTime=0;
//        PlayerGroup[i].GoTime=0;
//        PlayerGroup[i].Dot=0;
//    }
//    GetPlayerInfo(fp,p,PlayerNum);
//    for(i=0;i<5;i++)
//    {
//        printf("Number %d info: %s %s %d %d %d %d %f\n",
//               PlayerNum[i],PlayerGroup[PlayerNum[i]].First,
//               PlayerGroup[PlayerNum[i]].Last,PlayerGroup[PlayerNum[i]].GameTime,
//               PlayerGroup[PlayerNum[i]].HitTime,PlayerGroup[PlayerNum[i]].GoTime,
//               PlayerGroup[PlayerNum[i]].Dot,PlayerGroup[PlayerNum[i]].RB_Rate);
//    }
//    fclose(fp);
//    return 0;
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
//void GetPlayerInfo(FILE *fp,struct PLAYER *p,int PlayerNum[19])
//{
//    char Info[40];
//    char *p_Front,*p_Ref;
//    p_Ref=Info;
//    unsigned char i=0,PlayerCounter=0,CurrentPlayer=0;
//    while(fgets(Info,40,fp)!=NULL)
//    {
//        if(PlayerCounter==0)
//        {
//            PlayerCounter++;
//            PlayerNum[0]=Info[0]-48;
//            CurrentPlayer=0;
//        }
//        else
//        {
//            for(i=0;i<PlayerCounter;i++)
//            {
//                if(PlayerNum[i]==(Info[i]-48))
//                {
//                    CurrentPlayer=i;
//                    break;
//                }
//                else if(i==PlayerCounter-1 && PlayerNum[i]!=(Info[i]-48))
//                {
//                    PlayerCounter++;
//                    CurrentPlayer=PlayerCounter-1;
//                    PlayerNum[CurrentPlayer]=Info[0]-48;
//                    break;
//                }
//            }
//        }
//        p_Front=strchr(p_Ref,' ');
//        for(i=0;*(p_Front+1+i)!=' ';i++)
//        {
//            ((p+PlayerNum[CurrentPlayer])->First)[i]=*(p_Front+1+i);
//        }
//        ((p+PlayerNum[CurrentPlayer])->First)[i]='\0';
//        p_Front=p_Front+i+2;
//        for(i=0;*(p_Front+i)!=' ';i++)
//        {
//            ((p+PlayerNum[CurrentPlayer])->Last)[i]=*(p_Front+i);
//        }
//        ((p+PlayerNum[CurrentPlayer])->Last)[i]='\0';
//        p_Front=p_Front+i;
//        (p+PlayerNum[CurrentPlayer])->GameTime+=p_Front[1]-48;
//        (p+PlayerNum[CurrentPlayer])->HitTime+=p_Front[3]-48;
//        (p+PlayerNum[CurrentPlayer])->GoTime+=p_Front[5]-48;
//        (p+PlayerNum[CurrentPlayer])->Dot+=p_Front[7]-48;
//        (p+PlayerNum[CurrentPlayer])->RB_Rate+=
//            (((p+PlayerNum[CurrentPlayer])->HitTime*1.0)/(p+PlayerNum[CurrentPlayer])->GameTime);
//    }
//}


/////////////////////////////////////////////
////////////////Practice 14.5///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//
//#define CSIZE 4
//struct NAME{
//    char First[10];
//    char Last[10];
//};
//struct STUDENT{
//    struct NAME name;
//    float grade[3];
//    float average;
//};
//void eatline(void);
//int main(void)
//{
//    struct STUDENT StudentGroup[4]={
//        {.name={"han","yuan"}},
//        {.name={"zhang","huajian"}},
//        {.name={"Omar","Little"}},
//        {.name={"Jimmy","Mcnulty"}}
//    };
//    unsigned char i;
//    char Temp_First[10],Temp_Last[10];
//    puts("enter student's first name and last name");
//    while(scanf("%s%s",Temp_First,Temp_Last)==2)
//    {
//        for(i=0;i<4;i++)
//        {
//            if((strcmp(Temp_First,StudentGroup[i].name.First)!=0 ||
//                strcmp(Temp_Last,StudentGroup[i].name.Last)!=0) && i==3)
//            {
//                puts("enter right name");
//                break;
//            }
//            else if(strcmp(Temp_First,StudentGroup[i].name.First)==0 &&
//                strcmp(Temp_Last,StudentGroup[i].name.Last)==0)
//            {
//                puts("enter this student's grade");
//                scanf("%f%f%f",
//                      &(StudentGroup[i].grade[0]),
//                      &(StudentGroup[i].grade[1]),&(StudentGroup[i].grade[2]));
//                StudentGroup[i].average=(StudentGroup[i].grade[0]+StudentGroup[i].grade[1]+StudentGroup[i].grade[2])/3.0;
//                break;
//            }
//        }
//        eatline();
//        puts("enter student's first name and last name");
//    }
//    for(i=0;i<4;i++)
//    {
//        printf("%s %s's grade is %f %f %f,the average is %f\n",
//               StudentGroup[i].name.First,StudentGroup[i].name.Last,
//               StudentGroup[i].grade[0],StudentGroup[i].grade[1],StudentGroup[i].grade[2],
//               StudentGroup[i].average);
//    }
//    printf("all average is %f\n",
//           (StudentGroup[0].average+StudentGroup[1].average+
//            StudentGroup[2].average+StudentGroup[3].average)/4.0);
//    return 0;
//}
//void eatline(void)
//{
//    while (getchar() != '\n')
//        continue;
//}


/////////////////////////////////////////////
////////////////Practice 14.4//////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//struct Indiv{
//    char First[10];
//    char Middle[10];
//    char Last[10];
//};
//typedef struct Model { /* 简历 book 模板 */
//    char SSN[10];
//    struct Indiv Name;
//}MODEL;
//char * s_gets(char * st, int n);
//void MyPrint(MODEL *p,int num);
//void MyPrint2(MODEL IndivGroup[],int num);
//int main(void)
//{
//    MODEL IndivGroup[5]={
//        {"302039823",{"Omar","Devon","Little"}},
//        {"302039824",{"Jian","Hua","Zhang"}},
//        {"302039825",{"Yuan","B","Han"}},
//        {"302039826",{"Jimmy","Aden","Mcnulty"}},
//        {"302039827",{"Bunk","Troid","Edward"}},
//    };
//    MyPrint(&IndivGroup[0],5);
//    MyPrint2(IndivGroup,5);
//
//    return 0;
//}
//void MyPrint(MODEL *p,int num)
//{
//    int i;
//    for(i=0;i<num;i++)
//    {
//        if( (((p+i)->Name).Middle)[0] != '\0')
//        {
//            printf("%s,%s %c.-%s\n",
//                   ((p+i)->Name).First,((p+i)->Name).Last,
//                   (((p+i)->Name).Middle)[0],(p+i)->SSN);
//        }
//        else
//        {
//            printf("%s,%s-%s\n",
//                   ((p+i)->Name).First,((p+i)->Name).Last,
//                   (p+i)->SSN);
//        }
//    }
//}
//void MyPrint2(MODEL IndivGroup[],int num)
//{
//    int i;
//    for(i=0;i<num;i++)
//    {
//        if( ((IndivGroup[i].Name).Middle)[0] != '\0')
//        {
//            printf("%s,%s %c.-%s\n",
//                   (IndivGroup[i].Name).First,(IndivGroup[i].Name).Last,
//                   ((IndivGroup[i].Name).Middle)[0],IndivGroup[i].SSN);
//        }
//        else
//        {
//            printf("%s,%s-%s\n",
//                   (IndivGroup[i].Name).First,(IndivGroup[i].Name).Last,
//                   IndivGroup[i].SSN);
//        }
//    }
//}

/////////////////////////////////////////////
////////////////Practice 14.3//////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//
//#define MAXTITL 40
//#define MAXAUTL 40
//#define MAXBKS 100 /* 书籍的最大数量 */
//struct book { /* 简历 book 模板 */
//    char title[MAXTITL];
//    char author[MAXAUTL];
//    float value;
//};
//char * s_gets(char * st, int n);
//void SetTitleOrder(int *p,const struct book *bp,int count);
//void SetValueOrder(int *p,const struct book *bp,int count);
//int main(void)
//{
//    struct book library[MAXBKS]; /* book 类型结构的数组 */
//    struct book *bp;
//    bp=&library[0];
//    int count = 0;
//    int index;
//    printf("Please enter the book title.\n");
//    printf("Press [enter] at the start of a line to stop.\n");
//    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
//           && library[count].title[0] != '\0')
//    {
//        printf("Now enter the author.\n");
//        s_gets(library[count].author, MAXAUTL);
//        printf("Now enter the value.\n");
//        scanf("%f", &library[count++].value);
//        while (getchar() != '\n')
//            continue; /* 清理输入行*/
//        if (count < MAXBKS)
//            printf("Enter the next title.\n");
//    }
//    if (count > 0)
//    {
//        printf("Here is the list of your books:\n");
//        for (index = 0; index < count; index++)
//            printf("%s by %s: $%.2f\n", library[index].title,
//                   library[index].author, library[index].value);
//        int TitleOrder[count];
//        int i;
//        for(i=0;i<count;i++)
//            TitleOrder[i]=i;
//        SetTitleOrder(TitleOrder,bp,count);
//        printf("Here is the list of your books in title order:\n");
//        for (index = 0; index < count; index++)
//            printf("%s by %s: $%.2f\n", library[TitleOrder[index]].title,
//                   library[TitleOrder[index]].author, library[TitleOrder[index]].value);
//        for(i=0;i<count;i++)
//            TitleOrder[i]=i;
//        SetValueOrder(TitleOrder,bp,count);
//        printf("Here is the list of your books in value order:\n");
//        for (index = 0; index < count; index++)
//            printf("%s by %s: $%.2f\n", library[TitleOrder[index]].title,
//                   library[TitleOrder[index]].author, library[TitleOrder[index]].value);
//
//    }
//    else
//        printf("No books? Too bad.\n");
//
//    return 0;
//}
//char * s_gets(char * st, int n)
//{
//    char * ret_val;
//    char * find;
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        find = strchr(st, '\n'); // 查找换行符
//        if (find) // 如果地址不是 NULL，
//            *find = '\0'; // 在此处放置一个空字符
//        else
//            while (getchar() != '\n')
//                continue; // 处理输入行中剩余的字符
//    }
//    return ret_val;
//}
//void SetTitleOrder(int *p,const struct book *bp,int count)
//{
//    int i,j;
//    int temp;
//    for(i=0;i<count;i++)
//    {
//        for(j=i;j<count;j++)
//        {
//            if(strcmp((bp+j)->title,(bp+j+1)->title)<0)
//            {
//                temp=*(p+j);
//                *(p+j)=*(p+j+1);
//                *(p+j+1)=temp;
//            }
//        }
//    }
//}
//void SetValueOrder(int *p,const struct book *bp,int count)
//{
//    int i,j;
//    int temp;
//    for(i=0;i<count;i++)
//    {
//        for(j=i;j<count;j++)
//        {
//            if( (bp+j)->value - (bp+j+1)->value < 0)
//            {
//                temp=*(p+j);
//                *(p+j)=*(p+j+1);
//                *(p+j+1)=temp;
//            }
//        }
//    }
//}

///////////////////////////////////////////
//////////////Practice 14.2//////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdint.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//
//typedef struct DateInfo{
//    uint8_t Day;
//    char MonthAbbr[4];
//    uint16_t Year;
//}DATE_INFO;
//struct MonthInfo{
//    char MonthName[10];
//    char MonthAbbr[4];
//    unsigned char Days;
//    unsigned char MonthInNum;
//};
//
//void eatline(void);
//uint16_t BackDays(uint8_t DaysNum,unsigned char MonthNum,const struct MonthInfo *p);
//char * s_gets(char * st, int n);
//int main(void)
//{
//    struct MonthInfo Year_2020[12]={
//        { "January", "jan", 31, 1 }, { "February", "feb", 28, 2 },
//        { "March", "mar", 31, 3 },{ "April", "apr", 30, 4 },
//        { "May", "may", 31, 5 }, { "June", "jun", 30, 6 },
//        { "July", "jul", 31, 7 }, { "August", "aug", 31, 8 },
//        { "September", "sep", 30, 9 }, { "October", "oct", 31, 10 },
//        { "November", "nov", 30, 11 }, { "December", "dec", 31, 12 }
//    };
//    DATE_INFO My_Date;
//    struct MonthInfo *p;
//    unsigned char i=0,MonthNum=0;
//    puts("Enter the month");
//    while(s_gets(My_Date.MonthAbbr,4)!=NULL && My_Date.MonthAbbr[0]!='\0')
//    {
//        i=0;
//        while(i<12)
//        {
//            if(strcmp(My_Date.MonthAbbr,Year_2020[i].MonthAbbr)==0)
//            {
//                MonthNum=i+1;
//                break;
//            }
//            else if(strcmp(My_Date.MonthAbbr,Year_2020[i].MonthAbbr)!=0 && i==11)
//                puts("error input,try again");
//            i++;
//        }
//        eatline();
//        puts("Enter LF to next ,or you can enter month again");
//    }
//    puts("Enter the days");
//    while(scanf("%u",&My_Date.Day)!=1 && My_Date.Day>31)
//    {
//        puts("enter right days");
//    }
//    p=&Year_2020[0];
//    printf("There're %d days from 1.1 to %s.%d\n",
//           BackDays(My_Date.Day,MonthNum,p),(p+MonthNum-1)->MonthAbbr,My_Date.Day);
//
//
//    return 0;
//}
//uint16_t BackDays(uint8_t DaysNum,unsigned char MonthNum,const struct MonthInfo *p)
//{
//    uint16_t Days=0;
//    uint8_t i;
//    for(i=0;i<MonthNum-1;i++)
//    {
//        Days+=(*(p+i)).Days;
//    }
//    return Days+DaysNum;
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



///////////////////////////////////////////
//////////////Practice 14.1//////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdint.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//
//struct MonthInfo{
//    char MonthName[10];
//    char MonthAbbr[4];
//    unsigned char Days;
//    unsigned char MonthInNum;
//};
//void eatline(void);
//uint16_t BackDays(unsigned char MonthNum,const struct MonthInfo *p);
//char * s_gets(char * st, int n);
//int main(void)
//{
//    struct MonthInfo Year_2020[12]={
//        { "January", "jan", 31, 1 }, { "February", "feb", 28, 2 },
//        { "March", "mar", 31, 3 },{ "April", "apr", 30, 4 },
//        { "May", "may", 31, 5 }, { "June", "jun", 30, 6 },
//        { "July", "jul", 31, 7 }, { "August", "aug", 31, 8 },
//        { "September", "sep", 30, 9 }, { "October", "oct", 31, 10 },
//        { "November", "nov", 30, 11 }, { "December", "dec", 31, 12 }
//    };
//    struct MonthInfo *p;
//    char Month[4];
//    unsigned char i=0,MonthNum=0;
//    puts("Enter the month you want");
//    while(s_gets(Month,4)!=NULL && Month[0]!='\0')
//    {
//        i=0;
//        while(i<12)
//        {
//            if(strcmp(Month,Year_2020[i].MonthAbbr)==0)
//            {
//                MonthNum=i+1;
//                p=&Year_2020[0];
//                printf("There're %d days from Jan to %s\n",
//                       BackDays(MonthNum,p),(p+MonthNum-1)->MonthAbbr);
//                break;
//            }
//            else if(strcmp(Month,Year_2020[i].MonthAbbr)!=0 && i==11)
//                puts("error input,try again");
//            i++;
//        }
//        eatline();
//        puts("Enter the month you want");
//    }
//
//
//
//    return 0;
//}
//uint16_t BackDays(unsigned char MonthNum,const struct MonthInfo *p)
//{
//    uint16_t Days=0;
//    uint8_t i;
//    for(i=0;i<MonthNum;i++)
//    {
//        Days+=(*(p+i)).Days;
//    }
//    return Days;
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


/////////////////////////////////////////
////////////FuXiTi 14.11//////////////
///////////////////////////////////////
/////////////////////////////////////////
////////////FuXiTi 14.12//////////////
///////////////////////////////////////
/////////////////////////////////////////
////////////FuXiTi 14.13//////////////
///////////////////////////////////////
// #include <stdio.h>
// #include <stdint.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>
// #include <time.h>
// enum choices{no,yes,maybe};
// double fun1(double,double);
// double fun2(double,double);
// double fun3(double,double);
// double fun4(double,double);
// int main(void)
// {
    // char *(*p)(char *,char);
    // double *p[4] (double,double)={func1,func2,func3,func4};
    // p[1](10.0,2.5);
    // *p[1](10.0,2.5);
    // *(p+1)(10.0,2.5);
    // return 0;
// }



///////////////////////////////////////////
//////////////FuXiTi 14.10//////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdint.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//struct gas {
//    float distance;
//    float gals;
//    float mpg;
//};
//void Cal(struct gas *p);
//int main(void)
//{
//
//
//    return 0;
//}
//void Cal(struct gas *p)
//{
//    p->mpg=p->distance*p->gals;
//}


///////////////////////////////////////////
//////////////FuXiTi 14.8/14.9//////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdint.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//struct fullname {
//    char fname[20];
//    char lname[20];
//};
//struct bard {
//    struct fullname name;
//    int born;
//    int died;
//};
//struct car{
//    char Name[40];
//    int Horsepower;
//    float MilePerGallon;
//    float Wheel_base;
//    int Year_Manu;
//};
//int main(void)
//{
//    struct bard willie;
//    struct bard *pt = &willie;
//    willie.born;
//    pt->born;
//    scanf("%d",&willie.born);
//    scanf("%d",&pt->born);
//    scanf("%s",willie.name.lname);
//    scanf("%s",pt->name.lname);
//    willie.name.fname+2;//willie.name.fname[2];
//    strlen(willie.name.fname)+strlen(willie.name.lname);
//
//    return 0;
//}



///////////////////////////////////////////
////////////////FuXiTi 14.5/////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdint.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//
//struct MonthInfo{
//    char MonthName[10];
//    char MonthAbbr[4];
//    unsigned char Days;
//    unsigned char MonthInNum;
//};
//void eatline(void);
//uint16_t BackDays(unsigned char MonthNum,const struct MonthInfo *p);
//int main(void)
//{
//    struct MonthInfo Year_2020[12]={
//        { "January", "jan", 31, 1 }, { "February", "feb", 28, 2 },
//        { "March", "mar", 31, 3 },{ "April", "apr", 30, 4 },
//        { "May", "may", 31, 5 }, { "June", "jun", 30, 6 },
//        { "July", "jul", 31, 7 }, { "August", "aug", 31, 8 },
//        { "September", "sep", 30, 9 }, { "October", "oct", 31, 10 },
//        { "November", "nov", 30, 11 }, { "December", "dec", 31, 12 }
//    };
//    struct MonthInfo *p;
//    uint16_t MonthNum=0;
//    puts("Enter the month num you want");
//    while(scanf("%d",&MonthNum)==NULL)
//    {
//        puts("enter error");
//        eatline();
//    }
//    eatline();
//    p=&Year_2020[0];
//
//    printf("There're %d days from Jan to %s\n",
//           BackDays(MonthNum,p),(p+MonthNum-1)->MonthAbbr);
//    return 0;
//}
//uint16_t BackDays(unsigned char MonthNum,const struct MonthInfo *p)
//{
//    uint16_t Days=0;
//    uint8_t i;
//    for(i=0;i<MonthNum;i++)
//    {
//        Days+=(*(p+i)).Days;
//    }
//    return Days;
//}
//void eatline(void)
//{
//    while (getchar() != '\n')
//        continue;
//}

/*
2.
6 1
22 Spiffo Road
S p

3.
struct MonthInfo{
    char MonthName[10];
    char MonthAbbr[4];
    unsigned char Days;
    unsigned char MonthInNum;
};

4.
struct MonthInfo Year_2020[12];

6.a
Lens TenLens[10];
TenLens[2]={
    .foclen=500.0;
    .fstop=500.0/2.0;
};
b.
Lens InitLens={
    500.0;
    200.0；
    "xxx"
};

7.
a.
6
Arcturan
cturan

b.
deb.title.last
pb->title.last

void PrintStruct(const struct bem *ForPrint)
{
    printf("%s %s is a %d-limbed %s\n",
           ForPrint->title.first,(*ForPrint).title.last,ForPrint->limbs,ForPrint->type);

}

*/






/////////////////////////////////////////
////////////////Li 14.2/////////////////
///////////////////////////////////////
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>
// #include <time.h>

// #define MAXTITL 40
// #define MAXAUTL 40
// #define MAXBKS 100 /* 书籍的最大数量 */
// struct book { /* 简历 book 模板 */
    // char title[MAXTITL];
    // char author[MAXAUTL];
    // float value;
// };
// char * s_gets(char * st, int n);
// int main(void)
// {
    // struct book library[MAXBKS]; /* book 类型结构的数组 */
    // int count = 0;
    // int index;
    // printf("Please enter the book title.\n");
    // printf("Press [enter] at the start of a line to stop.\n");
    // while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           // && library[count].title[0] != '\0')
    // {
        // printf("Now enter the author.\n");
        // s_gets(library[count].author, MAXAUTL);
        // printf("Now enter the value.\n");
        // scanf("%f", &library[count++].value);
        // while (getchar() != '\n')
            // continue; /* 清理输入行*/
        // if (count < MAXBKS)
            // printf("Enter the next title.\n");
    // }
    // if (count > 0)
    // {
        // printf("Here is the list of your books:\n");
        // for (index = 0; index < count; index++)
            // printf("%s by %s: $%.2f\n", library[index].title,
                   // library[index].author, library[index].value);
    // }
    // else
        // printf("No books? Too bad.\n");

    // return 0;
// }
// char * s_gets(char * st, int n)
// {
    // char * ret_val;
    // char * find;
    // ret_val = fgets(st, n, stdin);
    // if (ret_val)
    // {
        // find = strchr(st, '\n'); // 查找换行符
        // if (find) // 如果地址不是 NULL，
            // *find = '\0'; // 在此处放置一个空字符
        // else
            // while (getchar() != '\n')
                // continue; // 处理输入行中剩余的字符
    // }
    // return ret_val;
// }

/////////////////////////////////////////
////////////////Li 14.4/////////////////
///////////////////////////////////////
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>
// #include <time.h>

// #define LEN 20
// struct names {
    // char first[LEN];
    // char last[LEN];
// };
// struct guy {
    // struct names handle;
    // char favfood[LEN];
    // char job[LEN];
    // float income;
// };
// int main(void)
// {
    // struct guy fellow[2] = {
        // { { "Ewen", "Villard" },
        // "grilled salmon",
        // "personality coach",
        // 68112.00
        // },
        // { { "Rodney", "Swillbelly" },
        // "tripe",
        // "tabloid editor",
        // 432400.00
        // }
    // };
    // struct guy * him; /* 这是一个指向结构的指针 */
    // printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    // him = &fellow[0]; /* 告诉编译器该指针指向何处 */
    // printf("pointer #1: %p #2: %p\n", him, him + 1);
    // printf("him->income is $%.2f: (*him).income is $%.2f\n", him->income, (*him).income);
    // him++; /* 指向下一个结构 */
    // printf("him->favfood is %s: him->handle.last is %s\n", him->favfood, him->handle.last);

    // return 0;
// }




/////////////////////////////////////////
////////////////Li 14.16////////////////
///////////////////////////////////////
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>
// #include <time.h>

// #define LEN 81
// char showmenu(void);
// void eatline(void); // 读取至行末尾
// void show(void(*fp)(char *), char * str);
// void ToUpper(char *); // 把字符串转换为大写
// void ToLower(char *); // 把字符串转换为小写
// void Transpose(char *); // 大小写转置
// void Dummy(char *); // 不更改字符串
// char * s_gets(char * st, int n);
// int main(void)
// {
    // char line[LEN];
    // char copy[LEN];
    // char choice;
    // void(*pfun)(char *); // 声明一个函数指针，被指向的函数接受char *类型的参数，无返回值
    // puts("Enter a string (empty line to quit):");
    // while (s_gets(line, LEN) != NULL&& line[0] != '\0')
    // {
        // while ((choice = showmenu()) != 'n')
        // {
            // switch (choice) // switch语句设置指针
            // {
                // case 'u': pfun = ToUpper;
                    // break;
                // case 'l': pfun = ToLower;
                    // break;
                // case 't': pfun = Transpose;
                    // break;
                // case 'o': pfun = Dummy;
                    // break;

            // }
            // strcpy(copy, line); // 为show()函数拷贝一份
            // show(pfun, copy); // 根据用户的选择，使用选定的函数
        // }
        // puts("Enter a string (empty line to quit):");
    // }
    // puts("Bye!");

    // return 0;
// }
// char showmenu(void)
// {
    // char ans;
    // puts("Enter menu choice:");
    // puts("u) uppercase l) lowercase");
    // puts("t) transposed case o) original case");
    // puts("n) next string");
    // ans = getchar(); // 获取用户的输入
    // ans = tolower(ans); // 转换为小写
    // eatline(); // 清理输入行
    // while (strchr("ulton", ans) == NULL)
    // {
        // puts("Please enter a u, l, t, o, or n:");
        // ans = tolower(getchar());
        // eatline();
    // }
    // return ans;
// }
// void eatline(void)
// {
    // while (getchar() != '\n')
        // continue;
// }
// void ToUpper(char * str)
// {
    // while (*str)
    // {
        // *str = toupper(*str);
        // str++;
    // }
// }
// void ToLower(char * str)
// {
    // while (*str)
    // {
        // *str = tolower(*str);
        // str++;
    // }
// }
// void Transpose(char * str)
// {
    // while (*str)
    // {
        // if (islower(*str))
            // *str = toupper(*str);
        // else if (isupper(*str))
            // *str = tolower(*str);
        // str++;
    // }
// }
// void Dummy(char * str)
// {
    // // 不改变字符串
// }
// void show(void(*fp)(char *), char * str)
// {
    // (*fp)(str); // 把用户选定的函数作用于str
    // puts(str); // 显示结果
// }
// char * s_gets(char * st, int n)
// {
    // char * ret_val;
    // char * find;
    // ret_val = fgets(st, n, stdin);
    // if (ret_val)
    // {
        // find = strchr(st, '\n'); // 查找换行符
        // if (find) // 如果地址不是 NULL,
            // *find = '\0'; // 在此处放置一个空字符
        // else
            // while (getchar() != '\n')
                // continue; // 处理输入行的剩余字符
    // }
    // return ret_val;
// }



///////////////////////////////////////////
//////////////////Li 14.15////////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#include <stdbool.h> // C99 特性
//enum spectrum { red, orange, yellow, green, blue, violet };
//const char * colors [] = { "red", "orange", "yellow",
//    "green", "blue", "violet" };
//#define LEN 30
//char * s_gets(char * st, int n);
//int main(void)
//{
//    char choice[LEN];
//    enum spectrum color;
//    bool color_is_found = false;
//    puts("Enter a color (empty line to quit):");
//    while (s_gets(choice, LEN) != NULL&& choice[0] != '\0')
//    {
//        for (color = red; color <= violet; color++)
//        {
//            if (strcmp(choice, colors[color]) == 0)
//            {
//                color_is_found = true;
//                break;
//            }
//        }
//        if (color_is_found)
//        {
//            switch (color)
//            {
//                case red:
//                    puts("Roses are red.");
//                    break;
//                case orange:
//                    puts("Poppies are orange.");
//                    break;
//                case yellow:
//                    puts("Sunflowers are yellow.");
//                    break;
//                case green:
//                    puts("Grass is green.");
//                    break;
//                case blue:
//                    puts("Bluebells are blue.");
//                    break;
//                case violet:
//                    puts("Violets are violet.");
//                    break;
//            }
//        }
//        else
//            printf("I don't know about the color %s.\n", choice);
//        color_is_found = false;
//        puts("Next color, please (empty line to quit):");
//
//    }
//    puts("Goodbye!");
//    return 0;
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



///////////////////////////////////////////
//////////////////Li 14.14////////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#define MAXTITL 40
//#define MAXAUTL 40
//#define MAXBKS 10 /* 最大书籍数量 */
//struct book { /* 建立 book 模板 */
//    char title[MAXTITL];
//    char author[MAXAUTL];
//    float value;
//};
//char * s_gets(char * st, int n);
//int main(void)
//{
//    struct book library[MAXBKS]; /* 结构数组 */
//    int count = 0;
//    int index, filecount;
//    FILE * pbooks;
//    int size = sizeof(struct book);
//    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
//    {
//        fputs("Can't open book.dat file\n", stderr);
//        exit(1);
//    }
//    rewind(pbooks); /* 定位到文件开始 */
//    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
//    {
//        if (count == 0)
//            puts("Current contents of book.dat:");
//        printf("%s by %s: $%.2f\n",
//               library[count].title, library[count].author, library[count].value);
//        count++;
//    }
//    filecount = count;
//    if (count == MAXBKS)
//    {
//        fputs("The book.dat file is full.", stderr);
//        exit(2);
//    }
//    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
//           && library[count].title[0] != '\0')
//    {
//        puts("Now enter the author.");
//        s_gets(library[count].author, MAXAUTL);
//        puts("Now enter the value.");
//        scanf("%f", &library[count++].value);
//        while (getchar() != '\n')
//            continue; /* 清理输入行 */
//        if (count < MAXBKS)
//            puts("Enter the next title.");
//    }
//    if (count > 0)
//    {
//        puts("Here is the list of your books:");
//        for (index = 0; index < count; index++)
//            printf("%s by %s: $%.2f\n",
//                   library[index].title, library[index].author, library[index].value);
//        fwrite(&library[filecount], size, count - filecount, pbooks);
//    }
//    else
//        puts("No books? Too bad.\n");
//    puts("Bye.\n");
//    fclose(pbooks);
//    return 0;
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


///////////////////////////////////////////
//////////////////Li 14.13////////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#define FUNDLEN 50
//#define N 2
//struct funds {
//    char bank[FUNDLEN];
//    double bankfund;
//    char save[FUNDLEN];
//    double savefund;
//};
//double sum(const struct funds money [], int n);
//int main(void)
//{
//    struct funds jones[N] = {
//        {
//            "Garlic-Melon Bank",
//            4032.27,
//            "Lucky's Savings and Loan",
//            8543.94
//        },
//        {
//            "Honest Jack's Bank",
//            3620.88,
//            "Party Time Savings",
//            3802.91
//        }
//    };
//    printf("The Joneses have a total of $%.2f.\n",sum(jones, N));
//    return 0;
//}
//double sum(const struct funds money [], int n)
//{
//    double total;
//    int i;
//    for (i = 0, total = 0; i < n; i++)
//        total += money[i].bankfund + money[i].savefund;
//    return(total);
//}


///////////////////////////////////////////
//////////////////Li 14.12////////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//struct flex{
//    size_t count;
//    double average;
//    double scores []; // 伸缩型数组成员
//
//};
//void showFlex(const struct flex * p);
//int main(void)
//{
//    struct flex * pf1, *pf2;
//    int n = 5;
//    int i;
//    int tot = 0;
//    // 为结构和数组分配存储空间
//    pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
//    pf1->count = n;
//    for (i = 0; i < n; i++)
//    {
//        pf1->scores[i] = 20.0 - i;
//        tot += pf1->scores[i];
//    }
//    pf1->average = tot / n;
//    showFlex(pf1);
//    n = 9;
//    tot = 0;
//    pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
//    pf2->count = n;
//    for (i = 0; i < n; i++)
//    {
//        pf2->scores[i] = 20.0 - i / 2.0;
//        tot += pf2->scores[i];
//    }
//    pf2->average = tot / n;
//    showFlex(pf2);
//    free(pf1);
//    free(pf2);
//    return 0;
//}
//void showFlex(const struct flex * p)
//{
//    int i;
//    printf("Scores : ");
//    for (i = 0; i < p->count; i++)
//        printf("%g ", p->scores[i]);
//    printf("\nAverage: %g\n", p->average);
//}


///////////////////////////////////////////
//////////////////Li 14.11////////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#define MAXTITL 41
//#define MAXAUTL 31
//struct book { // 结构模版：标记是 book
//    char title[MAXTITL];
//    char author[MAXAUTL];
//    float value;
//};
//
//int main(void)
//{
//    struct book readfirst;
//    int score;
//    printf("Enter test score: ");
//    scanf("%d", &score);
//    if (score >= 84)
//        readfirst = (struct book)
//            {"Crime and Punishment", "Fyodor Dostoyevsky", 11.25};
//    else
//        readfirst = (struct book)
//            {"Mr.Bouncy's Nice Hat", "Fred Winsome",5.99};
//    printf("Your assigned reading:\n");
//    printf("%s by %s: $%.2f\n",
//           readfirst.title, readfirst.author, readfirst.value);
//    return 0;
//}



///////////////////////////////////////////
//////////////////Li 14.10////////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#define SLEN 81
//struct namect {
//    char * fname; // 使用指针
//    char * lname;
//    int letters;
//};
//void getinfo(struct namect *); // 分配内存
//void makeinfo(struct namect *);
//void showinfo(const struct namect *);
//void cleanup(struct namect *); // 调用该函数时释放内存
//char * s_gets(char * st, int n);
//int main(void)
//{
//    struct namect person;
//    getinfo(&person);
//    makeinfo(&person);
//    showinfo(&person);
//    cleanup(&person);
//    return 0;
//}
//void getinfo(struct namect * pst)
//{
//    char temp[SLEN];
//    printf("Please enter your first name.\n");
//    s_gets(temp, SLEN);
//    // 分配内存以储存名
//    pst->fname = (char *) malloc(strlen(temp) + 1);
//    // 把名拷贝到动态分配的内存中
//    strcpy(pst->fname, temp);
//    printf("Please enter your last name.\n");
//    s_gets(temp, SLEN);
//    pst->lname = (char *) malloc(strlen(temp) + 1);
//    strcpy(pst->lname, temp);
//}
//void makeinfo(struct namect * pst)
//{
//    pst->letters = strlen(pst->fname) + strlen(pst->lname);
//}
//void showinfo(const struct namect * pst)
//{
//    printf("%s %s, your name contains %d letters.\n",
//           pst->fname, pst->lname, pst->letters);
//}
//void cleanup(struct namect * pst)
//{
//    free(pst->fname);
//    free(pst->lname);
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


///////////////////////////////////////////
//////////////////Li 14.9/////////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#define NLEN 30
//struct namect {
//    char fname[NLEN];
//    char lname[NLEN];
//    int letters;
//};
//struct namect getinfo(void);
//struct namect makeinfo(struct namect);
//void showinfo(struct namect);
//char * s_gets(char * st, int n);
//int main(void)
//{
//    struct namect person;
//    person = getinfo();
//    person = makeinfo(person);
//    showinfo(person);
//    return 0;
//}
//struct namect getinfo(void)
//{
//    struct namect temp;
//    printf("Please enter your first name.\n");
//    s_gets(temp.fname, NLEN);
//    printf("Please enter your last name.\n");
//    s_gets(temp.lname, NLEN);
//    return temp;
//}
//struct namect makeinfo(struct namect info)
//{
//    info.letters = strlen(info.fname) + strlen(info.lname);
//    return info;
//}
//void showinfo(struct namect info)
//{
//    printf("%s %s, your name contains %d letters.\n",
//           info.fname, info.lname, info.letters);
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



///////////////////////////////////////////
//////////////////Li 14.8/////////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#define NLEN 30
//struct namect {
//    char fname[NLEN];
//    char lname[NLEN];
//    int letters;
//};
//void getinfo(struct namect *);
//void makeinfo(struct namect *);
//void showinfo(const struct namect *);
//char * s_gets(char * st, int n);
//int main(void)
//{
//    struct namect person;
//    getinfo(&person);
//    makeinfo(&person);
//    showinfo(&person);
//    return 0;
//}
//void getinfo(struct namect * pst)
//{
//    printf("Please enter your first name.\n");
//    s_gets(pst->fname, NLEN);
//    printf("Please enter your last name.\n");
//    s_gets(pst->lname, NLEN);
//}
//void makeinfo(struct namect * pst)
//{
//    pst->letters = strlen(pst->fname) +strlen(pst->lname);
//}
//void showinfo(const struct namect * pst)
//{
//    printf("%s %s, your name contains %d letters.\n",
//           pst->fname, pst->lname, pst->letters);
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
///////////////////////////////////////////
//////////////////Li 14.7/////////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#define FUNDLEN 50
//struct funds {
//    char bank[FUNDLEN];
//    double bankfund;
//    char save[FUNDLEN];
//    double savefund;
//};
//double sum(struct funds moolah); /* 参数是一个结构 */
//int main(void)
//{
//    struct funds stan = {
//        "Garlic-Melon Bank",
//        4032.27,
//        "Lucky's Savings and Loan",
//        8543.94
//    };
//    printf("Stan has a total of $%.2f.\n",
//           sum(stan));
//    return 0;
//}
//double sum(struct funds moolah)
//{
//    return(moolah.bankfund + moolah.savefund);
//}



///////////////////////////////////////////
//////////////////Li 14.6/////////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#define FUNDLEN 50
//struct funds {
//    char bank[FUNDLEN];
//    double bankfund;
//    char save[FUNDLEN];
//    double savefund;
//};
//double sum(const struct funds *); /* 参数是一个指针 */
//int main(void)
//{
//    struct funds stan = {
//        "Garlic-Melon Bank",
//        4032.27,
//        "Lucky's Savings and Loan",
//        8543.94
//    };
//    printf("Stan has a total of $%.2f.\n",
//           sum(&stan));
//    return 0;
//}
//double sum(const struct funds * money)
//{
//    return(money->bankfund + money->savefund);
//}



///////////////////////////////////////////
//////////////////Li 14.5/////////////////
/////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//#define FUNDLEN 50
//struct funds {
//    char bank[FUNDLEN];
//    double bankfund;
//    char save[FUNDLEN];
//    double savefund;
//};
//double sum(double, double);
//int main(void)
//{
//    struct funds stan = {
//        "Garlic-Melon Bank",
//        4032.27,
//        "Lucky's Savings and Loan",
//        8543.94
//    };
//    printf("Stan has a total of $%.2f.\n",
//           sum(stan.bankfund, stan.savefund));
//    return 0;
//}
///* 两个double类型的数相加 */
//double sum(double x, double y)
//{
//    return(x + y);
//}

