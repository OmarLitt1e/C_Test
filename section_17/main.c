///////////////////////////////////////////
//////////////QingDan 17.8///////////////
/////////////////////////////////////////

/* use_q.c -- ����������� Queue �ӿ� */
/* �� queue.c һ����� */
#include <stdio.h>
#include "queue.h" /* ����Queue��Item */
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
        if (ch != 'a' && ch != 'd') /* ����������� */
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
//#include <stdlib.h> // �ṩ rand() �� srand() ��ԭ��
//#include <time.h> // �ṩ time() ��ԭ��
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
//        find = strchr(st, '\n'); // ���һ��з�
//        if (find) // �����ַ���� NULL,
//            *find = '\0'; // �ڴ˴�����һ�����ַ�
//        else
//            while (getchar() != '\n')
//                continue; // ���������е�ʣ���ַ�
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
//#include <stdlib.h> // �ṩ rand() �� srand() ��ԭ��
//#include <time.h> // �ṩ time() ��ԭ��
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
//        find = strchr(st, '\n'); // ���һ��з�
//        if (find) // �����ַ���� NULL,
//            *find = '\0'; // �ڴ˴�����һ�����ַ�
//        else
//            while (getchar() != '\n')
//                continue; // ���������е�ʣ���ַ�
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
//#include <stdlib.h> // �ṩ rand() �� srand() ��ԭ��
//#include <time.h> // �ṩ time() ��ԭ��
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
//        find = strchr(st, '\n'); // ���һ��з�
//        if (find) // �����ַ���� NULL,
//            *find = '\0'; // �ڴ˴�����һ�����ַ�
//        else
//            while (getchar() != '\n')
//                continue; // ���������е�ʣ���ַ�
//    }
//    return ret_val;
//}
//

/////////////////////////////////////////////
////////////////Practice 17.4///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h> // �ṩ rand() �� srand() ��ԭ��
//#include <time.h> // �ṩ time() ��ԭ��
//#include "queue.h" // ���� Item �� typedef
//#define MIN_PER_HR 60.0
//bool newcustomer(double x); // �Ƿ����¹˿͵�����
//Item customertime(long when); // ���ù˿Ͳ���
//int main(void)
//{
//    Queue line;
//    Item temp; // �µĹ˿�����
//    int hours; // ģ���Сʱ��
//    int perhour; // ÿСʱƽ������λ�˿�
//    long cycle, cyclelimit; // ѭ����������������������
//    long turnaways = 0; // ������������ܵĹ˿�����
//    long customers = 0; // ������еĹ˿�����
//    long served = 0; // ��ģ���ڼ���ѯ��Sigmund�Ĺ˿�����
//    long sum_line = 0; // �ۼƵĶ����ܳ�
//    int wait_time = 0; // �ӵ�ǰ��Sigmund���������ʱ��
//    double min_per_cust; // �˿͵�����ƽ��ʱ��
//    long line_wait = 0; // �����ۼƵĵȴ�ʱ��
//    InitializeQueue(&line);
//    srand((unsigned int) time(0)); // rand() �����ʼ��
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
//// x�ǹ˿͵�����ƽ��ʱ�䣨��λ�����ӣ�
//// ���1�������й˿͵������򷵻�true
//bool newcustomer(double x)
//{
//    if (rand() * x / RAND_MAX < 1)
//        return true;
//    else
//        return false;
//}
//// when�ǹ˿͵�����ʱ��
//// �ú�������һ��Item�ṹ���ù˿͵����ʱ������Ϊwhen��
//// ��ѯʱ������Ϊ1��3�����ֵ
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
///* films3.c -- ʹ�ó����������ͣ�ADT���������� */
///* ��list.cһ����� */
//#include <stdio.h>
//#include <stdlib.h> /* �ṩexit()��ԭ�� */
//#include "list_ForPractice17_3.h" /* ����List��Item */
//#include <string.h>
//void showmovies(Item item);
//char * s_gets(char str[], int lim);
//int main(void)
//{
//    List movies;
//    Item temp; /* ��ʼ�� */
//    InitializeList(&movies);
//    if (ListIsFull(&movies))
//    {
//        fprintf(stderr, "No memory available! Bye!\n");
//        exit(1);
//    }
//    /* ��ȡ�û����벢���� */
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
//    /* ��ʾ */
//    if (ListIsEmpty(&movies))
//        printf("No data entered. ");
//    else
//    {
//        printf("Here is the movie list:\n");
//        Traverse(&movies, showmovies);
//    }
//    printf("You entered %d movies.\n", ListItemCount(&movies));
//    /* ���� */
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
//        find = strchr(st, '\n'); // ���һ��з�
//        if (find) // �����ַ���� NULL,
//            *find = '\0'; // �ڴ˴�����һ�����ַ�
//        else
//            while (getchar() != '\n')
//                continue; // ���������е�ʣ���ַ�
//    }
//    return ret_val;
//}
//



