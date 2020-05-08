
#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "STD_Types.h"
#include "DIO_Types.h"
#include "DIO_HW.h"
#include "Bit_Math.h"
#include "DIO.h"

typedef struct{
	DIO_Dir PinDirection;
	STD_LevelTypes PinLevel;
}DIO_PinConfig;

#define PINCOUNT 32

void DIO_Init(void);


#endif /* DIO_CFG_H_ */