/******************************************************************
 * @Module   	: Dio
 * @Title 	 	: DIO Module Source file
 * @Filename 	: Dio.c
 * @target  	: TivaC TM4C123GH6PM Microcontroller
 * @Author 	 	: Hossam Mohamed
 * @Compiler 	: IAR 
 * @Notes    	: 
 ********************************************************************/

#include "Dio.h"
#include "Dio_Regs.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)

	#include "Det.h"

	/* AUTOSAR Version checking between Det and Dio Modules */
	#if ((DET_AR_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION) || \
		 (DET_AR_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION) || \
		 (DET_AR_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
		#error "The AR version of Det.h does not match the expected version"
	#endif

#endif

STATIC const Dio_ConfigChannel* Dio_PortChannels = NULL_PTR;
STATIC uint8					Dio_Status = DIO_NOT_INITIALIZED;

/************************************************************************************
*  Service name      : Dio_Init
*  Syntax            : void Dio_Init(const Dio_ConfigType* ConfigPtr)
*  Mode              : Supervisor Mode (Privileged Mode)
*  Service ID[hex]   : 0x10
*  Sync/Async        : Synchronous
*  Reentrancy        : Non Reentrant
*  Parameters (in)   : ConfigPtr - Pointer to post-build configuration data
*  Parameters (inout): None 
*  Parameters (out)  : None
*  Return value      : None
*  Description       : Function to Initialize the Dio module and point to the PB configuration structure using a
*  					   global pointer. This global pointer is global to be used by other functions to read the
* 					   PB configuration structures
 ************************************************************************************/
void Dio_Init(const Dio_ConfigType* ConfigPtr)
{
#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_INIT_SID, DIO_E_PARAM_CONFIG);
	}
	else
#endif
	{
		/*
		 * Set the module state to initialized and point to the PB configuration structure using a
		 * global pointer. This global pointer is global to be used by other functions to read the
		 * PB configuration structures
		 */
		Dio_Status = DIO_INITIALIZED;

		/* address of the first Channels structure --> Channels[0] */
		Dio_PortChannels = ConfigPtr->Channels;
	}
}

/************************************************************************************
*  Service name      : Dio_WriteChannel
*  Syntax            : void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
*  Mode              : Supervisor Mode (Privileged Mode)
*  Service ID[hex]   : 0x01
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : ChannelId - ID of DIO channel
*                      Level - Value to be written
*  Parameters (inout): None
*  Parameters (out)  : None
*  Return value      : None
*  Description       : Service to set a level of a channel.
 ************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	volatile uint32* Port_DATA_ptr = NULL_PTR;
	boolean			 error = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used channel is within the valid range */
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_SID,
						DIO_E_PARAM_INVALID_CHANNEL_ID);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	/* In-case there are no errors */
	if (FALSE == error)
	{
		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		Port_DATA_ptr = GPIODATA[Dio_PortChannels[ChannelId].Port_Num];

		/* Write the required level in the corresponding ChannelId in the Port */
		if (Level == STD_HIGH) /* Write Logic High */
		{
			/* Misra justfication: Assuming Port_DATA_ptr and Dio_PortChannels[ChannelId].Ch_Num are of appropriate types */
			SET_BIT(*Port_DATA_ptr, Dio_PortChannels[ChannelId].Ch_Num);
		}
		else if (Level == STD_LOW) /* Write Logic Low */
		{
			/* Misra justfication: Assuming Port_DATA_ptr and Dio_PortChannels[ChannelId].Ch_Num are of appropriate types */
			CLEAR_BIT(*Port_DATA_ptr, Dio_PortChannels[ChannelId].Ch_Num);
		}
		else
		{
			/* No Action Required */
		}
	}
	else
	{
		/* No Action Required */
	}
}

