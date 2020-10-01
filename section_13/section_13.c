/////////////////////////////////////////
/////////////Practice 13.14/////////////
///////////////////////////////////////

/*
1.生成20*30整数文本文件
2.将文本文件的整数存入int数组
3.将int数组做失真处理
4.用int数组初始化字符数组
5.将字符数组存储在文本文件，并且打印
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
void DataDistortionProcess(unsigned int x,unsigned int y,int temp[x][y]);
int main(int argc,char **argv)
{
    FILE *fp;
    unsigned char hang=0,Lie=0;
    time_t t;
    unsigned int x,y;
    puts("enter how many hangs and lies you need");
    scanf("%u %u",&x,&y);
    int temp[x][y];
    char Show[x][y+1];
    if(argc<2)
    {
        puts("lack parameter");
        exit(EXIT_FAILURE);
    }
    if((fp=fopen(argv[1],"w+"))==NULL)
    {
        puts("cannot open file");
        exit(EXIT_FAILURE);
    }
    srand((unsigned) time(&t));
    for(hang=0;hang<x;hang++)
    {

        for(Lie=0;Lie<y;Lie++)
        {
            fprintf(fp,"%d ",rand()%10);
        }
        fputc('\n',fp);
    }
    fseek(fp,0L,SEEK_SET);
    for(hang=0;hang<x;hang++)
    {
        for(Lie=0;Lie<y;Lie++)
            fscanf(fp,"%d",&temp[hang][Lie]);
    }

    DataDistortionProcess(x,y,temp);

    for(hang=0;hang<x;hang++)
    {

        for(Lie=0;Lie<y;Lie++)
        {
            Show[hang][Lie]=temp[hang][Lie]+32;
        }
        Show[hang][Lie]='\0';
    }
    for(hang=0;hang<x;hang++)
    {
        printf("%s\n",Show[hang]);
    }

    if((fp=fopen("show","w+"))==NULL)
    {
        puts("cannot creat file");
        exit(EXIT_FAILURE);
    }
    for(hang=0;hang<x;hang++)
    {
        fprintf(fp,"%s\n",Show[hang]);
    }

    fclose(fp);
    return 0;
}
void DataDistortionProcess(unsigned int x,unsigned int y,int temp[x][y])
{
    unsigned int i,j;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            if(i==0 && j==0)
            {
                if(abs(temp[0][0]-temp[0][1])>1 && abs(temp[0][0]-temp[1][0])>1)
                    temp[0][0]=(temp[0][1]+temp[1][0])/2;
            }
            else if(i==x-1 && j==0)
            {
                if(abs(temp[x-1][0]-temp[x-1][1])>1 && abs(temp[x-1][0]-temp[x-2][0])>1)
                    temp[0][0]=(temp[x-1][1]+temp[x-2][0])/2;
            }
            else if(i==0 && j==y-1)
            {
                if(abs(temp[0][y-1]-temp[0][y-2])>1 && abs(temp[0][y-1]-temp[1][y-1])>1)
                    temp[0][0]=(temp[0][y-2]+temp[1][y-1])/2;
            }
            else if(i==x-1 && j==y-1)
            {
                if(abs(temp[x-1][y-1]-temp[x-1][y-2])>1 && abs(temp[x-1][y-1]-temp[x-2][y-1])>1)
                    temp[0][0]=(temp[x-1][y-2]+temp[x-2][y-1])/2;
            }
            else if(i==0 && j!=0 && j!=y-1)
            {
                if(abs(temp[0][j]-temp[0][j-1])>1 && abs(temp[0][j]-temp[0][j+1])>1 && abs(temp[0][j]-temp[1][j])>1)
                    temp[0][0]=(temp[0][j-1]+temp[0][j+1]+temp[1][j])/3;
            }
            else if(i==x-1 && j!=0 && j!=y-1)
            {
                if(abs(temp[x-1][j]-temp[x-1][j-1])>1 && abs(temp[x-1][j]-temp[x-1][j+1])>1 && abs(temp[x-1][j]-temp[x-2][j])>1)
                    temp[0][0]=(temp[x-1][j-1]+temp[x-1][j+1]+temp[x-2][j])/3;
            }
            else if(j==0 && x!=0 && x!=x-1)
            {
                if(abs(temp[x][0]-temp[x-1][0])>1 && abs(temp[x][0]-temp[x+1][0])>1 && abs(temp[x][0]-temp[x][1])>1)
                    temp[0][0]=(temp[x-1][0]+temp[x+1][0]+temp[x][1])/3;
            }
            else if(j==y-1 && x!=0 && x!=x-1)
            {
                if(abs(temp[x][y-1]-temp[x-1][y-1])>1 && abs(temp[x][y-1]-temp[x+1][y-1])>1 && abs(temp[x][y-1]-temp[x][y-2])>1)
                    temp[0][0]=(temp[x-1][y-1]+temp[x+1][y-1]+temp[x][y-2])/3;
            }
            else
            {
                if(abs(temp[i][j]-temp[i-1][j])>1 && abs(temp[i][j]-temp[i+1][j])>1 && abs(temp[i][j]-temp[i][j-1])>1 && abs(temp[i][j]-temp[i][j+1])>1 )
                    temp[i][j]=(temp[i-1][j]+temp[i+1][j]+temp[i][j-1]+temp[i][j+1])/4;
            }

        }
    }
}


///////////////////////////////////////////
///////////////Practice 13.13//////////////
/////////////////////////////////////////
//
///*
//1.生成20*30整数文本文件
//2.将文本文件的整数存入int数组
//3.用int数组初始化字符数组
//4.将字符数组存储在文本文件，并且打印
//*/
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//int main(int argc,char **argv)
//{
//    FILE *fp;
//    unsigned char hang=0,Lie=0;
//    time_t t;
//    unsigned int x,y;
//    puts("enter how many hangs and lies you need");
//    scanf("%u %u",&x,&y);
//    int temp[x][y];
//    char Show[x][y+1];
//    if(argc<2)
//    {
//        puts("lack parameter");
//        exit(EXIT_FAILURE);
//    }
//    if((fp=fopen(argv[1],"w+"))==NULL)
//    {
//        puts("cannot open file");
//        exit(EXIT_FAILURE);
//    }
//    srand((unsigned) time(&t));
//    for(hang=0;hang<x;hang++)
//    {
//
//        for(Lie=0;Lie<y;Lie++)
//        {
//            fprintf(fp,"%d ",rand()%10);
//        }
//        fputc('\n',fp);
//    }
//    fseek(fp,0L,SEEK_SET);
//    for(hang=0;hang<x;hang++)
//    {
//        for(Lie=0;Lie<y;Lie++)
//            fscanf(fp,"%d",&temp[hang][Lie]);
//    }
//    for(hang=0;hang<x;hang++)
//    {
//
//        for(Lie=0;Lie<y;Lie++)
//        {
//            Show[hang][Lie]=temp[hang][Lie]+32;
//        }
//        Show[hang][Lie]='\0';
//    }
//    for(hang=0;hang<x;hang++)
//    {
//        printf("%s\n",Show[hang]);
//    }
//
//    if((fp=fopen("show","w+"))==NULL)
//    {
//        puts("cannot creat file");
//        exit(EXIT_FAILURE);
//    }
//    for(hang=0;hang<x;hang++)
//    {
//        fprintf(fp,"%s\n",Show[hang]);
//    }
//
//    fclose(fp);
//    return 0;
//}



