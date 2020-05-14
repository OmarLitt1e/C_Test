

/////////////////test 1.6/////////////////////
//#include <stdio.h>
////#include <stdlib.h>
//
//int main()
//{
//    printf("%d\n",((getchar())!='x'));
//    return 0;
//}

//#include <stdio.h>
//int main(void) {
// printf("Press a key. ENTER would be nice :-)\n\n");
// printf("The expression getchar() != EOF evaluates to %d\n", getchar() != EOF);
// return 0; }


/////////////////test 1.7/////////////////////
//#include <stdio.h>
////#include <stdlib.h>
//
//int main()
//{
//    int x;
//    x=EOF;
//    printf("%d\n",x);
//    return 0;
//}

///////////////test 1.7/////////////////////
#include <stdio.h>
//#include <stdlib.h>

int main()
{
    long nc;
    nc=0;
    while((getchar()!=EOF))
    {
        ++nc;
    }

    printf("%ld\n",nc);

    //return 0;
}


