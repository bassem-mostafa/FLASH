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
 *  @brief Platform FLASH Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_FLASH FLASH
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_FLASH_Driver Driver
 *
 *  @{
 *  @}
 */

#ifndef FLASH_H_
    #define FLASH_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include <stdint.h>

    #include "FLASH_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief FLASH Operation Status
     *
     *  @enum FLASH_Status_t
     */
    typedef enum FLASH_Status
    {
        FLASH_Status_Success = 0,     ///< Success
        FLASH_Status_ArgumentInvalid, ///< Invalid Argument
        FLASH_Status_NotSupported,    ///< Not Supported
        FLASH_Status_Error,           ///< General Error
        FLASH_Status_Busy,            ///< Busy
        FLASH_Status_Timeout,         ///< Timeout
    } FLASH_Status_t;

    /**
     *  @brief FLASH Address Type
     */
    typedef uint32_t FLASH_Address_t;

    /**
     *  @brief FLASH Data Type
     */
    typedef uint8_t FLASH_Data_t;

    /**
     *  @brief FLASH Data Length Type
     */
    typedef uint32_t FLASH_DataLength_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize FLASH instance
     *
     *  @note MUST BE called before using any FLASH API
     *
     *  @param[in] FLASHx Instance
     *
     *  @return FLASH_Status_t
     */
    FLASH_Status_t FLASH_Initialize( FLASH_t FLASHx );

    /**
     *  @brief Cycle FLASH instance
     *
     *  @param[in] FLASHx Instance
     *
     *  @return FLASH_Status_t
     */
    FLASH_Status_t FLASH_Cycle( FLASH_t FLASHx );

    /**
     *  @brief DeInitialize FLASH instance
     *
     *  @param[in] FLASHx Instance
     *
     *  @return FLASH_Status_t
     */
    FLASH_Status_t FLASH_DeInitialize( FLASH_t FLASHx );

    /**
     *  @brief Writes data starting from address
     *
     *  @param[in] FLASHx    FLASH to use
     *  @param[in] Address    Starting address
     *  @param[in] Data       Data pointer
     *  @param[in] DataLength Length of data
     *
     *  @return FLASH_Status_t
     */
    FLASH_Status_t FLASH_Write( FLASH_t FLASHx, FLASH_Address_t Address, FLASH_Data_t * Data, FLASH_DataLength_t DataLength );

    /**
     *  @brief Reads data starting from address
     *
     *  @param[in] FLASHx    FLASH to use
     *  @param[in] Address    Starting address
     *  @param[in] Data       Data pointer
     *  @param[in] DataLength Length of data
     *
     *  @return FLASH_Status_t
     */
    FLASH_Status_t FLASH_Read( FLASH_t FLASHx, FLASH_Address_t Address, FLASH_Data_t * Data, FLASH_DataLength_t DataLength );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char FLASH_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* FLASH_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
