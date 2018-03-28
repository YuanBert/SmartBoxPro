#ifndef __bsp_can_h
#define __bsp_can_h

#ifdef __cplusplus
extern "C"{
#endif

#include "main.h"
#include "stm32f1xx_hal.h"
#include "can.h"

LOCKERRORCODE BSP_CanInit(void);
LOCKERRORCODE BSP_CanFilterConfig(void);
LOCKERRORCODE BSP_CanSendDatas(uint8_t Id, uint8_t data1, uint8_t data2, uint8_t data3);


#ifdef __cplusplus
}
#endif
#endif