/************************************************************************************
*  Service name      : Dio_ReadChannel
*  Syntax            : Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
*  Mode              : Supervisor Mode (Privileged Mode)
*  Service ID[hex]   : 0x00
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : ChannelId
*                      ID of DIO channel
*  Parameters (inout): None
*  Parameters (out)  : None
*  Return value      : Dio_LevelType:
*					   - STD_HIGH The physical level of the corresponding Pin is STD_HIGH
*                      - STD_LOW The physical level of the corresponding Pin is STD_LOW
*  Description       : Returns the value of the specified DIO channel.
 ************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	volatile uint32* Port_DATA_ptr = NULL_PTR;
	boolean			 error = FALSE;

	Dio_LevelType ChannelLevel = STD_LOW; /* Default value */

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used channel is within the valid range */
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_SID,
						DIO_E_PARAM_INVALID_CHANNEL_ID);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	/* In-case there are no errors */
	if (FALSE == error)
	{
		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		Port_DATA_ptr = GPIODATA[Dio_PortChannels[ChannelId].Port_Num];

		if (READ_BIT(*Port_DATA_ptr, Dio_PortChannels[ChannelId].Ch_Num) == STD_HIGH)
		//if (IS_BIT_SET(*Port_DATA_ptr, Dio_PortChannels[ChannelId].Ch_Num) == STD_HIGH)
		{
			ChannelLevel = STD_HIGH;
		}
		else
		{
			ChannelLevel = STD_LOW;
		}
	}
	else
	{
		/* No Action Required */
	}

	return ChannelLevel;
}

/************************************************************************************
*  Service name      : Dio_ReadPort
*  Syntax            : Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
*  Mode              : Supervisor Mode (Privileged Mode)
*  Service ID[hex]   : 0x02
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : PortId - ID of DIO Port
*  Parameters (inout): None
*  Parameters (out)  : None
*  Return value      : Dio_PortLevelType - Level of all channels of that port
*  Description       : Returns the level of all channels of that port.
 ************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	volatile uint32* Port_DATA_ptr = NULL_PTR;
	boolean			 error = FALSE;

	Dio_PortLevelType PortLevel = STD_LOW; /* Default value */

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_PORT_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if Invalid port name requested */
	if (DIO_CONFIGURED_PORTS <= PortId)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_PORT_SID,
						DIO_E_PARAM_INVALID_PORT_ID);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif
	/* In-case there are no errors */
	if (FALSE == error)
	{
		Port_DATA_ptr = GPIODATA[PortId];
		PortLevel = (Dio_PortLevelType)(*Port_DATA_ptr); //TODO: check if this is correct
	}
	else
	{
		/* No Action Required */
	}
	return PortLevel;
}

/************************************************************************************
 * Service name      : Dio_ReadPort
*  Syntax            : Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
*  Mode              : Supervisor Mode (Privileged Mode)
*  Service ID[hex]   : 0x02
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : PortId - ID of DIO Port
*  Parameters (inout): None
*  Parameters (out)  : None
*  Return value      : Dio_PortLevelType - Level of all channels of that port
*  Description       : Returns the level of all channels of that port.
 ************************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
	volatile uint32* Port_DATA_ptr = NULL_PTR;
	boolean			 error = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_PORT_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if Invalid port name requested */
	if (DIO_CONFIGURED_PORTS <= PortId)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_PORT_SID,
						DIO_E_PARAM_INVALID_PORT_ID);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	if (FALSE == error)
	{
		Port_DATA_ptr = GPIODATA[PortId];
		*Port_DATA_ptr = Level; // TODO: check if this is correct
	}
	else
	{
		/* No Action Required */
	}
}

/************************************************************************************
*  Service name      : Dio_ReadChannelGroup
*  Syntax            : Dio_PortLevelType Dio_ReadChannelGroup(
*                              const Dio_ChannelGroupType* ChannelGroupIdPtr )
*  Mode              : Supervisor Mode (Privileged Mode)
*  Service ID[hex]   : 0x04
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : ChannelGroupIdPtr - Pointer to ChannelGroup
*  Parameters (inout): None
*  Parameters (out)  : None
*  Return value      : Dio_PortLevelType - Level of a subset of the adjoining
*                      bits of a port
*  Description       : This Service read a subset of the adjoining bits of a
*                      port.
 ************************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
	volatile uint32* Port_DATA_ptr = NULL_PTR;
	boolean			 error = FALSE;

	Dio_PortLevelType GroupLevel = STD_LOW; /* Default value */

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_GROUP_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if ChannelGroupIdPtr is a NULL_PTR */
	if (NULL_PTR == ChannelGroupIdPtr)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_GROUP_SID,
						DIO_E_PARAM_POINTER);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	if (FALSE == error)
	{
		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		Port_DATA_ptr = GPIODATA[ChannelGroupIdPtr->PortIndex];

		/* Read the required bits from the input port and mask it with the required value */ //TODO: check if this is correct
		GroupLevel = ((*Port_DATA_ptr) >> ChannelGroupIdPtr->offset) & ChannelGroupIdPtr->mask;
	}
	else
	{
		/* No Action Required */
	}
	return GroupLevel;
}

