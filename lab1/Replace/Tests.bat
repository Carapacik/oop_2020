@echo off

SET PROGRAM="%~1"

if %PROGRAM%=="" (
	echo Please specify path to program
	exit /B 1
)

REM EmptyFile
%PROGRAM% "Tests\empty.txt" "%TEMP%\output.txt" 0 1 || goto err
fc "Tests\empty.txt" "%TEMP%\output.txt" > nul || goto err
echo Test1 passed

REM InputFile not exists
%Program% notexist.txt "%TMP%\output.txt" 0 1 && goto err
echo Test2 passed

REM Incorrect number of arguments
%Program% "tests\input.txt" "%TMP%\output.txt" && goto err
echo Test3 passed

REM Incorrect number of arguments
%Program% "Tests\input.txt" "%TMP%\output.txt" 0 1 2 && goto err
echo Test4 passed

REM Incorrect arguments
%Program% hehe 0 1 2 && goto err
echo Test5 passed

REM EmptyString
%Program% "Tests\input.txt" "%TEMP%\output.txt" "" ayayay && goto err
echo Test6 passed

REM Normal replace with more than one serchString in substring
%Program% "Tests\input.txt" "%TEMP%\output.txt" kak "vot tak" || goto err
fc "Tests\output1.txt" "%TEMP%\output.txt" > nul || goto err
echo Test7 passed

REM Replace in a group of characters
%Program% "Tests\input.txt" "%TEMP%\output.txt" sdelat tak || goto err
fc "Tests\output2.txt" "%TEMP%\output.txt" > nul || goto err
echo Test8 passed

REM Replace on double substring
%Program% "Tests\input.txt" "%TEMP%\output.txt" g gg || goto err
fc "Tests\output3.txt" "%TEMP%\output.txt" > nul || goto err
echo Test9 passed

REM The input does not contain <replace string>
%Program% "Tests\input.txt" "%TEMP%\output.txt" "Kak tut horosho" bye || goto err
fc "Tests\output4.txt" "%TEMP%\output.txt" > nul || goto err
echo Test10 passed

REM Replace on itself
%Program% "Tests\input.txt" "%TEMP%\output.txt" g g || goto err
fc "Tests\output5.txt" "%TEMP%\output.txt" > nul || goto err
echo Test11 passed

REM Tests completed successfully
echo All test passed successfully
exit /B 0

REM Tests FAILED
:err
echo Test failed
exit /B 1