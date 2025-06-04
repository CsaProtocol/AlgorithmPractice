#include "set.hpp"

#include "../../zlasdtest/set/set.hpp"
#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"

#include <iostream>
#include <string>

#include "../../zlasdtest/container/dictionary.hpp"

namespace zmytest {

void zMySetInt(unsigned int& testnum, unsigned int& testerr) {
    lasd::SetLst<int> set;
    InsertM(testnum, testerr, set, true, std::move(4));
    InsertM(testnum, testerr, set, false, std::move(4));
    InsertM(testnum, testerr, set, true, std::move(6));
    InsertM(testnum, testerr, set, true, std::move(5));

    lasd::SetVec set2(set);
    lasd::SetLst<int> set3;

    lasd::Vector<int> vector1(5);
    vector1[0] = 10;
    vector1[1] = 30;
    vector1[2] = 20;
    vector1[3] = 30;
    vector1[4] = 40;

    InsertAllC(testnum, testerr, set3, true, set2);
    InsertSomeM(testnum, testerr, set3, true, std::move(vector1));

    lasd::SetVec<int> tempSet;
    InsertM(testnum, testerr, tempSet, true, std::move(7));
    set3 = std::move(lasd::SetLst(tempSet));
    vector1[0] = 10;
    vector1[1] = 30;
    vector1[2] = 20;
    vector1[3] = 30;
    vector1[4] = 40;
    lasd::SetLst<int> set5(std::move(vector1));
    Remove(testnum, testerr, set5, true, 30);
    NonEqualSetLst(testnum, testerr, set3, set5, true);
    InsertAllC(testnum, testerr, set3, true, set5);
    vector1.Resize(3);

    set5.Clear();
    MinNRemove(testnum, testerr, set5, false, 10);
    MaxNRemove(testnum, testerr, set5, false, 30);
    RemoveMin(testnum, testerr, set5, false);
    RemoveMax(testnum, testerr, set5, false);
    Predecessor(testnum, testerr, set5, false, 10, 0);
    PredecessorNRemove(testnum, testerr, set5, false, 30, 0);
    RemovePredecessor(testnum, testerr, set5, false, 30);
    Successor(testnum, testerr, set5, false, 10, 0);
    SuccessorNRemove(testnum, testerr, set5, false, 30, 0);
    RemoveSuccessor(testnum, testerr, set5, false, 30);
    Remove(testnum, testerr, set5, false, 30);

    vector1[0] = 10;
    vector1[1] = 20;
    vector1[2] = 30;

    InsertC(testnum, testerr, set5, true, 10);
    InsertM(testnum, testerr, set5, true, std::move(5));
    InsertAllM(testnum, testerr, set5, false, std::move(vector1));

    lasd::SetLst set6(set5);
    Remove(testnum, testerr, set6, true, 20);
    InsertC(testnum, testerr, set6, true, 25);
    EqualSetLst(testnum, testerr, set5, set6, false);
    Predecessor(testnum, testerr, set5, true, 100, 30);
    PredecessorNRemove(testnum, testerr, set5, false, 0, 0);
    PredecessorNRemove(testnum, testerr, set5, true, 100, 30);
    PredecessorNRemove(testnum, testerr, set5, false, 0, 0);
    RemovePredecessor(testnum, testerr, set5, true, 100);
    Successor(testnum, testerr, set5, false, 100, 0);
    Remove(testnum, testerr, set5, false, 0);
    GetAt(testnum, testerr, set5, true, 1, 10);
    Remove(testnum, testerr, set5, false, 200);

    vector1.Resize(10);
    for(int i = 0; i < 10; ++i) {
        vector1[i] = i;
    }

    lasd::SetVec<int> set9(std::move(vector1));
    GetAt(testnum, testerr, set9, true, 0, 0);
    GetAt(testnum, testerr, set9, true, 1, 1);
    GetAt(testnum, testerr, set9, true, 2, 2);
    GetAt(testnum, testerr, set9, true, 3, 3);
    GetAt(testnum, testerr, set9, true, 4, 4);
    GetAt(testnum, testerr, set9, true, 5, 5);
    GetAt(testnum, testerr, set9, true, 6, 6);
    GetAt(testnum, testerr, set9, true, 7, 7);
    GetAt(testnum, testerr, set9, true, 8, 8);
    GetAt(testnum, testerr, set9, true, 9, 9);

    lasd::SetVec<int> set8 = set9;
    Remove(testnum, testerr, set8, true, 2);
    InsertC(testnum, testerr, set8, true, 10);
    EqualSetVec(testnum, testerr, set9, set8, false);
    NonEqualSetVec(testnum, testerr, set9, set8, true);

    Predecessor(testnum, testerr, set8, false, -100, 0);
    PredecessorNRemove(testnum, testerr, set8, false, -100, 0);
    PredecessorNRemove(testnum, testerr, set8, true, 100, 10);

    Successor(testnum, testerr, set8, false, 200, 0);
    lasd::SetVec<int> set10;
    Exists(testnum, testerr, set10, false, 1);
    Remove(testnum, testerr, set10, false, 2);
}

void zMySetDouble(unsigned int& testnum, unsigned int& testerr) {
    lasd::SetLst<double> set;
    InsertM(testnum, testerr, set, true, std::move(4.5));
    InsertM(testnum, testerr, set, false, std::move(4.5));
    InsertM(testnum, testerr, set, true, std::move(6.7));
    InsertM(testnum, testerr, set, true, std::move(5.3));

    lasd::SetVec set2(set);
    lasd::SetLst<double> set3;

    lasd::Vector<double> vector1(5);
    vector1[0] = 10.1;
    vector1[1] = 30.3;
    vector1[2] = 20.2;
    vector1[3] = 30.3;
    vector1[4] = 40.4;

    InsertAllC(testnum, testerr, set3, true, set2);
    InsertSomeM(testnum, testerr, set3, true, std::move(vector1));

    lasd::SetVec<double> tempSet;
    InsertM(testnum, testerr, tempSet, true, std::move(7.8));
    set3 = std::move(lasd::SetLst(tempSet));
    vector1[0] = 10.1;
    vector1[1] = 30.3;
    vector1[2] = 20.2;
    vector1[3] = 30.3;
    vector1[4] = 40.4;
    lasd::SetLst<double> set5(std::move(vector1));
    Remove(testnum, testerr, set5, true, 30.3);
    NonEqualSetLst(testnum, testerr, set3, set5, true);
    InsertAllC(testnum, testerr, set3, true, set5);
    vector1.Resize(3);

    set5.Clear();
    MinNRemove(testnum, testerr, set5, false, 10.1);
    MaxNRemove(testnum, testerr, set5, false, 30.3);
    RemoveMin(testnum, testerr, set5, false);
    RemoveMax(testnum, testerr, set5, false);
    Predecessor(testnum, testerr, set5, false, 10.1, 0.0);
    PredecessorNRemove(testnum, testerr, set5, false, 30.3, 0.0);
    RemovePredecessor(testnum, testerr, set5, false, 30.3);
    Successor(testnum, testerr, set5, false, 10.1, 0.0);
    SuccessorNRemove(testnum, testerr, set5, false, 30.3, 0.0);
    RemoveSuccessor(testnum, testerr, set5, false, 30.3);
    Remove(testnum, testerr, set5, false, 30.3);

    vector1[0] = 10.1;
    vector1[1] = 20.2;
    vector1[2] = 30.3;

    InsertC(testnum, testerr, set5, true, 10.1);
    InsertM(testnum, testerr, set5, true, std::move(5.3));
    InsertAllM(testnum, testerr, set5, false, std::move(vector1));

    lasd::SetLst set6(set5);
    Remove(testnum, testerr, set6, true, 20.2);
    InsertC(testnum, testerr, set6, true, 25.5);
    EqualSetLst(testnum, testerr, set5, set6, false);
    Predecessor(testnum, testerr, set5, true, 100.0, 30.3);
    PredecessorNRemove(testnum, testerr, set5, false, 0.0, 0.0);
    PredecessorNRemove(testnum, testerr, set5, true, 100.0, 30.3);
    PredecessorNRemove(testnum, testerr, set5, false, 0.0, 0.0);
    RemovePredecessor(testnum, testerr, set5, true, 100.0);
    Successor(testnum, testerr, set5, false, 100.0, 0.0);
    Remove(testnum, testerr, set5, false, 0.0);
    GetAt(testnum, testerr, set5, true, 1, 10.1);
    Remove(testnum, testerr, set5, false, 200.0);

    vector1.Resize(10);
    for(int i = 0; i < 10; ++i) {
        vector1[i] = i + 0.5;
    }

    lasd::SetVec<double> set9(std::move(vector1));
    GetAt(testnum, testerr, set9, true, 0, 0.5);
    GetAt(testnum, testerr, set9, true, 1, 1.5);
    GetAt(testnum, testerr, set9, true, 2, 2.5);
    GetAt(testnum, testerr, set9, true, 3, 3.5);
    GetAt(testnum, testerr, set9, true, 4, 4.5);
    GetAt(testnum, testerr, set9, true, 5, 5.5);
    GetAt(testnum, testerr, set9, true, 6, 6.5);
    GetAt(testnum, testerr, set9, true, 7, 7.5);
    GetAt(testnum, testerr, set9, true, 8, 8.5);
    GetAt(testnum, testerr, set9, true, 9, 9.5);

    lasd::SetVec<double> set8 = set9;
    Remove(testnum, testerr, set8, true, 2.5);
    InsertC(testnum, testerr, set8, true, 10.5);
    EqualSetVec(testnum, testerr, set9, set8, false);
    NonEqualSetVec(testnum, testerr, set9, set8, true);

    Predecessor(testnum, testerr, set8, false, -100.0, 0.0);
    PredecessorNRemove(testnum, testerr, set8, false, -100.0, 0.0);
    PredecessorNRemove(testnum, testerr, set8, true, 100.0, 10.5);

    Successor(testnum, testerr, set8, false, 200.0, 0.0);
    lasd::SetVec<double> set10;
    Exists(testnum, testerr, set10, false, 1.0);
    Remove(testnum, testerr, set10, false, 2.0);
}

void zMySetString(unsigned int& testnum, unsigned int& testerr) {
    lasd::SetLst<std::string> set;
    InsertM(testnum, testerr, set, true, std::move(std::string("abc")));
    InsertM(testnum, testerr, set, false, std::move(std::string("abc")));
    InsertM(testnum, testerr, set, true, std::move(std::string("def")));
    InsertM(testnum, testerr, set, true, std::move(std::string("ghi")));

    lasd::SetVec<std::string> set2(set);
    lasd::SetLst<std::string> set3;

    lasd::Vector<std::string> vector1(5);
    vector1[0] = std::string("hello");
    vector1[1] = std::string("world");
    vector1[2] = std::string("lasd");
    vector1[3] = std::string("test");
    vector1[4] = std::string("string");

    InsertAllC(testnum, testerr, set3, true, set2);
    InsertSomeM(testnum, testerr, set3, true, std::move(vector1));

    lasd::SetVec<std::string> tempSet;
    InsertM(testnum, testerr, tempSet, true, std::move(std::string("new")));
    set3 = std::move(lasd::SetLst<std::string>(tempSet));
    vector1[0] = std::string("modified");
    vector1[1] = std::string("example");
    vector1[2] = std::string("test");
    vector1[3] = std::string("case");
    vector1[4] = std::string("string");
    lasd::SetLst<std::string> set5(std::move(vector1));
    Remove(testnum, testerr, set5, true, std::string("test"));
    NonEqualSetLst(testnum, testerr, set3, set5, true);
    InsertAllC(testnum, testerr, set3, true, set5);
    vector1.Resize(3);

    set5.Clear();
    MinNRemove(testnum, testerr, set5, false, std::string("a"));
    MaxNRemove(testnum, testerr, set5, false, std::string("z"));
    RemoveMin(testnum, testerr, set5, false);
    RemoveMax(testnum, testerr, set5, false);
    Predecessor(testnum, testerr, set5, false, std::string("abc"), std::string(""));
    PredecessorNRemove(testnum, testerr, set5, false, std::string("def"), std::string(""));
    RemovePredecessor(testnum, testerr, set5, false, std::string("ghi"));
    Successor(testnum, testerr, set5, false, std::string("abc"), std::string(""));
    SuccessorNRemove(testnum, testerr, set5, false, std::string("def"), std::string(""));
    RemoveSuccessor(testnum, testerr, set5, false, std::string("ghi"));
    Remove(testnum, testerr, set5, false, std::string("test"));

    InsertC(testnum, testerr, set5, true, std::string("example"));
    InsertM(testnum, testerr, set5, true, std::move(std::string("final")));
    InsertAllM(testnum, testerr, set5, false, std::move(vector1));

    lasd::SetLst<std::string> set6(set5);
    Remove(testnum, testerr, set6, false, std::string("case"));
    InsertC(testnum, testerr, set6, true, std::string("newcase"));
    EqualSetLst(testnum, testerr, set5, set6, false);
    Predecessor(testnum, testerr, set5, true, std::string("zzz"), std::string("final"));
    PredecessorNRemove(testnum, testerr, set5, false, std::string(""), std::string(""));
    PredecessorNRemove(testnum, testerr, set5, true, std::string("zzz"), std::string("final"));
    PredecessorNRemove(testnum, testerr, set5, false, std::string(""), std::string(""));
    RemovePredecessor(testnum, testerr, set5, true, std::string("zzz"));
    Successor(testnum, testerr, set5, false, std::string("aaa"), std::string(""));
    Remove(testnum, testerr, set5, true, std::string(""));
    GetAt(testnum, testerr, set5, false, 1, std::string("final"));
    Remove(testnum, testerr, set5, false, std::string("notfound"));

    vector1.Resize(10);
    for (int i = 0; i < 10; ++i) {
        vector1[i] = std::string("string") + std::to_string(i);
    }

    lasd::SetVec<std::string> set9(std::move(vector1));
    GetAt(testnum, testerr, set9, true, 0, std::string("string0"));
    GetAt(testnum, testerr, set9, true, 1, std::string("string1"));
    GetAt(testnum, testerr, set9, true, 2, std::string("string2"));
    GetAt(testnum, testerr, set9, true, 3, std::string("string3"));
    GetAt(testnum, testerr, set9, true, 4, std::string("string4"));
    GetAt(testnum, testerr, set9, true, 5, std::string("string5"));
    GetAt(testnum, testerr, set9, true, 6, std::string("string6"));
    GetAt(testnum, testerr, set9, true, 7, std::string("string7"));
    GetAt(testnum, testerr, set9, true, 8, std::string("string8"));
    GetAt(testnum, testerr, set9, true, 9, std::string("string9"));

    lasd::SetVec<std::string> set8 = set9;
    Remove(testnum, testerr, set8, true, std::string("string2"));
    InsertC(testnum, testerr, set8, true, std::string("newstring"));
    EqualSetVec(testnum, testerr, set9, set8, false);
    NonEqualSetVec(testnum, testerr, set9, set8, true);

    Predecessor(testnum, testerr, set8, false, std::string("aaa"), std::string(""));
    PredecessorNRemove(testnum, testerr, set8, false, std::string("aaa"), std::string(""));
    PredecessorNRemove(testnum, testerr, set8, true, std::string("zzz"), std::string("string9"));

    Successor(testnum, testerr, set8, false, std::string("zzz"), std::string(""));
    lasd::SetVec<std::string> set10;
    Exists(testnum, testerr, set10, false, std::string("notfound"));
    Remove(testnum, testerr, set10, false, std::string("notfound"));
}

void zMyTestSetLstCoverage() {
    lasd::SetLst<int> set;
    try {
        set.MaxNRemove();
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        set.MinNRemove();
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        set.PredecessorNRemove(0);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        set.SuccessorNRemove(200);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        set.RemovePredecessor(0);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        set.RemoveSuccessor(200);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        set.Insert(5);
        set.PredecessorNRemove(0);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        set.SuccessorNRemove(200);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        set.RemovePredecessor(0);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        set.RemoveSuccessor(250);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        set.RemovePredecessor(0);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        set.SuccessorNRemove(200);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        set.RemoveSuccessor(200);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
}

void zMyTestSetVecCoverage() {
    try {
        lasd::SetVec<int> set;
        set.MinNRemove();
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        lasd::SetVec<int> set;
        set.RemoveMin();
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        lasd::SetVec<int> set;
        set.MaxNRemove();
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        lasd::SetVec<int> set;
        set.RemoveMax();
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        const lasd::SetVec<int> set;
        std::cout << set.Max();
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        const lasd::SetVec<int> set;
        std::cout << set.Predecessor(0);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        const lasd::SetVec<int> set;
        std::cout << set.Successor(0);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        lasd::SetVec<int> set;
        set.PredecessorNRemove(0);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        lasd::SetVec<int> set;
        set.Insert(1);
        set.RemovePredecessor(0);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        lasd::SetVec<int> set;
        set.Insert(1);
        set.Insert(2);
        set.RemovePredecessor(100);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        lasd::SetVec<int> set;
        set.SuccessorNRemove(0);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        lasd::SetVec<int> set;
        set.RemoveSuccessor(0);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        lasd::SetVec<int> set;
        set.RemovePredecessor(200);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        lasd::SetVec<int> set;
        set.Insert(1);
        set.Insert(2);
        set.RemoveSuccessor(200);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        lasd::SetVec<int> set;
        set.Insert(1);
        set.Insert(std::move(1));
        set.Insert(3);
        set.Insert(std::move(2));
        set.SuccessorNRemove(200);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        lasd::SetVec<int> set;
        set.Insert(1);
        set.Insert(3);
        set.Insert(std::move(2));
        set.PredecessorNRemove(-200);
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
}

void zMyTestSet(unsigned int& testnum, unsigned int& testerr) {
    std::cout << "\n~*~#~*~ Test Set Container ~*~#~*~ " << std::endl;

    std::cout << "\n[Test 1] Testing Set<int>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMySetInt(testnum, testerr);
    std::cout << "Integer set tests completed" << std::endl;

    std::cout << "\n[Test 2] Testing Set<double>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMySetDouble(testnum, testerr);
    std::cout << "Double set tests completed" << std::endl;

    std::cout << "\n[Test 3] Testing Set<string>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMySetString(testnum, testerr);
    std::cout << "String set tests completed" << std::endl;

    std::cout << "\n[Test 4] Coverage tests..." << std::endl;
    zMyTestSetLstCoverage(); zMyTestSetVecCoverage();
    std::cout << "----------------------------------------" << std::endl;

    std::cout << "\nAll set tests completed!" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}
}
