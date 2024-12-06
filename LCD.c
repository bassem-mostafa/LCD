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

static LCD_Status_t LCD_Context_Initialize( void );
static LCD_Status_t LCD_Context_Cycle( void );
static LCD_Status_t LCD_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static LCD_Status_t LCD_Context_Initialize( void )
{
    LCD_Status_t LCD_Status = LCD_Status_Error;
    do
    {
        LCD_Trace( "%s( void )", __FUNCTION__ );
        for ( LCD_t LCD = LCD_1; LCD < LCD_NUMBER_OF_INSTANCES; ++LCD )
        {
            LCD_Context.Instance[ LCD ].LCD = LCD;
            if ( ( LCD_Status = LCD_Instance_Initialize( &LCD_Context.Instance[ LCD ] ) ) != LCD_Status_Success )
            {
                LCD_Warning( "LCD_%d Initialize Failed: Status %d", LCD, LCD_Status );
            }
        }
        LCD_Status = LCD_Status_Success;
    }
    while ( 0 );
    return LCD_Status;
}

static LCD_Status_t LCD_Context_Cycle( void )
{
    LCD_Status_t LCD_Status = LCD_Status_Error;
    do
    {
        LCD_Trace( "%s( void )", __FUNCTION__ );
        for ( LCD_t LCD = LCD_1; LCD < LCD_NUMBER_OF_INSTANCES; ++LCD )
        {
            LCD_Context.Instance[ LCD ].LCD = LCD; // FIXME
            if ( ( LCD_Status = LCD_Instance_Cycle( &LCD_Context.Instance[ LCD ] ) ) != LCD_Status_Success )
            {
                LCD_Warning( "LCD_%d Cycle Failed: Status %d", LCD, LCD_Status );
            }
        }
        LCD_Status = LCD_Status_Success;
    }
    while ( 0 );
    return LCD_Status;
}

