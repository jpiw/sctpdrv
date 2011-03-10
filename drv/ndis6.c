/*
 * Copyright (c) 2011 Bruce Cran.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */


#include "version.h"

struct NDISGLOBALS {
	NDIS_HANDLE protocolHandle;
};

typedef struct {
	NDIS_HANDLE bindingHandle;
	NDIS_HANDLE bindContext;
	NDIS_HANDLE unbindContext;
} NDISOPENCONTEXT;

struct NDISGLOBALS ndisGlobals;


NDIS_STATUS NdisProtocolBindAdapterHandler(
  __in  NDIS_HANDLE ProtocolDriverContext,
  __in  NDIS_HANDLE BindContext,
  __in  PNDIS_BIND_PARAMETERS BindParameters)
{
	#define MEDIUM_ARRAY_SIZE 13

	NDIS_STATUS status;
	NDIS_OPEN_PARAMETERS openParams;
	PNDIS_STRING adapterName;
	NDISOPENCONTEXT *openContext;
	NDIS_MEDIUM supportedMediums[MEDIUM_ARRAY_SIZE];
	UINT selectedMedium;
	NET_FRAME_TYPE FrameTypeArray[2] = {NDIS_ETH_TYPE_802_1X, NDIS_ETH_TYPE_802_1Q};

	adapterName = (PNDIS_STRING)BindParameters->AdapterName;

	supportedMediums[0] = NdisMedium802_3;
	supportedMediums[1] = NdisMedium802_5;
	supportedMediums[2] = NdisMediumFddi;
	supportedMediums[3] = NdisMediumWan;
	supportedMediums[4] = NdisMediumLocalTalk;
	supportedMediums[5] = NdisMediumDix;
	supportedMediums[6] = NdisMediumArcnetRaw;
	supportedMediums[7] = NdisMediumArcnet878_2;
	supportedMediums[8] = NdisMediumAtm;
	supportedMediums[9] = NdisMediumWirelessWan;
	supportedMediums[10] = NdisMediumIrda;
	supportedMediums[11] = NdisMediumCoWan;
	supportedMediums[12] = NdisMedium1394;

	NdisZeroMemory(&openParams, sizeof(NDIS_OPEN_PARAMETERS));

	openParams.Header.Type = NDIS_OBJECT_TYPE_OPEN_PARAMETERS;
	openParams.Header.Revision = NDIS_OPEN_PARAMETERS_REVISION_1;
	openParams.Header.Size = NDIS_SIZEOF_OPEN_PARAMETERS_REVSION_1;
	openParams.AdapterName = adapterName;
	openParams.MediumArray = &supportedMediums[0];
	openParams.MediumArraySize = MEDIUM_ARRAY_SIZE;
	openParams.SelectedMediumIndex = &selectedMedium;
	openParams.FrameTypeArray = FrameTypeArray;
	openParams.FrameTypeArraySize = sizeof(FrameTypeArray) / sizeof(NET_FRAME_TYPE);

	openContext = NdisAllocateMemoryWithTagPriority(&ndisGlobals.protocolHandle,
	    sizeof(NDISOPENCONTEXT), 'ptcs', NormalPoolPriority);

	if (openContext == NULL) {
		return NDIS_STATUS_RESOURCES;
	}

	openContext->bindContext = BindContext;

	status = NdisOpenAdapterEx(ndisGlobals.protocolHandle, (NDIS_HANDLE)openContext, &openParams,
		BindContext, &openContext->bindingHandle);

	if (status != NDIS_STATUS_SUCCESS && status != NDIS_STATUS_PENDING)
		NdisFreeMemory((PVOID)openContext, sizeof(NDISOPENCONTEXT), 0);

	return status;
}

NDIS_STATUS NdisProtocolUnbindAdapterHandler(
  __in  NDIS_HANDLE UnbindContext,
  __in  NDIS_HANDLE ProtocolBindingContext)
{
	NDIS_STATUS status;
	NDISOPENCONTEXT *bindingContext = (NDISOPENCONTEXT*)ProtocolBindingContext;

	bindingContext->unbindContext = UnbindContext;
	status = NdisCloseAdapterEx(bindingContext->bindingHandle);
	if (status == NDIS_STATUS_SUCCESS)
		NdisFreeMemory(bindingContext, sizeof(NDISOPENCONTEXT), 0);

	return status;
}

