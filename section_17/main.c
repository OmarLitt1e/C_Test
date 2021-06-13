///////////////////////////////////////////
//////////////QingDan 17.8///////////////
/////////////////////////////////////////

/* use_q.c -- 驱动程序测试 Queue 接口 */
/* 与 queue.c 一起编译 */
#include <stdio.h>
#include "queue.h" /* 定义Queue、Item */
int main(void)
{
    Queue line;
    Item temp;
    char ch;
    InitializeQueue(&line);
    puts("Testing the Queue interface. Type a to add a value,");
    puts("type d to delete a value, and type q to quit.");
    while ((ch = getchar()) != 'q')
    {
        if (ch != 'a' && ch != 'd') /* 忽略其他输出 */
            continue;
        if (ch == 'a')
        {
            printf("Integer to add: ");
            scanf("%d", &temp);
            if (!QueueIsFull(&line))
            {
                printf("Putting %d into queue\n", temp);
                EnQueue(temp, &line);
            }
            else
                puts("Queue is full!");
        }
        else
        {
            if (QueueIsEmpty(&line))
                puts("Nothing to delete!");
            else
            {
                DeQueue(&temp, &line);
                printf("Removing %d from queue\n", temp);
            }
        }
        printf("%d items in queue\n", QueueItemCount(&line));
        puts("Type a to add, d to delete, q to quit:");
    }
    EmptyTheQueue(&line);
    puts("Bye!");
    return 0;
}


/////////////////////////////////////////////
////////////////Practice 17.7///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdint.h>
//#include <stdlib.h> // 提供 rand() 和 srand() 的原型
//#include <time.h> // 提供 time() 的原型
//#include <stdbool.h>
//#include <string.h>
//#include "tree_17_7.h"
//#define MaxStringSize 20
//char * s_gets(char * st, int n);
//void eatline(void);
//void CountYourChar(Tree *pTree);
//void PutInTree(FILE *fp,Tree *pTree);
//void ShowAndCount(Tree *pTree);
//int main(void)
//{
//    Tree Tree,*pTree;
//    pTree=&Tree;
//    InitializeTree(pTree);
//
//    FILE *fp;
//    if((fp=fopen("Practice17_7.txt","r"))==NULL)
//    {
//        puts("cannot open file");
//        exit(EXIT_FAILURE);
//    }
//    PutInTree(fp,pTree);
//
//
//    puts("Choose from the lists:");
//    puts("1) show all the character and count the times they showing up");
//    puts("2) enter a character and will count times this character shows up in this .txt");
//    puts("3) quit");
//    int8_t Choice;
//    while((Choice = getchar())!=EOF && Choice != '3')
//    {
//        switch(Choice)
//        {
//            case '1':
//                ShowAndCount(pTree);
//                break;
//            case '2':
//                CountYourChar(pTree);
//                break;
//            default:
//                break;
//        }
//
//        eatline();
//        puts("Choose from the lists:");
//        puts("1) show all the character and count the times they showing up");
//        puts("2) enter a character and will count times this character shows up in this .txt");
//        puts("3) quit");
//    }
//
//
//    return 0;
//}
//void CountYourChar(Tree *pTree)
//{
//    Tree *ForSearch;
//    ForSearch=pTree;
//    char YourChar;
//    puts("enter a character,enter 'q' to quit");
//    while((YourChar=getchar())!=EOF && YourChar!='q')
//    {
//        while((ForSearch->root->left == NULL && ForSearch->root->right == NULL) == 0)
//        {
//            if(YourChar==(ForSearch->root->item).SingleChar)
//            {
//                printf("There are %u %c in file\n",(ForSearch->root->item).Counter,YourChar);
//                break;
//            }
//            else
//            {
//                if(YourChar>(ForSearch->root->item).SingleChar)
//                {
//                    if(ForSearch->root->right!=NULL)
//                        ForSearch->root=ForSearch->root->right;
//                    else
//                    {
//                        printf("There is no %c in file\n",YourChar);
//                        break;
//                    }
//                }
//                else
//                {
//                    if(ForSearch->root->left!=NULL)
//                        ForSearch->root=ForSearch->root->left;
//                    else
//                    {
//                        printf("There is no %c in file\n",YourChar);
//                        break;
//                    }
//                }
//            }
//        }
//        eatline();
//    }
//
//}
//
//void PutInTree(FILE *fp,Tree *pTree)
//{
//    Item Item,*MyItem;
//    MyItem = &Item;
//    while( ( (MyItem->SingleChar) = getc(fp) ) != EOF)
//    {
//        MyItem->Counter=0;
//        if(TreeIsFull(pTree)==true)
//        {
//            puts("Tree is not big enough");
//            break;
//        }
//        if(AddItem(MyItem,pTree)==false)
//        {
//            puts("add item failed");
//            break;
//        }
//    }
//    fclose(fp);
//}
//
//void ShowAndCount(Tree *pTree)
//{
//    Tree *ForSearch;
//    ForSearch=pTree;
//    while(ForSearch->root->left!=NULL)
//    {
//        printf("%c %u\n",(ForSearch->root->item).SingleChar,(ForSearch->root->item).Counter);
//        ForSearch->root=ForSearch->root->left;
//    }
//    ForSearch=pTree;
//    while(ForSearch->root->right!=NULL)
//    {
//        printf("%c %u\n",(ForSearch->root->item).SingleChar,(ForSearch->root->item).Counter);
//        ForSearch->root=ForSearch->root->right;
//    }
//}
//
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
//