///////////////////////////////////////////
///////////////Practice 13.12//////////////
/////////////////////////////////////////
//
///*
//1.生成20*30整数文本文件
//2.将文本文件的整数存入int数组
//3.用int数组初始化字符数组
//4.将字符数组存储在文本文件，并且打印
//*/
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <time.h>
//int main(int argc,char **argv)
//{
//    FILE *fp;
//    unsigned hang=0,Lie=0;
//    time_t t;
//    int temp[20][30];
//    char Show[20][31];
//    if(argc<2)
//    {
//        puts("lack parameter");
//        exit(EXIT_FAILURE);
//    }
//    if((fp=fopen(argv[1],"w+"))==NULL)
//    {
//        puts("cannot open file");
//        exit(EXIT_FAILURE);
//    }
//    srand((unsigned) time(&t));
//    for(hang=0;hang<20;hang++)
//    {
//
//        for(Lie=0;Lie<30;Lie++)
//        {
//            fprintf(fp,"%d ",rand()%10);
//        }
//        fputc('\n',fp);
//    }
//    fseek(fp,0L,SEEK_SET);
//    for(hang=0;hang<20;hang++)
//    {
//        for(Lie=0;Lie<30;Lie++)
//            fscanf(fp,"%d",&temp[hang][Lie]);
//    }
//    for(hang=0;hang<20;hang++)
//    {
//
//        for(Lie=0;Lie<30;Lie++)
//        {
//            Show[hang][Lie]=temp[hang][Lie]+32;
//        }
//        Show[hang][Lie]='\0';
//    }
//    for(hang=0;hang<20;hang++)
//    {
//        printf("%s\n",Show[hang]);
//    }
//
//    if((fp=fopen("show","w+"))==NULL)
//    {
//        puts("cannot creat file");
//        exit(EXIT_FAILURE);
//    }
//    for(hang=0;hang<20;hang++)
//    {
//        fprintf(fp,"%s\n",Show[hang]);
//    }
//
//    fclose(fp);
//    return 0;
//}



