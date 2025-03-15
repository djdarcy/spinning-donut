@echo off

if "%~1"=="" (
    echo Usage: convert-to-gif.bat input.mp4 [output.gif] [fps]
    echo Example: convert-to-gif.bat myvideo.mp4 output.gif 30
    exit /b
)

set INPUT=%1
set OUTPUT=%~n1.gif
if not "%~2"=="" set OUTPUT=%2
set FPS=30
if not "%~3"=="" set FPS=%3

rem Generate high-quality color palette
ffmpeg -i "%INPUT%" -vf "fps=%FPS%,scale=-1:-1:flags=lanczos,palettegen" -y palette.png

rem Generate GIF with optimized colors
ffmpeg -i "%INPUT%" -i palette.png -filter_complex "fps=%FPS%,scale=-1:-1:flags=lanczos[x];[x][1:v]paletteuse=dither=sierra2_4a" -y "%OUTPUT%"

del palette.png
echo Conversion complete! Output: %OUTPUT%


REM Old version
@REM if "%~1"=="" (
@REM     echo Usage: convert-to-gif.bat input.mp4 output.gif
@REM     exit /b
@REM )
@REM ffmpeg -i "%~1" -vf "fps=15,scale=480:-1:flags=lanczos" -c:v gif "%~2"
@REM echo GIF saved as %~2
