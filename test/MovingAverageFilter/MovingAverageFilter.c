#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


#define SIZE_WINDOW 10

// 定义滑动平均滤波器结构体
typedef struct {
    int32_t size;          // 缓冲区大小
    int32_t index;         // 当前缓冲区索引
    int64_t sum;           // 当前所有元素的总和
    int32_t buffer[SIZE_WINDOW];    // 数据缓冲区
} MovingAverageFilter;

// 初始化滑动平均滤波器
void initMovingAverageFilter(MovingAverageFilter *filter, int32_t size, int32_t initValue) {
    int32_t i = 0;

    filter->size = size;
    filter->index = 0;
    filter->sum = 0;
    for (i = 0; i < size; i++) {
        filter->buffer[i] = initValue;
        filter->sum += filter->buffer[i];
    }
}

// 更新滑动平均滤波器并获取过滤后的值
int32_t updateMovingAverageFilter(MovingAverageFilter *filter, int32_t newValue) {
    // 从总和中减去即将被替换的旧值
    filter->sum -= filter->buffer[filter->index];

    // 将新值添加到缓冲区
    filter->buffer[filter->index] = newValue;

    // 更新总和
    filter->sum += newValue;

    // 更新索引，使用模运算实现环形缓冲区
    filter->index = (filter->index + 1) % filter->size;

    // 返回平均值
    return filter->sum / filter->size;
}

const char delimChar = '\n';

int srcResultIg[4000];
int i;
int main()
{
    FILE *file;
    char line[100];
    char *token;
//    char *filename = "./Ig_average-100ms-268.036na-1.log";
//    char *filename = "./Ig_average-100ms-270.383na-2.log";
//    char *filename = "./Ig_average-100ms-270.383na-3.log";
//    char *filename = "./Ig_average-100ms-260.126na-4.log";
    char *filename = "./Ig_average-100ms-261.191na-5.log";

    file = fopen(filename, "r");
    if (file == NULL) {
//        printf("Error opening file.\n");
        perror("Error opening file.\n");
        return 1;
    }

    i = 0;
    while (fgets(line, sizeof(line), file)) {
        if(i < 4000){
          srcResultIg[i] = atoi(line);
          printf("%d\n", srcResultIg[i]);
          i += 1;
        }



//        token = strtok(line, &delimChar);
//        while (token != NULL) {
////            printf("%s\n", token);
//            token = strtok(NULL, &delimChar);
//            if(i < 4000){
//              srcResultIg[i] = atoi(token);
//              printf("%d\n", srcResultIg[i]);
//              i += 1;
//            }
//
//        }
    }

    fclose(file);



/*开始过滤**********************************************************************************************/


    int32_t totalIg = 0;
    MovingAverageFilter myFilter;
    initMovingAverageFilter(&myFilter, SIZE_WINDOW,srcResultIg[0]);
    for(i = 0; i < 4000; i++){
      totalIg += updateMovingAverageFilter(&myFilter, srcResultIg[i]);
    }
    totalIg = ((totalIg/4000)*(-5563)+(-57575))>>6;

    printf("final Ig = %d\n",totalIg);








    printf("hello\n");

    printf("press ctrl+z to quit\n");
    while(getchar() != EOF){

    }


    return 0;
}
