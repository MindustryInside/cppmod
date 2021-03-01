CC := g++

STANDARD := c++17
FLAGS := -Wall -Wextra -pedantic -g
CFLAGS := -std=$(STANDARD) -I"$(JAVA_HOME)/include" -Isrc/cpp

build := build
shared := libnativeio.so

ifeq ($(OS), Windows_NT)
	shared := nativeio.dll
	CFLAGS += -fPIC -shared -I"$(JAVA_HOME)/include/win32"
else
	ifeq ($(shell uname), Darwin) 
		shared := libnativeio.dylib
		CFLAGS += -dynamiclib -I"$(JAVA_HOME)/include/darwin"
	else
		CFLAGS += -fPIC -shared -I"$(JAVA_HOME)/include/linux"
	endif
endif

sources := $(shell find src/cpp -type f -name "*.cpp" -o -name "*.h")

all: $(shared)

$(shared): $(sources)
	@printf "SHARED\t%s\n" $@
	@$(CC) $(FLAGS) $(CFLAGS) -o $(build)/$@ src/cpp/*.cpp
