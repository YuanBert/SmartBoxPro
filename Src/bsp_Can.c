#include "bsp_Can.h"


uint8_t CanId;
static CanTxMsgTypeDef          TxMessage;
static CanRxMsgTypeDef          RxMessage;

LOCKERRORCODE BSP_CanInit(void)
{
	LOCKERRORCODE state = LOCK_OK;
	CanId = 0;
	
	hcan.pTxMsg = &TxMessage;
  	hcan.pRxMsg = &RxMessage;

	//»ñÈ¡CanIdÖµ
	if(GPIO_PIN_SET == GetAddrBit3Val)
	{
		CanId |= 0x08;
	}
	if(GPIO_PIN_SET == GetAddrBit2Val)
	{
		CanId |= 0x04;
	}
	if(GPIO_PIN_SET == GetAddrBit1Val)
	{
		CanId |= 0x02;
	}
	if(GPIO_PIN_SET == GetAddrBit0Val)
	{
		CanId |= 0x01;
	}
    
    HAL_CAN_Receive_IT(&hcan, CAN_FIFO0);
    
	return state;
}

LOCKERRORCODE BSP_CanFilterConfig(void)
{
	LOCKERRORCODE state = LOCK_OK;
        
	CAN_FilterConfTypeDef			sFilterConfig;
  	sFilterConfig.FilterNumber = 0;
  	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
  	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
  	sFilterConfig.FilterIdHigh = 0x0000;
  	sFilterConfig.FilterIdLow = 0x0000;
  	sFilterConfig.FilterMaskIdHigh = 0x0000;
  	sFilterConfig.FilterMaskIdLow = 0x0000;
  	sFilterConfig.FilterFIFOAssignment = 0;
  	sFilterConfig.FilterActivation = ENABLE;
  	HAL_CAN_ConfigFilter(&hcan,&sFilterConfig);
	return state;
}

LOCKERRORCODE BSP_CanSendDatas(uint8_t Id, uint8_t nBoxNumber, uint8_t nSwitchState, uint8_t nBoxGoodsState)
{
	LOCKERRORCODE state = LOCK_OK;
	
	hcan.pTxMsg->StdId = 0x000 | Id;
	hcan.pTxMsg->RTR = CAN_RTR_DATA;
	hcan.pTxMsg->IDE = CAN_ID_STD;
	hcan.pTxMsg->DLC = 3;
	hcan.pTxMsg->Data[0] = nBoxNumber;
	hcan.pTxMsg->Data[1] = nSwitchState;
	hcan.pTxMsg->Data[2] = nBoxGoodsState;

	if(HAL_OK != HAL_CAN_Transmit(&hcan, 10))
	{
		state = LOCK_ERROR;
	}

	if(HAL_CAN_STATE_READY != HAL_CAN_GetState(&hcan))
	{
		state = LOCK_ERROR;
	}
	
	return state;
}



