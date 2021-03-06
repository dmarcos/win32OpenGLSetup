@echo off

set CommonCompilerFlags=-MT -nologo -GR- -WX -W4 -wd4201 -wd4100 -wd4189 -wd4456 -wd4244 -DDALI_INTERNAL=1 -DDALI_SLOW=1 -DDALI_WIN32=1 -FC -Z7
set CommonLinkerFlags=-incremental:no -opt:ref user32.lib Gdi32.lib winmm.lib opengl32.lib

IF NOT EXIST .\build mkdir .\build
pushd build


CALL :__START_TIME_MEASURE
cl %CommonCompilerFlags% ..\src\win32_opengl.cpp -Fmwin32_opengl.map /link %CommonLinkerFlags%
CALL :__STOP_TIME_MEASURE
popd

REM Routines to calculate build time.
REM https://stackoverflow.com/questions/9922498/calculate-time-difference-in-windows-batch-file

:__START_TIME_MEASURE
SET STARTTIME=%TIME%
SET STARTTIME=%STARTTIME: =0%
EXIT /B 0

:__STOP_TIME_MEASURE
SET ENDTIME=%TIME%
SET ENDTIME=%ENDTIME: =0%
SET /A STARTTIME=(1%STARTTIME:~0,2%-100)*360000 + (1%STARTTIME:~3,2%-100)*6000 + (1%STARTTIME:~6,2%-100)*100 + (1%STARTTIME:~9,2%-100)
SET /A ENDTIME=(1%ENDTIME:~0,2%-100)*360000 + (1%ENDTIME:~3,2%-100)*6000 + (1%ENDTIME:~6,2%-100)*100 + (1%ENDTIME:~9,2%-100)
SET /A DURATION=%ENDTIME%-%STARTTIME%
IF %DURATION% == 0 SET TIMEDIFF=00:00:00,00 && EXIT /B 0
IF %ENDTIME% LSS %STARTTIME% SET /A DURATION=%STARTTIME%-%ENDTIME%
SET /A DURATIONH=%DURATION% / 360000
SET /A DURATIONM=(%DURATION% - %DURATIONH%*360000) / 6000
SET /A DURATIONS=(%DURATION% - %DURATIONH%*360000 - %DURATIONM%*6000) / 100
SET /A DURATIONHS=(%DURATION% - %DURATIONH%*360000 - %DURATIONM%*6000 - %DURATIONS%*100)
IF %DURATIONH% LSS 10 SET DURATIONH=0%DURATIONH%
IF %DURATIONM% LSS 10 SET DURATIONM=0%DURATIONM%
IF %DURATIONS% LSS 10 SET DURATIONS=0%DURATIONS%
IF %DURATIONHS% LSS 10 SET DURATIONHS=0%DURATIONHS%
SET TIMEDIFF=%DURATIONM%m %DURATIONS%s %DURATIONHS%0ms
echo BUILD TIME: %TIMEDIFF%
EXIT /B 0

