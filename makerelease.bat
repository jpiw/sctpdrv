@echo off
set PROJDIR=%CD%
if [%DEBUG%]==[1] (set BUILDTYPE=chk) else (set BUILDTYPE=fre)
if not exist "%WINDOWSSDKDIR%\Include\msi.h" set WINDOWSSDKDIR=C:\Program Files\Microsoft SDKs\Windows\v7.1
if not exist "%WDKPATH%\bin\setenv.bat" set WDKPATH=C:\WinDDK\7600.16385.1
if not exist "%WINDOWSSDKDIR%\Include\msi.h" goto missingfiles
if not exist "%WDKPATH%\bin\setenv.bat" goto missingfiles
if not exist "%WIX%bin\candle.exe" goto missingfiles
if not exist "%WINDOWSSDKDIR%\Include\msi.h" goto missingfiles
set WDK=cmd /c "%WDKPATH%\bin\setenv.bat %WDKPATH% %BUILDTYPE%

cd %PROJDIR%
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

copy /Y "%WIX%SDK\lib\wcautil_x64.lib"      lib\x64
copy /Y "%WIX%SDK\lib\dutil_x64.lib"        lib\x64
copy /Y "%WINDOWSSDKDIR%\Lib\x64\netfw.tlb" lib\x64
copy /Y "%WINDOWSSDKDIR%\Lib\x64\netsh.lib" lib\x64

copy /Y "%WIX%SDK\lib\wcautil.lib"          lib
copy /Y "%WIX%SDK\lib\dutil.lib"            lib
copy /Y "%WINDOWSSDKDIR%\Lib\netfw.tlb"     lib
copy /Y "%WINDOWSSDKDIR%\Lib\netsh.lib"     lib

echo on
REM Build the i386 Windows XP driver
%WDK% x86 wxp && CD %PROJDIR% && build/c"
@if %ERRORLEVEL% neq 0 goto builderror
%WDK% x86 wxp && CD %PROJDIR% && CD wix && set MSICULTURE=en-us&& nmake -f Makefile.wix && set MSICULTURE=ja-jp&& nmake -f Makefile.wix"
@if %ERRORLEVEL% neq 0 goto builderror

REM Build the i386 Windows Vista driver
%WDK% x86 wlh && CD %PROJDIR% && build/c"
@if %ERRORLEVEL% neq 0 goto builderror
%WDK% x86 wlh && CD %PROJDIR% && CD wix && set MSICULTURE=en-us&& nmake -f Makefile.wix && set MSICULTURE=ja-jp&& nmake -f Makefile.wix"
@if %ERRORLEVEL% neq 0 goto builderror

REM Build the amd64 Windows Vista driver
%WDK% x64 wlh && CD %PROJDIR% && build/c
@if %ERRORLEVEL% neq 0 goto builderror
%WDK% x64 wlh && CD %PROJDIR% && CD wix && set MSICULTURE=en-us&& nmake -f Makefile.wix && set MSICULTURE=ja-jp&& nmake -f Makefile.wix"
@if %ERRORLEVEL% neq 0 goto builderror

REM Build the i386 Windows 7 driver
%WDK% x86 win7 && CD %PROJDIR% && build/c
@if %ERRORLEVEL% neq 0 goto builderror
%WDK% x86 win7 && CD %PROJDIR% && CD wix && set MSICULTURE=en-us&& nmake -f Makefile.wix && set MSICULTURE=ja-jp&& nmake -f Makefile.wix"
@if %ERRORLEVEL% neq 0 goto builderror

REM Build the amd64 Windows 7 driver
%WDK% x64 win7 && CD %PROJDIR% && build/c
@if %ERRORLEVEL% neq 0 goto builderror
%WDK% x64 win7 && CD %PROJDIR% && CD wix && set MSICULTURE=en-us&& nmake -f Makefile.wix && set MSICULTURE=ja-jp&& nmake -f Makefile.wix"
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
