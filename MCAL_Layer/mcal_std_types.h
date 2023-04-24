/* 
 * File:   mcal_std_types.h
 * Author: ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 2, 2023, 6:42 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H


/* Section : Includes */
#include "std_libraries.h"
#include "compiler.h"


/* Section : Macro Declaration  */
#define STD_HIGH               0x01
#define STD_LOW                0x00
   
#define STD_ON                 0x01
#define STD_OFF                0x00

#define STD_ACTIVE             0x01
#define STD_IDEL               0x00

#define ZERO_INIT              0x00


/* Section : Data Type Declaration  */

typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef float float32;

typedef uint8 Std_ReturnType; 

#define E_OK        (Std_ReturnType)0x01 
#define E_NOT_OK    (Std_ReturnType)0x00 


#endif	/* MCAL_STD_TYPES_H */

