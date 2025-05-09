

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <sys/file.h>
#include <stdarg.h>

#define PERMS 0666/* RW for owner, group, others */

// void error(char *,  ...);


//
/* cp:  copy f1 to f2 */
//int main(int argc, char *argv[])
//{
//   int f1, f2, n;
//   char buf[BUFSIZ];
//
////   if (argc != 3)
////	   printf("Usage: cp from to");
//
//   if ((f1 = open(argv[1], O_BINARY, 0)) == -1)//O_BINARY O_RDONLY
//	   printf("cp: can't open %s", argv[1]);
//
////   if ((f2 = creat(argv[2], PERMS)) == -1)
////	   printf("cp: can't create %s, mode %03o",argv[2], PERMS);
//
//   while ((n = read(f1, buf, BUFSIZ)) > 0)
//   {
//     printf("%x\n",buf);
////	   if (write(f2, buf, n) != n)
////		   printf("cp: write error on file %s", argv[2]);
//   }
//
//   return 0;
//}


// void error(char *fmt, ...)
// {

//    va_list args;
//    va_start(args, fmt);
//    fprintf(stderr, "error: ");
//    vprintf(stderr, fmt, args);
//    fprintf(stderr, "\n");
//    va_end(args);
//    exit(1);
// }


int main(int argc, char *argv[])
{
  FILE * f1,f2;
   int n, i, cnt;
   char buf[BUFSIZ];

//   if (argc != 3)
//	   printf("Usage: cp from to");

   if ((f1 = fopen(argv[1], "rb+")) == NULL)//O_BINARY O_RDONLY
	   printf("cp: can't open %s", argv[1]);

//   if ((f2 = creat(argv[2], PERMS)) == -1)
//	   printf("cp: can't create %s, mode %03o",argv[2], PERMS);

   while ((n=fread(buf, 1, BUFSIZ, f1)) == BUFSIZ)
   {
     for(i = 0; i < BUFSIZ; i++){
      printf("%.2x ",buf[i]);

     }
     cnt += n;
//	   if (write(f2, buf, n) != n)
//		   printf("cp: write error on file %s", argv[2]);
   }
    cnt += n;
     for(i = 0; i < n; i++){
      printf("%.2x ",buf[i]);

     }


     printf("\ncnt = %d\n",cnt);
     printf("hello\n");
   fclose(f1);

   return 0;
}






