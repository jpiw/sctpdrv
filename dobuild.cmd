@echo off
set PROJDIR=%CD%
if [%DEBUG%]==[1] (set BUILDTYPE=chk) else (set BUILDTYPE=fre)
if [%DEBUG%]==[1] (set MSBUILDCONFIGURATION=Debug) else (set MSBUILDCONFIGURATION=Release)
if not exist "%WINDOWSSDKDIR%\Include\msi.h" set WINDOWSSDKDIR=C:\Program Files\Microsoft SDKs\Windows\v7.1
if not exist "%WDKPATH%\bin\setenv.bat" set WDKPATH=C:\WinDDK\7600.16385.1
if not exist "%WINDOWSSDKDIR%\Include\msi.h" goto missingfiles
if not exist "%WDKPATH%\bin\setenv.bat" goto missingfiles
if not exist "%WIX%bin\candle.exe" goto missingfiles
if not exist "%WINDOWSSDKDIR%\Include\msi.h" goto missingfiles
set WDK=cmd /c "%WDKPATH%\bin\setenv.bat %WDKPATH% %BUILDTYPE%
set SDK=cmd /c ""%WINDOWSSDKDIR%\bin\setenv.cmd"

CD /D %PROJDIR%
mkdir inc
mkdir lib
mkdir lib\x64
copy /Y "%WIX%SDK\inc\wcautil.h"             inc
copy /Y "%WIX%SDK\inc\dutil.h"               inc
copy /Y "%WINDOWSSDKDIR%\Include\netsh.h"    inc
copy /Y "%WINDOWSSDKDIR%\Include\netfw.h"    inc
copy /Y "%WINDOWSSDKDIR%\Include\icftypes.h" inc
copy /Y "%WINDOWSSDKDIR%\Include\msi.h"      inc
copy /Y "%WINDOWSSDKDIR%\Include\msiquery.h" inc
copy /Y "%WINDOWSSDKDIR%\Include\netsh.h"    inc

copy /Y "%WIX%SDK\lib\wcautil_2010_x64.lib" lib\x64
copy /Y "%WIX%SDK\lib\dutil_2010_x64.lib"   lib\x64
copy /Y "%WINDOWSSDKDIR%\Lib\x64\netfw.tlb" lib\x64
copy /Y "%WINDOWSSDKDIR%\Lib\x64\netsh.lib" lib\x64

copy /Y "%WIX%SDK\lib\wcautil_2010.lib"     lib
copy /Y "%WIX%SDK\lib\dutil_2010.lib"       lib
copy /Y "%WINDOWSSDKDIR%\Lib\netfw.tlb"     lib
copy /Y "%WINDOWSSDKDIR%\Lib\netsh.lib"     lib

echo on
REM Build the i386 Windows XP driver
%WDK% x86 wxp && CD /D %PROJDIR% && build/c"
@if %ERRORLEVEL% neq 0 goto builderror
copy /Y sp\dll\obj%BUILDTYPE%_wxp_x86\i386\sctpsp.dll sp\SctpSocket\SctpSocket
%SDK% /x86 /xp /%MSBUILDCONFIGURATION% && CD /D sp\SctpSocket && msbuild /p:Configuration=%MSBUILDCONFIGURATION% /p:Platform=Win32 /p:AssemblyLinkResource=sctpsp.dll"
@if %ERRORLEVEL% neq 0 goto builderror
%WDK% x86 wxp && CD /D %PROJDIR% && CD /D wix && set MSICULTURE=en-us&& nmake -f Makefile.wix && set MSICULTURE=ja-jp&& nmake -f Makefile.wix"
@if %ERRORLEVEL% neq 0 goto builderror

REM Build the i386 Windows Vista driver
%WDK% x86 wlh && CD /D %PROJDIR% && build/c"
@if %ERRORLEVEL% neq 0 goto builderror
copy /Y sp\dll\obj%BUILDTYPE%_wlh_x86\i386\sctpsp.dll sp\SctpSocket\SctpSocket
%SDK% /x86 /vista /%MSBUILDCONFIGURATION% && CD /D sp\SctpSocket && msbuild /p:Configuration=%MSBUILDCONFIGURATION% /p:Platform=Win32 /p:AssemblyLinkResource=sctpsp.dll"
@if %ERRORLEVEL% neq 0 goto builderror
%WDK% x86 wlh && CD /D %PROJDIR% && CD /D wix && set MSICULTURE=en-us&& nmake -f Makefile.wix && set MSICULTURE=ja-jp&& nmake -f Makefile.wix"
@if %ERRORLEVEL% neq 0 goto builderror

REM Build the amd64 Windows Vista driver
%WDK% x64 wlh && CD /D %PROJDIR% && build/c
@if %ERRORLEVEL% neq 0 goto builderror
copy /Y sp\dll\obj%BUILDTYPE%_wlh\amd64\sctpsp.dll sp\SctpSocket\SctpSocket
%SDK% /x64 /vista /%MSBUILDCONFIGURATION% && CD /D sp\SctpSocket && msbuild /p:Configuration=%MSBUILDCONFIGURATION% /p:Platform=x64 /p:AssemblyLinkResource=sctpsp.dll"
@if %ERRORLEVEL% neq 0 goto builderror
%WDK% x64 wlh && CD /D %PROJDIR% && CD /D wix && set MSICULTURE=en-us&& nmake -f Makefile.wix && set MSICULTURE=ja-jp&& nmake -f Makefile.wix"
@if %ERRORLEVEL% neq 0 goto builderror
@goto done

:missingfiles
@if not exist "%WDKPATH%\bin\setenv.bat" (
 echo ** Unable to find the path to the WDK          **
 echo ** Please set the WDKPATH environment variable **
) else if not exist "%WIX%bin\candle.exe" (
 echo ** Unable to find the Windows Installer XML    **
 echo ** Please set the WIX environment variable     **
) else if not exist "%WINDOWSSDKDIR%\Include\msi.h" (
 echo ** Unable to find the Windows SDK              **
 echo ** Please set the WINDOWSSDKDIR environment    **
 echo ** variable                                    **
)
goto done

:builderror
@echo The build failed.
 
:done
