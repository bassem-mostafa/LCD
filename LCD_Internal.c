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

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "LCD.h"
#include "LCD_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

LOG_Status_t LCD_LOG_Raw( LOG_Level_t LOG_Level, LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_RawWithArgs( LCD_LOG, LOG_Level, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t LCD_LOG_Trace( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_TraceWithArgs( LCD_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t LCD_LOG_Debug( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_DebugWithArgs( LCD_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t LCD_LOG_Info( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_InfoWithArgs( LCD_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t LCD_LOG_Warning( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_WarningWithArgs( LCD_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t LCD_LOG_Error( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_ErrorWithArgs( LCD_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t LCD_LOG_Fatal( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_FatalWithArgs( LCD_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LCD_Status_t LCD_Instance_IsValid( LCD_Instance_t * LCD_Instance )
{
    LCD_Status_t LCD_Status = LCD_Status_Error;
    do
    {
        LCD_Trace( "%s( Instance=%p )", __FUNCTION__, LCD_Instance );
        if ( LCD_Instance == NULL )
        {
            LCD_Error( "Invalid Argument" );
            LCD_Status = LCD_Status_ArgumentInvalid;
            break;
        }
        LCD_Status = LCD_Status_Error;
        for ( LCD_t LCD = LCD_Null; LCD < LCD_NUMBER_OF_INSTANCES; ++LCD )
        {
            if ( LCD_Instance == &LCD_Context.Instance[ LCD ] )
            {
                LCD_Status = LCD_Status_Success;
                break;
            }
        }
        if ( LCD_Status != LCD_Status_Success )
        {
            LCD_Error( "Invalid Reference" );
            LCD_Status = LCD_Status_Error;
            break;
        }
        LCD_Status = LCD_Status_Success;
    }
    while ( 0 );
    return LCD_Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

LCD_Context_t LCD_Context;

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
