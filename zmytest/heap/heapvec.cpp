#include "heapvec.hpp"



namespace zmytest {

void MapStringAppendX(std::string& s) {
    s += "X";
    std::cout << s << " ";
}

void MapStringRemoveLast(std::string& s) {
    if (!s.empty()) {
        s.pop_back();
    }
}

std::string FoldStringConcatenate(const std::string& accumulator, const std::string& current) {
    return accumulator + current;
}

void zMyTestHeapVecInt(unsigned int& testnum, unsigned int& testerr) {
    lasd::Vector<int> vec(10);
    SetAt(testnum, testerr, vec, true, 0, 0);
    SetAt(testnum, testerr, vec, true, 1, 1);
    SetAt(testnum, testerr, vec, true, 2, 2);
    SetAt(testnum, testerr, vec, true, 3, 3);
    SetAt(testnum, testerr, vec, true, 4, 4);
    SetAt(testnum, testerr, vec, true, 5, 5);
    SetAt(testnum, testerr, vec, true, 6, 6);
    SetAt(testnum, testerr, vec, true, 7, 7);
    SetAt(testnum, testerr, vec, true, 8, 8);
    SetAt(testnum, testerr, vec, true, 9, 9);

    lasd::HeapVec heapVec(vec);
    Size(testnum, testerr, heapVec, true, 10);
    IsHeap(testnum, testerr, heapVec, true);

    heapVec.Sort();
    IsHeap(testnum, testerr, heapVec, false);
    GetAt(testnum, testerr, heapVec, true, 0, 0);
    GetAt(testnum, testerr, heapVec, true, 1, 1);
    GetAt(testnum, testerr, heapVec, true, 2, 2);
    GetAt(testnum, testerr, heapVec, true, 3, 3);
    GetAt(testnum, testerr, heapVec, true, 4, 4);
    GetAt(testnum, testerr, heapVec, true, 5, 5);
    GetAt(testnum, testerr, heapVec, true, 6, 6);
    GetAt(testnum, testerr, heapVec, true, 7, 7);
    GetAt(testnum, testerr, heapVec, true, 8, 8);
    GetAt(testnum, testerr, heapVec, true, 9, 9);

    heapVec.Heapify();
    IsHeap(testnum, testerr, heapVec, true);

    Map(testnum, testerr, heapVec, true, &MapIncrementNPrint<int>);
    Map(testnum, testerr, heapVec, true, &MapDecrement<int>);
    Fold(testnum, testerr, heapVec, true, &FoldAdd<int>, 0, 45);
    Map(testnum, testerr, heapVec, true, &MapIncrementNPrint<int>);
    Fold(testnum, testerr, heapVec, true, &FoldMultiply<int>, 1, 3628800);
    GetAt(testnum, testerr, heapVec, false, 15, 0);

    lasd::HeapVec heapVec2(std::move(heapVec));
    Size(testnum, testerr, heapVec, true, 0);
    Size(testnum, testerr, heapVec2, true, 10);
    IsHeap(testnum, testerr, heapVec2, true);
    IsHeap(testnum, testerr, heapVec, true);

    heapVec.Clear();
    Size(testnum, testerr, heapVec, true, 0);
    Empty(testnum, testerr, heapVec, true);

    heapVec = heapVec;
    heapVec = heapVec2;

    EqualLinear(testnum, testerr, heapVec2, heapVec, true);
    IsHeap(testnum, testerr, heapVec, true);
    Traverse(testnum, testerr, heapVec, true, &TraversePrint<int>);
    Map(testnum, testerr, heapVec, true, &MapDecrement<int>);
    Fold(testnum, testerr, heapVec, true, &FoldAdd<int>, 0, 45);

    lasd::HeapVec heapVec3(heapVec2);
    EqualLinear(testnum, testerr, heapVec2, heapVec3, true);
    IsHeap(testnum, testerr, heapVec3, true);
    Size(testnum, testerr, heapVec3, true, 10);

    lasd::HeapVec heapVec4(std::move(vec));
    Map(testnum, testerr, heapVec4, true, &MapIncrementNPrint<int>);
    EqualLinear(testnum, testerr, heapVec2, heapVec4, true);
    IsHeap(testnum, testerr, heapVec4, true);
    Size(testnum, testerr, heapVec4, true, 10);

    lasd::HeapVec<int> heapVec5;
    heapVec5 = std::move(heapVec4);
    EqualLinear(testnum, testerr, heapVec2, heapVec5, true);
    IsHeap(testnum, testerr, heapVec5, true);
    Size(testnum, testerr, heapVec5, true, 10);
}

void zMyTestHeapVecDouble(unsigned int& testnum, unsigned int& testerr) {
    lasd::Vector<double> vec(10);
    SetAt(testnum, testerr, vec, true, 0, 0.5);
    SetAt(testnum, testerr, vec, true, 1, 1.5);
    SetAt(testnum, testerr, vec, true, 2, 2.5);
    SetAt(testnum, testerr, vec, true, 3, 3.5);
    SetAt(testnum, testerr, vec, true, 4, 4.5);
    SetAt(testnum, testerr, vec, true, 5, 5.5);
    SetAt(testnum, testerr, vec, true, 6, 6.5);
    SetAt(testnum, testerr, vec, true, 7, 7.5);
    SetAt(testnum, testerr, vec, true, 8, 8.5);
    SetAt(testnum, testerr, vec, true, 9, 9.5);

    lasd::HeapVec heapVec(vec);
    Size(testnum, testerr, heapVec, true, 10);
    IsHeap(testnum, testerr, heapVec, true);

    heapVec.Sort();
    IsHeap(testnum, testerr, heapVec, false);
    GetAt(testnum, testerr, heapVec, true, 0, 0.5);
    GetAt(testnum, testerr, heapVec, true, 1, 1.5);
    GetAt(testnum, testerr, heapVec, true, 2, 2.5);
    GetAt(testnum, testerr, heapVec, true, 3, 3.5);
    GetAt(testnum, testerr, heapVec, true, 4, 4.5);
    GetAt(testnum, testerr, heapVec, true, 5, 5.5);
    GetAt(testnum, testerr, heapVec, true, 6, 6.5);
    GetAt(testnum, testerr, heapVec, true, 7, 7.5);
    GetAt(testnum, testerr, heapVec, true, 8, 8.5);
    GetAt(testnum, testerr, heapVec, true, 9, 9.5);

    heapVec.Heapify();
    IsHeap(testnum, testerr, heapVec, true);

    Map(testnum, testerr, heapVec, true, &MapIncrementNPrint<double>);
    Map(testnum, testerr, heapVec, true, &MapDecrement<double>);
    Fold(testnum, testerr, heapVec, true, &FoldAdd<double>, 0.0, 50.0);
    Map(testnum, testerr, heapVec, true, &MapIncrementNPrint<double>);
    GetAt(testnum, testerr, heapVec, false, 15, 0.0);

    lasd::HeapVec heapVec2(std::move(heapVec));
    Size(testnum, testerr, heapVec, true, 0);
    Size(testnum, testerr, heapVec2, true, 10);
    IsHeap(testnum, testerr, heapVec2, true);
    IsHeap(testnum, testerr, heapVec, true);

    heapVec.Clear();
    Size(testnum, testerr, heapVec, true, 0);
    Empty(testnum, testerr, heapVec, true);

    heapVec = heapVec;
    heapVec = heapVec2;

    EqualLinear(testnum, testerr, heapVec2, heapVec, true);
    IsHeap(testnum, testerr, heapVec, true);
    Traverse(testnum, testerr, heapVec, true, &TraversePrint<double>);
    Map(testnum, testerr, heapVec, true, &MapDecrement<double>);
    Fold(testnum, testerr, heapVec, true, &FoldAdd<double>, 0.0, 50.0);

    lasd::HeapVec heapVec3(heapVec2);
    EqualLinear(testnum, testerr, heapVec2, heapVec3, true);
    IsHeap(testnum, testerr, heapVec3, true);
    Size(testnum, testerr, heapVec3, true, 10);

    lasd::HeapVec heapVec4(std::move(vec));
    Map(testnum, testerr, heapVec4, true, &MapIncrementNPrint<double>);
    EqualLinear(testnum, testerr, heapVec2, heapVec4, true);
    IsHeap(testnum, testerr, heapVec4, true);
    Size(testnum, testerr, heapVec4, true, 10);

    lasd::HeapVec<double> heapVec5;
    heapVec5 = std::move(heapVec4);
    EqualLinear(testnum, testerr, heapVec2, heapVec5, true);
    IsHeap(testnum, testerr, heapVec5, true);
    Size(testnum, testerr, heapVec5, true, 10);
}

void zMyTestHeapVecString(unsigned int& testnum, unsigned int& testerr) {
    lasd::Vector<std::string> vec(10);
    SetAt(testnum, testerr, vec, true, 0, std::string("A"));
    SetAt(testnum, testerr, vec, true, 1, std::string("B"));
    SetAt(testnum, testerr, vec, true, 2, std::string("C"));
    SetAt(testnum, testerr, vec, true, 3, std::string("D"));
    SetAt(testnum, testerr, vec, true, 4, std::string("E"));
    SetAt(testnum, testerr, vec, true, 5, std::string("F"));
    SetAt(testnum, testerr, vec, true, 6, std::string("G"));
    SetAt(testnum, testerr, vec, true, 7, std::string("H"));
    SetAt(testnum, testerr, vec, true, 8, std::string("I"));
    SetAt(testnum, testerr, vec, true, 9, std::string("J"));

    lasd::HeapVec heapVec(vec);
    Size(testnum, testerr, heapVec, true, 10);
    IsHeap(testnum, testerr, heapVec, true);

    heapVec.Sort();
    IsHeap(testnum, testerr, heapVec, false);
    GetAt(testnum, testerr, heapVec, true, 0, std::string("A"));
    GetAt(testnum, testerr, heapVec, true, 1, std::string("B"));
    GetAt(testnum, testerr, heapVec, true, 2, std::string("C"));
    GetAt(testnum, testerr, heapVec, true, 3, std::string("D"));
    GetAt(testnum, testerr, heapVec, true, 4, std::string("E"));
    GetAt(testnum, testerr, heapVec, true, 5, std::string("F"));
    GetAt(testnum, testerr, heapVec, true, 6, std::string("G"));
    GetAt(testnum, testerr, heapVec, true, 7, std::string("H"));
    GetAt(testnum, testerr, heapVec, true, 8, std::string("I"));
    GetAt(testnum, testerr, heapVec, true, 9, std::string("J"));

    heapVec.Heapify();
    IsHeap(testnum, testerr, heapVec, true);

    Map(testnum, testerr, heapVec, true, &MapStringAppendX);
    Map(testnum, testerr, heapVec, true, &MapStringRemoveLast);
    Fold(testnum, testerr, heapVec, true, &FoldStringConcatenate, std::string(""), std::string("BDACFEHGIJ"));
    Map(testnum, testerr, heapVec, true, &MapStringAppendX);
    GetAt(testnum, testerr, heapVec, false, 15, std::string(""));

    lasd::HeapVec heapVec2(std::move(heapVec));
    Size(testnum, testerr, heapVec, true, 0);
    Size(testnum, testerr, heapVec2, true, 10);
    IsHeap(testnum, testerr, heapVec2, true);
    IsHeap(testnum, testerr, heapVec, true);

    heapVec.Clear();
    Size(testnum, testerr, heapVec, true, 0);
    Empty(testnum, testerr, heapVec, true);

    heapVec = heapVec;
    heapVec = heapVec2;

    EqualLinear(testnum, testerr, heapVec2, heapVec, true);
    IsHeap(testnum, testerr, heapVec, true);
    Traverse(testnum, testerr, heapVec, true, &TraversePrint<std::string>);
    Map(testnum, testerr, heapVec, true, &MapStringRemoveLast);
    heapVec.Sort();
    Fold(testnum, testerr, heapVec, true, &FoldStringConcatenate, std::string(""), std::string("JIHGFEDCBA"));
    heapVec.Heapify();

    lasd::HeapVec heapVec3(heapVec2);
    EqualLinear(testnum, testerr, heapVec2, heapVec3, true);
    IsHeap(testnum, testerr, heapVec3, true);
    Size(testnum, testerr, heapVec3, true, 10);

    lasd::HeapVec heapVec4(std::move(vec));
    Map(testnum, testerr, heapVec4, true, &MapStringAppendX);
    EqualLinear(testnum, testerr, heapVec2, heapVec4, true);
    IsHeap(testnum, testerr, heapVec4, true);
    Size(testnum, testerr, heapVec4, true, 10);

    lasd::HeapVec<std::string> heapVec5;
    heapVec5 = std::move(heapVec4);
    EqualLinear(testnum, testerr, heapVec2, heapVec5, true);
    IsHeap(testnum, testerr, heapVec5, true);
    Size(testnum, testerr, heapVec5, true, 10);
}

void zMyTestHeapVec(unsigned int& testnum, unsigned int& testerr) {
    std::cout << "\n~*~#~*~ Test HeapVec Container ~*~#~*~ " << std::endl;

    std::cout << "\n[Test 1] Testing HeapVec<int>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyTestHeapVecInt(testnum, testerr);
    std::cout << "Integer heap tests completed" << std::endl;

    std::cout << "\n[Test 2] Testing HeapVec<double>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyTestHeapVecDouble(testnum, testerr);
    std::cout << "Double heap tests completed" << std::endl;

    std::cout << "\n[Test 3] Testing HeapVec<string>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyTestHeapVecString(testnum, testerr);
    std::cout << "String heap tests completed" << std::endl;

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "\nAll heap tests completed!" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

}
