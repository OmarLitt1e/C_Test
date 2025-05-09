
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "can-id.h"


void SwitchChannel_ID(void);
void SwitchUnit_ID(void);
void FixInfo_ID(void);
void Gen_Iges_ID(void);
void Gen_Vgeth_ID(void);
void ID_Parse(uint32_t ID);
void Gen_Light_ID(void);
void Gen_ID(uint8_t FuncID, uint8_t Item);

int main()
{
  CanAppTxFrame_t canAppTx;

//  SwitchChannel_ID();
//  SwitchUnit_ID();
//  FixInfo_ID();

//  Gen_Iges_ID();
//  Gen_Vgeth_ID();
//  Gen_ID(Vgeth_ID,Item_Vgeth);
//  Gen_ID(Vcesat_ID,Item_Vsd);
  ID_Parse(0x220200);

//  Gen_Light_ID();
  printf("\n\nHello world!\n");


  return 0;
}


void Gen_ID(uint8_t FuncID, uint8_t Item)
{
  CanAppTxFrame_t canAppTx;
  uint8_t thisNodeID_1 = 0x30, thisNodeID_2 = MAX_RsvID;
  uint32_t i = 0;

  printf("\n/***********Iges***********/\n");
  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = FuncID;
  canAppTx.ProtocolFrame.ctl = unitCTL_Heart;
  canAppTx.ProtocolFrame.item = 0;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("heart:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0;
  canAppTx.ProtocolFrame.ctl = unitCTL_Start;
  canAppTx.ProtocolFrame.item = Item;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("unitCTL_Start:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0;
  canAppTx.ProtocolFrame.ctl = unitCTL_SetCfg;
  canAppTx.ProtocolFrame.item = Item;
  canAppTx.ProtocolFrame.param = 1;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("unitCTL_SetCfg:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0;
  canAppTx.ProtocolFrame.ctl = unitCTL_GetRslt;
  canAppTx.ProtocolFrame.item = Item;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("unitCTL_GetRslt:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = Vcesat_ID;
  canAppTx.ProtocolFrame.ctl = unitCTL_GetWave;
  canAppTx.ProtocolFrame.item = Item;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("unitCTL_GetWave:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0;
  canAppTx.ProtocolFrame.ctl = unitCTL_EStop;
  canAppTx.ProtocolFrame.item = 0;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0xFF;

  printf("ESTOP:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0;
  canAppTx.ProtocolFrame.ctl = unitCTL_ResetAll;
  canAppTx.ProtocolFrame.item = 0;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("ResetAll:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);


  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = FuncID;
  canAppTx.ProtocolFrame.ctl = unitCTL_ExecCfg;
  canAppTx.ProtocolFrame.item = 0;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("unitCTL_ExecCfg:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = FuncID;
  canAppTx.ProtocolFrame.ctl = unitCTL_IAP;
  canAppTx.ProtocolFrame.item = 0;
//  canAppTx.ProtocolFrame.param = 0;//开始
  canAppTx.ProtocolFrame.param = 1;//结束
//  canAppTx.ProtocolFrame.param = 2;//数据
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("unitCTL_IAP:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

}



void ID_Parse(uint32_t ID)
{
  CanAppTxFrame_t canAppTx;

  printf("\n/***********ID Parse***********/\n");
  canAppTx.CanTxFrame.tx_efid = ID;
  printf("rsv1:  %0#4X\n", canAppTx.ProtocolFrame.rsv1);
  printf("nodeID:  %0#4X\n", canAppTx.ProtocolFrame.nodeID);
  printf("ctl:  %0#4X\n", canAppTx.ProtocolFrame.ctl);
  printf("item:  %0#4X\n", canAppTx.ProtocolFrame.item);
  printf("param:  %0#4X\n", canAppTx.ProtocolFrame.param);
  printf("rsv2:  %0#4X\n", canAppTx.ProtocolFrame.rsv2);


}

void SwitchUnit_ID(void)
{
  CanAppTxFrame_t canAppTx;
  uint8_t thisNodeID_1 = 0x30, thisNodeID_2 = MAX_RsvID;
  uint32_t i = 0;

  printf("\n/***********unit switch***********/\n");
  //通道卡心跳
  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = thisNodeID_1;
  canAppTx.ProtocolFrame.ctl = unitCTL_Heart;
  canAppTx.ProtocolFrame.item = 0;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = thisNodeID_2;

  printf("heart:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  //开始执行
  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0x00;
  canAppTx.ProtocolFrame.ctl = unitCTL_Start;
  canAppTx.ProtocolFrame.item = thisNodeID_1;
  canAppTx.ProtocolFrame.param = METHOD_Iges;
  canAppTx.ProtocolFrame.rsv2 = thisNodeID_2;

  printf("start:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);
  //复位
  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0x00;
  canAppTx.ProtocolFrame.ctl = unitCTL_Reset;
  canAppTx.ProtocolFrame.item = thisNodeID_1;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = thisNodeID_2;

  printf("reset:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);


}

void SwitchChannel_ID(void)
{
  CanAppTxFrame_t canAppTx;
  uint8_t thisNodeID_1 = 0x30, thisNodeID_2 = 0x06;
  uint32_t i = 0;

  printf("\n/***********channel switch***********/\n");
  //通道卡心跳
  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = thisNodeID_1;
  canAppTx.ProtocolFrame.ctl = unitCTL_Heart;
  canAppTx.ProtocolFrame.item = 0;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = thisNodeID_2;

  printf("heart:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  //通道卡默认配置
  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0x00;
  canAppTx.ProtocolFrame.ctl = unitCTL_SetCfg;
  canAppTx.ProtocolFrame.item = thisNodeID_1;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = thisNodeID_2;

  printf("setcfg 0:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);
  //通道卡当前配置
  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0x00;
  canAppTx.ProtocolFrame.ctl = unitCTL_SetCfg;
  canAppTx.ProtocolFrame.item = thisNodeID_1;
  canAppTx.ProtocolFrame.param = 1;
  canAppTx.ProtocolFrame.rsv2 = thisNodeID_2;

  printf("setcfg 1:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);
  //开始执行
  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0x00;
  canAppTx.ProtocolFrame.ctl = unitCTL_Start;
  canAppTx.ProtocolFrame.item = thisNodeID_1;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = thisNodeID_2;

  printf("start:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);
  //复位
  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0x00;
  canAppTx.ProtocolFrame.ctl = unitCTL_Reset;
  canAppTx.ProtocolFrame.item = thisNodeID_1;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = thisNodeID_2;

  printf("reset:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);




}

void FixInfo_ID(void)
{
#define param_FixSys 0
#define param_UnitCfg 1
#define param_BitMap 2

  CanAppTxFrame_t canAppTx;
  uint8_t thisNodeID_1 = 0x30, thisNodeID_2 = 0x07;
  uint32_t i = 0;

  printf("\n/***********Fix***********/\n");
  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = Fix0_ID;
  canAppTx.ProtocolFrame.ctl = unitCTL_Heart;
  canAppTx.ProtocolFrame.item = 0;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("heart:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);


  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = MASTER_ID;
  canAppTx.ProtocolFrame.ctl = unitCTL_GetWave;
  canAppTx.ProtocolFrame.item = Fix0_ID;
  canAppTx.ProtocolFrame.param = param_FixSys;
  canAppTx.ProtocolFrame.rsv2 = 0;
  printf("fix sys info:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0x00;
  canAppTx.ProtocolFrame.ctl = unitCTL_GetWave;
  canAppTx.ProtocolFrame.item = Fix0_ID;
  canAppTx.ProtocolFrame.param = param_UnitCfg;
  canAppTx.ProtocolFrame.rsv2 = 0;
  printf("unit info:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0x00;
  canAppTx.ProtocolFrame.ctl = unitCTL_GetWave;
  canAppTx.ProtocolFrame.item = Fix0_ID;
  canAppTx.ProtocolFrame.param = param_BitMap;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("bit map:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);



}

void Gen_Iges_ID(void)
{
  CanAppTxFrame_t canAppTx;
  uint8_t thisNodeID_1 = 0x30, thisNodeID_2 = MAX_RsvID;
  uint32_t i = 0;

  printf("\n/***********Iges***********/\n");
  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = IGES_ID;
  canAppTx.ProtocolFrame.ctl = unitCTL_Heart;
  canAppTx.ProtocolFrame.item = 0;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("heart:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0;
  canAppTx.ProtocolFrame.ctl = unitCTL_Start;
  canAppTx.ProtocolFrame.item = Item_Iges;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("unitCTL_Start:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0;
  canAppTx.ProtocolFrame.ctl = unitCTL_SetCfg;
  canAppTx.ProtocolFrame.item = Item_Iges;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("unitCTL_SetCfg:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0;
  canAppTx.ProtocolFrame.ctl = unitCTL_GetRslt;
  canAppTx.ProtocolFrame.item = Item_Iges;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("unitCTL_GetRslt:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0;
  canAppTx.ProtocolFrame.ctl = unitCTL_EStop;
  canAppTx.ProtocolFrame.item = 0;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0xFF;

  printf("ESTOP:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = 0;
  canAppTx.ProtocolFrame.ctl = unitCTL_ResetAll;
  canAppTx.ProtocolFrame.item = 0;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("ResetAll:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);


}

void Gen_Vgeth_ID(void)
{
  CanAppTxFrame_t canAppTx;
  uint8_t thisNodeID_1 = 0x30, thisNodeID_2 = MAX_RsvID;
  uint32_t i = 0;

  printf("\n/***********Vgeth***********/\n");
  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = Vgeth_ID;
  canAppTx.ProtocolFrame.ctl = unitCTL_Heart;
  canAppTx.ProtocolFrame.item = 0;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("heart:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

//  canAppTx.ProtocolFrame.rsv1 = 0;
//  canAppTx.ProtocolFrame.nodeID = 0;
//  canAppTx.ProtocolFrame.ctl = unitCTL_SetCfg;
//  canAppTx.ProtocolFrame.item = Item_Iges;
//  canAppTx.ProtocolFrame.param = 0;
//  canAppTx.ProtocolFrame.rsv2 = 0;
//
//  printf("unitCTL_SetCfg:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);
//
//  canAppTx.ProtocolFrame.rsv1 = 0;
//  canAppTx.ProtocolFrame.nodeID = 0;
//  canAppTx.ProtocolFrame.ctl = unitCTL_EStop;
//  canAppTx.ProtocolFrame.item = 0;
//  canAppTx.ProtocolFrame.param = 0;
//  canAppTx.ProtocolFrame.rsv2 = 0xFF;
//
//  printf("ESTOP:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);
//
//  canAppTx.ProtocolFrame.rsv1 = 0;
//  canAppTx.ProtocolFrame.nodeID = 0;
//  canAppTx.ProtocolFrame.ctl = unitCTL_ResetAll;
//  canAppTx.ProtocolFrame.item = 0;
//  canAppTx.ProtocolFrame.param = 0;
//  canAppTx.ProtocolFrame.rsv2 = 0;
//
//  printf("ResetAll:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);


}

void Gen_Vcesat_ID(void)
{
  CanAppTxFrame_t canAppTx;
  uint8_t thisNodeID_1 = 0x30, thisNodeID_2 = MAX_RsvID;
  uint32_t i = 0;

  printf("\n/***********Vcesat***********/\n");
  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = Vcesat_ID;
  canAppTx.ProtocolFrame.ctl = unitCTL_Heart;
  canAppTx.ProtocolFrame.item = 0;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("heart:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

//  canAppTx.ProtocolFrame.rsv1 = 0;
//  canAppTx.ProtocolFrame.nodeID = 0;
//  canAppTx.ProtocolFrame.ctl = unitCTL_SetCfg;
//  canAppTx.ProtocolFrame.item = Item_Iges;
//  canAppTx.ProtocolFrame.param = 0;
//  canAppTx.ProtocolFrame.rsv2 = 0;
//
//  printf("unitCTL_SetCfg:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);
//
//  canAppTx.ProtocolFrame.rsv1 = 0;
//  canAppTx.ProtocolFrame.nodeID = 0;
//  canAppTx.ProtocolFrame.ctl = unitCTL_EStop;
//  canAppTx.ProtocolFrame.item = 0;
//  canAppTx.ProtocolFrame.param = 0;
//  canAppTx.ProtocolFrame.rsv2 = 0xFF;
//
//  printf("ESTOP:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);
//
//  canAppTx.ProtocolFrame.rsv1 = 0;
//  canAppTx.ProtocolFrame.nodeID = 0;
//  canAppTx.ProtocolFrame.ctl = unitCTL_ResetAll;
//  canAppTx.ProtocolFrame.item = 0;
//  canAppTx.ProtocolFrame.param = 0;
//  canAppTx.ProtocolFrame.rsv2 = 0;
//
//  printf("ResetAll:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);



}

void Gen_Light_ID(void)
{
  CanAppTxFrame_t canAppTx;
  uint8_t thisNodeID_1 = 0x30, thisNodeID_2 = MAX_RsvID;
  uint32_t i = 0;

  printf("\n/***********Iges***********/\n");
  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = Light_ID;
  canAppTx.ProtocolFrame.ctl = unitCTL_Heart;
  canAppTx.ProtocolFrame.item = 0;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("heart:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

  canAppTx.ProtocolFrame.rsv1 = 0;
  canAppTx.ProtocolFrame.nodeID = Light_ID;
  canAppTx.ProtocolFrame.ctl = unitCTL_SetCfg;
  canAppTx.ProtocolFrame.item = 0;
  canAppTx.ProtocolFrame.param = 0;
  canAppTx.ProtocolFrame.rsv2 = 0;

  printf("unitCTL_SetCfg:  %0#10X\n", canAppTx.CanTxFrame.tx_efid);

}



