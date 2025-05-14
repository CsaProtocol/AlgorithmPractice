#include "setvec.hpp"

#include <iostream>
#include <string>

#include "../../../zlasdtest/container/container.hpp"
#include "../../../zlasdtest/container/dictionary.hpp"
#include "../../../zlasdtest/container/linear.hpp"
#include "../../../zlasdtest/container/mappable.hpp"
#include "../../../zlasdtest/container/testable.hpp"
#include "../../../zlasdtest/container/traversable.hpp"

#include "../../../zlasdtest/set/set.hpp"
#include "../../../list/list.hpp"
#include "../../../vector/vector.hpp"

namespace zmytest {

void zMyTestSetVecInt(unsigned int& testnum, unsigned int& testerr) {
    lasd::SetVec<int> set;
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

    Exists(testnum, testerr, set, true, 3);
    Exists(testnum, testerr, set, false, 4);

    MinNRemove(testnum, testerr, set, true, 1);
    MaxNRemove(testnum, testerr, set, true, 6);
    Min(testnum, testerr, set, true, 2); // Verify Min changed
    Max(testnum, testerr, set, true, 5); // Verify Max changed

    RemoveMin(testnum, testerr, set, true);
    RemoveMax(testnum, testerr, set, true);
    Min(testnum, testerr, set, true, 3); // Verify Min changed
    Max(testnum, testerr, set, true, 3); // Verify Max changed

    InsertC(testnum, testerr, set, true, 1);
    InsertC(testnum, testerr, set, true, 5);
    InsertC(testnum, testerr, set, true, 2);
    InsertC(testnum, testerr, set, true, 7);

    PredecessorNRemove(testnum, testerr, set, true, 3, 2);
    SuccessorNRemove(testnum, testerr, set, true, 3, 5);

    RemovePredecessor(testnum, testerr, set, true,7);
    RemoveSuccessor(testnum, testerr, set, true, 1);

    GetAt(testnum, testerr, set, true, 0, 1);
    GetAt(testnum, testerr, set, false,1, 7);

    lasd::SetVec<int> set2;
    InsertC(testnum, testerr, set2, true, 1);
    InsertC(testnum, testerr, set2, true, 7);
    InsertC(testnum, testerr, set, true, 7);
    EqualSetVec(testnum, testerr, set, set2, true);
    InsertC(testnum, testerr, set2, true, 9);
    EqualSetVec(testnum, testerr, set, set2, false);

    lasd::SetVec<int> setCopy(set);
    EqualSetVec(testnum, testerr, set, setCopy, true);

    lasd::SetVec<int> setMove(std::move(setCopy));
    EqualSetVec(testnum, testerr, set, setMove, true);

    lasd::SetVec<int> setCopyAssign;
    setCopyAssign = set;
    EqualSetVec(testnum, testerr, set, setCopyAssign, true);

    lasd::SetVec<int> setMoveAssign;
    setMoveAssign = std::move(setCopyAssign);
    EqualSetVec(testnum, testerr, set, setMoveAssign, true);

    set.Clear();
    Min(testnum, testerr, set, false, 0); // Should fail as set is empty

    lasd::Vector<int> vec(5);
    vec[0] = 10;
    vec[1] = 30;
    vec[2] = 20;
    vec[3] = 30;
    vec[4] = 40;

    const lasd::SetVec<int> setFromVec(vec);
    Size(testnum, testerr, setFromVec, true, 4); // Should have 4 elements (no duplicates)
    Exists(testnum, testerr, setFromVec, true, 10);
    Exists(testnum, testerr, setFromVec, true, 20);
    Exists(testnum, testerr, setFromVec, true, 30);
    Exists(testnum, testerr, setFromVec, true, 40);

    lasd::SetVec<int> setResize;
    InsertC(testnum, testerr, setResize, true, 10);
    InsertC(testnum, testerr, setResize, true, 20);
    InsertC(testnum, testerr, setResize, true, 30);

    setResize.Resize(10);
    Size(testnum, testerr, setResize, true, 3);
    Exists(testnum, testerr, setResize, true, 10);
    Exists(testnum, testerr, setResize, true, 20);
    Exists(testnum, testerr, setResize, true, 30);

    setResize.Resize(5);
    Size(testnum, testerr, setResize, true, 3);
    Exists(testnum, testerr, setResize, true, 10);
    Exists(testnum, testerr, setResize, true, 20);
    Exists(testnum, testerr, setResize, true, 30);

    InsertC(testnum, testerr, setResize, true, 40);
    InsertC(testnum, testerr, setResize, true, 50);
    InsertC(testnum, testerr, setResize, true, 60);
    Size(testnum, testerr, setResize, true, 6);

    Remove(testnum, testerr, setResize, true, 10);
    Remove(testnum, testerr, setResize, true, 20);
    Remove(testnum, testerr, setResize, true, 40);
    Remove(testnum, testerr, setResize, true, 50);
    Remove(testnum, testerr, setResize, true, 30);
    Remove(testnum, testerr, setResize, true, 60);
}

void zMyTestSetVecDouble(unsigned int& testnum, unsigned int& testerr) {
    lasd::SetVec<double> set;
    InsertC(testnum, testerr, set, true, 4.4);
    InsertC(testnum, testerr, set, true, 5.5);
    InsertC(testnum, testerr, set, true, 2.2);
    InsertC(testnum, testerr, set, true, 6.6);
    InsertC(testnum, testerr, set, true, 1.1);
    InsertC(testnum, testerr, set, true, 3.3);
    InsertC(testnum, testerr, set, false, 2.2);
    InsertC(testnum, testerr, set, false, 3.3);
    InsertC(testnum, testerr, set, false, 6.6);
    InsertC(testnum, testerr, set, false, 1.1);

    Remove(testnum, testerr, set, true, 4.4);
    Min(testnum, testerr, set, true, 1.1);
    Max(testnum, testerr, set, true, 6.6);
    Predecessor(testnum, testerr, set, true, 3.3, 2.2);
    Successor(testnum, testerr, set, true, 3.3, 5.5);
    Predecessor(testnum, testerr, set, false, 1.1, 0.0);

    Exists(testnum, testerr, set, true, 3.3);
    Exists(testnum, testerr, set, false, 4.4);

    MinNRemove(testnum, testerr, set, true, 1.1);
    MaxNRemove(testnum, testerr, set, true, 6.6);
    Min(testnum, testerr, set, true, 2.2);
    Max(testnum, testerr, set, true, 5.5);

    RemoveMin(testnum, testerr, set, true);
    RemoveMax(testnum, testerr, set, true);
    Min(testnum, testerr, set, true, 3.3);
    Max(testnum, testerr, set, true, 3.3);

    InsertC(testnum, testerr, set, true, 1.1);
    InsertC(testnum, testerr, set, true, 5.5);
    InsertC(testnum, testerr, set, true, 2.2);
    InsertC(testnum, testerr, set, true, 7.7);

    PredecessorNRemove(testnum, testerr, set, true, 3.3, 2.2);
    SuccessorNRemove(testnum, testerr, set, true, 3.3, 5.5);

    RemovePredecessor(testnum, testerr, set, true, 7.7);
    RemoveSuccessor(testnum, testerr, set, true, 1.1);

    GetAt(testnum, testerr, set, true, 0, 1.1);
    GetAt(testnum, testerr, set, false, 1, 7.7);

    lasd::SetVec<double> set2;
    InsertC(testnum, testerr, set2, true, 1.1);
    InsertC(testnum, testerr, set2, true, 7.7);
    InsertC(testnum, testerr, set, true, 7.7);
    EqualSetVec(testnum, testerr, set, set2, true);
    InsertC(testnum, testerr, set2, true, 9.9);
    EqualSetVec(testnum, testerr, set, set2, false);

    lasd::SetVec<double> setCopy(set);
    EqualSetVec(testnum, testerr, set, setCopy, true);

    lasd::SetVec<double> setMove(std::move(setCopy));
    EqualSetVec(testnum, testerr, set, setMove, true);

    lasd::SetVec<double> setCopyAssign;
    setCopyAssign = set;
    EqualSetVec(testnum, testerr, set, setCopyAssign, true);

    lasd::SetVec<double> setMoveAssign;
    setMoveAssign = std::move(setCopyAssign);
    EqualSetVec(testnum, testerr, set, setMoveAssign, true);

    set.Clear();
    Min(testnum, testerr, set, false, 0.0);

    lasd::Vector<double> vec(5);
    vec[0] = 10.1;
    vec[1] = 30.3;
    vec[2] = 20.2;
    vec[3] = 30.3;
    vec[4] = 40.4;

    const lasd::SetVec<double> setFromVec(vec);
    Size(testnum, testerr, setFromVec, true, 4);
    Exists(testnum, testerr, setFromVec, true, 10.1);
    Exists(testnum, testerr, setFromVec, true, 20.2);
    Exists(testnum, testerr, setFromVec, true, 30.3);
    Exists(testnum, testerr, setFromVec, true, 40.4);

    lasd::SetVec<double> setResize;
    InsertC(testnum, testerr, setResize, true, 10.1);
    InsertC(testnum, testerr, setResize, true, 20.2);
    InsertC(testnum, testerr, setResize, true, 30.3);

    setResize.Resize(10);
    Size(testnum, testerr, setResize, true, 3);
    Exists(testnum, testerr, setResize, true, 10.1);
    Exists(testnum, testerr, setResize, true, 20.2);
    Exists(testnum, testerr, setResize, true, 30.3);

    setResize.Resize(5);
    Size(testnum, testerr, setResize, true, 3);
    Exists(testnum, testerr, setResize, true, 10.1);
    Exists(testnum, testerr, setResize, true, 20.2);
    Exists(testnum, testerr, setResize, true, 30.3);

    InsertC(testnum, testerr, setResize, true, 40.4);
    InsertC(testnum, testerr, setResize, true, 50.5);
    Size(testnum, testerr, setResize, true, 5);
}

void zMyTestSetVecString(unsigned int& testnum, unsigned int& testerr) {
    lasd::SetVec<std::string> set;
    InsertC(testnum, testerr, set, true, std::string("Alpha"));
    InsertC(testnum, testerr, set, true, std::string("Beta"));
    InsertC(testnum, testerr, set, true, std::string("Gamma"));
    InsertC(testnum, testerr, set, true, std::string("Delta"));
    InsertC(testnum, testerr, set, true, std::string("Epsilon"));
    InsertC(testnum, testerr, set, true, std::string("Zeta"));
    InsertC(testnum, testerr, set, false, std::string("Gamma"));
    InsertC(testnum, testerr, set, false, std::string("Delta"));
    InsertC(testnum, testerr, set, false, std::string("Zeta"));
    InsertC(testnum, testerr, set, false, std::string("Epsilon"));

    Remove(testnum, testerr, set, true, std::string("Alpha"));
    Min(testnum, testerr, set, true, std::string("Beta"));
    Max(testnum, testerr, set, true, std::string("Zeta"));
    Predecessor(testnum, testerr, set, true, std::string("Delta"), std::string("Beta"));
    Successor(testnum, testerr, set, true, std::string("Delta"), std::string("Epsilon"));
    Predecessor(testnum, testerr, set, false, std::string("Beta"), std::string(""));

    Exists(testnum, testerr, set, true, std::string("Epsilon"));
    Exists(testnum, testerr, set, false, std::string("Alpha"));

    MinNRemove(testnum, testerr, set, true, std::string("Beta"));
    MaxNRemove(testnum, testerr, set, true, std::string("Zeta"));
    Min(testnum, testerr, set, true, std::string("Delta"));
    Max(testnum, testerr, set, true, std::string("Gamma"));

    RemoveMin(testnum, testerr, set, true);
    RemoveMax(testnum, testerr, set, true);
    Min(testnum, testerr, set, true, std::string("Epsilon"));
    Max(testnum, testerr, set, true, std::string("Epsilon"));

    InsertC(testnum, testerr, set, true, std::string("Beta"));
    InsertC(testnum, testerr, set, false, std::string("Epsilon"));
    InsertC(testnum, testerr, set, true, std::string("Delta"));
    InsertC(testnum, testerr, set, true, std::string("Gamma"));
    InsertC(testnum, testerr, set, true, std::string("Omega"));

    PredecessorNRemove(testnum, testerr, set, true, std::string("Delta"), std::string("Beta"));
    SuccessorNRemove(testnum, testerr, set, true, std::string("Delta"), std::string("Epsilon"));

    RemovePredecessor(testnum, testerr, set, true, std::string("Omega"));
    RemoveSuccessor(testnum, testerr, set, true, std::string("Beta"));

    GetAt(testnum, testerr, set, false, 0, std::string("Beta"));
    GetAt(testnum, testerr, set, true, 0, std::string("Omega"));

    lasd::SetVec<std::string> set2;
    InsertC(testnum, testerr, set2, true, std::string("Beta"));
    InsertC(testnum, testerr, set2, true, std::string("Omega"));
    InsertC(testnum, testerr, set, true, std::string("Beta"));
    EqualSetVec(testnum, testerr, set, set2, true);
    InsertC(testnum, testerr, set2, true, std::string("Kappa"));
    EqualSetVec(testnum, testerr, set, set2, false);

    lasd::SetVec<std::string> setCopy(set);
    EqualSetVec(testnum, testerr, set, setCopy, true);

    lasd::SetVec<std::string> setMove(std::move(setCopy));
    EqualSetVec(testnum, testerr, set, setMove, true);

    lasd::SetVec<std::string> setCopyAssign;
    setCopyAssign = set;
    EqualSetVec(testnum, testerr, set, setCopyAssign, true);

    lasd::SetVec<std::string> setMoveAssign;
    setMoveAssign = std::move(setCopyAssign);
    EqualSetVec(testnum, testerr, set, setMoveAssign, true);

    set.Clear();
    Min(testnum, testerr, set, false, std::string(""));

    lasd::Vector<std::string> vec(5);
    vec[0] = std::string("Alpha");
    vec[1] = std::string("Gamma");
    vec[2] = std::string("Beta");
    vec[3] = std::string("Gamma");
    vec[4] = std::string("Delta");

    const lasd::SetVec<std::string> setFromVec(vec);
    Size(testnum, testerr, setFromVec, true, 4);
    Exists(testnum, testerr, setFromVec, true, std::string("Alpha"));
    Exists(testnum, testerr, setFromVec, true, std::string("Beta"));
    Exists(testnum, testerr, setFromVec, true, std::string("Gamma"));
    Exists(testnum, testerr, setFromVec, true, std::string("Delta"));

    lasd::SetVec<std::string> setResize;
    InsertC(testnum, testerr, setResize, true, std::string("One"));
    InsertC(testnum, testerr, setResize, true, std::string("Two"));
    InsertC(testnum, testerr, setResize, true, std::string("Three"));

    setResize.Resize(10);
    Size(testnum, testerr, setResize, true, 3);
    Exists(testnum, testerr, setResize, true, std::string("One"));
    Exists(testnum, testerr, setResize, true, std::string("Two"));
    Exists(testnum, testerr, setResize, true, std::string("Three"));

    setResize.Resize(5);
    Size(testnum, testerr, setResize, true, 3);
    Exists(testnum, testerr, setResize, true, std::string("One"));
    Exists(testnum, testerr, setResize, true, std::string("Two"));
    Exists(testnum, testerr, setResize, true, std::string("Three"));

    InsertC(testnum, testerr, setResize, true, std::string("Four"));
    InsertC(testnum, testerr, setResize, true, std::string("Five"));
    Size(testnum, testerr, setResize, true, 5);
}
    
void zMyTestSetVec(unsigned int& testnum, unsigned int& testerr) {
    std::cout << "\n~*~#~*~ Test SetVec Container ~*~#~*~ " << std::endl;

    std::cout << "\n[Test 1] Testing SetVec<int>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyTestSetVecInt(testnum, testerr);
    std::cout << "Integer set tests completed" << std::endl;

    std::cout << "\n[Test 1] Testing SetVec<double>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyTestSetVecDouble(testnum, testerr);
    std::cout << "Double set tests completed" << std::endl;

    std::cout << "\n[Test 2] Testing SetVec<string>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyTestSetVecString(testnum, testerr);
    std::cout << "String set tests completed" << std::endl;

    std::cout << "\nAll set tests completed!" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}


}
