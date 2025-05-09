#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int32_t tempArray[1024];
int32_t Ig[1024];

static int32_t compare(const void *a, const void *b) {
  return (*(int32_t*)a - *(int32_t*)b);
}

// 计算去除最大值和最小值后的平均值
int32_t calculate_average(int32_t array[], int32_t size, int32_t remove_count) {
  // 检查数组大小是否足够
  if (size <= 2 * remove_count) {
      return 0;
  }

  // 排序数组
  qsort(array, size, sizeof(int32_t), compare);

  // 去除前 remove_count 个最小值和后 remove_count 个最大值，计算剩余元素的和
  int64_t sum = 0;  // 使用 int64_t 防止溢出
  for (int i = remove_count; i < size - remove_count; i++) {
      sum += array[i];
  }

  // 计算平均值（转换为 int32_t）
  return (int32_t)(sum / (size - 2 * remove_count));
}

static uint16_t windowSize = 60;
static uint32_t waveSS_ON = 0, waveSS_OFF = 1009;
int32_t tmpIg = 0;
int main()
{



    memset(tempArray, 0x00, sizeof(tempArray));
    memcpy(&tempArray[0], &Ig[waveSS_OFF-windowSize-1], windowSize*4);
    tmpIg = calculate_average(tempArray, windowSize, 10);



    printf("Hello world!\n");


  return 0;
}










