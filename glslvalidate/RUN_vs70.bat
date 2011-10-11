@echo off
title %0
call setenv.bat
set VS70IDE="C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe"
%VS70IDE% vs7.0\glslvalidate.vcproj
