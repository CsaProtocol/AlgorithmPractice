
cc = g++
cflags = -g -Wall -Wno-sequence-point -pedantic -O0 -std=c++20 -fsanitize=address
cflagsextra = -g -ftest-coverage -fprofile-arcs -Wextra -Woverloaded-virtual -Wuninitialized -Wmaybe-uninitialized -Werror -Wshadow -Wuninitialized -Wconversion -Wsign-compare -D_GLIBCXX_DEBUG -fsanitize=undefined -fno-omit-frame-pointer -Wstrict-aliasing=3 -Wcast-qual -Wcast-align
cflagsexplicitwall = -Waddress -Waligned-new -Warray-bounds=1 -Warray-compare -Warray-parameter=2 -Wbool-compare -Wbool-operation -Wc++11-compat -Wc++14-compat -Wc++17-compat -Wc++20-compat -Wcatch-value -Wchar-subscripts -Wclass-memaccess -Wcomment -Wdangling-else -Wdangling-pointer=2 -Wdelete-non-virtual-dtor -Wenum-compare -Wformat=1 -Wformat-contains-nul -Wformat-diag -Wformat-extra-args -Wformat-overflow=1 -Wformat-truncation=1 -Wformat-zero-length -Wframe-address -Winfinite-recursion -Winit-self -Wint-in-bool-context -Wlogical-not-parentheses -Wmaybe-uninitialized -Wmemset-elt-size -Wmemset-transposed-args -Wmisleading-indentation -Wmismatched-dealloc -Wmismatched-new-delete -Wmissing-attributes -Wmultistatement-macros -Wnarrowing -Wnonnull -Wnonnull-compare -Wopenmp-simd -Woverloaded-virtual=1 -Wpacked-not-aligned -Wparentheses -Wpessimizing-move -Wrange-loop-construct -Wreorder -Wrestrict -Wreturn-type -Wself-move -Wsequence-point -Wsign-compare -Wsizeof-array-div -Wsizeof-pointer-div -Wsizeof-pointer-memaccess -Wstrict-aliasing -Wstrict-overflow=1 -Wswitch -Wtautological-compare -Wtrigraphs -Wuninitialized -Wunknown-pragmas -Wunused -Wunused-but-set-variable -Wunused-function -Wunused-label -Wunused-local-typedefs -Wunused-value -Wunused-variable -Wuse-after-free=2 -Wvla-parameter -Wvolatile-register-var -Wzero-length-bounds

objects = main.o test.o mytest.o container.o exc1as.o exc1af.o exc1bs.o exc1bf.o exc2as.o exc2af.o exc2bs.o exc2bf.o exc3as.o exc3af.o zmytestvector.o zmytestsortablevector.o zmytestlist.o zmytestlinear.o zmytestsetlst.o zmytestsetvec.o zmytestset.o zmytestheapvec.o zmytestpqheap.o

libcon = container/container.hpp container/testable.hpp container/traversable.hpp container/traversable.cpp container/mappable.hpp container/mappable.cpp container/dictionary.hpp container/dictionary.cpp container/linear.hpp container/linear.cpp
libexc = $(libcon) zlasdtest/container/container.hpp zlasdtest/container/testable.hpp zlasdtest/container/traversable.hpp zlasdtest/container/mappable.hpp zlasdtest/container/dictionary.hpp zlasdtest/container/linear.hpp

libexc1a = $(libexc) vector/vector.hpp vector/vector.cpp list/list.hpp list/list.cpp
libexc1b = $(libexc1a) set/set.hpp set/lst/setlst.hpp set/lst/setlst.cpp set/vec/setvec.hpp set/vec/setvec.cpp

libexc2a = $(libexc) heap/heap.hpp heap/vec/heapvec.hpp heap/vec/heapvec.cpp zlasdtest/heap/heap.hpp
libexc2b = $(libexc2a) pq/pq.hpp pq/heap/pqheap.hpp pq/heap/pqheap.cpp zlasdtest/pq/pq.hpp