/////////////////////////////////////////////
////////////////Practice 17.6///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdint.h>
//#include <stdlib.h> // 提供 rand() 和 srand() 的原型
//#include <time.h> // 提供 time() 的原型
//#include <stdbool.h>
//#include <string.h>
//#define MaxStringSize 20
//char * s_gets(char * st, int n);
//void eatline(void);
//uint8_t FindInDichotomy(int SrcArray[],int Num,int Target);
//int main(void)
//{
//    int SrcArray[100];
//    uint8_t i;
//    for(i=0;i<100;i++)
//        SrcArray[i]=i;
//    if(FindInDichotomy(SrcArray,100,95))
//        puts("Got");
//    else
//        puts("Search Failure");
//
//    return 0;
//}
//uint8_t FindInDichotomy(int SrcArray[],int Num,int Target)
//{
//    int start,end,MidNum;
//    start = 0;
//    end = 99;
//    while(MidNum != Target)
//    {
//        MidNum = SrcArray[(start+end)/2];
//        if(MidNum > Target)
//            end = MidNum;
//        else if(MidNum < Target)
//            start = MidNum;
//        if(start == 99 || end == -1)
//            return 0;
//    }
//    return 1;
//}
//
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
//


/////////////////////////////////////////////
////////////////Practice 17.5///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdint.h>
//#include <stdlib.h> // 提供 rand() 和 srand() 的原型
//#include <time.h> // 提供 time() 的原型
//#include "stack.h"
//#include <stdbool.h>
//#include <string.h>
//#define MaxStringSize 20
//char * s_gets(char * st, int n);
//void eatline(void);
//int main(void)
//{
//
//    StackItem StackItem;
//    StackItem.former = NULL;
//
//    Stack Stack_0,*Stack;
//    Stack_0.tail = &StackItem;
//    Stack_0.size = 0;
//    Stack = &Stack_0;
//
//    puts("Enter a string,q to quit:");
//    int8_t EnterString[MaxStringSize];
//
//    uint8_t Choice=0;
//    while(s_gets(EnterString,MaxStringSize) != NULL && EnterString[0] != 'q')
//    {
//        uint8_t i;
//        puts("what to do with your input,q to abandon this");
//        while((Choice = getchar()) != EOF && Choice != 'q')
//        {
//            if(Choice == '\n')
//                continue;
//            switch(Choice)
//            {
//                case 'i':   //init stack
//                    InitializeStack(Stack);
//                    break;
//                case 'f':   //if stack is full
//                    if(StackIsFull(Stack) == true)
//                        puts("Stack is full");
//                    else
//                        puts("stack is not full");
//                    break;
//                case 'e':   //if stack is empty
//                    if(StackIsEmpty(Stack) == true)
//                        puts("Stack is empty");
//                    else
//                        puts("stack is not empty");
//                    break;
//                case 'c':   //count item
//                    printf("There are %d items\n",StackItemCount(Stack));
//                    break;
//                case 'a':   //add item
//                    for(i=0;i<strlen(EnterString);i++)
//                    {
//                        StackItem.item.Character = EnterString[i];
//                        if(EnStack(StackItem.item,Stack) == true)
//                            puts("operation success");
//                        else
//                            puts("operation fail");
//                    }
//                   break;
//                case 'd':   //delete item
//                    if(DeStack(Stack) == true)
//                        puts("operation success");
//                    else
//                        puts("operation fail");
//                    break;
//                default:
//                    break;
//            }
//        }
//        puts("Enter a string,empty to quit:");
//        eatline();
//    }
//
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
//

