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

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef LCD_INTERNAL_H_
    #define LCD_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "LCD_Port.h"
    #include "driver/LM6063DCW_A/LCD_LM6063DCW_A.h"
    #include "driver/LMB162AFC/LCD_LMB162AFC.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef LCD_TIM
        #define LCD_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef LCD_LOG
        #define LCD_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define LCD_NAME       "LCD"
    #define LCD_LOG_PREFIX UTIL_StringConcatenateConstant( LCD_NAME, "> " )

    #ifdef DEBUG
        #define LCD_Raw( Level, Format, ... ) LOG_Raw( LCD_LOG, Level, Format, ##__VA_ARGS__ )
        #define LCD_Trace( Format, ... )      LOG_Trace( LCD_LOG, UTIL_StringConcatenateConstant( LCD_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define LCD_Debug( Format, ... )      LOG_Debug( LCD_LOG, UTIL_StringConcatenateConstant( LCD_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define LCD_Info( Format, ... )       LOG_Info( LCD_LOG, UTIL_StringConcatenateConstant( LCD_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define LCD_Warning( Format, ... )    LOG_Warning( LCD_LOG, UTIL_StringConcatenateConstant( LCD_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define LCD_Error( Format, ... )      LOG_Error( LCD_LOG, UTIL_StringConcatenateConstant( LCD_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define LCD_Fatal( Format, ... )      LOG_Fatal( LCD_LOG, UTIL_StringConcatenateConstant( LCD_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define LCD_Raw( Level, Format, ... )
        #define LCD_Trace( Format, ... )
        #define LCD_Debug( Format, ... )
        #define LCD_Info( Format, ... )
        #define LCD_Warning( Format, ... )
        #define LCD_Error( Format, ... )
        #define LCD_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef enum LCD_Type
    {
        LCD_Type_Unknown = 0,
        LCD_Type_Null,
        LCD_Type_LM6063DCW_A,
    } LCD_Type_t;

    typedef struct LCD_Instance
    {
        LCD_Type_t Type;

        union
        {
            LCD_LM6063DCW_A_t LM6063DCW_Ax;
        };
    } LCD_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    LCD_Status_t LCD_Port_Initialize( LCD_t LCDx );
    LCD_Status_t LCD_Port_Cycle( LCD_t LCDx );
    LCD_Status_t LCD_Port_DeInitialize( LCD_t LCDx );

    LCD_Status_t LCD_Port_IsReady( LCD_t LCDx );

    LCD_Status_t LCD_Port_GetSize( LCD_t LCDx, LCD_Size_t * Size );

    LCD_Status_t LCD_Port_SetCursor( LCD_t LCDx, LCD_Coordinate_t Coordinate );

    LCD_Status_t LCD_Port_Write( LCD_t LCDx, LCD_Character_t Character );

    LCD_Status_t LCD_Port_SetPixel( LCD_t LCDx, LCD_Coordinate_t Coordinate, LCD_Pixel_t Pixel );

    LCD_Status_t LCD_Port_GetScreen( LCD_t LCDx, LCD_Screen_t * Screen );

    LCD_Status_t LCD_Port_Flush( LCD_t LCDx );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* LCD_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
