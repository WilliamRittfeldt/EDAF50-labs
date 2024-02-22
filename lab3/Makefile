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
PROGS =  tag_remover prime date toString

all: $(PROGS)

# Rule for tag_remover
tag_remover: tag_remover.o tag_remover_test.o
	$(CXX) -o tag_remover tag_remover.o tag_remover_test.o $(LDFLAGS)

# Rule for compiling tag_remover.o
tag_remover.o: tag_remover.cc tag_remover.h
	$(CXX) -c tag_remover.cc $(CXXFLAGS)

# Rule for compiling tag_remover.test.o
tagRemover_test.o: tagRemover_test.cc
	$(CXX) -c tagRemover_test.cc $(CXXFLAGS)

# Rule for prime
prime: prime.o
	$(CXX) -o prime prime.o $(LDFLAGS)

# Rule for compiling prime.o
prime.o: prime.cc
	$(CXX) -c prime.cc $(CXXFLAGS)
	
# Rule for date
date: date.o date_test.o
	$(CXX) -o date date.o date_test.o $(LDFLAGS)

# Rule for compiling date.o
date.o: date.cc
	$(CXX) -c date.cc $(CXXFLAGS)

# Rule for date_test
date_test: date.o date_test.o
	$(CXX) -o date_test date.o date_test.o $(LDFLAGS)

# Rule for toString 
toString: toString_test.o date.o
	$(CXX) -o toString toString_test.o date.o $(LDFLAGS)

# Rule for compiling toString.o
toString.o: toString.cc 
	$(CXX) -c toString.cc $(CXXFLAGS)

# Rule for compiling toString_test.o
toString_test.o: toString_test.cc date.h
	$(CXX) -c toString_test.cc $(CXXFLAGS)

#reprocessor.o:  preprocessor.cc
#	g++ -o preprocessor preprocessor.cc


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