///////////////////////////////////////////
///////////////Practice 13.11//////////////
/////////////////////////////////////////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//
//int main(int argc,char **argv)
//{
//    FILE *fp;
//    char temp[255];
//    if(argc<3)
//    {
//        puts("lack parameter");
//        exit(EXIT_FAILURE);
//    }
//    if((fp=fopen(argv[2],"r"))==NULL)
//    {
//        puts("cannot open file");
//        exit(EXIT_FAILURE);
//    }
//    while(feof(fp)==0)
//    {
//        fgets(temp,255,fp);
//        if(strstr(temp,argv[1])!=NULL)
//        {
//            fputs(temp,stdout);
//        }
//    }
//    fclose(fp);
//    return 0;
//}



///////////////////////////////////////////
///////////////Practice 13.10//////////////
/////////////////////////////////////////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//
//int main(int argc,char **argv)
//{
//    FILE *fp;
//    char c;
//    long int position;
//    if(argc<2)
//    {
//        puts("parameter error");
//        exit(EXIT_FAILURE);
//    }
//    if((fp=fopen(argv[1],"r"))==NULL)
//    {
//        puts("cannot open file");
//        exit(EXIT_FAILURE);
//    }
//    puts("enter file position you want to print");
//    while(scanf("%ld",&position)==1)
//    {
//        if(position<0)
//            exit(EXIT_FAILURE);
//        fseek(fp, position, SEEK_SET);
//        while((c=getc(fp))!='\n')
//              putc(c,stdout);
//        putc('\n',stdout);
//        puts("enter file position you want to print");
//    }
//    fclose(fp);
//
//
//
//    return 0;
//}



///////////////////////////////////////////
///////////////Practice 13.9//////////////
/////////////////////////////////////////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//
//#define MAX 41
//int main(int argc,char **argv)
//{
//    FILE *fp;
//    char words[MAX],c;
//    unsigned char Word_Counter=0;
//    if ((fp = fopen(argv[1], "a+")) == NULL)
//    {
//        fprintf(stdout, "Can't open \"wordy\" file.\n");
//        exit(EXIT_FAILURE);
//    }
//    while((c=getc(fp))!=EOF)
//    {
//        if(c=='\n')
//            Word_Counter++;
//    }
//    fseek(fp, 0L, SEEK_END);
//    //fprintf(fp, "\n");
//
//
//
//    puts("Enter words to add to the file; press the #");
//    puts("key at the beginning of a line to terminate.");
//    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
//    {
//        fprintf(fp, "%d     ", ++Word_Counter);
//        fprintf(fp, "%s\n", words);
//    }
//    puts("File contents:");
//    rewind(fp); /* 返回到文件开始处 */
//    while (fscanf(fp, "%s", words) == 1)
//        puts(words);
//    puts("Done!");
//    if (fclose(fp) != 0)
//        fprintf(stderr, "Error closing file\n");
//    return 0;
//}