/////////////////////////////////////////////
////////////////Practice 17.2///////////////
///////////////////////////////////////////
///* films3.c -- ʹ�ó����������ͣ�ADT���������� */
///* ��list.cһ����� */
//#include <stdio.h>
//#include <stdlib.h> /* �ṩexit()��ԭ�� */
//#include "list_ForPractice17_2.h" /* ����List��Item */
//#include <string.h>
//void showmovies(Item item);
//char * s_gets(char str[], int lim);
//int main(void)
//{
//    List movies;
//    Item temp; /* ��ʼ�� */
//    InitializeList(&movies);
//    if (ListIsFull(&movies))
//    {
//        fprintf(stderr, "No memory available! Bye!\n");
//        exit(1);
//    }
//    /* ��ȡ�û����벢���� */
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
//    /* ��ʾ */
//    if (ListIsEmpty(&movies))
//        printf("No data entered. ");
//    else
//    {
//        printf("Here is the movie list:\n");
//        Traverse(&movies, showmovies);
//    }
//    printf("You entered %d movies.\n", ListItemCount(&movies));
//    /* ���� */
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
//        find = strchr(st, '\n'); // ���һ��з�
//        if (find) // �����ַ���� NULL,
//            *find = '\0'; // �ڴ˴�����һ�����ַ�
//        else
//            while (getchar() != '\n')
//                continue; // ���������е�ʣ���ַ�
//    }
//    return ret_val;
//}
//
///////////////////////////////////////////
//////////////Practice 17.1///////////////
/////////////////////////////////////////
///* films2.c -- ʹ�ýṹ���� */
//#include <stdio.h>
//#include <stdlib.h> /* �ṩmalloc()ԭ�� */
//#include <string.h> /* �ṩstrcpy()ԭ�� */
//#define TSIZE 45 /* ����Ƭ���������С */
//struct film {
//    char title[TSIZE];
//    int rating;
//    struct film * next; /* ָ�������е���һ���ṹ */
//    struct film * former; /* ָ�������е���һ���ṹ */
//};
//char * s_gets(char str[], int lim);
//int main(void)
//{
//    struct film * head = NULL;
//    struct film * prev, *current;
//    char input[TSIZE];
//    /* �ռ���������Ϣ */
//    puts("Enter first movie title:");
//    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
//    {
//        current = (struct film *) malloc(sizeof(struct film));
//        if (head == NULL) /* ��1���ṹ */
//        {
//            head = current;
//            head->former = NULL;
//        }
//        else /* �����Ľṹ */
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
//    /* ��ʾ��Ӱ�б� */
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
//    /* ��������ͷ��ѷ�����ڴ� */
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
//        find = strchr(st, '\n'); // ���һ��з�
//        if (find) // �����ַ���� NULL,
//            *find = '\0'; // �ڴ˴�����һ�����ַ�
//        else
//            while (getchar() != '\n')
//                continue; // ���������е�ʣ���ַ�
//    }
//    return ret_val;
//}






