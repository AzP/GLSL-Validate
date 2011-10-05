
CXX=g++ $(CFLAGS)
LIBPATH=./../../OpenGLCompilerSept202005/glslang/MachineIndependent/lib
INCLUDEDIRS=-I./../../OpenGLCompilerSept202005/ $(shell wx-config --cppflags) -I/usr/X11R6/include $(shell pkg-config gtk+-2.0 --cflags)
LIBS=$(shell wx-config --libs)
CXXSOURCES=App.cpp Frame.cpp Tables.cpp DropTarget.cpp
CXXOBJECTS=$(CXXSOURCES:.cpp=.o)
CXXFLAGS=-DESRI_UNIX $(INCLUDEDIRS)
CXXOPTS=-fPIC -Wall -pedantic

TARGETOBJECT=GLSLValidate

default: all

debug: CXX += -ggdb -ggdb3
debug: all

all: $(TARGETOBJECT)

$(TARGETOBJECT): $(CXXOBJECTS)
	$(CXX) -o $@ $(CXXOBJECTS) $(CXXOPTS) -L$(LIBPATH) $(LIBS) $(INCLUDEDIRS) -lglslang -lm -lstdc++ -Wl,-rpath=${PWD}/$(LIBPATH)

#
# Cleanup
#
.PHONY : clean
clean :
	$(RM) $(TARGETOBJECT) $(CXXOBJECTS)

depend:
	makedepend -Y -- $(CXXSOURCES)

# DO NOT DELETE

App.o: App.h Frame.h
Frame.o: Frame.h Tables.h App.h DropTarget.h
Tables.o: Tables.h
DropTarget.o: DropTarget.h Frame.h