static LCD_Status_t LCD_Context_DeInitialize( void )
{
    LCD_Status_t LCD_Status = LCD_Status_Error;
    do
    {
        LCD_Trace( "%s( void )", __FUNCTION__ );
        for ( LCD_t LCD = LCD_Null; LCD < LCD_NUMBER_OF_INSTANCES; ++LCD )
        {
            LCD_Context.Instance[ LCD ].LCD = LCD; // FIXME
            if ( ( LCD_Status = LCD_Instance_DeInitialize( &LCD_Context.Instance[ LCD ] ) ) != LCD_Status_Success )
            {
                LCD_Warning( "LCD_%d DeInitialize Failed: Status %d", LCD, LCD_Status );
            }
        }
        LCD_Status = LCD_Status_Success;
    }
    while ( 0 );
    return LCD_Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

LCD_Status_t LCD_Initialize( void )
{
    LCD_Status_t LCD_Status = LCD_Status_Error;
    do
    {
        LCD_Trace( "%s( void )", __FUNCTION__ );
        LCD_Status = LCD_Context_Initialize( );
    }
    while ( 0 );
    return LCD_Status;
}

LCD_Status_t LCD_Cycle( void )
{
    LCD_Status_t LCD_Status = LCD_Status_Error;
    do
    {
        LCD_Trace( "%s( void )", __FUNCTION__ );
        LCD_Status = LCD_Context_Cycle( );
    }
    while ( 0 );
    return LCD_Status;
}

LCD_Status_t LCD_DeInitialize( void )
{
    LCD_Status_t LCD_Status = LCD_Status_Error;
    do
    {
        LCD_Trace( "%s( void )", __FUNCTION__ );
        LCD_Status = LCD_Context_DeInitialize( );
    }
    while ( 0 );
    return LCD_Status;
}

LCD_Status_t LCD_IsReady( LCD_t LCD )
{
    LCD_Status_t LCD_Status = LCD_Status_Error;
    do
    {
        LCD_Trace( "%s( LCD=%d )", __FUNCTION__, LCD );
        if ( ( LCD_Status = LCD_IsValid( LCD ) ) != LCD_Status_Success )
        {
            break;
        }
        LCD_Instance_t * LCD_Instance = &LCD_Context.Instance[ LCD ];
        LCD_Status = LCD_Instance_IsReady( LCD_Instance );
    }
    while ( 0 );
    return LCD_Status;
}

LCD_Status_t LCD_GetSize( LCD_t LCD, LCD_Size_t * LCD_Size )
{
    LCD_Status_t LCD_Status = LCD_Status_Error;
    do
    {
        LCD_Trace( "%s( LCD=%d, Size=%p )", __FUNCTION__, LCD, LCD_Size );
        if ( LCD_Size == NULL )
        {
            LCD_Status = LCD_Status_ArgumentInvalid;
            break;
        }
        if ( ( LCD_Status = LCD_IsValid( LCD ) ) != LCD_Status_Success )
        {
            break;
        }
        LCD_Instance_t * LCD_Instance = &LCD_Context.Instance[ LCD ];
        LCD_Status = LCD_Instance_GetSize( LCD_Instance, LCD_Size );
    }
    while ( 0 );
    return LCD_Status;
}

LCD_Status_t LCD_SetCursor( LCD_t LCD, LCD_Coordinate_t LCD_Coordinate )
{
    LCD_Status_t LCD_Status = LCD_Status_Error;
    do
    {
        LCD_Trace( "%s( LCD=%d, Coordinate={Row=%d, Column=%d} )", __FUNCTION__, LCD, LCD_Coordinate.Row, LCD_Coordinate.Column );
        if ( ( LCD_Status = LCD_IsValid( LCD ) ) != LCD_Status_Success )
        {
            break;
        }
        LCD_Instance_t * LCD_Instance = &LCD_Context.Instance[ LCD ];
        LCD_Status = LCD_Instance_SetCursor( LCD_Instance, LCD_Coordinate );
    }
    while ( 0 );
    return LCD_Status;
}

LCD_Status_t LCD_Write( LCD_t LCD, LCD_Character_t LCD_Character )
{
    LCD_Status_t LCD_Status = LCD_Status_Error;
    do
    {
        LCD_Trace( "%s( LCD=%d, Character=%02X )", __FUNCTION__, LCD, LCD_Character );
        if ( ( LCD_Status = LCD_IsValid( LCD ) ) != LCD_Status_Success )
        {
            break;
        }
        LCD_Instance_t * LCD_Instance = &LCD_Context.Instance[ LCD ];
        LCD_Status = LCD_Instance_Write( LCD_Instance, LCD_Character );
    }
    while ( 0 );
    return LCD_Status;
}

LCD_Status_t LCD_SetPixel( LCD_t LCD, LCD_Coordinate_t LCD_Coordinate, LCD_Pixel_t LCD_Pixel )
{
    LCD_Status_t LCD_Status = LCD_Status_Error;
    do
    {
        LCD_Trace( "%s( LCD=%d, Coordinate={Row=%d, Column=%d}, Pixel=%02X )", __FUNCTION__, LCD, LCD_Coordinate.Row, LCD_Coordinate.Column, LCD_Pixel );
        if ( ( LCD_Status = LCD_IsValid( LCD ) ) != LCD_Status_Success )
        {
            break;
        }
        LCD_Instance_t * LCD_Instance = &LCD_Context.Instance[ LCD ];
        LCD_Status = LCD_Instance_SetPixel( LCD_Instance, LCD_Coordinate, LCD_Pixel );
    }
    while ( 0 );
    return LCD_Status;
}

LCD_Status_t LCD_GetScreen( LCD_t LCD, LCD_Screen_t * LCD_Screen )
{
    LCD_Status_t LCD_Status = LCD_Status_Error;
    do
    {
        LCD_Trace( "%s( LCD=%d, Screen=%p )", __FUNCTION__, LCD, LCD_Screen );
        if ( ( LCD_Status = LCD_IsValid( LCD ) ) != LCD_Status_Success )
        {
            break;
        }
        LCD_Instance_t * LCD_Instance = &LCD_Context.Instance[ LCD ];
        LCD_Status = LCD_Instance_GetScreen( LCD_Instance, LCD_Screen );
    }
    while ( 0 );
    return LCD_Status;
}

LCD_Status_t LCD_Flush( LCD_t LCD )
{
    LCD_Status_t LCD_Status = LCD_Status_Error;
    do
    {
        LCD_Trace( "%s( LCD=%d )", __FUNCTION__, LCD );
        if ( ( LCD_Status = LCD_IsValid( LCD ) ) != LCD_Status_Success )
        {
            break;
        }
        LCD_Instance_t * LCD_Instance = &LCD_Context.Instance[ LCD ];
        LCD_Status = LCD_Instance_Flush( LCD_Instance );
    }
    while ( 0 );
    return LCD_Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char LCD_VERSION[] = "0.0.0.v20260117-1054";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
