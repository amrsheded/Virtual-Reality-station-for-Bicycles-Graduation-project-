/*
 *
 *EXT_INT.c
 *
 *  Created on: Mar 18, 2019
 *      Author: sheded
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Registers.h"

#include "EXT_INT.h"
/************************************************************************************************
*************************************************************************************************
                                  Exernal interrupt
************************************************************************************************/
                         // Initialization interrupt peripheral
void EXT_INT(u8 INT_number,u8 INT_sense)
{
  if(INT_number==1)
  {
     SET_BIT(GICR_REG,7);
	switch(INT_sense)
	{
	case Rising:
		{
			SET_BIT(MCUCR_REG,2);
			SET_BIT(MCUCR_REG,3);
			break;
		}
	case Falling:
	    {
		    CLR_BIT(MCUCR_REG,2);
		    SET_BIT(MCUCR_REG,3);
		    break;
	    }
	case Logical_change:
	    {
			 SET_BIT(MCUCR_REG,2);
			 CLR_BIT(MCUCR_REG,3);
			 break;
        }
	case Low_level:
	    {
			 CLR_BIT(MCUCR_REG,2);
			 CLR_BIT(MCUCR_REG,3);
			 break;
        }
    }
  }else if(INT_number==0)
  {
	  SET_BIT(GICR_REG,6);
	  switch(INT_sense)
	  	{
	  	case Rising:
	  		{
	  			SET_BIT(MCUCR_REG,0);
	  			SET_BIT(MCUCR_REG,1);
	  			break;
	  		}
	  	case Falling:
	  	    {
	  		    CLR_BIT(MCUCR_REG,0);
	  		    SET_BIT(MCUCR_REG,1);
	  		    break;
	  	    }
	  	case Logical_change:
	  	    {
	  			 SET_BIT(MCUCR_REG,0);
	  			 CLR_BIT(MCUCR_REG,1);
	  			 break;
	        }
	  	case Low_level:
	  	    {
	  			 CLR_BIT(MCUCR_REG,0);
	  			 CLR_BIT(MCUCR_REG,1);
	  			 break;
	        }
	    }

  }else if(INT_number==2)
  {
	  SET_BIT(GICR_REG,5);
	  switch(INT_sense)
	  	{
	  case Rising:
	  	  {
	  	  		SET_BIT(MCUCSR_REG,6);
	  	  		break;
	  	  }
	  case Falling:
	 	   {
	 	  	  	CLR_BIT(MCUCSR_REG,6);
	 	  	  	break;
	 	   }
	    }
  }
}

u8 Check_flag(u8 INT_number)            //Funtion for check flag if interrupt is executed
{
	u8 flag;
	if(INT_number==0)
	{
		flag=GET_BIT(GIFR_REG,6);
	}else if(INT_number==1)
	{
		flag=GET_BIT(GIFR_REG,7);
	}else if(INT_number==2)
	{
		flag=GET_BIT(GIFR_REG,5);
	}
return flag;
}
