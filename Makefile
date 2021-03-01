CC := g++

STANDARD := c++17
FLAGS := -Wall -Wextra -pedantic -g
CFLAGS := -std=$(STANDARD) -I"$(JAVA_HOME)/include" -I"$(JAVA_HOME)/include/win32" -Isrc/cpp -shared -fPIC

build := build
shared := libnativeio.so

ifeq ($(OS), Windows_NT)
	shared := nativeio.dll
else
	ifeq ($(shell uname), Darwin) 
		shared := libnativeio.dylib
		CFLAGS += -dynamiclib
	endif
endif

sources := $(shell find src/cpp -type f -name "*.cpp" -o -name "*.h")

all: $(shared)

$(shared): $(sources)
	@printf "SHARED\t%s\n" $@
	@$(CC) $(FLAGS) $(CFLAGS) -o $(build)/$@ src/cpp/*.cpp
