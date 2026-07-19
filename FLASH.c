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

#include "FLASH.h"
#include "FLASH_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

typedef struct FLASH_Context
{
} FLASH_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static FLASH_Status_t FLASH_Context_Initialize( void );
static FLASH_Status_t FLASH_Context_Cycle( void );
static FLASH_Status_t FLASH_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static FLASH_Context_t FLASH_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static FLASH_Status_t FLASH_Context_Initialize( void )
{
    FLASH_Status_t Status = FLASH_Status_Success;

    do
    {
        FLASH_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( FLASH_Context );
    }
    while ( 0 );

    return Status;
}

static FLASH_Status_t FLASH_Context_Cycle( void )
{
    FLASH_Status_t Status = FLASH_Status_Success;

    do
    {
        FLASH_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( FLASH_Context );
    }
    while ( 0 );

    return Status;
}

static FLASH_Status_t FLASH_Context_DeInitialize( void )
{
    FLASH_Status_t Status = FLASH_Status_Success;

    do
    {
        FLASH_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( FLASH_Context );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

FLASH_Status_t FLASH_Initialize( FLASH_t FLASHx )
{
    FLASH_Status_t Status = FLASH_Status_Success;
    FLASH_Status_t FLASH_Status = FLASH_Status_Success;

    do
    {
        FLASH_Trace( "%s( FLASHx=%d )", __FUNCTION__, FLASHx );

        if ( ( Status = FLASH_Context_Initialize( ) ) != FLASH_Status_Success )
        {
            break;
        }

        FLASH_t FLASH_start = ( FLASHx == FLASH_All ? FLASH_Null : FLASHx );
        FLASH_t FLASH_end = ( FLASHx == FLASH_All ? FLASH_Count : FLASHx + 1 );
        for ( FLASH_t FLASH_x = FLASH_start; FLASH_x < FLASH_end; ++FLASH_x )
        {
            if ( ( FLASH_Status = FLASH_Port_Initialize( FLASH_x ) ) != FLASH_Status_Success )
            {
                Status = FLASH_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

FLASH_Status_t FLASH_Cycle( FLASH_t FLASHx )
{
    FLASH_Status_t Status = FLASH_Status_Success;
    FLASH_Status_t FLASH_Status = FLASH_Status_Success;

    do
    {
        FLASH_Trace( "%s( FLASHx=%d )", __FUNCTION__, FLASHx );

        if ( ( Status = FLASH_Context_Cycle( ) ) != FLASH_Status_Success )
        {
            break;
        }

        FLASH_t FLASH_start = ( FLASHx == FLASH_All ? FLASH_Null : FLASHx );
        FLASH_t FLASH_end = ( FLASHx == FLASH_All ? FLASH_Count : FLASHx + 1 );
        for ( FLASH_t FLASH_x = FLASH_start; FLASH_x < FLASH_end; ++FLASH_x )
        {
            if ( ( FLASH_Status = FLASH_Port_Cycle( FLASH_x ) ) != FLASH_Status_Success )
            {
                Status = FLASH_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

FLASH_Status_t FLASH_DeInitialize( FLASH_t FLASHx )
{
    FLASH_Status_t Status = FLASH_Status_Success;
    FLASH_Status_t FLASH_Status = FLASH_Status_Success;

    do
    {
        FLASH_Trace( "%s( FLASHx=%d )", __FUNCTION__, FLASHx );

        FLASH_t FLASH_start = ( FLASHx == FLASH_All ? FLASH_Null : FLASHx );
        FLASH_t FLASH_end = ( FLASHx == FLASH_All ? FLASH_Count : FLASHx + 1 );
        for ( FLASH_t FLASH_x = FLASH_start; FLASH_x < FLASH_end; ++FLASH_x )
        {
            if ( ( FLASH_Status = FLASH_Port_DeInitialize( FLASH_x ) ) != FLASH_Status_Success )
            {
                Status = FLASH_Status;
            }
        }

        if ( ( Status = FLASH_Context_DeInitialize( ) ) != FLASH_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

FLASH_Status_t FLASH_Write( FLASH_t FLASHx, FLASH_Address_t Address, FLASH_Data_t * Data, FLASH_DataLength_t DataLength )
{
    FLASH_Status_t Status = FLASH_Status_Success;
    FLASH_Status_t FLASH_Status = FLASH_Status_Success;

    do
    {
        FLASH_Trace( "%s( FLASHx=%d )", __FUNCTION__, FLASHx );

        if ( Data == NULL || DataLength < 1 )
        {
            Status = FLASH_Status_ArgumentInvalid;
            break;
        }

        if ( FLASHx == FLASH_All )
        {
            // FIXME Is it required to define a criteria to write FLASH on all peripherals ?
            Status = FLASH_Status_NotSupported;
            break;
        }

        FLASH_t FLASH_start = ( FLASHx == FLASH_All ? FLASH_Null : FLASHx );
        FLASH_t FLASH_end = ( FLASHx == FLASH_All ? FLASH_Count : FLASHx + 1 );
        for ( FLASH_t FLASH_x = FLASH_start; FLASH_x < FLASH_end; ++FLASH_x )
        {
            if ( ( FLASH_Status = FLASH_Port_Write( FLASH_x, Address, Data, DataLength ) ) != FLASH_Status_Success )
            {
                Status = FLASH_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

FLASH_Status_t FLASH_Read( FLASH_t FLASHx, FLASH_Address_t Address, FLASH_Data_t * Data, FLASH_DataLength_t DataLength )
{
    FLASH_Status_t Status = FLASH_Status_Success;
    FLASH_Status_t FLASH_Status = FLASH_Status_Success;

    do
    {
        FLASH_Trace( "%s( FLASHx=%d )", __FUNCTION__, FLASHx );

        if ( Data == NULL || DataLength < 1 )
        {
            Status = FLASH_Status_ArgumentInvalid;
            break;
        }

        if ( FLASHx == FLASH_All )
        {
            // FIXME Is it required to define a criteria to read FLASH on all peripherals ?
            Status = FLASH_Status_NotSupported;
            break;
        }

        FLASH_t FLASH_start = ( FLASHx == FLASH_All ? FLASH_Null : FLASHx );
        FLASH_t FLASH_end = ( FLASHx == FLASH_All ? FLASH_Count : FLASHx + 1 );
        for ( FLASH_t FLASH_x = FLASH_start; FLASH_x < FLASH_end; ++FLASH_x )
        {
            if ( ( FLASH_Status = FLASH_Port_Read( FLASH_x, Address, Data, DataLength ) ) != FLASH_Status_Success )
            {
                Status = FLASH_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char FLASH_VERSION[] = "0.0.0.v20260719-2341";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
