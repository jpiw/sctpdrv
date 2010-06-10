@echo off
set TIMESERVER=http://timestamp.globalsign.com/scripts/timstamp.dll
set CROSSCERT=..\drv\MSCV-GlobalSign.cer
set CN="Bruce Cran"
if [%HAVE_CERT%]==[1] (
signtool sign /ac %CROSSCERT% /s my /n %CN% /t %TIMESERVER% %TREE%\sctp.cat %TREE%\sctp.sys %TREE%\sctpmon.dll %TREE%\sctpsp.dll %TREE%\spinstall.exe %TREE%\echo_client.exe %TREE%\echo_server.exe %TREE%\echo_server2.exe
) else (
signtool sign -p "Stream Control Transmission Protocol" /f ..\drv\sctpDrv.pfx %TREE%\sctp.sys
)
@echo on