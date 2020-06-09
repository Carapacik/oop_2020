@echo off

SET PROGRAM="%~1"

if %PROGRAM%=="" (
	echo Please specify path to program
	exit /B 1
)

REM Empty arguments
%Program%
if NOT ERRORLEVEL 1 goto err
echo Test1 passed

REM source notation < 2
%Program% 1 10 111
if NOT ERRORLEVEL 1 goto err
echo Test2 passed

REM destination notation < 2
%Program% 10 1 111
if NOT ERRORLEVEL 1 goto err
echo Test3 passed

REM destination notation < 36
%Program% 40 3 111
if NOT ERRORLEVEL 1 goto err
echo Test4 passed

REM source notation > 36
%Program% 3 37 111
if NOT ERRORLEVEL 1 goto err
echo Test5 passed

REM Incorrect arguments count
%Program% 10 11 99 10
if NOT ERRORLEVEL 1 goto err
echo Test6 passed

REM Empty string value
%Program% 11 10 ""
if NOT ERRORLEVEL 1 goto err
echo Test7 passed

REM Empty string destination notation
%Program% 14 "" 88
if NOT ERRORLEVEL 1 goto err
echo Test8 passed

REM Empty string source notation
%Program% "" 13 99
if NOT ERRORLEVEL 1 goto err
echo Test9 passed

REM Incorrect value
%Program% 10 11 1F
if NOT ERRORLEVEL 1 goto err
echo Test10 passed

REM INT_MIN
%Program% 20 10 -1DB1F928 > temp.txt
set /p VAR=<temp.txt
if NOT %VAR% == -2147483648 goto err
IF NOT ERRORLEVEL 0 goto err
echo Test11 passed

REM INT_MAX
%Program% 21 10 140H2D91 > temp.txt
set /p VAR=<temp.txt
if NOT %VAR% == 2147483647 goto err
IF NOT ERRORLEVEL 0 goto err
echo Test12 passed

REM value = 0
%Program% 10 35 0 > temp.txt
set /p VAR=<temp.txt
if NOT %VAR% == 0 goto err
IF NOT ERRORLEVEL 0 goto err
echo Test13 passed

REM value > 0
%Program% 10 35 38 > temp.txt
set /p VAR=<temp.txt
if NOT %VAR% == 13 goto err
IF NOT ERRORLEVEL 0 goto err
echo Test14 passed

REM value < 0
%Program% 12 22 -1375 > temp.txt
set /p VAR=<temp.txt
if NOT %VAR% == -4E5 goto err
IF NOT ERRORLEVEL 0 goto err
echo Test15 passed

REM Excess character
%Program% 12 10 11^2
if NOT ERRORLEVEL 1 goto err
echo Test16 passed

REM Tests completed successfully
echo All test passed successfully
exit /B 0

REM Tests FAILED
:err
echo Test failed
exit /B 1