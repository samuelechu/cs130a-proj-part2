CXX=clang++
#CXX=g++

# We have -Wno-unused-parameter so that the compiler
# doesn't complain too much about our stubs.

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field


BINARIES=testInsert testRuntime

all: ${BINARIES}

testInsert: testInsert.o List.o tddFuncs.o
	${CXX} $^ -o $@

testRuntime: testRuntime.o List.o tddFuncs.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./testInsert
	./testRuntime


clean:
	/bin/rm -f ${BINARIES} *.o *~
