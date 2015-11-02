CXX=clang++
#CXX=g++

# We have -Wno-unused-parameter so that the compiler
# doesn't complain too much about our stubs.

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field


BINARIES=testInsert testRuntime testUserNetwork testLoadUsers Launch

all: ${BINARIES}

testInsert: testInsert.o List.o tddFuncs.o
	${CXX} $^ -o $@

testRuntime: testRuntime.o List.o tddFuncs.o
	${CXX} $^ -o $@

testUserNetwork: testUserNetwork.o List.o UserNetwork.o User.o Wall.o WallPost.o tddFuncs.o
	${CXX} $^ -o $@

Launch: Launch.o List.o UserNetwork.o User.o Wall.o WallPost.o
	${CXX} $^ -o $@

testLoadUsers: testLoadUsers.o List.o UserNetwork.o User.o Wall.o WallPost.o tddFuncs.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./testInsert
	./testRuntime
	./testUserNetwork
	./testLoadUsers
	./Launch

clean:
	/bin/rm -f ${BINARIES} *.o *~
