CXX=clang++
#CXX=g++

# We have -Wno-unused-parameter so that the compiler
# doesn't complain too much about our stubs.

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

# Change to this before final submission:

#CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES=testInsert testUserNetwork testLoadUsers
#	testWordCount04 testWordCount05 testWordCount06 testWordCount07 \
#	testWordCountHelper01

all: ${BINARIES}

testInsert: testInsert.o LinkedList.o tddFuncs.o
	${CXX} $^ -o $@

testUserNetwork: testUserNetwork.o LinkedList.o UserNetwork.o User.o Wall.o WallPost.o tddFuncs.o
	${CXX} $^ -o $@

testLoadUsers: testLoadUsers.o LinkedList.o UserNetwork.o User.o Wall.o WallPost.o tddFuncs.o
	${CXX} $^ -o $@

#testWordCount01: testWordCount01.o WordCount.o WordCountHelper.o tddFuncs.o
#	${CXX} $^ -o $@


tests: ${BINARIES}
	./testInsert
	./testUserNetwork
	./testLoadUsers


clean:
	/bin/rm -f ${BINARIES} *.o *~
