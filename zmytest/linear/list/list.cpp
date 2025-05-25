#include "list.hpp"
#include "../../../list/list.hpp"
#include "../../../zlasdtest/list/list.hpp"

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>

#include "../../../zlasdtest/container/container.hpp"
#include "../../../zlasdtest/container/linear.hpp"
#include "../../../zlasdtest/container/mappable.hpp"
#include "../../../zlasdtest/container/testable.hpp"
#include "../../../zlasdtest/container/traversable.hpp"


namespace zmytest {

void zMyTestListInt(unsigned int& testnum, unsigned int& testerr) {
    lasd::List<int> list1;
    Empty(testnum, testerr, list1, true);
    Size(testnum, testerr, list1, true, 0);

    InsertAtFront(testnum, testerr, list1, true, 1);
    InsertAtFront(testnum, testerr, list1, true, 2);
    InsertAtFront(testnum, testerr, list1, true, 3);
    Size(testnum, testerr, list1, true, 3);
    GetFront(testnum, testerr, list1, true, 3);
    GetBack(testnum, testerr, list1, true, 1);

    InsertAtBack(testnum, testerr, list1, true, 4);
    InsertAtBack(testnum, testerr, list1, true, 5);
    Size(testnum, testerr, list1, true, 5);
    GetBack(testnum, testerr, list1, true, 5);

    std::cout << "\nInitial list content:" << std::endl;
    Traverse(testnum, testerr, list1, true, &TraversePrint<int>);

    FrontNRemove(testnum, testerr, list1, true, 3);
    BackNRemove(testnum, testerr, list1, true, 5);
    Size(testnum, testerr, list1, true, 3);

    lasd::List<int> list2(list1);
    EqualList(testnum, testerr, list1, list2, true);

    lasd::List<int> list3(std::move(list1));
    Empty(testnum, testerr, list1, true);
    Size(testnum, testerr, list3, true, 3);

    std::cout << "\nBefore MapIncrement:" << std::endl;
    Traverse(testnum, testerr, list3, true, &TraversePrint<int>);

    Map(testnum, testerr, list3, true, &MapIncrement<int>);

    std::cout << "\nAfter MapIncrement:" << std::endl;
    Traverse(testnum, testerr, list3, true, &TraversePrint<int>);

    Fold(testnum, testerr, list3, true, &FoldAdd<int>, 0, 10);

    SetAt(testnum, testerr, list3, true, 0, 10);
    Exists(testnum, testerr, list3, true, 10);
    Exists(testnum, testerr, list3, false, 999);

    list3.Clear();
    Empty(testnum, testerr, list3, true);
    Size(testnum, testerr, list3, true, 0);

    lasd::List<int> list4;
    InsertAtBack(testnum, testerr, list4, true, 1);
    InsertAtBack(testnum, testerr, list4, true, 2);
    InsertAtBack(testnum, testerr, list4, true, 3);

    Traverse(testnum, testerr, list4, true, &TraversePrint<int>);

    Traverse(testnum, testerr, list4, true, &TraversePrint<int>);

    list4.Clear();
    Empty(testnum, testerr, list4, true);

    //Test coverage
    InsertAtFront(testnum, testerr, list4, true, 1);
    RemoveFromFront(testnum, testerr, list4, true);
    Size(testnum, testerr, list4, true, 0);
    InsertAtBack(testnum, testerr, list4, true, 1);
    RemoveFromBack(testnum, testerr, list4, true);
    Size(testnum, testerr, list4, true, 0);

    InsertAtFront(testnum, testerr, list4, true, std::move(1));
    BackNRemove(testnum, testerr, list4, true, 1);
    RemoveFromBack(testnum, testerr, list4, false);
    GetAt(testnum, testerr, list4, false, 0, 1);
    GetFront(testnum, testerr, list4, false, 1);
    GetBack(testnum, testerr, list4, false, 1);
    MapPreOrder(testnum, testerr, list4, true, &MapIncrement<int>);
    MapPostOrder(testnum, testerr, list4, true, &MapIncrement<int>);
    TraversePostOrder(testnum, testerr, list4, true, &TraversePrint<int>);

    InsertAtBack(testnum, testerr, list4, true, 1);
    InsertAtBack(testnum, testerr, list4, true, 2);
    InsertAtBack(testnum, testerr, list4, true, 3);
    TraversePreOrder(testnum, testerr, list4, true, &TraversePrint<int>);
    MapPostOrder(testnum, testerr, list4, true, &MapIncrement<int>);
    TraversePostOrder(testnum, testerr, list4, true, &TraversePrint<int>);
    InsertAtFront(testnum, testerr, list4, true, std::move(1));
    RemoveFromFront(testnum, testerr, list4, true);

    lasd::List<int> list5;
    EqualList(testnum, testerr, list5, list4, false);
    NonEqualList(testnum, testerr, list5, list4, true);
    FrontNRemove(testnum, testerr, list5, false, 1);
    RemoveFromBack(testnum, testerr, list5, false);
    BackNRemove(testnum, testerr, list5, false, 1);
    GetAt(testnum, testerr, list5, false, 0, 1);
    GetAt(testnum, testerr, list4, true, 1, 3);
    GetFront(testnum, testerr, list4, true, 2);
    GetFront(testnum, testerr, list5, false, 1);

    lasd::List<int> list6(std::move(list4));
    GetFront(testnum, testerr, list6, true, 2);
    GetAt(testnum, testerr, list6, true, 1, 3);

    list4 = std::move(list6);
    GetFront(testnum, testerr, list4, true, 2);
    GetAt(testnum, testerr, list4, true, 1, 3);
    GetAt(testnum, testerr, list4, true, 2, 4);

    list6.Clear();
    RemoveFromFront(testnum, testerr, list6, false);
    RemoveFromBack(testnum, testerr, list6, false);
    FrontNRemove(testnum, testerr, list6, false, 1);
    BackNRemove(testnum, testerr, list6, false, 1);
    TraversePreOrder(testnum, testerr, list6, true, &TraversePrint<int>);

    InsertAtFront(testnum, testerr, list6, true, 1);
    InsertAtBack(testnum, testerr, list6, true, 2);
    InsertAtFront(testnum, testerr, list6, true, 3);
    InsertAtBack(testnum, testerr, list6, true, 4);
    GetAt(testnum, testerr, list6, true, 3, 4);
}

void zMyTestListDouble(unsigned int& testnum, unsigned int& testerr) {
    lasd::List<double> list1;
    Empty(testnum, testerr, list1, true);
    Size(testnum, testerr, list1, true, 0);

    InsertAtFront(testnum, testerr, list1, true, 1.5);
    InsertAtFront(testnum, testerr, list1, true, 2.7);
    InsertAtFront(testnum, testerr, list1, true, 3.14);
    Size(testnum, testerr, list1, true, 3);
    GetFront(testnum, testerr, list1, true, 3.14);
    GetBack(testnum, testerr, list1, true, 1.5);

    InsertAtBack(testnum, testerr, list1, true, 4.8);
    InsertAtBack(testnum, testerr, list1, true, 5.2);
    Size(testnum, testerr, list1, true, 5);
    GetBack(testnum, testerr, list1, true, 5.2);

    std::cout << "\nInitial double list content:" << std::endl;
    Traverse(testnum, testerr, list1, true, &TraversePrint<double>);

    FrontNRemove(testnum, testerr, list1, true, 3.14);
    BackNRemove(testnum, testerr, list1, true, 5.2);
    Size(testnum, testerr, list1, true, 3);

    lasd::List<double> list2(list1);
    EqualList(testnum, testerr, list1, list2, true);

    lasd::List<double> list3(std::move(list1));
    Empty(testnum, testerr, list1, true);
    Size(testnum, testerr, list3, true, 3);

    std::cout << "\nBefore multiply by 2:" << std::endl;
    Traverse(testnum, testerr, list3, true, &TraversePrint<double>);

    Map(testnum, testerr, list3, true, [](double& x) { x *= 2; });

    std::cout << "\nAfter multiply by 2:" << std::endl;
    Traverse(testnum, testerr, list3, true, &TraversePrint<double>);

    Fold(testnum, testerr, list3, true, &FoldAdd<double>, 0.0, 18.0);

    SetAt(testnum, testerr, list3, true, 0, 10.5);
    Exists(testnum, testerr, list3, true, 10.5);
    Exists(testnum, testerr, list3, false, 999.9);

    list3.Clear();
    Empty(testnum, testerr, list3, true);
    Size(testnum, testerr, list3, true, 0);

    lasd::List<double> list4;
    InsertAtBack(testnum, testerr, list4, true, 3.14159);
    InsertAtBack(testnum, testerr, list4, true, 2.71828);
    InsertAtBack(testnum, testerr, list4, true, 1.41421);

    std::cout << "\nSpecial mathematical constants list:" << std::endl;
    Traverse(testnum, testerr, list4, true, &TraversePrint<double>);

    list4.InsertAtBack(std::numeric_limits<double>::max());
    list4.InsertAtBack(std::numeric_limits<double>::min());
    list4.InsertAtBack(-std::numeric_limits<double>::max());
    list4.InsertAtBack(std::numeric_limits<double>::infinity());
    list4.InsertAtBack(-std::numeric_limits<double>::infinity());
    list4.InsertAtBack(std::numeric_limits<double>::quiet_NaN());

    std::cout << "\nEdge case values list:" << std::endl;
    Traverse(testnum, testerr, list4, true, &TraversePrint<double>);

    Exists(testnum, testerr, list4, true, std::numeric_limits<double>::max());
    Exists(testnum, testerr, list4, true, std::numeric_limits<double>::min());
    Exists(testnum, testerr, list4, true, -std::numeric_limits<double>::max());
    Exists(testnum, testerr, list4, true, std::numeric_limits<double>::infinity());
    Exists(testnum, testerr, list4, true, -std::numeric_limits<double>::infinity());
    Exists(testnum, testerr, list4, false, 0.0);

    list4.Clear();
    Empty(testnum, testerr, list4, true);
    InsertAtFront(testnum, testerr, list4, true, 3.14);
    FrontNRemove(testnum, testerr, list4, true, 3.14);
}

void zMyTestListString(unsigned int& testnum, unsigned int& testerr) {
    lasd::List<std::string> list1;
    Empty(testnum, testerr, list1, true);
    Size(testnum, testerr, list1, true, 0);

    InsertAtFront(testnum, testerr, list1, true, std::string("Hello"));
    InsertAtFront(testnum, testerr, list1, true, std::string("World"));
    InsertAtFront(testnum, testerr, list1, true, std::string("Test"));
    Size(testnum, testerr, list1, true, 3);
    GetFront(testnum, testerr, list1, true, std::string("Test"));
    GetBack(testnum, testerr, list1, true, std::string("Hello"));

    InsertAtBack(testnum, testerr, list1, true, std::string("LASD"));
    InsertAtBack(testnum, testerr, list1, true, std::string("2025"));
    Size(testnum, testerr, list1, true, 5);
    GetBack(testnum, testerr, list1, true, std::string("2025"));

    std::cout << "\nInitial string list content:" << std::endl;
    Traverse(testnum, testerr, list1, true, &TraversePrint<std::string>);

    FrontNRemove(testnum, testerr, list1, true, std::string("Test"));
    BackNRemove(testnum, testerr, list1, true, std::string("2025"));
    Size(testnum, testerr, list1, true, 3);

    lasd::List<std::string> list2(list1);
    EqualList(testnum, testerr, list1, list2, true);

    lasd::List<std::string> list3(std::move(list1));
    Empty(testnum, testerr, list1, true);
    Size(testnum, testerr, list3, true, 3);

    std::cout << "\nBefore uppercase transformation:" << std::endl;
    Traverse(testnum, testerr, list3, true, &TraversePrint<std::string>);

    Map(testnum, testerr, list3, true, [](std::string& s) {
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    });

    std::cout << "\nAfter uppercase transformation:" << std::endl;
    Traverse(testnum, testerr, list3, true, &TraversePrint<std::string>);

    std::string accumulator = "";

    Fold(testnum, testerr, list3, true, &FoldStringConcatenate, accumulator, std::string("WORLDHELLOLASD"));

    SetAt(testnum, testerr, list3, true, 0, std::string("Modified"));
    Exists(testnum, testerr, list3, true, std::string("Modified"));
    Exists(testnum, testerr, list3, false, std::string("NotExists"));

    lasd::List<std::string> list4;
    InsertAtBack(testnum, testerr, list4, true, std::string(""));
    InsertAtBack(testnum, testerr, list4, true, std::string(" "));
    InsertAtBack(testnum, testerr, list4, true, std::string("!@#$%^&*"));
    InsertAtBack(testnum, testerr, list4, true, std::string("Line\nBreak"));
    InsertAtBack(testnum, testerr, list4, true, std::string("Tab\tCharacter"));

    std::cout << "\nSpecial characters list:" << std::endl;
    Traverse(testnum, testerr, list4, true, &TraversePrint<std::string>);

    std::string longString(1000, 'a');
    InsertAtBack(testnum, testerr, list4, true, longString);
    Exists(testnum, testerr, list4, true, longString);

    list3.Clear();
    Empty(testnum, testerr, list3, true);
    Size(testnum, testerr, list3, true, 0);

    list4.Clear();
    Empty(testnum, testerr, list4, true);
    InsertAtBack(testnum, testerr, list4, true, std::string("a"));
    InsertAtBack(testnum, testerr, list4, true, std::string("b"));
    InsertAtBack(testnum, testerr, list4, true, std::string("c"));
    GetAt(testnum, testerr, list4, true, 2, std::string("c"));
}

void zMyTestListCoverage() {
    lasd::List<int> emptyList;
    try {
        emptyList.InsertAtFront(std::move(19));
        emptyList.RemoveFromFront();
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        emptyList.RemoveFromFront();
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        emptyList.FrontNRemove();
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        emptyList.BackNRemove();
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        emptyList.RemoveFromBack();
    } catch(const std::length_error& e) {
        std::cout << "Out of range error: " << e.what() << std::endl;
    }
    try {
        emptyList[0];
    } catch(const std::out_of_range& e) {
        std::cout << "Out of range error: " << e.what() << std::endl;
    }
    try {
        emptyList.InsertAtFront(3);
        emptyList.InsertAtBack(4);
        emptyList.InsertAtFront(5);
        emptyList.InsertAtBack(6);
        emptyList.InsertAtFront(7);
        emptyList.InsertAtBack(8);
        emptyList[0] = 3;
        emptyList[0] = 2;
        emptyList[3] = 1;
    } catch(const std::out_of_range& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    } catch (const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
}

void zMyTestList(unsigned int& testnum, unsigned int& testerr) {
    std::cout << "\n~*~#~*~ Test List Container ~*~#~*~ " << std::endl;

    std::cout << "\n[Test 1] Testing List<int>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyTestListInt(testnum, testerr);
    std::cout << "Integer list tests completed" << std::endl;

    std::cout << "\n[Test 2] Testing List<double>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyTestListDouble(testnum, testerr);
    std::cout << "Double list tests completed" << std::endl;

    std::cout << "\n[Test 3] Testing List<string>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyTestListString(testnum, testerr);
    std::cout << "String list tests completed" << std::endl;

    std::cout << "\n[Test 4] Testing List<int> coverage... Expect exceptions" << std::endl;
    zMyTestListCoverage();
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "\nAll list tests completed!" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

}