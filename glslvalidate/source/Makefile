CXX=g++
LIBPATH=-L../../OpenGLCompilerSept202005/glslang/MachineIndependent/lib
INCLUDEDIRS=-I../../OpenGLCompilerSept202005/ $(shell wx-config --cppflags) -I/usr/X11R6/include $(shell pkg-config gtk+-2.0 --cflags)
LIBS=$(shell wx-config --libs) 
CXXSOURCES=App.cpp Frame.cpp Tables.cpp DropTarget.cpp
CXXOBJECTS=$(CXXSOURCES:.cpp=.o)
CXXFLAGS=-DESRI_UNIX $(INCLUDEDIRS)

TARGETOBJECT=GLSLValidate

default: all

all: $(TARGETOBJECT)

$(TARGETOBJECT): $(CXXOBJECTS)
	$(CXX) -g -o $@ $(CXXOBJECTS) $(LIBPATH) $(LIBS) $(INCLUDEDIRS) -lglslang -lm -lstdc++

#
# Cleanup
#
.PHONY : clean
clean :
	$(RM) $(TARGETOBJECT) $(CXXOBJECTS)

depend:
	make depend
	makedepend -Y -- $(CXXSOURCES)

# DO NOT DELETE

App.o: App.h Frame.h
DropTarget.o: DropTarget.h Frame.h
Frame.o: Frame.h Tables.h App.h DropTarget.h
Tables.o: Tables.h
