#ifndef CAN_ID_H
#define CAN_ID_H

//位复用最大值
#define MAX_nodeID 0x3F
#define MAX_Ctl 0x1F
#define MAX_Item 0x3F
#define MAX_Param 0x0F
#define MAX_RsvID 0xFF

#define MASK_nodeID 0x1F800000U//bit28-23
#define MASK_bitCtl 0x007C0000U//bit22-18
#define MASK_bitItem 0x0003F000U//bit17-12
#define MASK_bitParam 0x00000F00U//bit11-8
#define MASK_RsvID 0x000000FFU//bit0-7


#define POS_nodeID 23
#define POS_bitCtl 18
#define POS_bitItem 12
#define POS_bitParam 8
#define POS_RsvID 0




/*测试机ID***********************/
//位复用最大值
#define MAX_nodeID 0x3F
#define MAX_Ctl 0x1F
#define MAX_Item 0x3F
#define MAX_Param 0x0F
#define MAX_RsvID 0xFF


//总共47（48-1）功能机ID：0x01-0x2F
#define NUM_FuncNode 4
#define MASTER_ID 0x00
#define MIN_FuncNode_ID 0x03

#define IGES_ID 0x03
#define Vgeth_ID 0x04
#define Vcesat_ID 0x05
#define VgethIEC_ID 0x06
#define Fix0_ID 0x20
#define Fix1_ID 0x21
#define Fix2_ID 0x22
#define Fix3_ID 0x23


#define Light_ID 0x1F
#define Ices_ID 0x08
#define MAX_FuncNode_ID 0x06


//总共16（64-48）单元选择卡ID：0x30-0x3F；；每个单元卡物理搭配32个通道卡
#define SwitchU0_ID 0x30
#define SwitchU1_ID 0x31
#define SwitchU2_ID 0x32
#define SwitchU3_ID 0x33

//切换单元ID,占位RsvID;最多16个切换板
#define NUM_ChBoardPerSw 16
#define MIN_SwChnlNode_ID 0x00//必须从0开始
#define MAX_SwChnlNode_ID 0x0F


#define MASK_nodeID 0x1F800000U//bit28-23
#define MASK_bitCtl 0x007C0000U//bit22-18
#define MASK_bitItem 0x0003F000U//bit17-12
#define MASK_bitParam 0x00000F00U//bit11-8

#define POS_nodeID 23
#define POS_bitCtl 18
#define POS_bitItem 12
#define POS_bitParam 8

#define MASK_FIFO0 (MASK_nodeID|(0x10<<POS_bitCtl))//去除Ctl>=0x10的控制帧

//主机与节点通信控制功能码定义
#define unitCTL_EStop 0x00
#define unitCTL_Start 0x01
#define unitCTL_Stop 0x02
#define unitCTL_ResetAll 0x03
#define unitCTL_SetCfg 0x06
#define unitCTL_GetRslt 0x07
#define unitCTL_GetWave 0x08
#define unitCTL_Reset 0x0E
#define unitCTL_IAP 0x0F
#define unitCTL_Heart 0x10
#define unitCTL_ExecCfg 0x11


//统一替代名称
#define Item_NULL 0
#define Item_Cont 1
#define Item_Ices 2
#define Item_Vces 3
#define Item_Iges 4
#define Item_Vgeth_IEC 5
#define Item_Vgeth 6
#define Item_Vgsth_IEC_183A 7//原Item_VdsthIEC
#define Item_Vgsth_183A 8//原Item_Vdsth
#define Item_Vcesat 9
#define Item_Vp 10
#define Item_Vsd 11
#define Item_Rdson 12

#define Item_Calc 48
#define Item_Delay 49



//测试方法定义
#define METHOD_MAX 8
#define METHOD_NULL 0xFF
#define METHOD_Iges 0
#define METHOD_Vgeth 1
#define METHOD_Ices 2
#define METHOD_Vcesat 3



/* CAN transmit message structure */
typedef struct {
    uint32_t tx_sfid;                                                   /*!< standard format frame identifier */
    uint32_t tx_efid;                                                   /*!< extended format frame identifier */
    uint8_t tx_ff;                                                      /*!< format of frame, standard or extended format */
    uint8_t tx_ft;                                                      /*!< type of frame, data or remote */
    uint8_t tx_dlen;                                                    /*!< data length */
    uint8_t tx_data[8];                                                 /*!< transmit data */
} can_trasnmit_message_struct;

/* CAN receive message structure */
typedef struct {
    uint32_t rx_sfid;                                                   /*!< standard format frame identifier */
    uint32_t rx_efid;                                                   /*!< extended format frame identifier */
    uint8_t rx_ff;                                                      /*!< format of frame, standard or extended format */
    uint8_t rx_ft;                                                      /*!< type of frame, data or remote */
    uint8_t rx_dlen;                                                    /*!< data length */
    uint8_t rx_data[8];                                                 /*!< receive data */
    uint8_t rx_fi;                                                      /*!< filtering index */
} can_receive_message_struct;


typedef union {
  can_trasnmit_message_struct  CanTxFrame;

  struct {
    uint32_t  sfid;
    uint32_t  rsv2:8;
    uint32_t  param:4;
    uint32_t  item:6;
    uint32_t  ctl:5;
    uint32_t  nodeID:6;
    uint32_t  rsv1:3;
    uint8_t  ff;
    uint8_t  rtr;
    uint8_t  dataLen;
    uint8_t  data[8];
  }ProtocolFrame;

}CanAppTxFrame_t;

typedef union {
  can_receive_message_struct  CanRxFrame;

  struct {
    uint32_t  sfid;
    uint32_t  rsv2:8;
    uint32_t  param:4;
    uint32_t  item:6;
    uint32_t  ctl:5;
    uint32_t  nodeID:6;
    uint32_t  rsv1:3;
    uint8_t  ff;
    uint8_t  rtr;
    uint8_t  dataLen;
    uint8_t  data[8];
    uint8_t  fi;
  }ProtocolFrame;

}CanAppRxFrame_t;



#endif
