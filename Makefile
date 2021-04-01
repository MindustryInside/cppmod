CXX := g++

CXXSOURCES := src/main/cpp

CFLAGS := -O3 -Wall -Wextra -pedantic -g -std=c++17 -I$(CXXSOURCES)
LDFLAGS := -fPIC -shared -I"$(JAVA_HOME)/include" -I"$(JAVA_HOME)/include/linux"

SOURCES := src/main/java
RESOURCES := src/main/resources
BUILD := build
CLASSES := $(BUILD)/classes
CXXBUILD := $(BUILD)/shared
LIBS := libs

MINDUSTRY := $(HOME)/.local/share/Mindustry

JAVAC := javac
JAVACFLAGS := -g -Xlint:all
JAVACFLAGS += -classpath "$(LIBS)/*"
JAVACFLAGS += -sourcepath $(SOURCES)
JAVACFLAGS += --release 8
JAR := jar
JARFLAGS := -C $(CLASSES) .
JARFLAGS += -C $(RESOURCES) .
JARFLAGS += -C $(CXXBUILD) .

version := v126.1

cxxsources := $(shell find $(CXXSOURCES) -type f -name "*.h" -or -name "*.cpp")

sources := $(shell find $(SOURCES) -type f -name "*.java")
classes = $(patsubst $(SOURCES)/%.java, $(CLASSES)/%.class, $(sources))
headers := $(CXXSOURCES)/java

shared := $(CXXBUILD)/libnativeio.so
jar := $(BUILD)/nativeio.jar

ifeq ($(OS), Windows_NT)
	# windows sucks
	rm = @cmd /C if exist $(1) rmdir /Q /S $(1)
	cp = @printf y | xcopy "$(subst /,\,$(1))" "$(subst /,\,$(2))" > $(BUILD)/install.txt
	mkdir = @cmd /C if not exist $(subst /,\,$(1)) mkdir $(subst /,\,$(1))

	MINDUSTRY := $(subst \,/,$(USERPROFILE))/AppData/Roaming/Mindustry

	shared := $(CXXBUILD)/nativeio.dll
	LDFLAGS := -fPIC -shared -I"$(JAVA_HOME)/include" -I"$(JAVA_HOME)/include/win32"
else
	rm = @rm -rf $(1)
	cp = @cp $(1) $(2)
	mkdir = @mkdir -p $(1)

	ifeq ($(shell uname), Darwin)
		shared :=  $(CXXBUILD)/libnativeio.dylib

		shared :=  $(CXXBUILD)/libnativeio.dylib
		LDFLAGS := -dynamiclib -I"$(JAVA_HOME)/include" -I"$(JAVA_HOME)/include/darwin"
	endif
endif

all: jar

libs := arc-core mindustry-core
libs := $(libs:%=$(LIBS)/%.jar)

define lib
	@printf "LIB\t%s\n" $(LIBS)/$(1).jar
	@curl --create-dirs -s -o $(LIBS)/$(1).jar 'https://jitpack.io/com/github/$(2)/$(3)/$(4)/$(3)-$(4).jar'
endef

headers: $(headers)
jar: $(jar)

$(libs):
	$(call rm, $(LIBS))
	$(call mkdir, $(LIBS))
	$(call lib,arc-core,Anuken/Arc,arc-core,$(version))
	$(call lib,mindustry-core,Anuken/Mindustry,core,$(version))

$(jar): $(shared) $(libs) $(classes)
	@printf "JAR\t%s\n" $@
	@$(JAR) -cf $@ $(JARFLAGS)

$(CLASSES)/%.class: $(SOURCES)/%.java
	@printf "JAVAC\t%s\n" $@
	@$(JAVAC) $(JAVACFLAGS) -d $(CLASSES) $<

$(shared):
	@printf "CXX\t%s\n" $@
	@$(call mkdir,$(CXXBUILD))
	@$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(CXXSOURCES:%=%/*.cpp)

$(headers): $(sources)
	@printf "HEADERS\t%s\n" $@
	@$(JAVAC) $(JAVACFLAGS) -d $(CLASSES) -h $@ $<

clean:
	$(call rm,$(BUILD))

install: $(jar)
	@printf "COPY\t%s %s\t\n" $< $(MINDUSTRY)/mods/$<
	$(call cp,$<,$(MINDUSTRY)/mods)
