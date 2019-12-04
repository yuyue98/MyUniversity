@echo off

for /f "delims=" %%i in ('dir /a:d /b 2.*') do (
    for /f "delims=" %%j in ('dir /a:d /b %%i') do (
        echo %%i/%%j
        dotnet new console -lang "C#" -o "%%i/%%j"
    )
)