/////////////////////////////////////////////
////////////////Practice 17.4///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h> // 提供 rand() 和 srand() 的原型
//#include <time.h> // 提供 time() 的原型
//#include "queue.h" // 更改 Item 的 typedef
//#define MIN_PER_HR 60.0
//bool newcustomer(double x); // 是否有新顾客到来？
//Item customertime(long when); // 设置顾客参数
//int main(void)
//{
//    Queue line;
//    Item temp; // 新的顾客数据
//    int hours; // 模拟的小时数
//    int perhour; // 每小时平均多少位顾客
//    long cycle, cyclelimit; // 循环计数器、计数器的上限
//    long turnaways = 0; // 因队列已满被拒的顾客数量
//    long customers = 0; // 加入队列的顾客数量
//    long served = 0; // 在模拟期间咨询过Sigmund的顾客数量
//    long sum_line = 0; // 累计的队列总长
//    int wait_time = 0; // 从当前到Sigmund空闲所需的时间
//    double min_per_cust; // 顾客到来的平均时间
//    long line_wait = 0; // 队列累计的等待时间
//    InitializeQueue(&line);
//    srand((unsigned int) time(0)); // rand() 随机初始化
//    puts("Case Study: Sigmund Lander's Advice Booth");
//    puts("Enter the number of simulation hours:");
//    scanf("%d", &hours);
//    cyclelimit = MIN_PER_HR * hours;
//    puts("Enter the average number of customers per hour:");
//    scanf("%d", &perhour);
//    min_per_cust = MIN_PER_HR / perhour;
//    for (cycle = 0; cycle < cyclelimit; cycle++)
//    {
//        if (newcustomer(min_per_cust))
//        {
//            if (QueueIsFull(&line))
//                turnaways++;
//            else
//            {
//                customers++;
//                temp = customertime(cycle);
//                EnQueue(temp, &line);
//            }
//        }
//        if (wait_time <= 0 && !QueueIsEmpty(&line))
//        {
//            DeQueue(&temp, &line);
//            wait_time = temp.processtime;
//            line_wait += cycle - temp.arrive;
//            served++;
//        }
//        if (wait_time > 0)
//            wait_time--;
//        sum_line += QueueItemCount(&line);
//    }
//    if (customers > 0)
//    {
//        printf("customers accepted: %ld\n", customers);
//        printf(" customers served: %ld\n", served);
//        printf(" turnaways: %ld\n", turnaways);
//        printf("average queue size: %.2f\n", (double) sum_line / cyclelimit);
//        printf(" average wait time: %.2f minutes\n", (double) line_wait / served);
//    }
//    else
//        puts("No customers!");
//    EmptyTheQueue(&line);
//    puts("Bye!");
//
//    return 0;
//}
//// x是顾客到来的平均时间（单位：分钟）
//// 如果1分钟内有顾客到来，则返回true
//bool newcustomer(double x)
//{
//    if (rand() * x / RAND_MAX < 1)
//        return true;
//    else
//        return false;
//}
//// when是顾客到来的时间
//// 该函数返回一个Item结构，该顾客到达的时间设置为when，
//// 咨询时间设置为1～3的随机值
//Item customertime(long when)
//{
//    Item cust;
//    cust.processtime = rand() % 3 + 1;
//    cust.arrive = when;
//    return cust;
//}


