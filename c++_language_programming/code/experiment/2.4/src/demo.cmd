@echo off

for /f "delims=" %%i in ('dir /b *.cpp') do (
    echo     * [%%i]^(experiment/2.4/src/%%i^)
)