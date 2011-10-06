INCLUDE = -I. -I.. -I../.. -I../Include -I/usr/include/ -I../Public -I../OSDependent/Linux -I../../OGLCompilersDLL
CC=g++
DEFINE=-fPIC -g3
INCPREPROCESSOR=./preprocessor
INCCODEGEN=./../GenericCodeGen
INCOSDEPENDENT=./../OSDependent/Linux/
INCINITIALISATION=./../../OGLCompilersDLL/
LIBPREPROCESSOR=./preprocessor/libPreprocessor.a
LIBOSDEPENDENT=./../OSDependent/Linux/libOssource.a
LIBINITIALISATION=./../../OGLCompilersDLL/libInitializeDll.a
LIBCODEGEN=./../GenericCodeGen/libCodeGen.a
OBJECTS= Initialize.o IntermTraverse.o \
	Intermediate.o ParseHelper.o PoolAlloc.o QualifierAlive.o \
	RemoveTree.o ShaderLang.o intermOut.o parseConst.o SymbolTable.o \
	InfoSink.o

SRCS= Gen_glslang.cpp Gen_glslang_tab.cpp Initialize.cpp IntermTraverse.cpp \
	Intermediate.cpp ParseHelper.cpp PoolAlloc.cp QualifierAlive.cpp \
	RemoveTree.cpp ShaderLang.cpp SymbolTable.cpp intermOut.cpp \
	parseConst.cpp InfoSink.cpp
CPPFLAGS=$(DEFINE) $(INCLUDE)
SHAREDOBJECT=./lib/libglslang.so

default: all

all: $(SHAREDOBJECT)

$(SHAREDOBJECT): Gen_glslang.o Gen_glslang_tab.o $(OBJECTS) \
	$(LIBPREPROCESSOR) $(LIBCODEGEN) $(LIBOSDEPENDENT) $(LIBINITIALISATION)
	$(CC) -fPIC -shared -lc -o $@ $(OBJECTS) $(LIBPREPROCESSOR) $(LIBCODEGEN) $(LIBOSDEPENDENT) $(LIBINITIALISATION) Gen_glslang.o Gen_glslang_tab.o

Gen_glslang.o : Gen_glslang.cpp glslang_tab.h
	$(CC) -fPIC -c $(INCLUDE) Gen_glslang.cpp -o $@

Gen_glslang_tab.o : Gen_glslang_tab.cpp 
	$(CC) -fPIC -c $(INCLUDE) Gen_glslang_tab.cpp -o $@

Gen_glslang.cpp: glslang.l
	@echo Generating Gen_glslang.cpp
	@dos2unix glslang.l
	flex glslang.l

Gen_glslang_tab.cpp glslang_tab.h: glslang.y
	@echo Generating Gen_glslang_tab.cpp
	@dos2unix glslang.y
	bison -t -v -d glslang.y
	mv glslang.tab.c Gen_glslang_tab.cpp
	mv glslang.tab.h glslang_tab.h

%.o : %.cpp
	$(CC) $(CPPFLAGS) -c $<

$(LIBPREPROCESSOR):
	cd $(INCPREPROCESSOR); make 

$(LIBCODEGEN):
	cd $(INCCODEGEN); make 

$(LIBINITIALISATION):
	cd $(INCINITIALISATION); make 

$(LIBOSDEPENDENT):
	cd $(INCOSDEPENDENT); make 

depend:
	cd $(INCPREPROCESSOR); make depend
	cd $(INCCODEGEN); make depend
	cd $(INCINITIALISATION); make depend
	cd $(INCOSDEPENDENT); make depend
	makedepend -Y -- $(CPPFLAGS) -- $(SRCS) 
