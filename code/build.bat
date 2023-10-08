@echo off

mkdir ..\..\build
pushd ..\..\build
cl -Zi ..\zuave\code\win32_zuave.cpp user32.lib
popd