/////////////////////////////////////////////
////////////////Practice 17.3///////////////
///////////////////////////////////////////
///* films3.c -- 使用抽象数据类型（ADT）风格的链表 */
///* 与list.c一起编译 */
//#include <stdio.h>
//#include <stdlib.h> /* 提供exit()的原型 */
//#include "list_ForPractice17_3.h" /* 定义List、Item */
//#include <string.h>
//void showmovies(Item item);
//char * s_gets(char str[], int lim);
//int main(void)
//{
//    List movies;
//    Item temp; /* 初始化 */
//    InitializeList(&movies);
//    if (ListIsFull(&movies))
//    {
//        fprintf(stderr, "No memory available! Bye!\n");
//        exit(1);
//    }
//    /* 获取用户输入并储存 */
//    puts("Enter first movie title:");
//    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
//    {
//        puts("Enter your rating <0-10>:");
//        scanf("%d", &temp.rating);
//        while (getchar() != '\n')
//            continue;
//        if (AddItem(temp, &movies) == false)
//        {
//            fprintf(stderr, "Problem allocating memory\n");
//            break;
//        }
//        if (ListIsFull(&movies))
//        {
//            puts("The list is now full.");
//            break;
//        }
//        puts("Enter next movie title (empty line to stop):");
//    }
//    /* 显示 */
//    if (ListIsEmpty(&movies))
//        printf("No data entered. ");
//    else
//    {
//        printf("Here is the movie list:\n");
//        Traverse(&movies, showmovies);
//    }
//    printf("You entered %d movies.\n", ListItemCount(&movies));
//    /* 清理 */
//    EmptyTheList(&movies);
//    printf("Bye!\n");
//
//    return 0;
//}
//void showmovies(Item item)
//{
//    printf("Movie: %s Rating: %d\n", item.title, item.rating);
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
////////////////Practice 17.2///////////////
///////////////////////////////////////////
///* films3.c -- 使用抽象数据类型（ADT）风格的链表 */
///* 与list.c一起编译 */
//#include <stdio.h>
//#include <stdlib.h> /* 提供exit()的原型 */
//#include "list_ForPractice17_2.h" /* 定义List、Item */
//#include <string.h>
//void showmovies(Item item);
//char * s_gets(char str[], int lim);
//int main(void)
//{
//    List movies;
//    Item temp; /* 初始化 */
//    InitializeList(&movies);
//    if (ListIsFull(&movies))
//    {
//        fprintf(stderr, "No memory available! Bye!\n");
//        exit(1);
//    }
//    /* 获取用户输入并储存 */
//    puts("Enter first movie title:");
//    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
//    {
//        puts("Enter your rating <0-10>:");
//        scanf("%d", &temp.rating);
//        while (getchar() != '\n')
//            continue;
//        if (AddItem(temp, &movies) == false)
//        {
//            fprintf(stderr, "Problem allocating memory\n");
//            break;
//        }
//        if (ListIsFull(&movies))
//        {
//            puts("The list is now full.");
//            break;
//        }
//        puts("Enter next movie title (empty line to stop):");
//    }
//    /* 显示 */
//    if (ListIsEmpty(&movies))
//        printf("No data entered. ");
//    else
//    {
//        printf("Here is the movie list:\n");
//        Traverse(&movies, showmovies);
//    }
//    printf("You entered %d movies.\n", ListItemCount(&movies));
//    /* 清理 */
//    EmptyTheList(&movies);
//    printf("Bye!\n");
//
//    return 0;
//}
//void showmovies(Item item)
//{
//    printf("Movie: %s Rating: %d\n", item.title, item.rating);
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
///////////////////////////////////////////
//////////////Practice 17.1///////////////
/////////////////////////////////////////
///* films2.c -- 使用结构链表 */
//#include <stdio.h>
//#include <stdlib.h> /* 提供malloc()原型 */
//#include <string.h> /* 提供strcpy()原型 */
//#define TSIZE 45 /* 储存片名的数组大小 */
//struct film {
//    char title[TSIZE];
//    int rating;
//    struct film * next; /* 指向链表中的下一个结构 */
//    struct film * former; /* 指向链表中的上一个结构 */
//};
//char * s_gets(char str[], int lim);
//int main(void)
//{
//    struct film * head = NULL;
//    struct film * prev, *current;
//    char input[TSIZE];
//    /* 收集并储存信息 */
//    puts("Enter first movie title:");
//    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
//    {
//        current = (struct film *) malloc(sizeof(struct film));
//        if (head == NULL) /* 第1个结构 */
//        {
//            head = current;
//            head->former = NULL;
//        }
//        else /* 后续的结构 */
//        {
//            prev->next = current;
//            current->former = prev;
//        }
//        current->next = NULL;
//        strcpy(current->title, input);
//        puts("Enter your rating <0-10>:");
//        scanf("%d", &current->rating);
//        while (getchar() != '\n')
//            continue;
//        puts("Enter next movie title (empty line to stop):");
//        prev = current;
//    }
//    /* 显示电影列表 */
//    if (head == NULL)
//        printf("No data entered. ");
//    else
//        printf("Here is the movie list:\n");
//    current = head;
//    struct film * tail;
//    while (current != NULL)
//    {
//        tail=current;
//        printf("Movie: %s Rating: %d\n", current->title, current->rating);
//        current = current->next;
//    }
//    puts("Here is the movie list in inverted order:");
//    while (tail != NULL)
//    {
//        printf("Movie: %s Rating: %d\n", tail->title, tail->rating);
//        tail = tail->former;
//    }
//    /* 完成任务，释放已分配的内存 */
//    current = head;
//    while (current != NULL && head != NULL)
//    {
//        current = head;
//        head = current->next;
//        free(current);
//    }
//    printf("Bye!\n");
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