VOID NdisProtocolOpenAdapterCompleteHandlerEx(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  NDIS_STATUS Status)
{
	NDISOPENCONTEXT *openContext = (NDISOPENCONTEXT*)ProtocolBindingContext;

	NdisCompleteBindAdapterEx(openContext->bindContext, Status);
}

VOID NdisProtocolCloseAdapterCompleteHandlerEx(
  __in  NDIS_HANDLE ProtocolBindingContext)
{
	NDISOPENCONTEXT *openContext = (NDISOPENCONTEXT*)ProtocolBindingContext;

	NdisCompleteUnbindAdapterEx(openContext->unbindContext);
	NdisFreeMemory(openContext, sizeof(NDISOPENCONTEXT), 0);
}

VOID NdisProtocolOidRequestCompleteHandler(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  PNDIS_OID_REQUEST OidRequest,
  __in  NDIS_STATUS Status)
{

}

VOID NdisProtocolReceiveNetBufferListsHandler(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  PNET_BUFFER_LIST NetBufferLists,
  __in  NDIS_PORT_NUMBER PortNumber,
  __in  ULONG NumberOfNetBufferLists,
  __in  ULONG ReceiveFlags)
{

}

VOID NdisProtocolSendNetBufferListsCompleteHandler(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  PNET_BUFFER_LIST NetBufferLists,
  __in  ULONG SendCompleteFlags)
{

}

VOID NdisProtocolStatusHandlerEx(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  PNDIS_STATUS_INDICATION StatusIndication)
{

}

NDIS_STATUS NdisProtocolNetPnPEventHandler(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  PNET_PNP_EVENT_NOTIFICATION NetPnPEvent)
{
	return NDIS_STATUS_SUCCESS;
}


DWORD SctpRegisterProtocol(void)
{
	NDIS_PROTOCOL_DRIVER_CHARACTERISTICS protocolChar;
	NDIS_STATUS ndisStatus;
	NDIS_STRING protoName = NDIS_STRING_CONST("sctpdrv");
	DWORD rc = 0;

	NdisZeroMemory(&protocolChar,sizeof(NDIS_PROTOCOL_DRIVER_CHARACTERISTICS));

	protocolChar.Header.Type = NDIS_OBJECT_TYPE_PROTOCOL_DRIVER_CHARACTERISTICS;
	protocolChar.Header.Revision = NDIS_PROTOCOL_DRIVER_CHARACTERISTICS_REVISION_1;
	protocolChar.Header.Size = NDIS_SIZEOF_PROTOCOL_DRIVER_CHARACTERISTICS_REVISION_1;
	protocolChar.MajorNdisVersion = 0x06;
	protocolChar.MinorNdisVersion = 0x00;
	protocolChar.MajorDriverVersion = VER_MAJOR;
	protocolChar.MinorDriverVersion = VER_MINOR;
	protocolChar.Name = protoName;
	protocolChar.OpenAdapterCompleteHandlerEx = NdisProtocolOpenAdapterCompleteHandlerEx;
	protocolChar.CloseAdapterCompleteHandlerEx = NdisProtocolCloseAdapterCompleteHandlerEx;
	protocolChar.SendNetBufferListsCompleteHandler = NdisProtocolSendNetBufferListsCompleteHandler;
	protocolChar.OidRequestCompleteHandler = NdisProtocolOidRequestCompleteHandler;
	protocolChar.StatusHandlerEx = NdisProtocolStatusHandlerEx;
	protocolChar.ReceiveNetBufferListsHandler = NdisProtocolReceiveNetBufferListsHandler;
	protocolChar.NetPnPEventHandler = NdisProtocolNetPnPEventHandler;
	protocolChar.BindAdapterHandlerEx = NdisProtocolBindAdapterHandler;
	protocolChar.UnbindAdapterHandlerEx = NdisProtocolUnbindAdapterHandler;

	ndisStatus = NdisRegisterProtocolDriver(NULL, &protocolChar, &ndisGlobals.protocolHandle);
	if (ndisStatus != NDIS_STATUS_SUCCESS) {
		DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] Failed to register protocol driver, code=%08x\n", ndisStatus);
		rc = 1;
	}

	return rc;
}

void SctpDeregisterProtocol(void)
{
	NdisDeregisterProtocolDriver(&ndisGlobals.protocolHandle);
}