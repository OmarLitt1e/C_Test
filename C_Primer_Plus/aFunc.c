#include <stdio.h>
int Global_Variable;
void aFunc(void)
{
    Global_Variable=20;
    printf("%d\n",Global_Variable);
}