/*
/////////////////////////////////////////////
///////////////////FuXiTi //////////////////
///////////////////////////////////////////

1.
属性和操作

2.
//struct film {
//    char title[TSIZE];
//    int rating;
//    struct film * former; /* 指向链表中的上一个结构 */
//    struct film * next; /* 指向链表中的下一个结构 */
//};
/*
//3.
//提供类型属性和相关操作的抽象描述。这些描述既不能依赖特定的实 现，也不能依赖特定的编程语言
//
//4.
//
//5.
//a.设计一个栈ADT
//类型名： 栈
//类型属性： 可以储存一系列项
//类型操作：
//    初始化栈为空
//    确定栈为空
//    确定栈已满
//    确定栈中的项数
//    在栈末尾添加项
//    遍历栈，处理栈中的项，只能一项一项的查找栈尾
//    清空栈，一项项的删除栈尾
//b.为栈设计一个C编程接口，例如stack.h头文件
//见stack.h
//
//6.
//顺序查找最多需要3次
//二叉查找方法最多需要2次
//有1023个项时，顺序查找最多需要1023次，二叉查找方法最多需要10次
//65535个项，顺序查找最多需要65535次，二叉查找方法最多需要17次
//
//7.
//a.
//                  nice
//
//        food				    roam
//dodge		  gate		office		   wave
//
//
//b.
//							wave
//					roam
//				office
//			nice
//		gate
//	food
//dodge
//
//
//c.
//		food
//dodge						roam
//					office		wave
//    gate
//                        nice
//
//
//d.
//                    nice
//        food				        roam
//dodge		   gate		    office		   wave
//
//
//
//8.
//a.
//                  nice
//
//        dodge				    roam
//		    gate		office		   wave
//
//
//b.
//							wave
//					roam
//				office
//			nice
//		gate
//	dodge
//
//c.
//		dodge
//						   roam
//					office		wave
//			gate
//				nice
//
//d.
//                    nice
//        dodge				            roam
//                gate		    office		   wave
//
//

*/


