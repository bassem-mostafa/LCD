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

/**
 *  @file
 *
 *  @brief Platform LCD Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_LCD LCD
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_LCD_Driver Driver
 *
 *  @{
 *  @}
 */

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

    #include <stdint.h>

    #include "LCD_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief LCD Operation Status
     *
     *  @enum LCD_Status_t
     */
    typedef enum LCD_Status
    {
        LCD_Status_Success = 0,     ///< Success
        LCD_Status_ArgumentInvalid, ///< Argument Invalid
        LCD_Status_NotSupported,    ///< Not Supported
        LCD_Status_Error,           ///< General Error
        LCD_Status_Busy,            ///< Busy
        LCD_Status_Timeout,         ///< Timeout
    } LCD_Status_t;

    /**
     *  @brief LCD Coordinate
     *
     *  @struct LCD_Coordinate_t
     */
    typedef struct LCD_Coordinate
    {
        uint32_t Row;
        uint32_t Column;
    } LCD_Coordinate_t;

    /**
     *  @brief LCD Size
     *
     *  @struct LCD_Size_t
     */
    typedef struct LCD_Size
    {
        uint32_t Width;
        uint32_t Height;
    } LCD_Size_t;

    /**
     *  @brief LCD Character
     */
    typedef uint8_t LCD_Character_t;

    /**
     *  @brief LCD Pixel
     */
    typedef uint32_t LCD_Pixel_t;

    /**
     *  @brief LCD Screen
     */
    typedef LCD_Pixel_t * LCD_Screen_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize LCD instance
     *
     *  @note MUST BE called before using any LCD API
     *
     *  @param[in] LCDx Instance
     *
     *  @return LCD_Status_t
     */
    LCD_Status_t LCD_Initialize( LCD_t LCDx );

    /**
     *  @brief Cycle LCD instance
     *
     *  @param[in] LCDx Instance
     *
     *  @return LCD_Status_t
     */
    LCD_Status_t LCD_Cycle( LCD_t LCDx );

    /**
     *  @brief DeInitialize LCD instance
     *
     *  @param[in] LCDx Instance
     *
     *  @return LCD_Status_t
     */
    LCD_Status_t LCD_DeInitialize( LCD_t LCDx );

    /**
     *  @brief Check readiness of LCD instance
     *
     *  @param[in] LCDx Instance
     *
     *  @return LCD_Status_t
     */
    LCD_Status_t LCD_IsReady( LCD_t LCDx );

    /**
     *  @brief Get size of LCD instance
     *
     *  @param[in]  LCDx Instance
     *  @param[out] Size Screen dimensions
     *
     *  @return LCD_Status_t
     */
    LCD_Status_t LCD_GetSize( LCD_t LCDx, LCD_Size_t * Size );

    /**
     *  @brief Set cursor location on LCD instance
     *
     *  @param[in] LCDx       Instance
     *  @param[in] Coordinate Location
     *
     *  @return LCD_Status_t
     */
    LCD_Status_t LCD_SetCursor( LCD_t LCDx, LCD_Coordinate_t Coordinate );

    /**
     *  @brief Write character on LCD instance
     *
     *  @param[in] LCDx      Instance
     *  @param[in] Character Character
     *
     *  @return LCD_Status_t
     */
    LCD_Status_t LCD_Write( LCD_t LCDx, LCD_Character_t Character );

    /**
     *  @brief Set pixel on LCD instance
     *
     *  @param[in] LCDx       Instance
     *  @param[in] Coordinate Location
     *  @param[in] Pixel      Value
     *
     *  @return LCD_Status_t
     */
    LCD_Status_t LCD_SetPixel( LCD_t LCDx, LCD_Coordinate_t Coordinate, LCD_Pixel_t Pixel );

    /**
     *  @brief Get screen of LCD instance
     *
     *  @param[in] LCDx   Instance
     *  @param[in] Screen Shadow buffer content
     *
     *  @return LCD_Status_t
     */
    LCD_Status_t LCD_GetScreen( LCD_t LCDx, LCD_Screen_t * Screen );

    /**
     *  @brief Flush LCD instance
     *
     *  @param[in] LCDx Instance
     *
     *  @return LCD_Status_t
     */
    LCD_Status_t LCD_Flush( LCD_t LCDx );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char LCD_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* LCD_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
