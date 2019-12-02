@echo off

setlocal enabledelayedexpansion
for /f "delims=" %%i in ('dir /b *') do (
    if "%%~xi"==".c" (
        for %%j in (%%~ni) do (
            if "%%~xj"=="" (
                echo * [%%~ni]^(zl_test/%%i^)
                REM echo [1]%%j.c
            ) else (echo   * [%%~ni]^(zl_test/%%i^)
                REM echo [2]%%j.c
            )
        )
    )
)
setlocal disabledelayedexpansion
