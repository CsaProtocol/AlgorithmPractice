#include "test.hpp"

#include <iostream>

#include "heap/heapvec.hpp"
#include "linear/linear.hpp"
#include "linear/list/list.hpp"
#include "linear/sortablevector/sortablevector.hpp"
#include "linear/vector/vector.hpp"
#include "pq/pq.hpp"
#include "set/set.hpp"
#include "set/setlst/setlst.hpp"
#include "set/setvec/setvec.hpp"

namespace zmytest {
    void mytestex1() {
        unsigned int testnum = 0;
        unsigned int testerr = 0;
        unsigned int testpass = 0;

        std::cout << "\n~*~#~*~ Exercise 1 Tests ~*~#~*~ " << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        zMyTestVector(testnum, testerr);
        zMyTestSortableVector(testnum, testerr);
        zMyTestList(testnum, testerr);
        zMyTestLinear(testnum, testerr);

        zMyTestSetLst(testnum, testerr);
        zMyTestSetVec(testnum, testerr);
        zMyTestSet(testnum, testerr);

        testpass = testnum - testerr;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "\nExercise 1 tests completed!" << std::endl;
        std::cout << std::endl << "Personal tests for Exercise 1 (Passed/Errors/Tests: " << testpass << "/" << testerr << "/" << testnum << ")" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    void mytestex2() {
        unsigned int testnum = 0;
        unsigned int testerr = 0;
        unsigned int testpass = 0;

        std::cout << "\n~*~#~*~ Exercise 2 Tests ~*~#~*~ " << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        zMyTestHeapVec(testnum, testerr);
        zMyTestPQHeap(testnum, testerr);

        testpass = testnum - testerr;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "\nExercise 2 tests completed!" << std::endl;
        std::cout << std::endl << "Personal tests for Exercise 2 (Passed/Errors/Tests: " << testpass << "/" << testerr << "/" << testnum << ")" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    void mytest() {
        unsigned int testnum = 0;
        unsigned int testerr = 0;
        unsigned int testpass = 0;

        std::cout << "\n~*~#~*~ All Tests ~*~#~*~ " << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        zMyTestVector(testnum, testerr);
        zMyTestSortableVector(testnum, testerr);
        zMyTestList(testnum, testerr);
        zMyTestLinear(testnum, testerr);

        zMyTestSetLst(testnum, testerr);
        zMyTestSetVec(testnum, testerr);
        zMyTestSet(testnum, testerr);

        zMyTestHeapVec(testnum, testerr);
        zMyTestPQHeap(testnum, testerr);

        testpass = testnum - testerr;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "\nAll tests completed!" << std::endl;
        std::cout << std::endl << "Personal tests (Passed/Errors/Tests: " << testpass << "/" << testerr << "/" << testnum << ")" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }
}
