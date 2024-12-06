// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

#ifdef LCD // FIX STM32
    #undef LCD
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef LCD_H_
    #define LCD_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "LCD_Port.h"

    #include <stdint.h>

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef enum LCD_Status
    {
        LCD_Status_Success = 0,
        LCD_Status_ArgumentInvalid,
        LCD_Status_NotSupported,
        LCD_Status_Error,
        LCD_Status_Busy,
        LCD_Status_Timeout,
    } LCD_Status_t;

    typedef uint32_t LCD_Row_t;

    typedef uint32_t LCD_Column_t;

    typedef struct LCD_Coordinate
    {
        LCD_Row_t Row;
        LCD_Column_t Column;
    } LCD_Coordinate_t;

    typedef uint32_t LCD_Width_t;

    typedef uint32_t LCD_Height_t;

    typedef struct LCD_Size
    {
        LCD_Width_t Width;
        LCD_Height_t Height;
    } LCD_Size_t;

    typedef uint8_t LCD_Character_t;

    typedef uint32_t LCD_Pixel_t;

    typedef LCD_Pixel_t * LCD_Screen_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    LCD_Status_t LCD_Initialize( void );
    LCD_Status_t LCD_Cycle( void );
    LCD_Status_t LCD_DeInitialize( void );

    LCD_Status_t LCD_IsReady( LCD_t LCD );

    LCD_Status_t LCD_GetSize( LCD_t LCD, LCD_Size_t * LCD_Size );

    LCD_Status_t LCD_SetCursor( LCD_t LCD, LCD_Coordinate_t LCD_Coordinate );

    LCD_Status_t LCD_Write( LCD_t LCD, LCD_Character_t LCD_Character );

    LCD_Status_t LCD_SetPixel( LCD_t LCD, LCD_Coordinate_t LCD_Coordinate, LCD_Pixel_t LCD_Pixel );

    LCD_Status_t LCD_GetScreen( LCD_t LCD, LCD_Screen_t * LCD_Screen );

    LCD_Status_t LCD_Flush( LCD_t LCD );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    extern const char LCD_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* LCD_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
