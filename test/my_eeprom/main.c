#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define PAGE_SIZE 256
#define PAGE_NUM 512

uint8_t simu_eeprom[PAGE_SIZE*PAGE_NUM];

typedef struct{


}_BLOCK_LIST_;


int main(void)
{
  uint16_t i = 0;

  for(i = 0; i < PAGE_NUM*PAGE_SIZE; i++){
    simu_eeprom[i] = 0xFF;
  }







  printf("/n/nHello world!\n");


  return 0;
}



static void m24m01_write_buf(uint32_t RegAddr, uint8_t *DataWR, uint16_t len)
{

}

static void m24m01_read_buf(uint32_t RegAddr, uint8_t * Data,uint16_t len)
{

}






















