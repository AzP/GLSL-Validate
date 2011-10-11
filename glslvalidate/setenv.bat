@echo off

REM setenv.bat

REM This batch file sets up environment variables needed to build glslvalidate.
REM Please change this to reflect your local tree.
REM By default, it assumes that the 3rd party libraries are peers to the glslvalidate root.

SET PEER=%CD%\..
SET GLSLPARSER=%PEER%\OpenGLCompilerSept202005
SET WXWIDGETS_LIB=%PEER%\wxWidgets-2.8.12\lib\vc_lib
SET WXWIDGETS_INC=%PEER%\wxWidgets-2.8.12\include
