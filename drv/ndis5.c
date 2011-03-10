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

struct NDISGLOBALS {
	NDIS_HANDLE protocolHandle;
};

typedef struct
{
	NDIS_HANDLE bindingHandle;
	NDIS_HANDLE bindContext;
	NDIS_HANDLE unbindContext;
} NDISOPENCONTEXT;

struct NDISGLOBALS ndisGlobals;

VOID NdisBindAdapter(
  __out  PNDIS_STATUS Status,
  __in   NDIS_HANDLE BindContext,
  __in   PNDIS_STRING DeviceName,
  __in   PVOID SystemSpecific1,
  __in   PVOID SystemSpecific2)
{
	#define MEDIUM_ARRAY_SIZE 13

	NDIS_STATUS status;
	NDIS_STATUS openErrorStatus;
	UINT mediumIndex;
	NDIS_MEDIUM supportedMediums[MEDIUM_ARRAY_SIZE];
	PNDIS_STRING adapterName;
	NDISOPENCONTEXT *openContext;

	UNREFERENCED_PARAMETER(SystemSpecific1);
	UNREFERENCED_PARAMETER(SystemSpecific2);

	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisBindAdapter\n");

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

	adapterName = (PNDIS_STRING)DeviceName;

	NdisAllocateMemoryWithTag(&openContext, sizeof(NDISOPENCONTEXT), 'ptcs');
	if (openContext == NULL) {
		*Status = NDIS_STATUS_RESOURCES;
		return;
	}

	openContext->bindContext = BindContext;

	NdisOpenAdapter(&status, &openErrorStatus, &openContext->bindingHandle, &mediumIndex,
		supportedMediums, MEDIUM_ARRAY_SIZE, ndisGlobals.protocolHandle, openContext,
		adapterName, 0, NULL);

	if (status != STATUS_SUCCESS && status != NDIS_STATUS_PENDING)
		DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] Failed to open adapter, code=%08x: %wZ\n", status, &DeviceName);
	else
		DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisBindAdapter (success)\n");

	*Status = status;
}

VOID NdisOpenAdapterComplete(
  NDIS_HANDLE ProtocolBindingContext,
  NDIS_STATUS Status,
  NDIS_STATUS OpenErrorStatus)
{
	NDIS_STATUS status;
	NDISOPENCONTEXT *openContext;

	openContext = (NDISOPENCONTEXT*)ProtocolBindingContext;

	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisOpenAdapterComplete\n");
	NdisCompleteBindAdapter(openContext->bindContext, Status, OpenErrorStatus);
}

VOID NdisCloseAdapterComplete(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  NDIS_STATUS Status)
{
	NDISOPENCONTEXT *openContext = (NDISOPENCONTEXT*)ProtocolBindingContext;
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisCloseAdapterComplete\n");
	NdisCompleteUnbindAdapter(openContext->unbindContext, Status);
	NdisFreeMemory((PVOID)openContext, sizeof(NDISOPENCONTEXT), 0);
}

VOID NdisSendComplete(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  PNDIS_PACKET Packet,
  __in  NDIS_STATUS Status)
{
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisSendComplete\n");
}

VOID NdisTransferDataComplete(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  PNDIS_PACKET Packet,
  __in  NDIS_STATUS Status,
  __in  UINT BytesTransferred)
{
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisTransferDataComplete\n");
}

VOID NdisResetComplete(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  NDIS_STATUS Status)
{
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisResetComplete\n");
}

VOID NdisRequestComplete(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  PNDIS_REQUEST NdisRequest,
  __in  NDIS_STATUS Status)
{
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisRequestComplete\n");
}

NDIS_STATUS NdisReceive(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  NDIS_HANDLE MacReceiveContext,
  __in  PVOID HeaderBuffer,
  __in  UINT HeaderBufferSize,
  __in  PVOID LookAheadBuffer,
  __in  UINT LookaheadBufferSize,
  __in  UINT PacketSize)
{
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisReceive\n");
	return NDIS_STATUS_NOT_ACCEPTED;
}

VOID NdisReceiveComplete(
  __in  NDIS_HANDLE ProtocolBindingContext)
{
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisReceiveComplete\n");
}

VOID NdisStatus(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  NDIS_STATUS GeneralStatus,
  __in  PVOID StatusBuffer,
  __in  UINT StatusBufferSize)
{
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisStatus\n");
}

VOID NdisStatusComplete(
  __in  NDIS_HANDLE ProtocolBindingContext)
{
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisStatusComplete\n");
}

