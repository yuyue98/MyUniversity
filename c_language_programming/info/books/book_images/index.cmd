@echo off

for %%i in (*.jpg) do (
    echo ![%%~ni]^(book_images/%%i^)
)