/************************************************************************************
 * Service name      : Dio_WriteChannelGroup
*  Syntax            : void Dio_WriteChannelGroup( const Dio_ChannelGroupType*
*                              ChannelGroupIdPtr, Dio_PortLevelType Level )
*  Mode              : Supervisor Mode (Privileged Mode)
*  Service ID[hex]   : 0x05
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : ChannelGroupIdPtr - Pointer to ChannelGroup
*                      Level - Value to be written
*  Parameters (inout): None
*  Parameters (out)  : None
*  Return value      : None
*  Description       : Service to set a subset of the adjoining bits of a port
*                      to a specified level
 ************************************************************************************/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level)
{
	volatile uint32* Port_DATA_ptr = NULL_PTR;
	uint8			 mask = STD_LOW;
	uint8			 offset = STD_LOW;

	boolean error = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if ChannelGroupIdPtr is a NULL_PTR */
	if (NULL_PTR == ChannelGroupIdPtr)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_GROUP_SID,
						DIO_E_PARAM_POINTER);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif
	/* In-case there are no errors */
	if (FALSE == error)
	{
		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		Port_DATA_ptr = GPIODATA[ChannelGroupIdPtr->PortIndex];

		/* Get the mask and offset of the ChannelGroupIdPtr */
		mask = ChannelGroupIdPtr->mask;
		offset = ChannelGroupIdPtr->offset;

		/* Read the required bits from the input port and mask it with the required value */ //TODO: check if this is correct
		*Port_DATA_ptr = ((*Port_DATA_ptr) & (~(mask << offset))) | ((Level & mask) << offset);
	}
	else
	{
		/* No Action Required */
	}
}

/************************************************************************************
*  Service name      : Dio_GetVersionInfo
*  Syntax            : void Dio_GetVersionInfo(Std_VersionInfoType* versioninfo )
*  Mode              : User Mode (Non-Privileged Mode)
*  Service ID[hex]   : 0x12
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : None
*  Parameters (inout): None
*  Parameters (out)  : versioninfo - Pointer to where to store the version
*                      information of this module.
*  Return value      : None
*  Description       : Service to get the version information of this module
 ************************************************************************************/
#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
	#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if (NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_GET_VERSION_INFO_SID,
						DIO_E_PARAM_POINTER);
	}
	else
	#endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)DIO_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)DIO_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)DIO_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)DIO_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)DIO_SW_PATCH_VERSION;
	}
}
#endif

/************************************************************************************
*  Service name      : Dio_FlipChannel
*  Syntax            : Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
*  Mode              : Supervisor Mode (Privileged Mode)
*  Service ID[hex]   : 0x11
*  Sync/Async        : Synchronous
*  Reentrancy        : Reentrant
*  Parameters (in)   : ChannelId
*                      - ID of DIO channel
*  Parameters (inout): None
*  Parameters (out)  : None
*  Return value      : Dio_LevelType
*  Return value      : Dio_LevelType - STD_HIGH The physical level of the
*                      corresponding Pin is STD_HIGH
*                      - STD_LOW The physical level of the corresponding Pin is
*                      STD_LOW
*  Description       : Service to flip (change from 1 to 0 or from 0 to 1) the
*                      level of a channel and return the level of the channel
*                      after flip
 ************************************************************************************/
#if (DIO_FLIP_CHANNEL_API == STD_ON)
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	volatile uint32* Port_DATA_ptr = NULL_PTR;
	boolean			 error = FALSE;

	Dio_LevelType ChannelLevel = STD_LOW; /* Default value */

	#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_FLIP_CHANNEL_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used channel is within the valid range */
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_FLIP_CHANNEL_SID,
						DIO_E_PARAM_INVALID_CHANNEL_ID);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	#endif

	/* In-case there are no errors */
	if (FALSE == error)
	{
		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		Port_DATA_ptr = GPIODATA[Dio_PortChannels[ChannelId].Port_Num];

		/* Toggle the required channel */
		TOGGLE_BIT(*Port_DATA_ptr, Dio_PortChannels[ChannelId].Ch_Num);

		/* Read the channel level after toggle */
		if (READ_BIT(*Port_DATA_ptr, Dio_PortChannels[ChannelId].Ch_Num) == STD_HIGH)
		{
			ChannelLevel = STD_HIGH;
		}
		else
		{
			ChannelLevel = STD_LOW;
		}
	}
	else
	{
		/* No Action Required */
	}

	return ChannelLevel;
}
#endif