INT NdisReceivePacket(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  PNDIS_PACKET Packet)
{
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisReceivePacket\n");
	return 0;
}

VOID NdisUnbindAdapter(
  __out  PNDIS_STATUS Status,
  __in   NDIS_HANDLE ProtocolBindingContext,
  __in   NDIS_HANDLE UnbindContext)
{
	NDISOPENCONTEXT *openContext = (NDISOPENCONTEXT*)ProtocolBindingContext;
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisUnbindAdapter\n");

	openContext->unbindContext = UnbindContext;
	NdisCloseAdapter(Status, openContext->bindingHandle);

	if (*Status != NDIS_STATUS_PENDING)
		NdisFreeMemory((PVOID)openContext, sizeof(NDISOPENCONTEXT), 0);
}

NDIS_STATUS NdisPnPEventHandler(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  PNET_PNP_EVENT NetPnPEvent)
{
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisPnPEventHandler\n");
	return NDIS_STATUS_SUCCESS;
}

VOID NdisCoSendComplete(
  __in  NDIS_STATUS Status,
  __in  NDIS_HANDLE ProtocolVcContext,
  __in  PNDIS_PACKET Packet)
{
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisCoSendComplete\n");
}

VOID NdisCoStatus(
  __in      NDIS_HANDLE ProtocolBindingContext,
  __in_opt  NDIS_HANDLE ProtocolVcContext,
  __in      NDIS_STATUS GeneralStatus,
  __in      PVOID StatusBuffer,
  __in      UINT StatusBufferSize)
{
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisCoStatus\n");
}

UINT NdisCoReceivePacket(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  NDIS_HANDLE ProtocolVcContext,
  __in  PNDIS_PACKET Packet)
{
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisCoReceivePacket\n");
	return 0;
}

VOID NdisCoAfRegisterNotify(
  __in  NDIS_HANDLE ProtocolBindingContext,
  __in  PCO_ADDRESS_FAMILY AddressFamily)
{
	DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] NdisCoAfRegisterNotify\n");
}

DWORD SctpRegisterProtocol(void)
{
	NDIS_PROTOCOL_CHARACTERISTICS protocolChar;
	NDIS_STATUS ndisStatus;
	NDIS_STRING protoName = NDIS_STRING_CONST("SctpDrv");
	DWORD rc = 0;

	NdisZeroMemory(&protocolChar,sizeof(NDIS_PROTOCOL_CHARACTERISTICS));

	protocolChar.MajorNdisVersion = 0x05;
	protocolChar.MinorNdisVersion = 0x01;
	protocolChar.Name                        = protoName;
	protocolChar.OpenAdapterCompleteHandler  = NdisOpenAdapterComplete;
	protocolChar.CloseAdapterCompleteHandler = NdisCloseAdapterComplete;
	protocolChar.SendCompleteHandler         = NdisSendComplete;
	protocolChar.TransferDataCompleteHandler = NdisTransferDataComplete;
	protocolChar.ResetCompleteHandler        = NdisResetComplete;
	protocolChar.RequestCompleteHandler      = NdisRequestComplete;
	protocolChar.ReceiveHandler              = NdisReceive;
	protocolChar.ReceiveCompleteHandler      = NdisReceiveComplete;
	protocolChar.StatusHandler               = NdisStatus;
	protocolChar.StatusCompleteHandler       = NdisStatusComplete;
	protocolChar.ReceivePacketHandler        = NdisReceivePacket;
	protocolChar.BindAdapterHandler          = NdisBindAdapter;
	protocolChar.UnbindAdapterHandler        = NdisUnbindAdapter;
	protocolChar.PnPEventHandler             = NdisPnPEventHandler;
	protocolChar.CoSendCompleteHandler		 = NdisCoSendComplete;
	protocolChar.CoStatusHandler			 = NdisCoStatus;
	protocolChar.CoReceivePacketHandler		 = NdisCoReceivePacket;

	NdisRegisterProtocol(&ndisStatus, &ndisGlobals.protocolHandle, &protocolChar, sizeof(NDIS_PROTOCOL_CHARACTERISTICS));
	if (ndisStatus != NDIS_STATUS_SUCCESS) {
		DebugPrint(DEBUG_GENERIC_ERROR, "[sctp] Failed to register protocol driver, code=%08x\n", ndisStatus);
		rc = 1;
	}

	return rc;
}

DWORD SctpDeregisterProtocol(void)
{
	NDIS_STATUS status;
	NdisDeregisterProtocol(&status, ndisGlobals.protocolHandle);
	return 0;
}