#
# Cleanup
#
.PHONY : clean
clean :
	$(RM) *.o *.a Gen_glslang_tab.cpp Gen_glslang.cpp glslang_tab.h glslang.output
	$(RM) ./lib/*.so
	cd $(INCPREPROCESSOR); make clean
	cd $(INCCODEGEN); make clean
	cd $(INCINITIALISATION); make clean
	cd $(INCOSDEPENDENT); make clean
	
# DO NOT DELETE

Initialize.o: ../Include/intermediate.h ../Include/Common.h
Initialize.o: /usr/include/stdint.h /usr/include/features.h
Initialize.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Initialize.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Initialize.o: /usr/include/bits/wchar.h /usr/include/assert.h
Initialize.o: ../Include/PoolAlloc.h ../Include/Types.h
Initialize.o: ../Include/BaseTypes.h ../Include/ConstantUnion.h Initialize.h
Initialize.o: ../Include/ResourceLimits.h ../Include/ShHandle.h
Initialize.o: ../Public/ShaderLang.h ../Include/ResourceLimits.h
Initialize.o: ../Include/InfoSink.h /usr/include/math.h
Initialize.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
Initialize.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
Initialize.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
Initialize.o: /usr/include/bits/mathcalls.h SymbolTable.h ../Include/Common.h
Initialize.o: ../Include/intermediate.h ../Include/InfoSink.h
IntermTraverse.o: ../Include/intermediate.h ../Include/Common.h
IntermTraverse.o: /usr/include/stdint.h /usr/include/features.h
IntermTraverse.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
IntermTraverse.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
IntermTraverse.o: /usr/include/bits/wchar.h /usr/include/assert.h
IntermTraverse.o: ../Include/PoolAlloc.h ../Include/Types.h
IntermTraverse.o: ../Include/BaseTypes.h ../Include/ConstantUnion.h
Intermediate.o: localintermediate.h ../Include/intermediate.h
Intermediate.o: ../Include/Common.h /usr/include/stdint.h
Intermediate.o: /usr/include/features.h /usr/include/sys/cdefs.h
Intermediate.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
Intermediate.o: /usr/include/gnu/stubs-64.h /usr/include/bits/wchar.h
Intermediate.o: /usr/include/assert.h ../Include/PoolAlloc.h
Intermediate.o: ../Include/Types.h ../Include/BaseTypes.h
Intermediate.o: ../Include/ConstantUnion.h ../Public/ShaderLang.h
Intermediate.o: ../Include/ResourceLimits.h SymbolTable.h ../Include/Common.h
Intermediate.o: ../Include/intermediate.h ../Include/InfoSink.h
Intermediate.o: QualifierAlive.h RemoveTree.h /usr/include/limits.h
Intermediate.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
Intermediate.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
ParseHelper.o: ParseHelper.h ../Include/ShHandle.h ../Public/ShaderLang.h
ParseHelper.o: ../Include/ResourceLimits.h ../Include/InfoSink.h
ParseHelper.o: ../Include/Common.h /usr/include/stdint.h
ParseHelper.o: /usr/include/features.h /usr/include/sys/cdefs.h
ParseHelper.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
ParseHelper.o: /usr/include/gnu/stubs-64.h /usr/include/bits/wchar.h
ParseHelper.o: /usr/include/assert.h ../Include/PoolAlloc.h
ParseHelper.o: /usr/include/math.h /usr/include/bits/huge_val.h
ParseHelper.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
ParseHelper.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
ParseHelper.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
ParseHelper.o: SymbolTable.h ../Include/Common.h ../Include/intermediate.h
ParseHelper.o: ../Include/InfoSink.h localintermediate.h
ParseHelper.o: ../Include/intermediate.h ../Include/Types.h
ParseHelper.o: ../Include/BaseTypes.h ../Include/ConstantUnion.h
ParseHelper.o: ../Include/InitializeParseContext.h
ParseHelper.o: ../OSDependent/Linux/osinclude.h /usr/include/pthread.h
ParseHelper.o: /usr/include/endian.h /usr/include/bits/endian.h
ParseHelper.o: /usr/include/bits/byteswap.h /usr/include/sched.h
ParseHelper.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
ParseHelper.o: /usr/include/time.h /usr/include/bits/sched.h
ParseHelper.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/setjmp.h
ParseHelper.o: /usr/include/semaphore.h /usr/include/sys/types.h
ParseHelper.o: /usr/include/sys/select.h /usr/include/bits/select.h
ParseHelper.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
ParseHelper.o: /usr/include/sys/sysmacros.h /usr/include/bits/semaphore.h
ParseHelper.o: /usr/include/errno.h /usr/include/bits/errno.h
ParseHelper.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
ParseHelper.o: /usr/include/asm-generic/errno.h
ParseHelper.o: /usr/include/asm-generic/errno-base.h
ParseHelper.o: ../Include/InitializeGlobals.h ../Include/PoolAlloc.h
QualifierAlive.o: ../Include/intermediate.h ../Include/Common.h
QualifierAlive.o: /usr/include/stdint.h /usr/include/features.h
QualifierAlive.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
QualifierAlive.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
QualifierAlive.o: /usr/include/bits/wchar.h /usr/include/assert.h
QualifierAlive.o: ../Include/PoolAlloc.h ../Include/Types.h
QualifierAlive.o: ../Include/BaseTypes.h ../Include/ConstantUnion.h
RemoveTree.o: ../Include/intermediate.h ../Include/Common.h
RemoveTree.o: /usr/include/stdint.h /usr/include/features.h
RemoveTree.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
RemoveTree.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
RemoveTree.o: /usr/include/bits/wchar.h /usr/include/assert.h
RemoveTree.o: ../Include/PoolAlloc.h ../Include/Types.h
RemoveTree.o: ../Include/BaseTypes.h ../Include/ConstantUnion.h RemoveTree.h
ShaderLang.o: SymbolTable.h ../Include/Common.h ../Include/intermediate.h
ShaderLang.o: ../Include/InfoSink.h ParseHelper.h ../Include/ShHandle.h
ShaderLang.o: ../Public/ShaderLang.h ../Include/ResourceLimits.h
ShaderLang.o: ../Include/InfoSink.h ../Include/Common.h /usr/include/stdint.h
ShaderLang.o: /usr/include/features.h /usr/include/sys/cdefs.h
ShaderLang.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
ShaderLang.o: /usr/include/gnu/stubs-64.h /usr/include/bits/wchar.h
ShaderLang.o: /usr/include/assert.h ../Include/PoolAlloc.h
ShaderLang.o: /usr/include/math.h /usr/include/bits/huge_val.h
ShaderLang.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
ShaderLang.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
ShaderLang.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
ShaderLang.o: localintermediate.h ../Include/intermediate.h
ShaderLang.o: ../Include/Types.h ../Include/BaseTypes.h
ShaderLang.o: ../Include/ConstantUnion.h
ShaderLang.o: ../../OGLCompilersDLL/InitializeDll.h
ShaderLang.o: ../OSDependent/Linux/osinclude.h /usr/include/pthread.h
ShaderLang.o: /usr/include/endian.h /usr/include/bits/endian.h
ShaderLang.o: /usr/include/bits/byteswap.h /usr/include/sched.h
ShaderLang.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
ShaderLang.o: /usr/include/time.h /usr/include/bits/sched.h
ShaderLang.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/setjmp.h
ShaderLang.o: /usr/include/semaphore.h /usr/include/sys/types.h
ShaderLang.o: /usr/include/sys/select.h /usr/include/bits/select.h
ShaderLang.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
ShaderLang.o: /usr/include/sys/sysmacros.h /usr/include/bits/semaphore.h
ShaderLang.o: /usr/include/errno.h /usr/include/bits/errno.h
ShaderLang.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
ShaderLang.o: /usr/include/asm-generic/errno.h
ShaderLang.o: /usr/include/asm-generic/errno-base.h
ShaderLang.o: ../Include/InitializeGlobals.h ../Include/PoolAlloc.h
ShaderLang.o: Initialize.h ../Include/ResourceLimits.h
SymbolTable.o: SymbolTable.h ../Include/Common.h ../Include/intermediate.h
SymbolTable.o: ../Include/InfoSink.h
intermOut.o: localintermediate.h ../Include/intermediate.h
intermOut.o: ../Include/Common.h /usr/include/stdint.h
intermOut.o: /usr/include/features.h /usr/include/sys/cdefs.h
intermOut.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
intermOut.o: /usr/include/gnu/stubs-64.h /usr/include/bits/wchar.h
intermOut.o: /usr/include/assert.h ../Include/PoolAlloc.h ../Include/Types.h
intermOut.o: ../Include/BaseTypes.h ../Include/ConstantUnion.h
intermOut.o: ../Public/ShaderLang.h ../Include/ResourceLimits.h SymbolTable.h
intermOut.o: ../Include/Common.h ../Include/intermediate.h
intermOut.o: ../Include/InfoSink.h
parseConst.o: ParseHelper.h ../Include/ShHandle.h ../Public/ShaderLang.h
parseConst.o: ../Include/ResourceLimits.h ../Include/InfoSink.h
parseConst.o: ../Include/Common.h /usr/include/stdint.h
parseConst.o: /usr/include/features.h /usr/include/sys/cdefs.h
parseConst.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
parseConst.o: /usr/include/gnu/stubs-64.h /usr/include/bits/wchar.h
parseConst.o: /usr/include/assert.h ../Include/PoolAlloc.h
parseConst.o: /usr/include/math.h /usr/include/bits/huge_val.h
parseConst.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
parseConst.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
parseConst.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
parseConst.o: SymbolTable.h ../Include/Common.h ../Include/intermediate.h
parseConst.o: ../Include/InfoSink.h localintermediate.h
parseConst.o: ../Include/intermediate.h ../Include/Types.h
parseConst.o: ../Include/BaseTypes.h ../Include/ConstantUnion.h
InfoSink.o: ../Include/InfoSink.h
