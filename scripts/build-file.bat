@echo off
echo Building File %1
g++ "%1" -o ".\\bin\\%~n1.exe"
if errorlevel 1 (
    pause
    exit
) 
echo .\bin\%~n1.exe
echo. 
".\\bin\\%~n1.exe"
echo.
pause
exit