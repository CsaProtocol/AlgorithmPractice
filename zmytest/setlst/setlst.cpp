#include "setlst.hpp"

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"

#include "../../zlasdtest/set/set.hpp"
#include "../../list/list.hpp"
#include "../../vector/vector.hpp"

namespace zmytest {

void zMyTestSetLstInt(unsigned int& testnum, unsigned int& testerr) {
    lasd::SetLst<int> set;
    InsertC(testnum, testerr, set, true, 4);
    InsertC(testnum, testerr, set, true, 5);
    InsertC(testnum, testerr, set, true, 2);
    InsertC(testnum, testerr, set, true, 6);
    InsertC(testnum, testerr, set, true, 1);
    InsertC(testnum, testerr, set, true, 3);
    InsertC(testnum, testerr, set, false, 2);
    InsertC(testnum, testerr, set, false, 3);
    InsertC(testnum, testerr, set, false, 6);
    InsertC(testnum, testerr, set, false, 1);

    Remove(testnum, testerr, set, true, 4);
    Min(testnum, testerr, set, true, 1);
    Max(testnum, testerr, set, true, 6);
    Predecessor(testnum, testerr, set, true, 3, 2);
    Successor(testnum, testerr, set, true, 3, 5);
    Predecessor(testnum, testerr, set, false, 1, 0);

    // Test Exists
    Exists(testnum, testerr, set, true, 3);
    Exists(testnum, testerr, set, false, 4);

    // Test MinNRemove, MaxNRemove
    MinNRemove(testnum, testerr, set, true, 1);
    MaxNRemove(testnum, testerr, set, true, 6);
    Min(testnum, testerr, set, true, 2); // Verify Min changed
    Max(testnum, testerr, set, true, 5); // Verify Max changed

    // Test RemoveMin, RemoveMax
    RemoveMin(testnum, testerr, set, true);
    RemoveMax(testnum, testerr, set, true);
    Min(testnum, testerr, set, true, 3); // Verify Min changed
    Max(testnum, testerr, set, true, 3); // Verify Max changed

    // Rebuild the set
    InsertC(testnum, testerr, set, true, 1);
    InsertC(testnum, testerr, set, true, 5);
    InsertC(testnum, testerr, set, true, 2);
    InsertC(testnum, testerr, set, true, 7);

    // Test PredecessorNRemove, SuccessorNRemove
    PredecessorNRemove(testnum, testerr, set, true, 3, 2);
    SuccessorNRemove(testnum, testerr, set, true, 3, 5);

    // Test RemovePredecessor, RemoveSuccessor
    RemovePredecessor(testnum, testerr, set, true,7);
    RemoveSuccessor(testnum, testerr, set, true, 1);

    // Test index operator
    GetAt(testnum, testerr, set, true, 0, 1);
    GetAt(testnum, testerr, set, false,1, 7);

    // Test equality
    lasd::SetLst<int> set2;
    InsertC(testnum, testerr, set2, true, 1);
    InsertC(testnum, testerr, set2, true, 7);
    InsertC(testnum, testerr, set, true, 7);
    EqualSetLst(testnum, testerr, set, set2, true);
    InsertC(testnum, testerr, set2, true, 9);
    EqualSetLst(testnum, testerr, set, set2, false);

    // Test copy constructor
    lasd::SetLst<int> setCopy(set);
    EqualSetLst(testnum, testerr, set, setCopy, true);

    // Test move constructor
    lasd::SetLst<int> setMove(std::move(setCopy));
    EqualSetLst(testnum, testerr, set, setMove, true);

    // Test copy assignment
    lasd::SetLst<int> setCopyAssign;
    setCopyAssign = set;
    EqualSetLst(testnum, testerr, set, setCopyAssign, true);

    // Test move assignment
    lasd::SetLst<int> setMoveAssign;
    setMoveAssign = std::move(setCopyAssign);
    EqualSetLst(testnum, testerr, set, setMoveAssign, true);

    // Test Clear
    set.Clear();
    Min(testnum, testerr, set, false, 0); // Should fail as set is empty

    // Test construct from container
    lasd::Vector<int> vec(5);
    vec[0] = 10;
    vec[1] = 30;
    vec[2] = 20;
    vec[3] = 30; // duplicate
    vec[4] = 40;

    lasd::SetLst<int> setFromVec(vec);
    Size(testnum, testerr, setFromVec, true, 4); // Should have 4 elements (no duplicates)
    Exists(testnum, testerr, setFromVec, true, 10);
    Exists(testnum, testerr, setFromVec, true, 20);
    Exists(testnum, testerr, setFromVec, true, 30);
    Exists(testnum, testerr, setFromVec, true, 40);
}

void zMyTestSetLstString(unsigned int& testnum, unsigned int& testerr) {
}

void zMyTestSetLst(unsigned int& testnum, unsigned int& testerr) {
    std::cout << "\n~*~#~*~ Test SetLst Container ~*~#~*~ " << std::endl;

    std::cout << "\n[Test 1] Testing SetLst<int>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyTestSetLstInt(testnum, testerr);
    std::cout << "Integer set tests completed" << std::endl;

    std::cout << "\n[Test 2] Testing SetLst<string>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyTestSetLstString(testnum, testerr);
    std::cout << "String set tests completed" << std::endl;

    std::cout << "\nAll set tests completed!" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

}