/////////////////////////////////////////////
////////////////QingDan 17.12///////////////
///////////////////////////////////////////
//
//
///* petclub.c -- 使用二叉查找数 */
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#include "tree.h"
//
//char menu(void);
//void addpet(Tree * pt);
//void droppet(Tree * pt);
//void showpets(const Tree * pt);
//void findpet(const Tree * pt);
//void printitem(Item item);
//void uppercase(char * str);
//char * s_gets(char * st, int n);
//int main(void)
//{
//    Tree pets;
//    char choice;
//    InitializeTree(&pets);
//    while ((choice = menu()) != 'q')
//    {
//        switch (choice)
//        {
//            case 'a':
//                addpet(&pets);
//                break;
//            case 'l':
//                showpets(&pets);
//                break;
//            case 'f':
//                findpet(&pets);
//                break;
//            case 'n':
//                printf("%d pets in club\n", TreeItemCount(&pets));
//                break;
//            case 'd':
//                droppet(&pets);
//                break;
//            default:
//                puts("Switching error");
//        }
//    }
//    DeleteAll(&pets);
//    puts("Bye.");
//
//    return 0;
//}
//char menu(void)
//{
//    int ch;
//    puts("Nerfville Pet Club Membership Program");
//    puts("Enter the letter corresponding to your choice:");
//    puts("a) add a pet l) show list of pets");
//    puts("n) number of pets f) find pets");
//    puts("d) delete a pet q) quit");
//    while ((ch = getchar()) != EOF)
//    {
//        while (getchar() != '\n') /* 处理输入行的剩余内容 */
//            continue;
//        ch = tolower(ch);
//        if (strchr("alrfndq", ch) == NULL)
//            puts("Please enter an a, l, f, n, d, or q:");
//        else
//            break;
//    }
//    if (ch == EOF) /* 使程序退出 */
//    ch = 'q';
//    return ch;
//}
//void addpet(Tree * pt)
//{
//    Item temp;
//    if (TreeIsFull(pt))
//        puts("No room in the club!");
//    else
//    {
//        puts("Please enter name of pet:");
//        s_gets(temp.petname, SLEN);
//        puts("Please enter pet kind:");
//        s_gets(temp.petkind, SLEN);
//        uppercase(temp.petname);
//        uppercase(temp.petkind);
//        AddItem(&temp, pt);
//    }
//}
//void showpets(const Tree * pt)
//{
//    if (TreeIsEmpty(pt))
//        puts("No entries!");
//    else
//        Traverse(pt, printitem);
//}
//void printitem(Item item)
//{
//    printf("Pet: %-19s Kind: %-19s\n", item.petname,item.petkind);
//}
//void findpet(const Tree * pt)
//{
//    Item temp;
//    if (TreeIsEmpty(pt))
//    {
//        puts("No entries!");
//        return; /* 如果树为空，则退出该函数 */
//    }
//    puts("Please enter name of pet you wish to find:");
//    s_gets(temp.petname, SLEN);
//    puts("Please enter pet kind:");
//    s_gets(temp.petkind, SLEN);
//    uppercase(temp.petname);
//    uppercase(temp.petkind);
//    printf("%s the %s ", temp.petname, temp.petkind);
//    if (InTree(&temp, pt))
//        printf("is a member.\n");
//    else
//        printf("is not a member.\n");
//}
//void droppet(Tree * pt)
//{
//    Item temp;
//    if (TreeIsEmpty(pt))
//    {
//        puts("No entries!");
//        return; /* 如果树为空，则退出该函数 */
//    }
//    puts("Please enter name of pet you wish to delete:");
//    s_gets(temp.petname, SLEN);
//    puts("Please enter pet kind:");
//    s_gets(temp.petkind, SLEN);
//    uppercase(temp.petname);
//    uppercase(temp.petkind);
//    printf("%s the %s ", temp.petname, temp.petkind);
//    if (DeleteItem(&temp, pt))
//        printf("is dropped from the club.\n");
//    else
//        printf("is not a member.\n");
//}
//void uppercase(char * str)
//{
//    while (*str)
//    {
//        *str = toupper(*str);
//        str++;
//    }
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
////////////////QingDan 17.9///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h> // 提供 rand() 和 srand() 的原型
//#include <time.h> // 提供 time() 的原型
//#include "queue.h" // 更改 Item 的 typedef
//#define MIN_PER_HR 60.0
//bool newcustomer(double x); // 是否有新顾客到来？
//Item customertime(long when); // 设置顾客参数
//int main(void)
//{
//    Queue line;
//    Item temp; // 新的顾客数据
//    int hours; // 模拟的小时数
//    int perhour; // 每小时平均多少位顾客
//    long cycle, cyclelimit; // 循环计数器、计数器的上限
//    long turnaways = 0; // 因队列已满被拒的顾客数量
//    long customers = 0; // 加入队列的顾客数量
//    long served = 0; // 在模拟期间咨询过Sigmund的顾客数量
//    long sum_line = 0; // 累计的队列总长
//    int wait_time = 0; // 从当前到Sigmund空闲所需的时间
//    double min_per_cust; // 顾客到来的平均时间
//    long line_wait = 0; // 队列累计的等待时间
//    InitializeQueue(&line);
//    srand((unsigned int) time(0)); // rand() 随机初始化
//    puts("Case Study: Sigmund Lander's Advice Booth");
//    puts("Enter the number of simulation hours:");
//    scanf("%d", &hours);
//    cyclelimit = MIN_PER_HR * hours;
//    puts("Enter the average number of customers per hour:");
//    scanf("%d", &perhour);
//    min_per_cust = MIN_PER_HR / perhour;
//    for (cycle = 0; cycle < cyclelimit; cycle++)
//    {
//        if (newcustomer(min_per_cust))
//        {
//            if (QueueIsFull(&line))
//                turnaways++;
//            else
//            {
//                customers++;
//                temp = customertime(cycle);
//                EnQueue(temp, &line);
//            }
//        }
//        if (wait_time <= 0 && !QueueIsEmpty(&line))
//        {
//            DeQueue(&temp, &line);
//            wait_time = temp.processtime;
//            line_wait += cycle - temp.arrive;
//            served++;
//        }
//        if (wait_time > 0)
//            wait_time--;
//        sum_line += QueueItemCount(&line);
//    }
//    if (customers > 0)
//    {
//        printf("customers accepted: %ld\n", customers);
//        printf(" customers served: %ld\n", served);
//        printf(" turnaways: %ld\n", turnaways);
//        printf("average queue size: %.2f\n", (double) sum_line / cyclelimit);
//        printf(" average wait time: %.2f minutes\n", (double) line_wait / served);
//    }
//    else
//        puts("No customers!");
//    EmptyTheQueue(&line);
//    puts("Bye!");
//
//    return 0;
//}
//// x是顾客到来的平均时间（单位：分钟）
//// 如果1分钟内有顾客到来，则返回true
//bool newcustomer(double x)
//{
//    if (rand() * x / RAND_MAX < 1)
//        return true;
//    else
//        return false;
//}
//// when是顾客到来的时间
//// 该函数返回一个Item结构，该顾客到达的时间设置为when，
//// 咨询时间设置为1～3的随机值
//Item customertime(long when)
//{
//    Item cust;
//    cust.processtime = rand() % 3 + 1;
//    cust.arrive = when;
//    return cust;
//}


