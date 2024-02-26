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
PROGS = nstest nstime

all: $(PROGS)




nstest: nstest.o vns.o umns.o mns.o hns.o
	$(CXX) -o nstest nstest.o vns.o umns.o mns.o hns.o $(LDFLAGS)

nstime: nstime.o vns.o umns.o mns.o hns.o
	$(CXX) -o nstime nstime.o vns.o umns.o mns.o hns.o $(LDFLAGS)

# Rule for vns
vns.o: vns.cc 
	$(CXX) -c vns.cc $(LDFLAGS)

# Rule for mns
mns.o: mns.cc
	$(CXX) -c mns.cc $(LDFLAGS)

# Rule for umns
umns.o: umns.cc
	$(CXX) -c umns.cc $(LDFLAGS)

# Rule for hns
hns.o: hns.cc
	$(CXX) -c hns.cc $(LDFLAGS)

nstest.o: nstest.cc
	$(CXX) -c nstest.cc $(LDFLAGS)

nstime.o: nstime.cc
	$(CXX) -c nstime.cc $(LDFLAGS)


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
