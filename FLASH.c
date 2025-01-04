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

#include "EEPROM.h"
#include "EEPROM_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

typedef struct EEPROM_Context
{
    EEPROM_Instance_t Instance[ EEPROM_Count ];
} EEPROM_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static EEPROM_Status_t EEPROM_Context_Initialize( void );
static EEPROM_Status_t EEPROM_Context_Cycle( void );
static EEPROM_Status_t EEPROM_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static EEPROM_Context_t EEPROM_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static EEPROM_Status_t EEPROM_Context_Initialize( void )
{
    EEPROM_Status_t Status = EEPROM_Status_Error;
    do
    {
        EEPROM_Trace( "%s( void )", __FUNCTION__ );
        for ( EEPROM_t EEPROM_x = EEPROM_Null; EEPROM_x < EEPROM_Count; ++EEPROM_x )
        {
            EEPROM_Context.Instance[ EEPROM_x ].EEPROMx = EEPROM_x;
        }
        Status = EEPROM_Status_Success;
    }
    while ( 0 );
    return Status;
}

static EEPROM_Status_t EEPROM_Context_Cycle( void )
{
    EEPROM_Status_t Status = EEPROM_Status_Error;
    do
    {
        EEPROM_Trace( "%s( void )", __FUNCTION__ );

        Status = EEPROM_Status_Success;
    }
    while ( 0 );
    return Status;
}

static EEPROM_Status_t EEPROM_Context_DeInitialize( void )
{
    EEPROM_Status_t Status = EEPROM_Status_Error;
    do
    {
        EEPROM_Trace( "%s( void )", __FUNCTION__ );

        Status = EEPROM_Status_Success;
    }
    while ( 0 );
    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

EEPROM_Status_t EEPROM_Initialize( EEPROM_t EEPROMx )
{
    EEPROM_Status_t Status = EEPROM_Status_Error;

    do
    {
        EEPROM_Trace( "%s( EEPROMx=%d )", __FUNCTION__, EEPROMx );

        if ( ( Status = EEPROM_IsValid( EEPROMx ) ) != EEPROM_Status_Success )
        {
            break;
        }

        if ( ( Status = EEPROM_Context_Initialize( ) ) != EEPROM_Status_Success )
        {
            break;
        }

        for ( EEPROM_t EEPROM_x = EEPROM_Null; EEPROM_x < EEPROM_Count; ++EEPROM_x )
        {
            if ( EEPROMx != EEPROM_All && EEPROMx != EEPROM_x )
            {
                continue;
            }

            EEPROM_Status_t EEPROM_Status = EEPROM_Status_Success;
            if ( ( EEPROM_Status = EEPROM_Instance_Initialize( &EEPROM_Context.Instance[ EEPROM_x ] ) ) != EEPROM_Status_Success )
            {
                Status = EEPROM_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

EEPROM_Status_t EEPROM_Cycle( EEPROM_t EEPROMx )
{
    EEPROM_Status_t Status = EEPROM_Status_Error;

    do
    {
        EEPROM_Trace( "%s( EEPROMx=%d )", __FUNCTION__, EEPROMx );

        if ( ( Status = EEPROM_IsValid( EEPROMx ) ) != EEPROM_Status_Success )
        {
            break;
        }

        if ( ( Status = EEPROM_Context_Cycle( ) ) != EEPROM_Status_Success )
        {
            break;
        }

        for ( EEPROM_t EEPROM_x = EEPROM_Null; EEPROM_x < EEPROM_Count; ++EEPROM_x )
        {
            if ( EEPROMx != EEPROM_All && EEPROMx != EEPROM_x )
            {
                continue;
            }

            EEPROM_Status_t EEPROM_Status = EEPROM_Status_Success;
            if ( ( EEPROM_Status = EEPROM_Instance_Cycle( &EEPROM_Context.Instance[ EEPROM_x ] ) ) != EEPROM_Status_Success )
            {
                Status = EEPROM_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

EEPROM_Status_t EEPROM_DeInitialize( EEPROM_t EEPROMx )
{
    EEPROM_Status_t Status = EEPROM_Status_Error;

    do
    {
        EEPROM_Trace( "%s( EEPROMx=%d )", __FUNCTION__, EEPROMx );

        if ( ( Status = EEPROM_IsValid( EEPROMx ) ) != EEPROM_Status_Success )
        {
            break;
        }

        for ( EEPROM_t EEPROM_x = EEPROM_Null; EEPROM_x < EEPROM_Count; ++EEPROM_x )
        {
            if ( EEPROMx != EEPROM_All && EEPROMx != EEPROM_x )
            {
                continue;
            }

            EEPROM_Status_t EEPROM_Status = EEPROM_Status_Success;
            if ( ( EEPROM_Status = EEPROM_Instance_DeInitialize( &EEPROM_Context.Instance[ EEPROM_x ] ) ) != EEPROM_Status_Success )
            {
                Status = EEPROM_Status;
            }
        }

        Status = EEPROM_Context_DeInitialize( );
    }
    while ( 0 );

    return Status;
}

EEPROM_Status_t EEPROM_Write( EEPROM_t EEPROMx, EEPROM_Address_t Address, EEPROM_Data_t * Data, EEPROM_DataLength_t DataLength )
{
    EEPROM_Status_t Status = EEPROM_Status_Error;
    do
    {
        EEPROM_Trace( "%s( EEPROM=%d, Address=%08X, Data=%p, Length=%d )", __FUNCTION__, EEPROMx, Address, Data, DataLength );
        if ( ( Status = EEPROM_IsValid( EEPROMx ) ) != EEPROM_Status_Success )
        {
            break;
        }
        EEPROM_Instance_t * Instance = &EEPROM_Context.Instance[ EEPROMx ];
        Status = EEPROM_Instance_Write( Instance, Address, Data, DataLength );
    }
    while ( 0 );
    return Status;
}

EEPROM_Status_t EEPROM_Read( EEPROM_t EEPROMx, EEPROM_Address_t Address, EEPROM_Data_t * Data, EEPROM_DataLength_t DataLength )
{
    EEPROM_Status_t Status = EEPROM_Status_Error;
    do
    {
        EEPROM_Trace( "%s( EEPROM=%d, Address=%08X, Data=%p, Length=%d )", __FUNCTION__, EEPROMx, Address, Data, DataLength );
        if ( ( Status = EEPROM_IsValid( EEPROMx ) ) != EEPROM_Status_Success )
        {
            break;
        }
        EEPROM_Instance_t * Instance = &EEPROM_Context.Instance[ EEPROMx ];
        Status = EEPROM_Instance_Read( Instance, Address, Data, DataLength );
    }
    while ( 0 );
    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char EEPROM_VERSION[] = "0.0.0.v20260117-1054";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