/*
/////////////////////////////////////////////
///////////////////FuXiTi //////////////////
///////////////////////////////////////////

1.
���ԺͲ���

2.
//struct film {
//    char title[TSIZE];
//    int rating;
//    struct film * former; /* ָ�������е���һ���ṹ */
//    struct film * next; /* ָ�������е���һ���ṹ */
//};
/*
//3.
//�ṩ�������Ժ���ز����ĳ�����������Щ�����Ȳ��������ض���ʵ �֣�Ҳ���������ض��ı������
//
//4.
//
//5.
//a.���һ��ջADT
//�������� ջ
//�������ԣ� ���Դ���һϵ����
//���Ͳ�����
//    ��ʼ��ջΪ��
//    ȷ��ջΪ��
//    ȷ��ջ����
//    ȷ��ջ�е�����
//    ��ջĩβ�����
//    ����ջ������ջ�е��ֻ��һ��һ��Ĳ���ջβ
//    ���ջ��һ�����ɾ��ջβ
//b.Ϊջ���һ��C��̽ӿڣ�����stack.hͷ�ļ�
//��stack.h
//
//6.
//˳����������Ҫ3��
//������ҷ��������Ҫ2��
//��1023����ʱ��˳����������Ҫ1023�Σ�������ҷ��������Ҫ10��
//65535���˳����������Ҫ65535�Σ�������ҷ��������Ҫ17��
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
///* petclub.c -- ʹ�ö�������� */
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
//        while (getchar() != '\n') /* ���������е�ʣ������ */
//            continue;
//        ch = tolower(ch);
//        if (strchr("alrfndq", ch) == NULL)
//            puts("Please enter an a, l, f, n, d, or q:");
//        else
//            break;
//    }
//    if (ch == EOF) /* ʹ�����˳� */
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
//        return; /* �����Ϊ�գ����˳��ú��� */
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
//        return; /* �����Ϊ�գ����˳��ú��� */
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
//        find = strchr(st, '\n'); // ���һ��з�
//        if (find) // �����ַ���� NULL,
//            *find = '\0'; // �ڴ˴�����һ�����ַ�
//        else
//            while (getchar() != '\n')
//                continue; // ���������е�ʣ���ַ�
//    }
//    return ret_val;
//}
//
/////////////////////////////////////////////
////////////////QingDan 17.9///////////////
///////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h> // �ṩ rand() �� srand() ��ԭ��
//#include <time.h> // �ṩ time() ��ԭ��
//#include "queue.h" // ���� Item �� typedef
//#define MIN_PER_HR 60.0
//bool newcustomer(double x); // �Ƿ����¹˿͵�����
//Item customertime(long when); // ���ù˿Ͳ���
//int main(void)
//{
//    Queue line;
//    Item temp; // �µĹ˿�����
//    int hours; // ģ���Сʱ��
//    int perhour; // ÿСʱƽ������λ�˿�
//    long cycle, cyclelimit; // ѭ����������������������
//    long turnaways = 0; // ������������ܵĹ˿�����
//    long customers = 0; // ������еĹ˿�����
//    long served = 0; // ��ģ���ڼ���ѯ��Sigmund�Ĺ˿�����
//    long sum_line = 0; // �ۼƵĶ����ܳ�
//    int wait_time = 0; // �ӵ�ǰ��Sigmund���������ʱ��
//    double min_per_cust; // �˿͵�����ƽ��ʱ��
//    long line_wait = 0; // �����ۼƵĵȴ�ʱ��
//    InitializeQueue(&line);
//    srand((unsigned int) time(0)); // rand() �����ʼ��
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
//// x�ǹ˿͵�����ƽ��ʱ�䣨��λ�����ӣ�
//// ���1�������й˿͵������򷵻�true
//bool newcustomer(double x)
//{
//    if (rand() * x / RAND_MAX < 1)
//        return true;
//    else
//        return false;
//}
//// when�ǹ˿͵�����ʱ��
//// �ú�������һ��Item�ṹ���ù˿͵����ʱ������Ϊwhen��
//// ��ѯʱ������Ϊ1��3�����ֵ
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
///* use_q.c -- ����������� Queue �ӿ� */
///* �� queue.c һ����� */
//#include <stdio.h>
//#include "queue.h" /* ����Queue��Item */
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
//        if (ch != 'a' && ch != 'd') /* ����������� */
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
///* films3.c -- ʹ�ó����������ͣ�ADT���������� */
///* ��list.cһ����� */
//#include <stdio.h>
//#include <stdlib.h> /* �ṩexit()��ԭ�� */
//#include "list.h" /* ����List��Item */
//#include <string.h>
//void showmovies(Item item);
//char * s_gets(char str[], int lim);
//int main(void)
//{
//    List movies;
//    Item temp; /* ��ʼ�� */
//    InitializeList(&movies);
//    if (ListIsFull(&movies))
//    {
//        fprintf(stderr, "No memory available! Bye!\n");
//        exit(1);
//    }
//    /* ��ȡ�û����벢���� */
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
//    /* ��ʾ */
//    if (ListIsEmpty(&movies))
//        printf("No data entered. ");
//    else
//    {
//        printf("Here is the movie list:\n");
//        Traverse(&movies, showmovies);
//    }
//    printf("You entered %d movies.\n", ListItemCount(&movies));
//    /* ���� */
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
//        find = strchr(st, '\n'); // ���һ��з�
//        if (find) // �����ַ���� NULL,
//            *find = '\0'; // �ڴ˴�����һ�����ַ�
//        else
//            while (getchar() != '\n')
//                continue; // ���������е�ʣ���ַ�
//    }
//    return ret_val;
//}




