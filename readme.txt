How to build glslvalidate
-------------------------

This code is tested/developed with MS VisualStudio.net v7.0 2002.

1) In VS7.0, open "OpenGLCompilerXXXX\StandAlone.sln" and build "glslang".

2) Run "glslvalidate\build-vs70.bat" (which will set up some environment
variables and open the solution file with VS7.0; do not open the .sln file
directly, or the environment will not be configured properly.)

3) Build the "glslvalidate" project.

