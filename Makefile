CXX=clang++
#CXX=g++

# We have -Wno-unused-parameter so that the compiler
# doesn't complain too much about our stubs.

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field


BINARIES= testUserNetwork testLoadUsers Launch

all: ${BINARIES}

testUserNetwork: testUserNetwork.o UserNetwork.o User.o Wall.o WallPost.o WallPostResponse.o tddFuncs.o
	${CXX} $^ -o $@

Launch: Launch.o UserNetwork.o User.o Wall.o WallPost.o WallPostResponse.o
	${CXX} $^ -o $@

testLoadUsers: testLoadUsers.o UserNetwork.o User.o Wall.o WallPost.o WallPostResponse.o tddFuncs.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./testUserNetwork
	./testLoadUsers
	./Launch

clean:
	/bin/rm -f ${BINARIES} *.o *~
