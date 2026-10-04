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

LCD_Status_t LCD_Initialize( LCD_t LCDx )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCDx=%d )", __FUNCTION__, LCDx );

        if ( ( Status = LCD_Port_Initialize( LCDx ) ) != LCD_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_Cycle( LCD_t LCDx )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCDx=%d )", __FUNCTION__, LCDx );

        if ( ( Status = LCD_Port_Cycle( LCDx ) ) != LCD_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_DeInitialize( LCD_t LCDx )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCDx=%d )", __FUNCTION__, LCDx );

        if ( ( Status = LCD_Port_DeInitialize( LCDx ) ) != LCD_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_IsReady( LCD_t LCDx )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCDx=%d )", __FUNCTION__, LCDx );

        if ( ( Status = LCD_Port_IsReady( LCDx ) ) != LCD_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_GetSize( LCD_t LCDx, LCD_Size_t * Size )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCDx=%d, Size=%p )", __FUNCTION__, LCDx );

        if ( Size == NULL )
        {
            Status = LCD_Status_ArgumentInvalid;
            break;
        }

        if ( ( Status = LCD_Port_GetSize( LCDx, Size ) ) != LCD_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_SetCursor( LCD_t LCDx, LCD_Coordinate_t Coordinate )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCDx=%d, Coordinate={Row=%d, Column=%d} )", __FUNCTION__, LCDx, Coordinate.Row, Coordinate.Column );

        if ( ( Status = LCD_Port_SetCursor( LCDx, Coordinate ) ) != LCD_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_Write( LCD_t LCDx, LCD_Character_t Character )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCDx=%d, Character=%02X )", __FUNCTION__, LCDx, Character );

        if ( ( Status = LCD_Port_Write( LCDx, Character ) ) != LCD_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_SetPixel( LCD_t LCDx, LCD_Coordinate_t Coordinate, LCD_Pixel_t Pixel )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCDx=%d, Coordinate={Row=%d, Column=%d}, Pixel=%02X )", __FUNCTION__, LCDx, Coordinate.Row, Coordinate.Column, Pixel );

        if ( ( Status = LCD_Port_SetPixel( LCDx, Coordinate, Pixel ) ) != LCD_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_GetScreen( LCD_t LCDx, LCD_Screen_t * Screen )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCDx=%d, Screen=%p )", __FUNCTION__, LCDx, Screen );

        if ( ( Status = LCD_Port_GetScreen( LCDx, Screen ) ) != LCD_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_Flush( LCD_t LCDx )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCDx=%d )", __FUNCTION__, LCDx );

        if ( ( Status = LCD_Port_Flush( LCDx ) ) != LCD_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char LCD_VERSION[] = "0.0.0.v20261005-0134";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
