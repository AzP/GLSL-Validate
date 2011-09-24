CC = g++

OBJECTS = CodeGen.o Link.o
AR=ar

SRCS=CodeGen.cpp Link.cpp

default : all
all : libCodeGen.a

libCodeGen.a : $(OBJECTS)
	$(AR) rvu $@ $(OBJECTS)
	ranlib $@

%.o : %.cpp
	$(CC) -c -fPIC $<

#
# Cleanup
#
.PHONY : clean
clean :
	$(RM) *.o *.a

depend:
	makedepend -- $(CFLAGS) -- $(SRCS)
# DO NOT DELETE

CodeGen.o: ../Include/Common.h /usr/include/stdint.h /usr/include/features.h
CodeGen.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
CodeGen.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
CodeGen.o: /usr/include/bits/wchar.h /usr/include/assert.h
CodeGen.o: ../Include/PoolAlloc.h ../Include/ShHandle.h
CodeGen.o: ../Public/ShaderLang.h ../Include/ResourceLimits.h
CodeGen.o: ../Include/InfoSink.h /usr/include/math.h
CodeGen.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
CodeGen.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
CodeGen.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
CodeGen.o: /usr/include/bits/mathcalls.h
Link.o: ../Include/Common.h /usr/include/stdint.h /usr/include/features.h
Link.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Link.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Link.o: /usr/include/bits/wchar.h /usr/include/assert.h
Link.o: ../Include/PoolAlloc.h ../Include/ShHandle.h ../Public/ShaderLang.h
Link.o: ../Include/ResourceLimits.h ../Include/InfoSink.h /usr/include/math.h
Link.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
Link.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
Link.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
Link.o: /usr/include/bits/mathcalls.h