///////////////////////////////////////////
///////////////Practice 13.8//////////////
/////////////////////////////////////////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//
//
//int main(int argc,char **argv)
//{
//    FILE *fp;
//    char c1,c2;
//    unsigned char Counter1=0,Counter2=0,i=2;
//    char File1[80];
//    if(argc<2)
//    {
//        puts("less of parameter,exit now");
//        exit(EXIT_FAILURE);
//    }
//    puts("ok");
//    c1=argv[1][0];
//    if(argc<2)
//    {
//        puts("enter file name");
//        while(gets(File1)!=NULL)
//        {
//            if((fp=fopen(File1,"r"))==NULL)
//            {
//                puts("cannot open it,skip it");
//                continue;
//            }
//            while((c2=getc(fp))!=EOF)
//            {
//                if(c2==c1)
//                    Counter1++;
//            }
//            printf("File %s has %u %c\n",File1,Counter1,c1);
//        }
//    }
//    else
//    {
//        while(i<argc)
//        {
//            if((fp=fopen(argv[i],"r"))!=NULL)
//            {
//                while((c2=getc(fp))!=EOF)
//                {
//                    if(c2==c1)
//                        Counter2++;
//                }
//                printf("File %s has %u %c\n",argv[i],Counter2,c1);
//            }
//            else
//            {
//                puts("cannot open file,skip");
//            }
//            i++;
//        }
//    }
//
//    fclose(fp);
//
//    return 0;
//}



///////////////////////////////////////////
///////////////Practice 13.7b//////////////
/////////////////////////////////////////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#define BUFSIZE 4096
//void MyPrint(FILE *fp1,FILE *fp2);
//char * Mygets(char * st, int n,FILE *fp);
//int main(int argc,char **argv)
//{
//    FILE * fp1,* fp2;
//    char file1[100],file2[100];
//    if (argc == 1)
//    {
//        puts("enter 2 file name need to open");
//        scanf("%s%s",file1,file2);
//        if ((fp1 = fopen(file1, "r")) == NULL)
//        {
//            fprintf(stderr, "Can't open %s\n", file1);
//            exit(EXIT_FAILURE);
//        }
//        else
//        {
//            puts("open file 1 successfully");
//        }
//        if ((fp2 = fopen(file2, "r")) == NULL)
//        {
//            fprintf(stderr, "Can't open %s\n", file2);
//            exit(EXIT_FAILURE);
//        }
//        else
//        {
//            puts("open file 2 successfully");
//        }
//    }
//    else if (argc == 3)
//    {
//        if ((fp1 = fopen(argv[1], "r")) == NULL)
//        {
//            fprintf(stderr, "Can't open %s\n", argv[1]);
//            exit(EXIT_FAILURE);
//        }
//        else
//        {
//            puts("open file 1 successfully");
//        }
//        if ((fp2 = fopen(argv[2], "r")) == NULL)
//        {
//            fprintf(stderr, "Can't open %s\n", argv[2]);
//            exit(EXIT_FAILURE);
//        }
//        else
//        {
//            puts("open file 2 successfully");
//        }
//    }
//    if (setvbuf(fp1, NULL, _IOFBF, BUFSIZE) != 0)
//    {
//        fputs("Can't create fp1 buffer\n", stderr);
//        exit(EXIT_FAILURE);
//    }
//    if (setvbuf(fp2, NULL, _IOFBF, BUFSIZE) != 0)
//    {
//        fputs("Can't create fp2 buffer\n", stderr);
//        exit(EXIT_FAILURE);
//    }
//    MyPrint(fp1,fp2);
//    fclose(fp1);
//    fclose(fp2);
//
//    return 0;
//}
//void MyPrint(FILE *fp1,FILE *fp2)
//{
//    char temp1[BUFSIZE];
//    char temp2[BUFSIZE];
////    while(feof(fp1)==0 || feof(fp2)==0)
////    {
////        if(feof(fp1)==0 )
////        {
////            if(Mygets(temp1,BUFSIZE,fp1)!=NULL)
////                fputs(temp1,stdout);
////        }
////        if(feof(fp2)==0 )
////        {
////            if(Mygets(temp2,BUFSIZE,fp2)!=NULL)
////                fputs(temp2,stdout);
////        }
////        puts("");
////    }
//    while(feof(fp1)==0 || feof(fp2)==0)
//    {
//        if(Mygets(temp1,BUFSIZE,fp1)!=NULL)
//            fputs(temp1,stdout);
//        if(Mygets(temp2,BUFSIZE,fp2)!=NULL)
//            fputs(temp2,stdout);
//        puts("");
//    }
//}
//char * Mygets(char * st, int n,FILE *fp)
//{
//    char * ret_val;
//    char * find;
//    ret_val = fgets(st, n, fp);
//    if (ret_val)
//    {
//        find = strchr(st, '\n'); // 查找换行符
//        if (find) // 如果地址不是NULL，
//            *find = '\0'; // 在此处放置一个空字符
//    }
//    return ret_val;
//}



