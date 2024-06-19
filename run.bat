@echo off
g++ "%1" -o ".\\bin\\%~n1.exe"
if errorlevel 1 (
    pause
    exit
) 
".\\bin\\%~n1.exe"
echo. 
pause
exit