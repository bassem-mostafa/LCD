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

typedef struct LCD_Context
{
    LCD_Instance_t Instance[ LCD_Count ];
} LCD_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static LCD_Status_t LCD_Context_Initialize( void );
static LCD_Status_t LCD_Context_Cycle( void );
static LCD_Status_t LCD_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static LCD_Context_t LCD_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static LCD_Status_t LCD_Context_Initialize( void )
{
    LCD_Status_t Status = LCD_Status_Success;
    do
    {
        LCD_Trace( "%s( void )", __FUNCTION__ );

        for ( LCD_t LCD_x = LCD_Null; LCD_x < LCD_Count; ++LCD_x )
        {
            LCD_Context.Instance[ LCD_x ].LCDx = LCD_x;
            if ( ( Status = LCD_Instance_Initialize( &LCD_Context.Instance[ LCD_x ] ) ) != LCD_Status_Success )
            {
                LCD_Warning( "LCD_%d Initialize Failed: Status %d", LCD_x, Status );
            }
        }
    }
    while ( 0 );
    return Status;
}

static LCD_Status_t LCD_Context_Cycle( void )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( void )", __FUNCTION__ );

        for ( LCD_t LCD_x = LCD_Null; LCD_x < LCD_Count; ++LCD_x )
        {
            LCD_Context.Instance[ LCD_x ].LCDx = LCD_x; // FIXME
            if ( ( Status = LCD_Instance_Cycle( &LCD_Context.Instance[ LCD_x ] ) ) != LCD_Status_Success )
            {
                LCD_Warning( "LCD_%d Cycle Failed: Status %d", LCD, Status );
            }
        }
    }
    while ( 0 );

    return Status;
}

static LCD_Status_t LCD_Context_DeInitialize( void )
{
    LCD_Status_t Status = LCD_Status_Success;
    do
    {
        LCD_Trace( "%s( void )", __FUNCTION__ );
        for ( LCD_t LCD_x = LCD_Null; LCD_x < LCD_Count; ++LCD_x )
        {
            LCD_Context.Instance[ LCD_x ].LCDx = LCD_x; // FIXME

            if ( ( Status = LCD_Instance_DeInitialize( &LCD_Context.Instance[ LCD_x ] ) ) != LCD_Status_Success )
            {
                LCD_Warning( "LCD_%d DeInitialize Failed: Status %d", LCD_x, Status );
            }
        }
        Status = LCD_Status_Success;
    }
    while ( 0 );
    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

LCD_Status_t LCD_Initialize( LCD_t LCDx )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( void )", __FUNCTION__ );

        Status = LCD_Context_Initialize( );
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_Cycle( LCD_t LCDx )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( void )", __FUNCTION__ );

        Status = LCD_Context_Cycle( );
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_DeInitialize( LCD_t LCDx )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( void )", __FUNCTION__ );

        Status = LCD_Context_DeInitialize( );
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_IsReady( LCD_t LCDx )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCD=%d )", __FUNCTION__, LCDx );

        if ( ( Status = LCD_IsValid( LCDx ) ) != LCD_Status_Success )
        {
            break;
        }

        Status = LCD_Instance_IsReady( &LCD_Context.Instance[ LCDx ] );
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_GetSize( LCD_t LCDx, LCD_Size_t * Size )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCD=%d, Size=%p )", __FUNCTION__, LCDx, Size );

        if ( Size == NULL )
        {
            Status = LCD_Status_ArgumentInvalid;
            break;
        }

        if ( ( Status = LCD_IsValid( LCDx ) ) != LCD_Status_Success )
        {
            break;
        }

        Status = LCD_Instance_GetSize( &LCD_Context.Instance[ LCDx ], Size );
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_SetCursor( LCD_t LCDx, LCD_Coordinate_t Coordinate )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCD=%d, Coordinate={Row=%d, Column=%d} )", __FUNCTION__, LCDx, Coordinate.Row, Coordinate.Column );

        if ( ( Status = LCD_IsValid( LCDx ) ) != LCD_Status_Success )
        {
            break;
        }

        Status = LCD_Instance_SetCursor( &LCD_Context.Instance[ LCDx ], Coordinate );
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_Write( LCD_t LCDx, LCD_Character_t Character )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCD=%d, Character=%02X )", __FUNCTION__, LCDx, Character );

        if ( ( Status = LCD_IsValid( LCDx ) ) != LCD_Status_Success )
        {
            break;
        }

        Status = LCD_Instance_Write( &LCD_Context.Instance[ LCDx ], Character );
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_SetPixel( LCD_t LCDx, LCD_Coordinate_t Coordinate, LCD_Pixel_t Pixel )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCD=%d, Coordinate={Row=%d, Column=%d}, Pixel=%02X )", __FUNCTION__, LCDx, Coordinate.Row, Coordinate.Column, Pixel );

        if ( ( Status = LCD_IsValid( LCDx ) ) != LCD_Status_Success )
        {
            break;
        }

        Status = LCD_Instance_SetPixel( &LCD_Context.Instance[ LCDx ], Coordinate, Pixel );
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_GetScreen( LCD_t LCDx, LCD_Screen_t * Screen )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCD=%d, Screen=%p )", __FUNCTION__, LCDx, Screen );

        if ( ( Status = LCD_IsValid( LCDx ) ) != LCD_Status_Success )
        {
            break;
        }

        Status = LCD_Instance_GetScreen( &LCD_Context.Instance[ LCDx ], Screen );
    }
    while ( 0 );

    return Status;
}

LCD_Status_t LCD_Flush( LCD_t LCDx )
{
    LCD_Status_t Status = LCD_Status_Success;

    do
    {
        LCD_Trace( "%s( LCD=%d )", __FUNCTION__, LCDx );

        if ( ( Status = LCD_IsValid( LCDx ) ) != LCD_Status_Success )
        {
            break;
        }

        Status = LCD_Instance_Flush( &LCD_Context.Instance[ LCDx ] );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char LCD_VERSION[] = "0.0.0.v20260202-1914";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