///////////////////////////////////////////
///////////////Practice 13.7a//////////////
/////////////////////////////////////////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#define BUFSIZE 4096
//void MyPrint(FILE *fp1,FILE *fp2);
//int main(int argc,char **argv)
//{
//    FILE * fp1,* fp2;
//    char file1[100],file2[100];
//    if (argc == 1)
//    {
//        puts("enter 2 file name need to open");
//        scanf("%s%s",file1,file2);
//        if ((fp1 = fopen(file1, "r")) == NULL)
//        {
//            fprintf(stderr, "Can't open %s\n", file1);
//            exit(EXIT_FAILURE);
//        }
//        else
//        {
//            puts("open file 1 successfully");
//        }
//        if ((fp2 = fopen(file2, "r")) == NULL)
//        {
//            fprintf(stderr, "Can't open %s\n", file2);
//            exit(EXIT_FAILURE);
//        }
//        else
//        {
//            puts("open file 2 successfully");
//        }
//    }
//    else if (argc == 3)
//    {
//        if ((fp1 = fopen(argv[1], "r")) == NULL)
//        {
//            fprintf(stderr, "Can't open %s\n", argv[1]);
//            exit(EXIT_FAILURE);
//        }
//        else
//        {
//            puts("open file 1 successfully");
//        }
//        if ((fp2 = fopen(argv[2], "r")) == NULL)
//        {
//            fprintf(stderr, "Can't open %s\n", argv[2]);
//            exit(EXIT_FAILURE);
//        }
//        else
//        {
//            puts("open file 2 successfully");
//        }
//    }
//    if (setvbuf(fp1, NULL, _IOFBF, BUFSIZE) != 0)
//    {
//        fputs("Can't create fp1 buffer\n", stderr);
//        exit(EXIT_FAILURE);
//    }
//    if (setvbuf(fp2, NULL, _IOFBF, BUFSIZE) != 0)
//    {
//        fputs("Can't create fp2 buffer\n", stderr);
//        exit(EXIT_FAILURE);
//    }
//    MyPrint(fp1,fp2);
//    fclose(fp1);
//    fclose(fp2);
//
//    return 0;
//}
//void MyPrint(FILE *fp1,FILE *fp2)
//{
//    char temp1[BUFSIZE];
//    char temp2[BUFSIZE];
//    unsigned char Flag_File1End=0,Flag_File2End=0;
//    while(Flag_File1End==0 || Flag_File2End==0)
//    {
//        if(feof(fp1)==0 && Flag_File1End==0)
//        {
//            if(fgets(temp1,BUFSIZE,fp1)!=NULL)
//                fputs(temp1,stdout);
//        }
//        if(feof(fp1)!=0 && Flag_File1End==0)
//        {
//            Flag_File1End=1;
//            fputc('\n',stdout);
//        }
//
//        if(feof(fp2)==0 && Flag_File2End==0)
//        {
//            if(fgets(temp2,BUFSIZE,fp2)!=NULL)
//                fputs(temp2,stdout);
//        }
//        if(feof(fp2)!=0 && Flag_File2End==0)
//        {
//            Flag_File2End=1;
//            fputc('\n',stdout);
//        }
//
//
//    }
//}

