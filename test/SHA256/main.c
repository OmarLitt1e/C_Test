#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "sha2.h"


uint8_t MyUInt8RingShift(uint8_t src, uint8_t ShiftNum, uint8_t LeftOrRight);

uint8_t FixKey[16];
uint8_t myRandom[16];
uint8_t SHA256_Src[32];
uint8_t SHA256_Eigen1[32];
uint8_t SHA256_Eigen2[32];
uint8_t SHA256_Eigen3[32];
int main()
{
  int i = 0;

  memset(SHA256_Eigen1,0x00,sizeof(SHA256_Eigen1));
  memset(SHA256_Eigen2,0x00,sizeof(SHA256_Eigen2));

  srand(1);

  puts("\nFixKey:");
  for(i = 0; i < 16; i++){
    FixKey[i] = i;
    printf("%0#4x ",FixKey[i]);
  }
  FixKey[0] = 100;
  memcpy(SHA256_Src,FixKey,16);


  puts("\nmyRandom:");
  for(i = 0; i < 16; i++){
    myRandom[i] = rand()%UINT8_MAX;
    printf("%0#4x ",myRandom[i]);
  }
  memcpy(&SHA256_Src[0]+16,myRandom,16);


  sha2(SHA256_Src,sizeof(SHA256_Src),SHA256_Eigen1,0);
  puts("\nSHA256_Eigen1:");
  for(i = 0; i < 32; i++){
    printf("%0#4x ",SHA256_Eigen1[i]);
  }

  puts("\nSHA256_Eigen2:");
  uint8_t ShiftNum = SHA256_Eigen1[0];
  for(i = 0; i < 32; i++){
    SHA256_Eigen2[i] = MyUInt8RingShift(SHA256_Eigen1[i],ShiftNum,0);
    printf("%0#4x ",SHA256_Eigen2[i]);
  }

  sha2(SHA256_Eigen2,sizeof(SHA256_Eigen2),SHA256_Eigen3,0);
  puts("\nSHA256_Eigen3:");
  for(i = 0; i < 32; i++){
    printf("%0#4x ",SHA256_Eigen3[i]);
  }




//  uint8_t RingSrc = 0x81;
//
//  printf("RingSrc shift = %u\n",MyUInt8RingShift(RingSrc,1,0));



  printf("\nHello world!\n");


  return 0;
}


uint8_t MyUInt8RingShift(uint8_t src, uint8_t ShiftNum, uint8_t LeftOrRight)
{
  uint8_t des = 0;

  if(ShiftNum >= 8){
    ShiftNum = ShiftNum%8;
  }

  if(LeftOrRight == 0){//Left
    des = src<<ShiftNum;
    src >>= 8-ShiftNum;
    des |= src;
  }
  else{
    des = src>>ShiftNum;
    src <<= 8-ShiftNum;
    des |= src;
  }

  return des;

}






