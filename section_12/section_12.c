//////////////////////////////////////////////
//////////////Practice 12.2/12.3//////////////////
////////////////////////////////////////////

#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
    int mode;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        show_info(mode,get_Distance(),get_Fuel());
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}



////////////////////////////////////////////////
////////////////Practice 12.1//////////////////
//////////////////////////////////////////////
//
//#include <stdio.h>
//void critic(int *p);
//int main(void)
//{
//    int units=0; /* 可选的重复声明 */
//    int *p=&units;
//    printf("How many pounds to a firkin of butter?\n");
//    scanf("%d", &units);
//    while (units != 56)
//        critic(p);
//    printf("You must have looked it up!\n");
//    return 0;
//}
//void critic(int *p)
//{
//    /* 删除了可选的重复声明 */
//    printf("No luck, my friend. Try again.\n");
//    scanf("%d", p);
//}
