#include "sortablevector.hpp"
#include "../../../vector/vector.hpp"
#include "../../../zlasdtest/vector/vector.hpp"

#include <iostream>
#include <string>

#include "../../../zlasdtest/container/container.hpp"
#include "../../../zlasdtest/container/linear.hpp"
#include "../../../zlasdtest/container/traversable.hpp"

namespace zmytest {

void zMySortableVectorInt(unsigned int& testnum, unsigned int& testerr) {
    lasd::SortableVector<int> vec1(0);
    Empty(testnum, testerr, vec1, true);
    Size(testnum, testerr, vec1, true, 0);

    vec1.Resize(6);
    SetAt(testnum, testerr, vec1, true, 0, 42);
    SetAt(testnum, testerr, vec1, true, 1, -7);
    SetAt(testnum, testerr, vec1, true, 2, 0);
    SetAt(testnum, testerr, vec1, true, 3, 15);
    SetAt(testnum, testerr, vec1, true, 4, -3);
    SetAt(testnum, testerr, vec1, true, 5, 8);

    std::cout << "\nBefore sorting:" << std::endl;
    Traverse(testnum, testerr, vec1, true, &TraversePrint<int>);

    vec1.Sort();

    std::cout << "\nAfter sorting:" << std::endl;
    Traverse(testnum, testerr, vec1, true, &TraversePrint<int>);

    GetAt(testnum, testerr, vec1, true, 0, -7);
    GetAt(testnum, testerr, vec1, true, 1, -3);
    GetAt(testnum, testerr, vec1, true, 2, 0);
    GetAt(testnum, testerr, vec1, true, 3, 8);
    GetAt(testnum, testerr, vec1, true, 4, 15);
    GetAt(testnum, testerr, vec1, true, 5, 42);

    vec1.Resize(5);
    SetAt(testnum, testerr, vec1, true, 0, 10);
    SetAt(testnum, testerr, vec1, true, 1, 5);
    SetAt(testnum, testerr, vec1, true, 2, 5);
    SetAt(testnum, testerr, vec1, true, 3, 10);
    SetAt(testnum, testerr, vec1, true, 4, 1);

    std::cout << "\nBefore sorting (with duplicates):" << std::endl;
    Traverse(testnum, testerr, vec1, true, &TraversePrint<int>);

    vec1.Sort();

    std::cout << "\nAfter sorting (with duplicates):" << std::endl;
    Traverse(testnum, testerr, vec1, true, &TraversePrint<int>);

    lasd::SortableVector<int> vec2(vec1);
    EqualVector(testnum, testerr, vec1, vec2, true);

    lasd::SortableVector<int> vec3(std::move(vec1));
    Empty(testnum, testerr, vec1, true);
    EqualVector(testnum, testerr, vec2, vec3, true);

    vec2 = vec3;
    vec1 = std::move(vec3);
    Empty(testnum, testerr, vec3, true);
    EqualVector(testnum, testerr, vec1, vec2, true);

    vec1.Clear();
    Empty(testnum, testerr, vec1, true);
    Size(testnum, testerr, vec1, true, 0);
}

void zMySortableVectorDouble(unsigned int& testnum, unsigned int& testerr) {
    lasd::SortableVector<double> vec1(0);
    Empty(testnum, testerr, vec1, true);
    Size(testnum, testerr, vec1, true, 0);

    vec1.Resize(6);
    SetAt(testnum, testerr, vec1, true, 0, 3.14);
    SetAt(testnum, testerr, vec1, true, 1, -2.5);
    SetAt(testnum, testerr, vec1, true, 2, 0.0);
    SetAt(testnum, testerr, vec1, true, 3, 1.618);
    SetAt(testnum, testerr, vec1, true, 4, -1.1);
    SetAt(testnum, testerr, vec1, true, 5, 2.718);

    std::cout << "\nBefore sorting:" << std::endl;
    Traverse(testnum, testerr, vec1, true, &TraversePrint<double>);

    vec1.Sort();

    std::cout << "\nAfter sorting:" << std::endl;
    Traverse(testnum, testerr, vec1, true, &TraversePrint<double>);

    GetAt(testnum, testerr, vec1, true, 0, -2.5);
    GetAt(testnum, testerr, vec1, true, 1, -1.1);
    GetAt(testnum, testerr, vec1, true, 2, 0.0);
    GetAt(testnum, testerr, vec1, true, 3, 1.618);
    GetAt(testnum, testerr, vec1, true, 4, 2.718);
    GetAt(testnum, testerr, vec1, true, 5, 3.14);

    vec1.Resize(5);
    SetAt(testnum, testerr, vec1, true, 0, 1.5);
    SetAt(testnum, testerr, vec1, true, 1, 0.0);
    SetAt(testnum, testerr, vec1, true, 2, 1.5);
    SetAt(testnum, testerr, vec1, true, 3, -0.0);
    SetAt(testnum, testerr, vec1, true, 4, 0.5);

    std::cout << "\nBefore sorting (with duplicates and zeros):" << std::endl;
    Traverse(testnum, testerr, vec1, true, &TraversePrint<double>);

    vec1.Sort();

    std::cout << "\nAfter sorting (with duplicates and zeros):" << std::endl;
    Traverse(testnum, testerr, vec1, true, &TraversePrint<double>);

    lasd::SortableVector<double> vec2(vec1);
    EqualVector(testnum, testerr, vec1, vec2, true);

    lasd::SortableVector<double> vec3(std::move(vec1));
    Empty(testnum, testerr, vec1, true);
    EqualVector(testnum, testerr, vec2, vec3, true);

    vec2 = vec3;
    vec1 = std::move(vec3);
    Empty(testnum, testerr, vec3, true);
    EqualVector(testnum, testerr, vec1, vec2, true);

    vec1.Clear();
    Empty(testnum, testerr, vec1, true);
    Size(testnum, testerr, vec1, true, 0);
}

void zMySortableVectorString(unsigned int& testnum, unsigned int& testerr) {
    lasd::SortableVector<std::string> vec1(0);
    Empty(testnum, testerr, vec1, true);
    Size(testnum, testerr, vec1, true, 0);

    vec1.Resize(5);
    SetAt(testnum, testerr, vec1, true, 0, std::string("Zebra"));
    SetAt(testnum, testerr, vec1, true, 1, std::string("Alpha"));
    SetAt(testnum, testerr, vec1, true, 2, std::string("Beta"));
    SetAt(testnum, testerr, vec1, true, 3, std::string("Delta"));
    SetAt(testnum, testerr, vec1, true, 4, std::string("Charlie"));

    std::cout << "\nBefore sorting:" << std::endl;
    Traverse(testnum, testerr, vec1, true, &TraversePrint<std::string>);

    vec1.Sort();

    std::cout << "\nAfter sorting:" << std::endl;
    Traverse(testnum, testerr, vec1, true, &TraversePrint<std::string>);

    GetAt(testnum, testerr, vec1, true, 0, std::string("Alpha"));
    GetAt(testnum, testerr, vec1, true, 1, std::string("Beta"));
    GetAt(testnum, testerr, vec1, true, 2, std::string("Charlie"));
    GetAt(testnum, testerr, vec1, true, 3, std::string("Delta"));
    GetAt(testnum, testerr, vec1, true, 4, std::string("Zebra"));

    vec1.Resize(4);
    SetAt(testnum, testerr, vec1, true, 0, std::string(""));
    SetAt(testnum, testerr, vec1, true, 1, std::string("123"));
    SetAt(testnum, testerr, vec1, true, 2, std::string("!@#"));
    SetAt(testnum, testerr, vec1, true, 3, std::string("ABC"));

    std::cout << "\nBefore sorting (with special characters):" << std::endl;
    Traverse(testnum, testerr, vec1, true, &TraversePrint<std::string>);

    vec1.Sort();

    std::cout << "\nAfter sorting (with special characters):" << std::endl;
    Traverse(testnum, testerr, vec1, true, &TraversePrint<std::string>);

    lasd::SortableVector<std::string> vec2(vec1);
    EqualVector(testnum, testerr, vec1, vec2, true);

    lasd::SortableVector<std::string> vec3(std::move(vec1));
    Empty(testnum, testerr, vec1, true);
    EqualVector(testnum, testerr, vec2, vec3, true);

    vec2 = vec3;
    vec1 = std::move(vec3);
    Empty(testnum, testerr, vec3, true);
    EqualVector(testnum, testerr, vec1, vec2, true);

    vec1.Clear();
    Empty(testnum, testerr, vec1, true);
    Size(testnum, testerr, vec1, true, 0);
}

void zMyTestSortableVector(unsigned int& testnum, unsigned int& testerr) {
    std::cout << "\n~*~#~*~ Test Sortable Vector Container ~*~#~*~ " << std::endl;

    std::cout << "\n[Test 1] Testing SortableVector<int>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMySortableVectorInt(testnum, testerr);
    std::cout << "Sortable integer vector tests completed" << std::endl;

    std::cout << "\n[Test 2] Testing SortableVector<double>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMySortableVectorDouble(testnum, testerr);
    std::cout << "Sortable double vector tests completed" << std::endl;

    std::cout << "\n[Test 3] Testing SortableVector<string>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMySortableVectorString(testnum, testerr);
    std::cout << "Sortable string vector tests completed" << std::endl;

    std::cout << "\nAll sortable vector tests completed!" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

}