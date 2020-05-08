
#include "DIO.h"

void DIO_WriteChannel(DIO_Channels ChannelId,STD_LevelTypes level){
	DIO_PORTS Portx = ChannelId/8;
	DIO_Channels ChannelPos = ChannelId%8;
	
	switch(Portx){
		case DIO_PORTA:
			if(level == STD_Higt)
				Set_Bit(PORTA_Reg,ChannelPos);
			else
				Clear_Bit(PORTA_Reg,ChannelPos);
		break;
		case DIO_PORTB:
			if(level == STD_Higt)
				Set_Bit(PORTB_Reg,ChannelPos);
			else
				Clear_Bit(PORTB_Reg,ChannelPos);
		break;
		case DIO_PORTC:
			if(level == STD_Higt)
				Set_Bit(PORTC_Reg,ChannelPos);
			else
				Clear_Bit(PORTC_Reg,ChannelPos);
		break;
		case DIO_PORTD:
			if(level == STD_Higt)
				Set_Bit(PORTD_Reg,ChannelPos);
			else
				Clear_Bit(PORTD_Reg,ChannelPos);
		break;
	}
	
}

STD_LevelTypes DIO_ReadChannel(DIO_Channels ChannelId){
		DIO_PORTS Portx = ChannelId/8;
		DIO_Channels ChannelPos = ChannelId%8;
		STD_LevelTypes level = STD_Low;
		
		switch(Portx){
			case DIO_PORTA:
				level = Get_Bit(PINA_Reg,ChannelPos);
			break;
			case DIO_PORTB:
				level = Get_Bit(PINB_Reg,ChannelPos);
			break;
			case DIO_PORTC:
				level = Get_Bit(PINC_Reg,ChannelPos);
			break;
			case DIO_PORTD:
				level = Get_Bit(PIND_Reg,ChannelPos);
			break;
		}
	return level;
}

void DIO_WritePort(DIO_PORTS Portx,uint8 data){
	
	switch(Portx){
		case DIO_PORTA:
			PORTA_Reg = data;
		break;
		case DIO_PORTB:
			PORTB_Reg = data;
		break;
		case DIO_PORTC:
			PORTC_Reg = data;
		break;
		case DIO_PORTD:
			PORTD_Reg = data;
		break;
	}
	
}