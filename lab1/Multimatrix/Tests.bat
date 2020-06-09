@echo off

SET PROGRAM="%~1"

if %PROGRAM%=="" (
	echo Please specify path to program
	exit /B 1
)

REM Empty arguments
%PROGRAM% && goto err
echo Test1 passed

REM Invalid number of arguments
%PROGRAM% "Tests\input1.txt" "Tests\input2.txt" "Tests\input3.txt" && goto err
echo Test2 passed

REM Failed to open file for reading
%PROGRAM% "Tests\in.txt" "Tests\input1.txt"  && goto err
echo Test3 passed

REM Empty files
%PROGRAM% "Tests\empty.txt" "Tests\empty.txt" && goto err
echo Test4 passed

REM Invalid data in file
%PROGRAM% "Tests\invalid.txt" "Tests\input1.txt" && goto err
echo Test5 passed

REM Null Matrix
%PROGRAM% "Tests\input1.txt" "Tests\null.txt" || goto err
fc output.txt "Tests\output1.txt" > nul || goto err
echo Test6 passed

REM Correct
%PROGRAM% "Tests\input1.txt" "Tests\input2.txt" || goto err
fc output.txt "Tests\output2.txt" > nul || goto err
echo Test7 passed

REM Correct 2
%PROGRAM% "Tests\input2.txt" "Tests\input3.txt" || goto err
fc output.txt "Tests\output3.txt" > nul || goto err
echo Test8 passed

REM Correct 3
%PROGRAM% "Tests\input1.txt" "Tests\input3.txt" || goto err
fc output.txt "Tests\output4.txt" > nul || goto err
echo Test9 passed

REM Tests completed successfully
echo All test passed successfully
exit /B 0

REM Tests FAILED
:err
echo Test failed
exit /B 1