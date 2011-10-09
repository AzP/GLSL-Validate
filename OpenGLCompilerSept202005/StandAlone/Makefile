CC=g++
OBJECTPATH=./../glslang/MachineIndependent
LIBPATH=./../glslang/MachineIndependent/lib
INSTALLLIBPATH=./
SRCS=StandAlone.cpp

TARGETOBJECT=StandAlone.o

default: all

debug: CC += -ggdb -ggdb3
debug: all
debug: INSTALLLIBPATH=./../glslang/MachineIndependent/lib

all: StandAlone

StandAlone: $(TARGETOBJECT) SHAREDOBJECT
	$(CC) -fPIC -g -o $@ $(TARGETOBJECT) -L $(LIBPATH) -lglslang -lpthread -lm -lstdc++ -Wl,-rpath=$(INSTALLLIBPATH)

SHAREDOBJECT:
	cd $(OBJECTPATH); make all

%.o : %.cpp
	$(CC) -c $<

#
# Cleanup
#
.PHONY : clean
clean :
	$(RM) *.o StandAlone
	cd $(OBJECTPATH); make clean

depend:
	cd $(OBJECTPATH); make depend
	makedepend -Y -- %.cpp
# DO NOT DELETE

StandAlone.o: ./../glslang/Include/ShHandle.h
StandAlone.o: ./../glslang/Public/ShaderLang.h
StandAlone.o: ./../glslang/Include/ResourceLimits.h
StandAlone.o: ./../glslang/Include/InfoSink.h ./../glslang/Include/Common.h
StandAlone.o: /usr/include/stdint.h /usr/include/features.h
StandAlone.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
StandAlone.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
StandAlone.o: /usr/include/bits/wchar.h /usr/include/assert.h
StandAlone.o: ./../glslang/Include/PoolAlloc.h /usr/include/math.h
StandAlone.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
StandAlone.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
StandAlone.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
StandAlone.o: /usr/include/bits/mathcalls.h ./../glslang/Public/ShaderLang.h
