@echo off
set PROJDIR=%CD%
set SIGNCMD=signtool sign -p "Stream Control Transmission Protocol" /f drv\sctpDrv.pfx
if [%DEBUG%]==[1] (set BUILDTYPE=chk) else (set BUILDTYPE=fre)
if not exist "%WINDOWSSDKDIR%\Include\msi.h" set WINDOWSSDKDIR=C:\Program Files\Microsoft SDKs\Windows\v7.0
if not exist "%WDKPATH%\bin\setenv.bat" set WDKPATH=C:\WinDDK\7600.16385.0
if not exist "%WDKPATH%\bin\setenv.bat" goto missingfiles
if not exist "%WIX%bin\candle.exe" goto missingfiles
if not exist "%WINDOWSSDKDIR%\Include\msi.h" goto missingfiles

cd %PROJDIR%
mkdir inc
mkdir lib
mkdir lib\ia64
mkdir lib\x64
copy /Y "%WIX%SDK\inc\wcautil.h" inc
copy /Y "%WIX%SDK\inc\dutil.h" inc
copy /Y "%WINDOWSSDKDIR%\Include\netsh.h" inc
copy /Y "%WINDOWSSDKDIR%\Include\netfw.h" inc
copy /Y "%WINDOWSSDKDIR%\Include\icftypes.h" inc
copy /Y "%WINDOWSSDKDIR%\Include\msi.h" inc
copy /Y "%WINDOWSSDKDIR%\Include\msiquery.h" inc
copy /Y "%WINDOWSSDKDIR%\Include\netsh.h" inc

copy /Y "%WIX%SDK\lib\wcautil_ia64.lib" lib
copy /Y "%WIX%SDK\lib\dutil_ia64.lib" lib
copy /Y "%WINDOWSSDKDIR%\Lib\ia64\netfw.tlb" lib
copy /Y "%WINDOWSSDKDIR%\Lib\ia64\netsh.lib" lib\ia64
copy /Y "%WIX%SDK\lib\wcautil_x64.lib" lib
copy /Y "%WIX%SDK\lib\dutil_x64.lib" lib
copy /Y "%WINDOWSSDKDIR%\Lib\x64\netfw.tlb" lib
copy /Y "%WINDOWSSDKDIR%\Lib\x64\netsh.lib" lib\x64
copy /Y "%WIX%SDK\lib\wcautil.lib" lib
copy /Y "%WIX%SDK\lib\dutil.lib" lib
copy /Y "%WINDOWSSDKDIR%\Lib\netfw.tlb" lib
copy /Y "%WINDOWSSDKDIR%\Lib\netsh.lib" lib

echo on
REM Build the i386 Windows XP driver
cmd /c "%WDKPATH%\bin\setenv.bat %WDKPATH% %BUILDTYPE% x86 wxp  && CD %PROJDIR% && build/c && CD wix && set MSICULTURE=en-us&& nmake -f Makefile.wix && set MSICULTURE=ja-jp&& nmake -f Makefile.wix"
@if %ERRORLEVEL% neq 0 goto builderror

REM Build the i386 Windows 7 driver
cmd /c "%WDKPATH%\bin\setenv.bat %WDKPATH% %BUILDTYPE% x86 win7 && CD %PROJDIR% && build/c && %SIGNCMD% drv\obj%BUILDTYPE%_win7_x86\i386\sctp.sys && CD wix && set MSICULTURE=en-us&& nmake -f Makefile.wix && set MSICULTURE=ja-jp&& nmake -f Makefile.wix"
@if %ERRORLEVEL% neq 0 goto builderror

REM Build the amd64 Windows 7 driver
cmd /c "%WDKPATH%\bin\setenv.bat %WDKPATH% %BUILDTYPE% x64 win7 && CD %PROJDIR% && build/c && %SIGNCMD% drv\obj%BUILDTYPE%_win7_amd64\amd64\sctp.sys && CD wix && set MSICULTURE=en-us&& nmake -f Makefile.wix && set MSICULTURE=ja-jp&& nmake -f Makefile.wix"
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
