@echo off
cl /O2 donut.c
if %ERRORLEVEL% NEQ 0 echo Compilation failed! Please check your setup.
pause
