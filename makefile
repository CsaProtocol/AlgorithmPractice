
cc = g++
cflags = -g -Wall -Wextra -pedantic -O0 -std=c++20
cflagsextra = -Werror -Wshadow -Wuninitialized -Wconversion -Wsign-compare -D_GLIBCXX_DEBUG -fsanitize=undefined -fno-omit-frame-pointer -Wstrict-aliasing=3 -Wcast-qual -Wcast-align

objects = main.o test.o mytest.o container.o exc1as.o exc1af.o exc1bs.o exc1bf.o zmytestvector.o zmytestsortablevector.o zmytestlist.o zmytestlinear.o zmytestsetlst.o

libcon = container/container.hpp container/testable.hpp container/traversable.hpp container/traversable.cpp container/mappable.hpp container/mappable.cpp container/dictionary.hpp container/dictionary.cpp container/linear.hpp container/linear.cpp

libexc = $(libcon) zlasdtest/container/container.hpp zlasdtest/container/testable.hpp zlasdtest/container/traversable.hpp zlasdtest/container/mappable.hpp zlasdtest/container/dictionary.hpp zlasdtest/container/linear.hpp

libexc1a = $(libexc) vector/vector.hpp vector/vector.cpp list/list.hpp list/list.cpp

libexc1b = $(libexc1a) set/set.hpp set/lst/setlst.hpp set/lst/setlst.cpp set/vec/setvec.hpp set/vec/setvec.cpp

all: main

main: $(objects)
	$(cc) $(cflags) $(cflagsextra) $(objects) -o main

clean:
	clear; rm -rfv *.o; rm -fv main

main.o: main.cpp
	$(cc) $(cflags) -c main.cpp

test.o: zlasdtest/test.cpp zlasdtest/test.hpp
	$(cc) $(cflags) -c zlasdtest/test.cpp -o test.o

mytest.o: zmytest/test.cpp zmytest/test.hpp
	$(cc) $(cflags) -c zmytest/test.cpp -o mytest.o

container.o: $(libcon) zlasdtest/container/container.cpp zlasdtest/container/container.hpp
	$(cc) $(cflags) -c zlasdtest/container/container.cpp -o container.o

exc1as.o: $(libexc1a) zlasdtest/exercise1a/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise1a/simpletest.cpp -o exc1as.o

exc1af.o: $(libexc1a) zlasdtest/exercise1a/fulltest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise1a/fulltest.cpp -o exc1af.o

exc1bs.o: $(libexc1b) zlasdtest/exercise1b/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise1b/simpletest.cpp -o exc1bs.o

exc1bf.o: $(libexc1b) zlasdtest/exercise1b/fulltest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise1b/fulltest.cpp -o exc1bf.o


zmytestvector.o: zmytest/linear/vector zmytest/linear/vector
	$(cc) $(cflags) -c zmytest/linear/vector/vector.cpp -o zmytestvector.o

zmytestsortablevector.o: zmytest/linear/sortablevector/sortablevector.cpp zmytest/linear/sortablevector/sortablevector.hpp
	$(cc) $(cflags) -c zmytest/linear/sortablevector/sortablevector.cpp -o zmytestsortablevector.o

zmytestlist.o: zmytest/linear/list/list.cpp zmytest/linear/list/list.hpp
	$(cc) $(cflags) -c zmytest/linear/list/list.cpp -o zmytestlist.o

zmytestlinear.o: zmytest/linear/linear.cpp zmytest/linear/linear.hpp
	$(cc) $(cflags) -c zmytest/linear/linear.cpp -o zmytestlinear.o

zmytestsetlst.o: zmytest/setlst/setlst.cpp zmytest/setlst/setlst.hpp
	$(cc) $(cflags) -c zmytest/setlst/setlst.cpp -o zmytestsetlst.o