/////////////////////////////////////////////
////////////////QingDan 17.8///////////////
///////////////////////////////////////////
//
///* use_q.c -- 驱动程序测试 Queue 接口 */
///* 与 queue.c 一起编译 */
//#include <stdio.h>
//#include "queue.h" /* 定义Queue、Item */
//int main(void)
//{
//    Queue line;
//    Item temp;
//    char ch;
//    InitializeQueue(&line);
//    puts("Testing the Queue interface. Type a to add a value,");
//    puts("type d to delete a value, and type q to quit.");
//    while ((ch = getchar()) != 'q')
//    {
//        if (ch != 'a' && ch != 'd') /* 忽略其他输出 */
//            continue;
//        if (ch == 'a')
//        {
//            printf("Integer to add: ");
//            scanf("%d", &temp);
//            if (!QueueIsFull(&line))
//            {
//                printf("Putting %d into queue\n", temp);
//                EnQueue(temp, &line);
//            }
//            else
//                puts("Queue is full!");
//        }
//        else
//        {
//            if (QueueIsEmpty(&line))
//                puts("Nothing to delete!");
//            else
//            {
//                DeQueue(&temp, &line);
//                printf("Removing %d from queue\n", temp);
//            }
//        }
//        printf("%d items in queue\n", QueueItemCount(&line));
//        puts("Type a to add, d to delete, q to quit:");
//    }
//    EmptyTheQueue(&line);
//    puts("Bye!");
//    return 0;
//}