///////////////////////////////////////////
///////////////Practice 13.6//////////////
/////////////////////////////////////////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#define BUFSIZE 4096
//int main(void)
//{
//    FILE *fp,*fp_Write;
//    char str[40];
//    char SrcName[100],CpyName[100];
//    size_t bytes;
//    static char temp[BUFSIZE]; // 只分配一次
//    puts("Enter source file name");
//    gets(SrcName);
//    puts("Enter copy file name");
//    gets(CpyName);
//    if((fp=fopen(SrcName,"rb"))==NULL)
//    {
//        puts("Can not open src file");
//        exit(EXIT_FAILURE);
//    }
//    if((fp_Write=fopen(CpyName,"r+"))==NULL)
//    {
//        puts("Can not open cpy file");
//        exit(EXIT_FAILURE);
//    }
//    if (setvbuf(fp, NULL, _IOFBF, BUFSIZE) != 0)
//    {
//        fputs("Can't create output buffer\n", stderr);
//        exit(EXIT_FAILURE);
//    }
//    if (setvbuf(fp_Write, NULL, _IOFBF, BUFSIZE) != 0)
//    {
//        fputs("Can't create input buffer\n", stderr);
//        //continue;
//    }
//    while ((bytes = fread(temp, sizeof(char), BUFSIZE, fp)) > 0)
//        fwrite(temp, sizeof(char), bytes, fp_Write);
//    puts(temp);
////    fread(str,1,6,fp);
////    fwrite(str,1,6,fp_Write);
//    fclose(fp);
//    fclose(fp_Write);
//    return 0;
//}



///////////////////////////////////////////
///////////////Practice 13.5//////////////
/////////////////////////////////////////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define BUFSIZE 4096
//#define SLEN 81
//void append(FILE *source, FILE *dest);
//char * s_gets(char * st, int n);
//int main(int argc,char *argv[])
//{
//    FILE *fa, *fs; // fa 指向目标文件，fs 指向源文件
//    char file_app[SLEN]; // 目标文件名
//    char file_src[SLEN]; // 源文件名
//    int ch;
//    if (strcmp(argv[1], argv[2]) == 0)
//    {
//        fputs("Can't append file to itself\n", stderr);
//        exit(EXIT_FAILURE);
//    }
//    if ((fa = fopen(argv[2], "a+")) == NULL)
//    {
//        fprintf(stderr, "Can't open %s\n", argv[1]);
//        exit(EXIT_FAILURE);
//    }
//    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
//    {
//        fputs("Can't create output buffer\n", stderr);
//        exit(EXIT_FAILURE);
//    }
//    if ((fs = fopen(argv[1], "r")) == NULL)
//    {
//        fprintf(stderr, "Can't open %s\n", argv[2]);
//        exit(EXIT_FAILURE);
//    }
//            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
//            {
//                fputs("Can't create input buffer\n", stderr);
//                //continue;
//            }
//            append(fs, fa);
//            if (ferror(fs) != 0)
//                fprintf(stderr, "Error in reading file %s.\n", file_src);
//            if (ferror(fa) != 0)
//                fprintf(stderr, "Error in writing file %s.\n", file_app);
//            fclose(fs);
//            printf("File %s appended.\n", argv[1]);
//    rewind(fa);
//    printf("%s contents:\n", argv[2]);
//    while ((ch = getc(fa)) != EOF)
//        putchar(ch);
//    puts("Done displaying.");
//    fclose(fa);
//    return 0;
//}
//void append(FILE *source, FILE *dest)
//{
//    size_t bytes;
//    static char temp[BUFSIZE]; // 只分配一次
//    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
//        fwrite(temp, sizeof(char), bytes, dest);
//
//
//}
//char * s_gets(char * st, int n)
//{
//    char * ret_val;
//    char * find;
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        find = strchr(st, '\n'); // 查找换行符
//        if (find) // 如果地址不是NULL，
//            *find = '\0'; // 在此处放置一个空字符
//        else
//            while (getchar() != '\n')
//            continue;
//    }
//    return ret_val;
//}
//