/////////////////////////////////////////////
////////////////QingDan 17.2///////////////
///////////////////////////////////////////
///* films2.c -- ʹ�ýṹ���� */
//#include <stdio.h>
//#include <stdlib.h> /* �ṩmalloc()ԭ�� */
//#include <string.h> /* �ṩstrcpy()ԭ�� */
//#define TSIZE 45 /* ����Ƭ���������С */
//struct film {
//    char title[TSIZE];
//    int rating;
//    struct film * next; /* ָ�������е���һ���ṹ */
//};
//char * s_gets(char str[], int lim);
//int main(void)
//{
//    struct film * head = NULL;
//    struct film * prev, *current;
//    char input[TSIZE];
//    /* �ռ���������Ϣ */
//    puts("Enter first movie title:");
//    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
//    {
//        current = (struct film *) malloc(sizeof(struct film));
//        if (head == NULL) /* ��1���ṹ */
//            head = current;
//        else /* �����Ľṹ */
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
//    /* ��ʾ��Ӱ�б� */
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
//    /* ��������ͷ��ѷ�����ڴ� */
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
//        find = strchr(st, '\n'); // ���һ��з�
//        if (find) // �����ַ���� NULL,
//            *find = '\0'; // �ڴ˴�����һ�����ַ�
//        else
//            while (getchar() != '\n')
//                continue; // ���������е�ʣ���ַ�
//    }
//    return ret_val;
//}


/////////////////////////////////////////////
////////////////QingDan 17.1///////////////
///////////////////////////////////////////
///* films1.c -- ʹ��һ���ṹ���� */
//#include <stdio.h>
//#include <string.h>
//#define TSIZE 45 /* ����Ƭ���������С */
//#define FMAX 5 /* ӰƬ��������� */
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
//        find = strchr(st, '\n'); // ���һ��з�
//        if (find) // �����ַ���� NULL,
//            *find = '\0'; // �ڴ˴�����һ�����ַ�
//        else
//            while (getchar() != '\n')
//                continue; // ���������е�ʣ���ַ�
//    }
//    return ret_val;
//}