/////////////////////////////////////////////
////////////////QingDan 17.4///////////////
///////////////////////////////////////////
//
//
///* films3.c -- 使用抽象数据类型（ADT）风格的链表 */
///* 与list.c一起编译 */
//#include <stdio.h>
//#include <stdlib.h> /* 提供exit()的原型 */
//#include "list.h" /* 定义List、Item */
//#include <string.h>
//void showmovies(Item item);
//char * s_gets(char str[], int lim);
//int main(void)
//{
//    List movies;
//    Item temp; /* 初始化 */
//    InitializeList(&movies);
//    if (ListIsFull(&movies))
//    {
//        fprintf(stderr, "No memory available! Bye!\n");
//        exit(1);
//    }
//    /* 获取用户输入并储存 */
//    puts("Enter first movie title:");
//    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
//    {
//        puts("Enter your rating <0-10>:");
//        scanf("%d", &temp.rating);
//        while (getchar() != '\n')
//            continue;
//        if (AddItem(temp, &movies) == false)
//        {
//            fprintf(stderr, "Problem allocating memory\n");
//            break;
//        }
//        if (ListIsFull(&movies))
//        {
//            puts("The list is now full.");
//            break;
//        }
//        puts("Enter next movie title (empty line to stop):");
//    }
//    /* 显示 */
//    if (ListIsEmpty(&movies))
//        printf("No data entered. ");
//    else
//    {
//        printf("Here is the movie list:\n");
//        Traverse(&movies, showmovies);
//    }
//    printf("You entered %d movies.\n", ListItemCount(&movies));
//    /* 清理 */
//    EmptyTheList(&movies);
//    printf("Bye!\n");
//
//    return 0;
//}
//void showmovies(Item item)
//{
//    printf("Movie: %s Rating: %d\n", item.title, item.rating);
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




/////////////////////////////////////////////
////////////////QingDan 17.2///////////////
///////////////////////////////////////////
///* films2.c -- 使用结构链表 */
//#include <stdio.h>
//#include <stdlib.h> /* 提供malloc()原型 */
//#include <string.h> /* 提供strcpy()原型 */
//#define TSIZE 45 /* 储存片名的数组大小 */
//struct film {
//    char title[TSIZE];
//    int rating;
//    struct film * next; /* 指向链表中的下一个结构 */
//};
//char * s_gets(char str[], int lim);
//int main(void)
//{
//    struct film * head = NULL;
//    struct film * prev, *current;
//    char input[TSIZE];
//    /* 收集并储存信息 */
//    puts("Enter first movie title:");
//    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
//    {
//        current = (struct film *) malloc(sizeof(struct film));
//        if (head == NULL) /* 第1个结构 */
//            head = current;
//        else /* 后续的结构 */
//            prev->next = current;
//        current->next = NULL;
//        strcpy(current->title, input);
//        puts("Enter your rating <0-10>:");
//        scanf("%d", &current->rating);
//        while (getchar() != '\n')
//            continue;
//        puts("Enter next movie title (empty line to stop):");
//        prev = current;
//    }
//    /* 显示电影列表 */
//    if (head == NULL)
//        printf("No data entered. ");
//    else
//        printf("Here is the movie list:\n");
//    current = head;
//    while (current != NULL)
//    {
//        printf("Movie: %s Rating: %d\n", current->title, current->rating);
//        current = current->next;
//    }
//    /* 完成任务，释放已分配的内存 */
//    current = head;
//    while (current != NULL && head != NULL)
//    {
//        current = head;
//        head = current->next;
//        free(current);
//    }
//    printf("Bye!\n");
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


/////////////////////////////////////////////
////////////////QingDan 17.1///////////////
///////////////////////////////////////////
///* films1.c -- 使用一个结构数组 */
//#include <stdio.h>
//#include <string.h>
//#define TSIZE 45 /* 储存片名的数组大小 */
//#define FMAX 5 /* 影片的最大数量 */
//struct film {
//    char title[TSIZE];
//    int rating;
//};
//char * s_gets(char str[], int lim);
//int main(void)
//{
//    struct film movies[FMAX];
//    int i = 0;
//    int j;
//    puts("Enter first movie title:");
//    while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL &&
//           movies[i].title[0] != '\0')
//    {
//        puts("Enter your rating <0-10>:");
//        scanf("%d", &movies[i++].rating);
//        while (getchar() != '\n')
//            continue;
//        puts("Enter next movie title (empty line to stop):");
//    }
//    if (i == 0)
//        printf("No data entered. ");
//    else
//        printf("Here is the movie list:\n");
//    for (j = 0; j < i; j++)
//        printf("Movie: %s Rating: %d\n", movies[j].title,movies[j].rating);
//    printf("Bye!\n");
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



