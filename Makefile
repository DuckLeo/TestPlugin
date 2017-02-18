GPP=g++
GCC=gcc
OUTFILE= "test_plugin.so"

COMPILE_FLAGS=-c -O3 -w -DLINUX -I./SDK/amx/

all:
	$(GCC) $(COMPILE_FLAGS) ./SDK/amx/*.c
	$(GPP) $(COMPILE_FLAGS) ./SDK/*.cpp
	$(GPP) $(COMPILE_FLAGS) *.cpp
	$(GPP) -O2 -fshort-wchar -shared -o $(OUTFILE) *.o