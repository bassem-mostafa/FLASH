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
    FLASH_Instance_t Instance[ FLASH_Count ];
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
    FLASH_Status_t Status = FLASH_Status_Error;
    do
    {
        FLASH_Trace( "%s( void )", __FUNCTION__ );
        for ( FLASH_t FLASH_x = FLASH_Null; FLASH_x < FLASH_Count; ++FLASH_x )
        {
            FLASH_Context.Instance[ FLASH_x ].FLASHx = FLASH_x;
        }
        Status = FLASH_Status_Success;
    }
    while ( 0 );
    return Status;
}

static FLASH_Status_t FLASH_Context_Cycle( void )
{
    FLASH_Status_t Status = FLASH_Status_Error;
    do
    {
        FLASH_Trace( "%s( void )", __FUNCTION__ );

        Status = FLASH_Status_Success;
    }
    while ( 0 );
    return Status;
}

static FLASH_Status_t FLASH_Context_DeInitialize( void )
{
    FLASH_Status_t Status = FLASH_Status_Error;
    do
    {
        FLASH_Trace( "%s( void )", __FUNCTION__ );

        Status = FLASH_Status_Success;
    }
    while ( 0 );
    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

FLASH_Status_t FLASH_Initialize( FLASH_t FLASHx )
{
    FLASH_Status_t Status = FLASH_Status_Error;

    do
    {
        FLASH_Trace( "%s( FLASHx=%d )", __FUNCTION__, FLASHx );

        if ( ( Status = FLASH_IsValid( FLASHx ) ) != FLASH_Status_Success )
        {
            break;
        }

        if ( ( Status = FLASH_Context_Initialize( ) ) != FLASH_Status_Success )
        {
            break;
        }

        for ( FLASH_t FLASH_x = FLASH_Null; FLASH_x < FLASH_Count; ++FLASH_x )
        {
            if ( FLASHx != FLASH_All && FLASHx != FLASH_x )
            {
                continue;
            }

            FLASH_Status_t FLASH_Status = FLASH_Status_Success;
            if ( ( FLASH_Status = FLASH_Instance_Initialize( &FLASH_Context.Instance[ FLASH_x ] ) ) != FLASH_Status_Success )
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
    FLASH_Status_t Status = FLASH_Status_Error;

    do
    {
        FLASH_Trace( "%s( FLASHx=%d )", __FUNCTION__, FLASHx );

        if ( ( Status = FLASH_IsValid( FLASHx ) ) != FLASH_Status_Success )
        {
            break;
        }

        if ( ( Status = FLASH_Context_Cycle( ) ) != FLASH_Status_Success )
        {
            break;
        }

        for ( FLASH_t FLASH_x = FLASH_Null; FLASH_x < FLASH_Count; ++FLASH_x )
        {
            if ( FLASHx != FLASH_All && FLASHx != FLASH_x )
            {
                continue;
            }

            FLASH_Status_t FLASH_Status = FLASH_Status_Success;
            if ( ( FLASH_Status = FLASH_Instance_Cycle( &FLASH_Context.Instance[ FLASH_x ] ) ) != FLASH_Status_Success )
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
    FLASH_Status_t Status = FLASH_Status_Error;

    do
    {
        FLASH_Trace( "%s( FLASHx=%d )", __FUNCTION__, FLASHx );

        if ( ( Status = FLASH_IsValid( FLASHx ) ) != FLASH_Status_Success )
        {
            break;
        }

        for ( FLASH_t FLASH_x = FLASH_Null; FLASH_x < FLASH_Count; ++FLASH_x )
        {
            if ( FLASHx != FLASH_All && FLASHx != FLASH_x )
            {
                continue;
            }

            FLASH_Status_t FLASH_Status = FLASH_Status_Success;
            if ( ( FLASH_Status = FLASH_Instance_DeInitialize( &FLASH_Context.Instance[ FLASH_x ] ) ) != FLASH_Status_Success )
            {
                Status = FLASH_Status;
            }
        }

        Status = FLASH_Context_DeInitialize( );
    }
    while ( 0 );

    return Status;
}

FLASH_Status_t FLASH_Write( FLASH_t FLASHx, FLASH_Address_t Address, FLASH_Data_t * Data, FLASH_DataLength_t DataLength )
{
    FLASH_Status_t Status = FLASH_Status_Error;
    do
    {
        FLASH_Trace( "%s( FLASH=%d, Address=%08X, Data=%p, Length=%d )", __FUNCTION__, FLASHx, Address, Data, DataLength );
        if ( ( Status = FLASH_IsValid( FLASHx ) ) != FLASH_Status_Success )
        {
            break;
        }
        FLASH_Instance_t * Instance = &FLASH_Context.Instance[ FLASHx ];
        Status = FLASH_Instance_Write( Instance, Address, Data, DataLength );
    }
    while ( 0 );
    return Status;
}

FLASH_Status_t FLASH_Read( FLASH_t FLASHx, FLASH_Address_t Address, FLASH_Data_t * Data, FLASH_DataLength_t DataLength )
{
    FLASH_Status_t Status = FLASH_Status_Error;
    do
    {
        FLASH_Trace( "%s( FLASH=%d, Address=%08X, Data=%p, Length=%d )", __FUNCTION__, FLASHx, Address, Data, DataLength );
        if ( ( Status = FLASH_IsValid( FLASHx ) ) != FLASH_Status_Success )
        {
            break;
        }
        FLASH_Instance_t * Instance = &FLASH_Context.Instance[ FLASHx ];
        Status = FLASH_Instance_Read( Instance, Address, Data, DataLength );
    }
    while ( 0 );
    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char FLASH_VERSION[] = "0.0.0.v20260202-1914";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