///////////////////////////////////////////
///////////////Practice 13.4//////////////
/////////////////////////////////////////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//int main(int argc,char *argv[])
//{
//    FILE *fp;
//    char str[40];
//    if(argc<2)
//        exit(EXIT_FAILURE);
//    unsigned char i;
//    for(i=1;i<argc;i++)
//    {
//        if((fp=fopen(argv[i],"r"))!=NULL)
//        {
//            fgets(str,40,fp);
//            fputs(str,stdout);
//        }
//        else
//        {
//            puts("cannot open file");
//        }
//        fclose(fp);
//    }
//    return 0;
//}



///////////////////////////////////////////
///////////////Practice 13.3//////////////
/////////////////////////////////////////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//int main(void)
//{
//    FILE *fp,*fp_Write;
//    char str[40];
//    unsigned char i=0;
//    char InFile[20],OutFile[20];
//
//
//    puts("enter input file name and output file name");
//    scanf("%s%s",InFile,OutFile);
//    if((fp=fopen(InFile,"r"))==NULL)
//    {
//        puts("cannot open Input file");
//        exit(EXIT_FAILURE);
//    }
//    if((fp_Write=fopen(OutFile,"w"))==NULL)
//    {
//        puts("cannot creat Output file");
//        exit(EXIT_FAILURE);
//    }
//    fgets(str,40,fp);
//    while(str[i++]!='\0')
//    {
//        str[i]=toupper(str[i]);
//    }
//    fputs(str,fp_Write);
//    fclose(fp);
//    fclose(fp_Write);
//    return 0;
//}



///////////////////////////////////////////
///////////////Practice 13.2//////////////
/////////////////////////////////////////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//int main(int argc,char *argv[])
//{
//    FILE *fp,*fp_Write;
//    char str[40];
//    if(argc<3)
//        exit(EXIT_FAILURE);
//    if((fp=fopen(argv[1],"rb"))==NULL)
//    {
//        puts("Can not open src file");
//        exit(EXIT_FAILURE);
//    }
//    if((fp_Write=fopen(argv[2],"wb"))==NULL)
//    {
//        puts("Can not open cpy file");
//        exit(EXIT_FAILURE);
//    }
//
//    fread(str,1,6,fp);
//    fwrite(str,1,6,fp_Write);
//    fclose(fp);
//    fclose(fp_Write);
//    return 0;
//}



///////////////////////////////////////////
///////////////Practice 13.1//////////////
/////////////////////////////////////////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//int main(void)
//{
//    int ch; // 读取文件时，储存每个字符的地方
//    FILE *fp; // “文件指针”
//    char fName[40];
//    unsigned long count = 0;
//    puts("Enter file name");
//    gets(fName);
//    if ((fp = fopen(fName, "r")) == NULL)
//    {
//        puts("Cant not open file");
//        exit(EXIT_FAILURE);
//    }
//    while ((ch = getc(fp)) != EOF)
//    {
//        putc(ch, stdout); // 与 putchar(ch); 相同
//        count++;
//    }
//    fclose(fp);
//    printf("File %s has %lu characters\n", fName, count);
//    return 0;
//}

///////////////////////////////////////////
///////////////LiZi 13.5//////////////////
/////////////////////////////////////////
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define BUFSIZE 4096
// #define SLEN 81
// void append(FILE *source, FILE *dest);
// char * s_gets(char * st, int n);
// int main(void)
// {
    // FILE *fa, *fs; // fa 指向目标文件，fs 指向源文件
    // int files = 0; // 附加的文件数量
    // char file_app[SLEN]; // 目标文件名
    // char file_src[SLEN]; // 源文件名
    // int ch;
    // puts("Enter name of destination file:");
    // s_gets(file_app, SLEN);
    // if ((fa = fopen(file_app, "a+")) == NULL)
    // {
        // fprintf(stderr, "Can't open %s\n", file_app);
        // exit(EXIT_FAILURE);
    // }
    // if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    // {
        // fputs("Can't create output buffer\n", stderr);
        // exit(EXIT_FAILURE);
    // }
    // puts("Enter name of first source file (empty line to quit):");
    // while (s_gets(file_src, SLEN) && file_src[0] != '\0')
    // {
        // if (strcmp(file_src, file_app) == 0)
            // fputs("Can't append file to itself\n", stderr);
        // else if ((fs = fopen(file_src, "r")) == NULL)
            // fprintf(stderr, "Can't open %s\n", file_src);
        // else
        // {
            // if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            // {
                // fputs("Can't create input buffer\n", stderr);
                // continue;
            // }
            // append(fs, fa);
            // if (ferror(fs) != 0)
                // fprintf(stderr, "Error in reading file %s.\n", file_src);
            // if (ferror(fa) != 0)
                // fprintf(stderr, "Error in writing file %s.\n", file_app);
            // fclose(fs);
            // files++;
            // printf("File %s appended.\n", file_src);
            // puts("Next file (empty line to quit):");
        // }
    // }
    // printf("Done appending.%d files appended.\n", files);
    // rewind(fa);
    // printf("%s contents:\n", file_app);
    // while ((ch = getc(fa)) != EOF)
        // putchar(ch);
    // puts("Done displaying.");
    // fclose(fa);
    // return 0;
