

#ifndef DIO_H_
#define DIO_H_

#include "STD_Types.h"
#include "DIO_Types.h"
#include "DIO_HW.h"
#include "Bit_Math.h"

void DIO_WriteChannel(DIO_Channels ChannelId,STD_LevelTypes level);
STD_LevelTypes DIO_ReadChannel(DIO_Channels ChannelId);
void DIO_WritePort(DIO_PORTS Portx,uint8 data);


#endif /* DIO_H_ */