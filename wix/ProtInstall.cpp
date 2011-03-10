// ProtInstall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "netcfgapi.h"

// Copyright And Configuration Management ----------------------------------
//
//               NDISPROT Software Installer - ProtInstall.cpp
//
//                  Companion Sample Code for the Article
//
//                "Installing NDIS Protocols Programatically"
//                     Published on http://www.ndis.com
//
//   Copyright (c) 2004-2006 Printing Communications Associates, Inc. (PCAUSA)
//                          http://www.pcausa.com
//
// GPL software is an abomination. Far from being free, it is available ONLY
// to members of the "GPL Club". If you don't want to join the club, then GPL
// software is poison.
//
// This software IS free software under the terms of a BSD-style license:
//
// The right to use this code in your own derivative works is granted so long
// as 1.) your own derivative works include significant modifications of your
// own, 2.) you retain the above copyright notices and this paragraph in its
// entirety within sources derived from this code.
//
// This product includes software developed by PCAUSA. The name of PCAUSA
// may not be used to endorse or promote products derived from this software
// without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// End ---------------------------------------------------------------------

#define APP_NAME    _T("ProtInstall")

BOOLEAN bVerbose = TRUE;

//
// Function:  ErrMsg
//
// Purpose:   Insert text for each network component type.
//
// Arguments:
//    hr  [in]  Error code.
//
// Returns:   None.
//
// Notes:
//
VOID ErrMsg (HRESULT hr, LPCSTR lpFmt, ...)
{
    LPSTR   lpSysMsg;
    char     buf[400];
    size_t   offset;
    va_list  vArgList;

    if ( hr != 0 )
    {
        sprintf( buf,
            "Error %#lx: ",
            hr );
    }
    else
    {
        buf[0] = 0;
    }

    offset = strlen( buf );

    va_start( vArgList,
        lpFmt );

    sprintf( buf+offset,
        lpFmt,
        vArgList );

    va_end( vArgList );

    if ( hr != 0 ) {
        FormatMessageA( FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_FROM_SYSTEM |
            FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL,
            hr,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            (LPSTR)&lpSysMsg,
            0,
            NULL
            );

        if ( lpSysMsg )
        {
            offset = strlen( buf );

            sprintf( buf+offset,
                "\n\nPossible cause:\n\n" );

            offset = strlen( buf );

            strcat( buf+offset,
                lpSysMsg );

            LocalFree( (HLOCAL)lpSysMsg );
        }
    }

    WcaLog(LOGMSG_STANDARD, buf);
}

//
// Function:  InstallSpecifiedComponent
//
// Purpose:   Install a network component from an INF file.
//
// Arguments:
//    lpszInfFile [in]  INF file.
//    lpszPnpID   [in]  PnpID of the network component to install.
//    pguidClass  [in]  Class GUID of the network component.
//
// Returns:   None.
//
// Notes:
//

HRESULT InstallSpecifiedComponent(
    LPTSTR lpszInfFile,
    LPTSTR lpszPnpID,
    const GUID *pguidClass
    )
{
    INetCfg    *pnc;
    LPTSTR     lpszApp;
    HRESULT    hr;

    hr = HrGetINetCfg( TRUE, APP_NAME, &pnc, &lpszApp );

    if ( hr == S_OK )
    {
        //
        // Install the network component.
        //
        hr = HrInstallNetComponent(
            pnc,
            lpszPnpID,
            pguidClass,
            lpszInfFile
            );

        if ( (hr == S_OK) || (hr == NETCFG_S_REBOOT) )
        {
            hr = pnc->Apply();
        }
        else
        {
            if ( hr != HRESULT_FROM_WIN32(ERROR_CANCELLED) )
            {
            	WcaLog(LOGMSG_STANDARD, "Failed to apply PnpID %S, inf %S\n",
            		lpszPnpID, lpszInfFile);
                ErrMsg( hr, "Couldn't install the network component." );
            }
        }

        HrReleaseINetCfg( pnc, TRUE );
    }
    else
    {
        if ( (hr == NETCFG_E_NO_WRITE_LOCK) && lpszApp )
        {
            ErrMsg( hr,
                "%s currently holds the lock, try later.",
                lpszApp );

            CoTaskMemFree( lpszApp );
        }
        else
        {
            ErrMsg( hr,
                "Couldn't the get notify object interface." );
        }
    }

    return hr;
}

