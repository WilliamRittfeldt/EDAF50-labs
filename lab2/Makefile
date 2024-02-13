# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast -Og
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS =  spell #hello kan stå här också 

all: $(PROGS)

#hello: hello.o #funkar ej 

preprocessor:  preprocessor.cc
	g++ -o preprocessor preprocessor.cc


spell:	spell.o Dictionary.o 
	g++ -o spell spell.o Dictionary.o $(LDFLAGS)

# Add a rule for compiling Dictionary.o
Dictionary.o:	Dictionary.cc
	g++ -c Dictionary.cc $(CXXFLAGS)

# Existing rules for spell.o and other objects
spell.o:	spell.cc
	g++ -c spell.cc $(CXXFLAGS) 

#test: test_coding
#	./test_coding

#encode: encode.o
#g++ -o encode encode.cc

#decode: decode.o
#g++ -o decode decode.cc

# Targets rely on implicit rules for compiling and linking
#ltest: ltest.o list.o
#test_coding: test_coding.o coding.o
#print_argv: print_argv.o



# Phony targets
.PHONY: all test clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d


# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