// }
// void append(FILE *source, FILE *dest)
// {
    // size_t bytes;
    // static char temp[BUFSIZE]; // 只分配一次
    // while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        // fwrite(temp, sizeof(char), bytes, dest);
// }
// char * s_gets(char * st, int n)
// {
    // char * ret_val;
    // char * find;
    // ret_val = fgets(st, n, stdin);
    // if (ret_val)
    // {
        // find = strchr(st, '\n'); // 查找换行符
        // if (find) // 如果地址不是NULL，
            // *find = '\0'; // 在此处放置一个空字符
        // else
            // while (getchar() != '\n')
            // continue;
    // }
    // return ret_val;
// }

///////////////////////////////////////////
///////////////FuXiTi 13//////////////////
/////////////////////////////////////////
/*

1.
没指定打开模式
fclose的参数应该是FILE*的指针

2.
find digits in file and print

3.
ch=getc(fp1);
fprintf(fp2,"%c\n",ch);
putc(ch,stdout);
fclose(fp1);

4.
5.

6.
二进制文件以\n换行
文本文件\r\n
流没有区别

7.
fwrite二进制形式
fprintf文本形式

8.
1,2没区别

9.
r+

4.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double PrintAverage(unsigned char x,char data[][40]);
int main(int argc, char *argv [])
{
    int ch;
    FILE *fp,*fp_ForOut;
    char data[20][40];
    unsigned char i=0,j=0,Counter=0,Flag_DataBegin=0;
    if (argc < 3)
        exit(EXIT_FAILURE);
    if ((fp = fopen(argv[1], "r")) == NULL)
        exit(EXIT_FAILURE);
    while ((ch = getc(fp)) != EOF)
    {
        if (!isspace(ch))
        {
            Flag_DataBegin=1;
            data[i][j++]=ch;
            Counter=i;
        }
        else if(isspace(ch))
        {
            if(Flag_DataBegin)
            {
                i++;
                j=0;
                data[i][j]='\0';
            }
            Flag_DataBegin=0;

        }
    }
    if ((fp_ForOut = fopen(argv[2], "r+")) == NULL)
        exit(EXIT_FAILURE);
    fprintf(fp_ForOut,"%f\n",PrintAverage(Counter,data));
    fclose(fp);
    fclose(fp_ForOut);
    return 0;
}
double PrintAverage(unsigned char x,char data[][40])
{
    unsigned char i;
    double DataInDouble[x],Sum=0;
    for(i=0;i<x;i++)
    {
        DataInDouble[i]=atof(data[i]);
        Sum+=DataInDouble[i];
    }
    return Sum/x;
}

5.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char *argv [])
{
    FILE *fp;
    char c,str[40];
    if(argc<3)
        exit(EXIT_FAILURE);
    if((fp=fopen(argv[2],"r"))==NULL)
    {
        printf("Open failure");
        exit(EXIT_FAILURE);
    }
    c=*argv[1];
    while(fgets(str,40,fp)!=NULL)
    {
        if(strchr(str,c)!=NULL)
        {
            printf("%s\n",str);
        }
    }
    fclose(fp);

    return 0;
}


*/
