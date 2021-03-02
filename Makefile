CXX := g++

STANDARD := c++17
CFLAGS := -O3 -Wall -Wextra -pedantic -g -std=$(STANDARD) -Isrc/cpp
LDFLAGS := -fPIC -shared -I"$(JAVA_HOME)/include" -I"$(JAVA_HOME)/include/linux"

build := build
shared := libnativeio.so

ifeq ($(OS), Windows_NT)
	shared := nativeio.dll
	LDFLAGS := -fPIC -shared -I"$(JAVA_HOME)/include" -I"$(JAVA_HOME)/include/win32"
else
	ifeq ($(shell uname), Darwin) 
		shared := libnativeio.dylib
		LDFLAGS := -dynamiclib -I"$(JAVA_HOME)/include" -I"$(JAVA_HOME)/include/darwin"
	endif
endif

sources := $(shell find src/cpp -type f -name "*.cpp" -o -name "*.h")

all: $(shared)

$(shared): $(sources)
	@printf "SHARED\t%s\n" $@
	@$(CXX) $(CFLAGS) $(LDFLAGS) -o $(build)/$@ src/cpp/*.cpp

.PHONY: all