DWORD InstallDriver(LPWSTR fromDirectory)
{
    DWORD   nResult = ERROR_SUCCESS;

    WcaLog(LOGMSG_STANDARD, "Installing %S...\n", PROVIDER_INF);

	if (SetCurrentDirectory(fromDirectory) == 0) {
		WcaLog(LOGMSG_STANDARD, "Failed to set current directory to %S\n", fromDirectory);
		return ERROR_INSTALL_FAILURE;
	}

    TCHAR   szFileFullPath[ _MAX_PATH ];
    _snwprintf(szFileFullPath, _MAX_PATH, L"%s%s%s%s", fromDirectory, L"\\", PROVIDER_INF, L".inf");

    WcaLog(LOGMSG_STANDARD, "INF Path: %S\n", szFileFullPath);

    HRESULT hr = S_OK;

    WcaLog(LOGMSG_STANDARD, "PnpID: %S\n", SCTP_PNP_ID);

    hr = InstallSpecifiedComponent(
        szFileFullPath,
        SCTP_PNP_ID,
        &GUID_DEVCLASS_NETTRANS);

    if( hr != S_OK )
    {
        ErrMsg( hr, "InstallSpecifiedComponent\n" );
        nResult = ERROR_INSTALL_FAILURE;
    }

    return nResult;
}

DWORD UninstallDriver(LPWSTR fromDirectory)
{
    WcaLog(LOGMSG_STANDARD, "Uninstalling %S...\n", PROVIDER_INF);

    INetCfg              *pnc;
    INetCfgComponent     *pncc;
    INetCfgClass         *pncClass;
    INetCfgClassSetup    *pncClassSetup;
    LPTSTR               lpszApp;
    GUID                 guidClass;
    OBO_TOKEN            obo;
    HRESULT              hr;
    DWORD				 nResult = ERROR_SUCCESS;

    if (SetCurrentDirectory(fromDirectory) == 0) {
		WcaLog(LOGMSG_STANDARD, "Failed to set current directory to %S\n", fromDirectory);
		return ERROR_INSTALL_FAILURE;
	}

    hr = HrGetINetCfg( TRUE, APP_NAME, &pnc, &lpszApp );

    if ( hr == S_OK ) {

        //
        // Get a reference to the network component to uninstall.
        //
        hr = pnc->FindComponent( SCTP_PNP_ID, &pncc );

        if ( hr == S_OK )
        {
            //
            // Get the class GUID.
            //
            hr = pncc->GetClassGuid( &guidClass );

            if ( hr == S_OK )
            {
                //
                // Get a reference to component's class.
                //

                hr = pnc->QueryNetCfgClass( &guidClass,
                    IID_INetCfgClass,
                    (PVOID *)&pncClass );
                if ( hr == S_OK )
                {
                    //
                    // Get the setup interface.
                    //

                    hr = pncClass->QueryInterface( IID_INetCfgClassSetup,
                        (LPVOID *)&pncClassSetup );

                    if ( hr == S_OK )
                    {
                        //
                        // Uninstall the component.
                        //

                        ZeroMemory( &obo,
                            sizeof(OBO_TOKEN) );

                        obo.Type = OBO_USER;

                        hr = pncClassSetup->DeInstall( pncc,
                            &obo,
                            NULL );
                        if ( (hr == S_OK) || (hr == NETCFG_S_REBOOT) )
                        {
                            hr = pnc->Apply();

                            if ( (hr != S_OK) && (hr != NETCFG_S_REBOOT) )
                            {
								nResult = ERROR_INSTALL_FAILURE;
                                ErrMsg( hr,
                                    "Couldn't apply the changes after"
                                    " uninstalling %S.",
                                    PROVIDER_INF );
                            }
                        }
                        else
                        {
							nResult = ERROR_INSTALL_FAILURE;
                            ErrMsg( hr,
                                "Failed to uninstall %S.",
                                PROVIDER_INF );
                        }

                        ReleaseRef( pncClassSetup );
                    }
                    else
                    {
						nResult = ERROR_INSTALL_FAILURE;
                        ErrMsg( hr,
                            "Couldn't get an interface to setup class." );
                    }

                    ReleaseRef( pncClass );
                }
                else
                {
					nResult = ERROR_INSTALL_FAILURE;
                    ErrMsg( hr,
                        "Couldn't get a pointer to class interface "
                        "of %S.",
                        PROVIDER_INF );
                }
            }
            else
            {
				nResult = ERROR_INSTALL_FAILURE;
                ErrMsg( hr,
                    "Couldn't get the class guid of %S.",
                    PROVIDER_INF );
            }

            ReleaseRef( pncc );
        }
        else
        {
			nResult = ERROR_INSTALL_FAILURE;
            ErrMsg( hr,
                "Couldn't get an interface pointer to %S.",
                PROVIDER_INF );
        }

        HrReleaseINetCfg( pnc,
            TRUE );
    }
    else
    {
        if ( (hr == NETCFG_E_NO_WRITE_LOCK) && lpszApp )
        {
			nResult = ERROR_INSTALL_FAILURE;
            ErrMsg( hr,
                "%S currently holds the lock, try later.",
                lpszApp );

            CoTaskMemFree( lpszApp );
        }
        else
        {
			nResult = ERROR_INSTALL_FAILURE;
            ErrMsg( hr, "Couldn't get the notify object interface." );
        }
    }

    return nResult;
}
