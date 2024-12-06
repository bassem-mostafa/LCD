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
        #define LCD_TIM TIM_1
    #endif

    #ifndef LCD_LOG
        #define LCD_LOG LOG_1
    #endif

    #define LCD_NAME       "LCD"
    #define LCD_LOG_PREFIX UTIL_StringConcatenateConstant( LCD_NAME, "> " )

    #ifdef DEBUG
        #define LCD_Raw( Level, Format, ... ) LCD_LOG_Raw( Level, Format, ##__VA_ARGS__ )
        #define LCD_Trace( Format, ... )      LCD_LOG_Trace( UTIL_StringConcatenateConstant( LCD_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define LCD_Debug( Format, ... )      LCD_LOG_Debug( UTIL_StringConcatenateConstant( LCD_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define LCD_Info( Format, ... )       LCD_LOG_Info( UTIL_StringConcatenateConstant( LCD_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define LCD_Warning( Format, ... )    LCD_LOG_Warning( UTIL_StringConcatenateConstant( LCD_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define LCD_Error( Format, ... )      LCD_LOG_Error( UTIL_StringConcatenateConstant( LCD_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define LCD_Fatal( Format, ... )      LCD_LOG_Fatal( UTIL_StringConcatenateConstant( LCD_LOG_PREFIX, Format ), ##__VA_ARGS__ )
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

    typedef struct LCD_Instance_Context_t LCD_Instance_Context_t;

    typedef struct LCD_Instance
    {
        LCD_t LCD;

        union
        {
            LCD_Instance_Context_t * Context;
            LCD_LM6063DCW_A_Instance_t * LM6063DCW_A;
            LCD_LMB162AFC_Instance_t * LMB162AFC;
        };
    } LCD_Instance_t;

    typedef struct LCD_Context
    {
        LCD_Instance_t Instance[ LCD_NUMBER_OF_INSTANCES ];
    } LCD_Context_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    LOG_Status_t LCD_LOG_Raw( LOG_Level_t LOG_Level, LOG_Format_t LOG_Format, ... );
    LOG_Status_t LCD_LOG_Trace( LOG_Format_t LOG_Format, ... );
    LOG_Status_t LCD_LOG_Debug( LOG_Format_t LOG_Format, ... );
    LOG_Status_t LCD_LOG_Info( LOG_Format_t LOG_Format, ... );
    LOG_Status_t LCD_LOG_Warning( LOG_Format_t LOG_Format, ... );
    LOG_Status_t LCD_LOG_Error( LOG_Format_t LOG_Format, ... );
    LOG_Status_t LCD_LOG_Fatal( LOG_Format_t LOG_Format, ... );

    LCD_Status_t LCD_Instance_IsValid( LCD_Instance_t * LCD_Instance );

    // The following APIs MUST be provided by the port
    LCD_Status_t LCD_IsValid( LCD_t LCD );

    LCD_Status_t LCD_Instance_Initialize( LCD_Instance_t * LCD_Instance );
    LCD_Status_t LCD_Instance_Cycle( LCD_Instance_t * LCD_Instance );
    LCD_Status_t LCD_Instance_DeInitialize( LCD_Instance_t * LCD_Instance );

    LCD_Status_t LCD_Instance_GetSize( LCD_Instance_t * LCD_Instance, LCD_Size_t * LCD_Size );

    LCD_Status_t LCD_Instance_SetCursor( LCD_Instance_t * LCD_Instance, LCD_Coordinate_t LCD_Coordinate );

    LCD_Status_t LCD_Instance_Write( LCD_Instance_t * LCD_Instance, LCD_Character_t LCD_Character );

    LCD_Status_t LCD_Instance_SetPixel( LCD_Instance_t * LCD_Instance, LCD_Coordinate_t LCD_Coordinate, LCD_Pixel_t LCD_Pixel );

    LCD_Status_t LCD_Instance_GetScreen( LCD_Instance_t * LCD_Instance, LCD_Screen_t * LCD_Screen );

    LCD_Status_t LCD_Instance_Flush( LCD_Instance_t * LCD_Instance );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    extern LCD_Context_t LCD_Context;

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
