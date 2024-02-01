@echo off
set SOURCE_ROOT=%CD%
set BUILD_DIR=%SOURCE_ROOT%\build
set INSTALL_PREFIX=%SOURCE_ROOT%\dist

REM Check OS and set up build
if "%OS%"=="Windows_NT" (
    meson setup --prefix=%INSTALL_PREFIX% --cross-file %SOURCE_ROOT%\cross\windows.txt %BUILD_DIR%
) else (
    echo Unsupported OS
    exit /b 1
)

REM Configure, build, and install the project
meson compile -C %BUILD_DIR%
meson install -C %BUILD_DIR%

REM Generate compile_commands.json for clangd
meson compile_commands -C %BUILD_DIR%

