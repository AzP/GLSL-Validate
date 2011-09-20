@echo off
title %0
call setenv.bat
set VS70IDE="F:\Microsoft Visual Studio .NET\Common7\IDE\devenv.exe"
%VS70IDE% vs7.0\glslvalidate.vcproj
