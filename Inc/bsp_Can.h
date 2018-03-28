#ifndef __bsp_can_h
#define __bsp_can_h

#ifdef __cplusplus
extern "C"{
#endif

#include "main.h"
#include "stm32f1xx_hal.h"
#include "can.h"


#define GetAddrBit0Val		HAL_GPIO_ReadPin(LOCK_ADDR0_GPIO_Port, LOCK_ADDR0_Pin)
#define GetAddrBit1Val		HAL_GPIO_ReadPin(LOCK_ADDR1_GPIO_Port, LOCK_ADDR1_Pin)
#define GetAddrBit2Val		HAL_GPIO_ReadPin(LOCK_ADDR2_GPIO_Port, LOCK_ADDR2_Pin)
#define GetAddrBit3Val		HAL_GPIO_ReadPin(LOCK_ADDR3_GPIO_Port, LOCK_ADDR3_Pin)


LOCKERRORCODE BSP_CanInit(void);
LOCKERRORCODE BSP_CanFilterConfig(void);
LOCKERRORCODE BSP_CanSendDatas(uint8_t Id, uint8_t nBoxNumber, uint8_t nSwitchState, uint8_t nBoxGoodsState);


#ifdef __cplusplus
}
#endif
#endif
