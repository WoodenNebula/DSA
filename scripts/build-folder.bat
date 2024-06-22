@echo off
echo Building Folder %1
g++ "%1\\*.cpp" -o ".\\bin\\%~n1.exe"
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