libexc3a = $(libexc1a) stack/stack.hpp stack/lst/stacklst.cpp stack/lst/stacklst.hpp stack/vec/stackvec.cpp stack/vec/stackvec.hpp queue/queue.hpp queue/lst/queuelst.cpp queue/lst/queuelst.hpp queue/vec/queuevec.cpp queue/vec/queuevec.hpp

all: main

lcov-report: coverage
	mkdir lcov-report
	lcov --capture --directory . --output-file lcov-report/coverage.info
	genhtml lcov-report/coverage.info --output-directory lcov-report

gcovr-report: coverage
	mkdir gcovr-report
	gcovr --root . --html --html-details --output gcovr-report/coverage.html

coverage:
	gcov zmytestvector.o zmytestsortablevector.o zmytestlist.o zmytestlinear.o zmytestsetlst.o zmytestsetvec.o exc1as.o exc1af.o exc1bs.o exc1bf.o main.o test.o

main: $(objects)
	$(cc) $(cflags) $(objects) -o main

clean:
	clear; rm -rfv *.o *.gcov *.gcno *.gcda gcovr-report/ lcov-report/ combined_output.txt main

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

exc2as.o: $(libexc2a) zlasdtest/exercise2a/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise2a/simpletest.cpp -o exc2as.o
exc2af.o: $(libexc2a) zlasdtest/exercise2a/fulltest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise2a/fulltest.cpp -o exc2af.o

exc2bs.o: $(libexc2b) zlasdtest/exercise2b/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise2b/simpletest.cpp -o exc2bs.o
exc2bf.o: $(libexc2b) zlasdtest/exercise2b/fulltest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise2b/fulltest.cpp -o exc2bf.o

exc3as.o: $(libexc3a) zlasdtest/exercise3a/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise3a/simpletest.cpp -o exc3as.o
exc3af.o: $(libexc3a) zlasdtest/exercise3a/fulltest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise3a/fulltest.cpp -o exc3af.o


zmytestvector.o: zmytest/linear/vector zmytest/linear/vector
	$(cc) $(cflags) -c zmytest/linear/vector/vector.cpp -o zmytestvector.o

zmytestsortablevector.o: zmytest/linear/sortablevector/sortablevector.cpp zmytest/linear/sortablevector/sortablevector.hpp
	$(cc) $(cflags) -c zmytest/linear/sortablevector/sortablevector.cpp -o zmytestsortablevector.o

zmytestlist.o: zmytest/linear/list/list.cpp zmytest/linear/list/list.hpp
	$(cc) $(cflags) -c zmytest/linear/list/list.cpp -o zmytestlist.o

zmytestlinear.o: zmytest/linear/linear.cpp zmytest/linear/linear.hpp
	$(cc) $(cflags) -c zmytest/linear/linear.cpp -o zmytestlinear.o

zmytestsetlst.o: zmytest/set/setlst/setlst.cpp zmytest/set/setlst/setlst.hpp
	$(cc) $(cflags) -c zmytest/set/setlst/setlst.cpp -o zmytestsetlst.o

zmytestsetvec.o: zmytest/set/setvec/setvec.cpp zmytest/set/setvec/setvec.hpp
	$(cc) $(cflags) -c zmytest/set/setvec/setvec.cpp -o zmytestsetvec.o

zmytestset.o: zmytest/set/set.hpp zmytest/set/set.cpp
	$(cc) $(cflags) -c zmytest/set/set.cpp -o zmytestset.o

zmytestheapvec.o: zmytest/heap/heapvec.cpp zmytest/heap/heapvec.hpp
	$(cc) $(cflags) -c zmytest/heap/heapvec.cpp -o zmytestheapvec.o

zmytestpqheap.o: zmytest/pq/pq.cpp zmytest/pq/pq.hpp
	$(cc) $(cflags) -c zmytest/pq/pq.cpp -o zmytestpqheap.o