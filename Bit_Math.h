/*
 * Bit_Math.h
 *
 * Created: 4/27/2020 11:33:53 AM
 *  Author: user
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define Set_Bit(Reg , Bit)(Reg |= (1<<Bit))
#define Clear_Bit(Reg , Bit)(Reg &=~ (1<<Bit))
#define Toggle_Bit(Reg , Bit)(Reg ^= (1<<Bit))
#define Get_Bit(Reg , Bit)((Reg>>Bit) & 1)





#endif /* BIT_MATH_H_ */