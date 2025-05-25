#include "vector.hpp"
#include "../../../vector/vector.hpp"
#include "../../../zlasdtest/vector/vector.hpp"

#include <iostream>
#include <string>

#include "../../../zlasdtest/container/container.hpp"
#include "../../../zlasdtest/container/linear.hpp"
#include "../../../zlasdtest/container/mappable.hpp"
#include "../../../zlasdtest/container/testable.hpp"
#include "../../../zlasdtest/container/traversable.hpp"

namespace zmytest {

void zMyVectorInt(unsigned int& testnum, unsigned int& testerr) {
    lasd::Vector<int> vec1(0);
    Empty(testnum, testerr, vec1, true);
    Size(testnum, testerr, vec1, true, 0);

    vec1.Resize(4);
    SetAt(testnum, testerr, vec1, true, 0, 1);
    SetAt(testnum, testerr, vec1, true, 1, 2);
    SetAt(testnum, testerr, vec1, true, 2, 3);
    SetAt(testnum, testerr, vec1, true, 3, 4);

    GetAt(testnum, testerr, vec1, true, 0, 1);
    GetAt(testnum, testerr, vec1, true, 1, 2);
    GetAt(testnum, testerr, vec1, true, 2, 3);
    GetAt(testnum, testerr, vec1, true, 3, 4);

    GetFront(testnum, testerr, vec1, true, 1);
    GetBack(testnum, testerr, vec1, true, 4);
    SetFront(testnum, testerr, vec1, true, 10);
    SetBack(testnum, testerr, vec1, true, 20);
    GetFront(testnum, testerr, vec1, true, 10);
    GetBack(testnum, testerr, vec1, true, 20);

    Traverse(testnum, testerr, vec1, true, &TraversePrint<int>);
    TraversePostOrder(testnum, testerr, vec1, true, &TraversePrint<int>);

    Fold(testnum, testerr, vec1, true, &FoldAdd<int>, 0, 35);
    FoldPostOrder(testnum, testerr, vec1, true, &FoldAdd<int>, 0, 35);

    Fold(testnum, testerr, vec1, true, &FoldMultiply<int>, 1, 1200);
    FoldPostOrder(testnum, testerr, vec1, true, &FoldMultiply<int>, 1, 1200);

    TraversePreOrder(testnum, testerr, vec1, true, &TraversePrint<int>);

    lasd::Vector<int> vec2(vec1);
    lasd::Vector<int> vec3(std::move(vec1));

    EqualVector(testnum, testerr, vec2, vec3, true);
    NonEqualVector(testnum, testerr, vec2, vec3, false);

    vec2 = vec1;
    Empty(testnum, testerr, vec1, true);
    Empty(testnum, testerr, vec2, true);

    vec2 = vec3;
    vec1 = std::move(vec3);
    Empty(testnum, testerr, vec3, true);
    EqualVector(testnum, testerr, vec1, vec2, true);
    NonEqualVector(testnum, testerr, vec1, vec2, false);

    vec1.Clear();
    Empty(testnum, testerr, vec1, true);
    Size(testnum, testerr, vec1, true, 0);

    EqualVector(testnum, testerr, vec1, vec2, false);
    NonEqualVector(testnum, testerr, vec1, vec2, true);
    EqualVector(testnum, testerr, vec1, vec1, true);
    lasd::Vector<int> vec4(1);
    EqualVector(testnum, testerr, vec1, vec4, false);
    NonEqualVector(testnum, testerr, vec1, vec4, true);

    vec1.Resize(2);
    SetAt(testnum, testerr, vec1, true, 0, 1);
    GetFront(testnum, testerr, vec1, true, 1);
    SetAt(testnum, testerr, vec1, true, 1, 2);
    GetBack(testnum, testerr, vec1, true, 2);

    vec1.Clear();
    Empty(testnum, testerr, vec1, true);
    GetFront(testnum, testerr, vec1, false, 1);
    GetBack(testnum, testerr, vec1, false, 2);
}

void zMyVectorDouble(unsigned int& testnum, unsigned int& testerr) {
    lasd::Vector<double> vec1(0);
    Empty(testnum, testerr, vec1, true);
    Size(testnum, testerr, vec1, true, 0);

    vec1.Resize(1);
    SetAt(testnum, testerr, vec1, true, 0, 3.14);
    GetAt(testnum, testerr, vec1, true, 0, 3.14);

    vec1.Resize(3);
    SetAt(testnum, testerr, vec1, true, 0, 0.00001);
    SetAt(testnum, testerr, vec1, true, 1, 0.00002);
    SetAt(testnum, testerr, vec1, true, 2, 0.00003);
    GetAt(testnum, testerr, vec1, true, 0, 0.00001);
    GetAt(testnum, testerr, vec1, true, 1, 0.00002);
    GetAt(testnum, testerr, vec1, true, 2, 0.00003);

    vec1.Resize(3);
    SetAt(testnum, testerr, vec1, true, 0, 1e6);
    SetAt(testnum, testerr, vec1, true, 1, 2e6);
    SetAt(testnum, testerr, vec1, true, 2, 3e6);
    GetAt(testnum, testerr, vec1, true, 0, 1e6);
    GetAt(testnum, testerr, vec1, true, 1, 2e6);
    GetAt(testnum, testerr, vec1, true, 2, 3e6);

    vec1.Resize(4);
    SetAt(testnum, testerr, vec1, true, 0, -1.5);
    SetAt(testnum, testerr, vec1, true, 1, -2.7);
    SetAt(testnum, testerr, vec1, true, 2, -3.2);
    SetAt(testnum, testerr, vec1, true, 3, -4.9);
    GetAt(testnum, testerr, vec1, true, 0, -1.5);
    GetAt(testnum, testerr, vec1, true, 1, -2.7);
    GetAt(testnum, testerr, vec1, true, 2, -3.2);
    GetAt(testnum, testerr, vec1, true, 3, -4.9);
    GetFront(testnum, testerr, vec1, true, -1.5);
    GetBack(testnum, testerr, vec1, true, -4.9);

    vec1.Resize(4);
    SetAt(testnum, testerr, vec1, true, 0, -1.5);
    SetAt(testnum, testerr, vec1, true, 1, 2.7);
    SetAt(testnum, testerr, vec1, true, 2, -3.2);
    SetAt(testnum, testerr, vec1, true, 3, 4.9);

    Traverse(testnum, testerr, vec1, true, &TraversePrint<double>);

    lasd::Vector<double> vec5(4);
    SetAt(testnum, testerr, vec5, true, 0, 1.5);
    SetAt(testnum, testerr, vec5, true, 1, 2.7);
    SetAt(testnum, testerr, vec5, true, 2, 3.2);
    SetAt(testnum, testerr, vec5, true, 3, 4.9);

    lasd::TraversableContainer<double>::FoldFun<double> foldfun = [](const double& element, const double& accumulator) -> double {
        return accumulator + element;
    };
    Fold(testnum, testerr, vec5, true, foldfun, 0.0, 12.3);
    FoldPreOrder(testnum, testerr, vec1, true, foldfun, 0.0, 2.9);
    FoldPostOrder(testnum, testerr, vec5, true, foldfun, 0.0, 12.3);

    vec1.Resize(0);
    Empty(testnum, testerr, vec1, true);
    Size(testnum, testerr, vec1, true, 0);

    vec1.Resize(1);
    Size(testnum, testerr, vec1, true, 1);
    vec1.Resize(100);
    Size(testnum, testerr, vec1, true, 100);
    vec1.Resize(50);
    Size(testnum, testerr, vec1, true, 50);
    vec1.Resize(2);
    Size(testnum, testerr, vec1, true, 2);

    lasd::Vector<double> vec2(0);
    lasd::Vector<double> vec3(vec2);
    EqualVector(testnum, testerr, vec2, vec3, true);

    vec1.Resize(3);
    SetAt(testnum, testerr, vec1, true, 0, 1.1);
    SetAt(testnum, testerr, vec1, true, 1, 2.2);
    SetAt(testnum, testerr, vec1, true, 2, 3.3);

    lasd::Vector<double> vec4(std::move(vec1));
    Empty(testnum, testerr, vec1, true);
    GetAt(testnum, testerr, vec4, true, 0, 1.1);

    vec1.Clear();
    Empty(testnum, testerr, vec1, true);
    Size(testnum, testerr, vec1, true, 0);

    vec2.Resize(3);
    EqualVector(testnum, testerr, vec1, vec2, false);
    NonEqualVector(testnum, testerr, vec1, vec2, true);
    EqualVector(testnum, testerr, vec1, vec1, true);
    const lasd::Vector<double> vec6(1);
    EqualVector(testnum, testerr, vec1, vec6, false);
    NonEqualVector(testnum, testerr, vec1, vec6, true);

    vec1.Resize(2);
    SetAt(testnum, testerr, vec1, true, 0, 1.0);
    GetFront(testnum, testerr, vec1, true, 1.0);
    SetAt(testnum, testerr, vec1, true, 1, 2.0);
    GetBack(testnum, testerr, vec1, true, 2.0);

    vec1.Clear();
    Empty(testnum, testerr, vec1, true);
    GetFront(testnum, testerr, vec1, false, 1.0);
    GetBack(testnum, testerr, vec1, false, 2.0);
}

void zMyVectorString(unsigned int& testnum, unsigned int& testerr) {
    lasd::Vector<std::string> vec1(0);
    Empty(testnum, testerr, vec1, true);
    Size(testnum, testerr, vec1, true, 0);

    vec1.Resize(4);
    SetAt(testnum, testerr, vec1, true, 0, std::string("Hello"));
    SetAt(testnum, testerr, vec1, true, 1, std::string("World"));
    SetAt(testnum, testerr, vec1, true, 2, std::string("Test"));
    SetAt(testnum, testerr, vec1, true, 3, std::string("Vector"));

    GetAt(testnum, testerr, vec1, true, 0, std::string("Hello"));
    GetAt(testnum, testerr, vec1, true, 1, std::string("World"));
    GetAt(testnum, testerr, vec1, true, 2, std::string("Test"));
    GetAt(testnum, testerr, vec1, true, 3, std::string("Vector"));

    GetFront(testnum, testerr, vec1, true, std::string("Hello"));
    GetBack(testnum, testerr, vec1, true, std::string("Vector"));
    SetFront(testnum, testerr, vec1, true, std::string("First"));
    SetBack(testnum, testerr, vec1, true, std::string("Last"));
    GetFront(testnum, testerr, vec1, true, std::string("First"));
    GetBack(testnum, testerr, vec1, true, std::string("Last"));

    Traverse(testnum, testerr, vec1, true, &TraversePrint<std::string>);
    TraversePreOrder(testnum, testerr, vec1, true, &TraversePrint<std::string>);
    TraversePostOrder(testnum, testerr, vec1, true, &TraversePrint<std::string>);

    vec1.Resize(3);
    SetAt(testnum, testerr, vec1, true, 0, std::string(""));
    SetAt(testnum, testerr, vec1, true, 1, std::string("A"));
    SetAt(testnum, testerr, vec1, true, 2, std::string("Lorem ipsum dolor sit amet"));

    lasd::Vector<std::string> vec2(vec1);
    EqualVector(testnum, testerr, vec1, vec2, true);
    NonEqualVector(testnum, testerr, vec1, vec2, false);

    lasd::Vector<std::string> vec3(std::move(vec1));
    Empty(testnum, testerr, vec1, true);
    EqualVector(testnum, testerr, vec2, vec3, true);

    vec2 = vec3;
    vec1 = std::move(vec3);
    Empty(testnum, testerr, vec3, true);
    EqualVector(testnum, testerr, vec1, vec2, true);

    lasd::TraversableContainer<std::string>::FoldFun<std::string> concatFold =
        [](const std::string& element, const std::string& accumulator) -> std::string {
            return accumulator + element;
        };

    Fold(testnum, testerr, vec2, true, concatFold, std::string(""), vec2[0] + vec2[1] + vec2[2]);

    vec1.Resize(0);
    Empty(testnum, testerr, vec1, true);
    vec1.Resize(5);
    Size(testnum, testerr, vec1, true, 5);

    vec1.Clear();
    Empty(testnum, testerr, vec1, true);
    Size(testnum, testerr, vec1, true, 0);

    EqualVector(testnum, testerr, vec1, vec2, false);
    NonEqualVector(testnum, testerr, vec1, vec2, true);
    EqualVector(testnum, testerr, vec1, vec1, true);
    const lasd::Vector<std::string> vec4(1);
    EqualVector(testnum, testerr, vec1, vec4, false);
    NonEqualVector(testnum, testerr, vec1, vec4, true);

    vec1.Resize(2);
    SetAt(testnum, testerr, vec1, true, 0, std::string("A"));
    GetFront(testnum, testerr, vec1, true, std::string("A"));
    SetAt(testnum, testerr, vec1, true, 1, std::string("B"));
    GetBack(testnum, testerr, vec1, true, std::string("B"));

    lasd::Vector<std::string> vec5(0);
    Empty(testnum, testerr, vec5, true);
    GetFront(testnum, testerr, vec5, false, std::string("A"));
    GetBack(testnum, testerr, vec5, false, std::string("B"));
}

void zMyTestVectorCoverage() {
    lasd::Vector<int> emptyVector(0);
    try {
        int& frontValue = emptyVector.Front();
        std::cout << "Front value: " << frontValue << std::endl;
    } catch(const std::length_error& e) {
        std::cout << "Non-const Front() exception: " << e.what() << std::endl;
    }
    try {
        int& backValue = emptyVector.Back();
        std::cout << "Front value: " << backValue << std::endl;
    } catch(const std::length_error& e) {
        std::cout << "Non-const Front() exception: " << e.what() << std::endl;
    }
}

void zMyTestVector(unsigned int& testnum, unsigned int& testerr) {
    std::cout << "\n~*~#~*~ Test Vector Container ~*~#~*~ " << std::endl;

    std::cout << "\n[Test 1] Testing Vector<int>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyVectorInt(testnum, testerr);
    std::cout << "Integer vector tests completed" << std::endl;

    std::cout << "\n[Test 2] Testing Vector<double>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyVectorDouble(testnum, testerr);
    std::cout << "Double vector tests completed" << std::endl;

    std::cout << "\n[Test 3] Testing Vector<string>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyVectorString(testnum, testerr);
    std::cout << "String vector tests completed" << std::endl;

    std::cout << "Running coverage tests... (These tests will not be numbered - Expect exceptions)" << std::endl;
    zMyTestVectorCoverage();

    std::cout << "\nAll vector tests completed!" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}







}

