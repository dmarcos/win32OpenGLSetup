@echo off

pushd build

taskkill /IM win32_opengl.exe 2> nul
START /B win32_opengl.exe

popd