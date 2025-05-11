#include "test.hpp"

#include <iostream>

#include "linear/linear.hpp"
#include "linear/list/list.hpp"
#include "setlst/setlst.hpp"
#include "linear/sortablevector/sortablevector.hpp"
#include "linear/vector/vector.hpp"

namespace zmytest {


    void mytest() {
        unsigned int testnum = 0;
        unsigned int testerr = 0;
        unsigned int testpass = 0;

        zMyTestVector(testnum, testerr);
        zMyTestSortableVector(testnum, testerr);
        zMyTestList(testnum, testerr);
        zMyTestLinear(testnum, testerr);

        zMyTestSetLst(testnum, testerr);


        testpass = testnum - testerr;
        std::cout << std::endl << "Personal tests (Passed/Errors/Tests: " << testpass << "/" << testerr << "/" << testnum << ")" << std::endl;
    }


}