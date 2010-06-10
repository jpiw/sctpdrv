@echo off
set TIMESERVER=http://timestamp.globalsign.com/scripts/timstamp.dll
if [%NO_TIMESTAMP%]==[1] ( set TIMESTAMP= ) else ( set TIMESTAMP=/t %TIMESERVER% )
set CROSSCERT=..\drv\MSCV-GlobalSign.cer
set CN="Bruce Cran"
if [%RELEASE_SIGN%]==[1] (
signtool sign /ac %CROSSCERT% /s my /n %CN% %TIMESTAMP% %TREE%\sctp.cat %TREE%\sctp.sys %TREE%\sctpmon.dll %TREE%\sctpsp.dll %TREE%\spinstall.exe %TREE%\echo_client.exe %TREE%\echo_server.exe %TREE%\echo_server2.exe
) else (
signtool sign -p "Stream Control Transmission Protocol" /f ..\drv\sctpDrv.pfx %TREE%\sctp.sys
)
@echo on