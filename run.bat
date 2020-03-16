@echo off

pushd build

taskkill /IM win32_dali.exe 2> nul
START /B win32_dali.exe

popd