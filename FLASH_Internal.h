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

#ifndef FLASH_INTERNAL_H_
    #define FLASH_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "FLASH_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef FLASH_TIM
        #define FLASH_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef FLASH_LOG
        #define FLASH_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define FLASH_NAME       "FLASH"
    #define FLASH_LOG_PREFIX UTIL_StringConcatenateConstant( FLASH_NAME, "> " )

    #ifdef DEBUG
        #define FLASH_Raw( Level, Format, ... ) LOG_Raw( FLASH_LOG, Level, Format, ##__VA_ARGS__ )
        #define FLASH_Trace( Format, ... )      LOG_Trace( FLASH_LOG, UTIL_StringConcatenateConstant( FLASH_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define FLASH_Debug( Format, ... )      LOG_Debug( FLASH_LOG, UTIL_StringConcatenateConstant( FLASH_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define FLASH_Info( Format, ... )       LOG_Info( FLASH_LOG, UTIL_StringConcatenateConstant( FLASH_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define FLASH_Warning( Format, ... )    LOG_Warning( FLASH_LOG, UTIL_StringConcatenateConstant( FLASH_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define FLASH_Error( Format, ... )      LOG_Error( FLASH_LOG, UTIL_StringConcatenateConstant( FLASH_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define FLASH_Fatal( Format, ... )      LOG_Fatal( FLASH_LOG, UTIL_StringConcatenateConstant( FLASH_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define FLASH_Raw( Level, Format, ... )
        #define FLASH_Trace( Format, ... )
        #define FLASH_Debug( Format, ... )
        #define FLASH_Info( Format, ... )
        #define FLASH_Warning( Format, ... )
        #define FLASH_Error( Format, ... )
        #define FLASH_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef struct FLASH_Instance_Context_t FLASH_Instance_Context_t;

    typedef struct FLASH_Instance
    {
        FLASH_t FLASHx;

        union
        {
            FLASH_Instance_Context_t * Context;
        };
    } FLASH_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    FLASH_Status_t FLASH_IsValid( FLASH_t FLASHx );

    FLASH_Status_t FLASH_Instance_Initialize( FLASH_Instance_t * Instance );
    FLASH_Status_t FLASH_Instance_Cycle( FLASH_Instance_t * Instance );
    FLASH_Status_t FLASH_Instance_DeInitialize( FLASH_Instance_t * Instance );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* FLASH_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
