#!/bin/bash - 
#===============================================================================
#
#          FILE:  PrepareRelease.sh
# 
#         USAGE:  ./PrepareRelease.sh 
# 
#   DESCRIPTION: Builds everything and copies interesting files
#				 to a subdir called Release
# 
#        AUTHOR: Peter Asplund (peter.azp@gmail.com), 
#       CREATED: 2011-10-09 19.31.36 CEST
#===============================================================================

set -o nounset                              # Treat unset variables as an error

make -C OpenGLCompilerSept202005/StandAlone
make -C glslvalidate/source/

mkdir Release
cp -v glslvalidate/source/glslvalidate Release/
cp -v OpenGLCompilerSept202005/StandAlone/StandAlone Release/
cp -v OpenGLCompilerSept202005/glslang/MachineIndependent/lib/libglslang.so Release/
