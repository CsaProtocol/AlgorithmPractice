#include "pq.hpp"
#include "../../zlasdtest/pq/pq.hpp"

#include <climits>
#include "../../pq/heap/pqheap.hpp"
#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/traversable.hpp"

namespace zmytest {

void zMyTestPQHeapInt(unsigned int& testnum, unsigned int& testerr) {

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

    lasd::PQHeap pqHeap(vec);
    Size(testnum, testerr, pqHeap, true, 10);
    TipNRemove(testnum, testerr, pqHeap, true, 9);
    Traverse(testnum, testerr, pqHeap, true, &TraversePrint<int>);
    RemoveTip(testnum, testerr, pqHeap, true);
    Size(testnum, testerr, pqHeap, true, 8);
    Tip(testnum, testerr, pqHeap, true, 7);

    Insert(testnum, testerr, pqHeap, 10);
    Insert(testnum, testerr, pqHeap, 11);
    Insert(testnum, testerr, pqHeap, 12);
    Insert(testnum, testerr, pqHeap, 13);
    Size(testnum, testerr, pqHeap, true, 12);

    Change(testnum, testerr, pqHeap, true, 4, 20);
    Change(testnum, testerr, pqHeap, true, 5, 21);
    Tip(testnum, testerr, pqHeap, true, 21);

    lasd::PQHeap pqHeap2(std::move(vec));
    Size(testnum, testerr, pqHeap2, true, 10);
    TipNRemove(testnum, testerr, pqHeap2, true, 9);
    Traverse(testnum, testerr, pqHeap2, true, &TraversePrint<int>);
    RemoveTip(testnum, testerr, pqHeap2, true);
    Size(testnum, testerr, pqHeap2, true, 8);
    Tip(testnum, testerr, pqHeap2, true, 7);
    Insert(testnum, testerr, pqHeap2, 10);
    Insert(testnum, testerr, pqHeap2, 11);
    Insert(testnum, testerr, pqHeap2, 12);
    Insert(testnum, testerr, pqHeap2, 13);
    Size(testnum, testerr, pqHeap2, true, 12);

    lasd::PQHeap pqHeap3(pqHeap2);
    Size(testnum, testerr, pqHeap3, true, 12);
    TipNRemove(testnum, testerr, pqHeap3, true, 13);
    Traverse(testnum, testerr, pqHeap3, true, &TraversePrint<int>);
    RemoveTip(testnum, testerr, pqHeap3, true);
    Size(testnum, testerr, pqHeap3, true, 10);

    lasd::PQHeap pqHeap4(std::move(pqHeap));
    Size(testnum, testerr, pqHeap4, true, 12);
    TipNRemove(testnum, testerr, pqHeap4, true, 21);
    Traverse(testnum, testerr, pqHeap4, true, &TraversePrint<int>);

    lasd::PQHeap<int> pqHeap5;
    pqHeap5 = std::move(pqHeap4);
    Empty(testnum, testerr, pqHeap4, true);
    Size(testnum, testerr, pqHeap4, true, 0);
    Size(testnum, testerr, pqHeap5, true, 11);
    TipNRemove(testnum, testerr, pqHeap5, true, 20);
    Traverse(testnum, testerr, pqHeap5, true, &TraversePrint<int>);

    pqHeap4 = pqHeap5;
    Size(testnum, testerr, pqHeap4, true, 10);
    TipNRemove(testnum, testerr, pqHeap4, true, 13);
    Traverse(testnum, testerr, pqHeap4, true, &TraversePrint<int>);
    RemoveTip(testnum, testerr, pqHeap4, true);
    Size(testnum, testerr, pqHeap4, true, 8);
    Tip(testnum, testerr, pqHeap4, true, 11);

    lasd::PQHeap<int> pqHeap6(std::move(pqHeap5));
    Size(testnum, testerr, pqHeap6, true, 10);
    TipNRemove(testnum, testerr, pqHeap6, true, 13);
    Traverse(testnum, testerr, pqHeap6, true, &TraversePrint<int>);
    RemoveTip(testnum, testerr, pqHeap6, true);
    Size(testnum, testerr, pqHeap6, true, 8);
    Tip(testnum, testerr, pqHeap6, true, 11);

    std::cout << "\n[Edge Case 1] Testing empty heap operations..." << std::endl;
    lasd::PQHeap<int> emptyHeap;
    Empty(testnum, testerr, emptyHeap, true);
    Size(testnum, testerr, emptyHeap, true, 0);

    std::cout << "\n[Edge Case 2] Testing duplicate values..." << std::endl;
    lasd::PQHeap<int> duplicateHeap;
    Insert(testnum, testerr, duplicateHeap, 5);
    Insert(testnum, testerr, duplicateHeap, 5);
    Insert(testnum, testerr, duplicateHeap, 5);
    Insert(testnum, testerr, duplicateHeap, 5);
    Size(testnum, testerr, duplicateHeap, true, 4);
    TipNRemove(testnum, testerr, duplicateHeap, true, 5);
    TipNRemove(testnum, testerr, duplicateHeap, true, 5);
    TipNRemove(testnum, testerr, duplicateHeap, true, 5);
    TipNRemove(testnum, testerr, duplicateHeap, true, 5);
    Empty(testnum, testerr, duplicateHeap, true);

    std::cout << "\n[Edge Case 3] Testing negative values..." << std::endl;
    lasd::PQHeap<int> negativeHeap;
    Insert(testnum, testerr, negativeHeap, -5);
    Insert(testnum, testerr, negativeHeap, -10);
    Insert(testnum, testerr, negativeHeap, -3);
    Insert(testnum, testerr, negativeHeap, -7);
    Size(testnum, testerr, negativeHeap, true, 4);
    TipNRemove(testnum, testerr, negativeHeap, true, -3);
    TipNRemove(testnum, testerr, negativeHeap, true, -5);
    TipNRemove(testnum, testerr, negativeHeap, true, -7);
    TipNRemove(testnum, testerr, negativeHeap, true, -10);
    Empty(testnum, testerr, negativeHeap, true);

    std::cout << "\n[Edge Case 4] Testing resize with many elements..." << std::endl;
    lasd::PQHeap<int> resizeHeap;
    for (int i = 0; i < 100; i++) {
        Insert(testnum, testerr, resizeHeap, i);
    }
    Size(testnum, testerr, resizeHeap, true, 100);
    Tip(testnum, testerr, resizeHeap, true, 99);
    for(int i = 99; i >= 0; --i) {
        TipNRemove(testnum, testerr, resizeHeap, true, i);
    }
    Size(testnum, testerr, resizeHeap, true, 0);


    std::cout << "\n[Edge Case 5] Testing Heapify with unordered vector..." << std::endl;
    lasd::Vector<int> unsortedVec(10);
    SetAt(testnum, testerr, unsortedVec, true, 0, 4);
    SetAt(testnum, testerr, unsortedVec, true, 1, 2);
    SetAt(testnum, testerr, unsortedVec, true, 2, 8);
    SetAt(testnum, testerr, unsortedVec, true, 3, 1);
    SetAt(testnum, testerr, unsortedVec, true, 4, 6);
    SetAt(testnum, testerr, unsortedVec, true, 5, 3);
    SetAt(testnum, testerr, unsortedVec, true, 6, 9);
    SetAt(testnum, testerr, unsortedVec, true, 7, 5);
    SetAt(testnum, testerr, unsortedVec, true, 8, 7);
    SetAt(testnum, testerr, unsortedVec, true, 9, 0);

    lasd::PQHeap<int> unsortedHeap(unsortedVec);
    Size(testnum, testerr, unsortedHeap, true, 10);
    TipNRemove(testnum, testerr, unsortedHeap, true, 9);
    TipNRemove(testnum, testerr, unsortedHeap, true, 8);
    TipNRemove(testnum, testerr, unsortedHeap, true, 7);

    std::cout << "\n[Edge Case 6] Testing assignment of empty heap..." << std::endl;
    lasd::PQHeap<int> emptyHeap2;
    lasd::PQHeap<int> nonEmptyHeap;
    Insert(testnum, testerr, nonEmptyHeap, 1);
    Insert(testnum, testerr, nonEmptyHeap, 2);

    nonEmptyHeap = emptyHeap2;
    Empty(testnum, testerr, nonEmptyHeap, true);
    Size(testnum, testerr, nonEmptyHeap, true, 0);

    std::cout << "\n[Edge Case 7] Testing Change with no order change..." << std::endl;
    lasd::PQHeap<int> changeHeap;
    Insert(testnum, testerr, changeHeap, 10);
    Insert(testnum, testerr, changeHeap, 5);
    Insert(testnum, testerr, changeHeap, 7);

    Change(testnum, testerr, changeHeap, true, 0, 10);
    Tip(testnum, testerr, changeHeap, true, 10);

    Change(testnum, testerr, changeHeap, true, 1, 6);
    TipNRemove(testnum, testerr, changeHeap, true, 10);
    Tip(testnum, testerr, changeHeap, true, 7);

    std::cout << "\n[Edge Case 8] Testing extreme values..." << std::endl;
    lasd::PQHeap<int> extremeHeap;
    Insert(testnum, testerr, extremeHeap, INT_MAX);
    Insert(testnum, testerr, extremeHeap, INT_MIN);
    Insert(testnum, testerr, extremeHeap, 0);
    Size(testnum, testerr, extremeHeap, true, 3);
    TipNRemove(testnum, testerr, extremeHeap, true, INT_MAX);
    TipNRemove(testnum, testerr, extremeHeap, true, 0);
    TipNRemove(testnum, testerr, extremeHeap, true, INT_MIN);
    Empty(testnum, testerr, extremeHeap, true);

    std::cout << "\n[Edge Case 9] Testing change with extreme value updates..." << std::endl;
    lasd::PQHeap<int> extremeChangeHeap;
    Insert(testnum, testerr, extremeChangeHeap, 10);
    Insert(testnum, testerr, extremeChangeHeap, 20);
    Insert(testnum, testerr, extremeChangeHeap, 30);

    Change(testnum, testerr, extremeChangeHeap, true, 1, INT_MAX);
    Tip(testnum, testerr, extremeChangeHeap, true, INT_MAX);

    Change(testnum, testerr, extremeChangeHeap, true, 2, INT_MIN);
    TipNRemove(testnum, testerr, extremeChangeHeap, true, INT_MAX);
    TipNRemove(testnum, testerr, extremeChangeHeap, true, 30);
    TipNRemove(testnum, testerr, extremeChangeHeap, true, INT_MIN);
    Empty(testnum, testerr, extremeChangeHeap, true);

    std::cout << "\n[Edge Case 10] Testing Insert after RemoveTip when empty..." << std::endl;
    lasd::PQHeap<int> emptyThenFillHeap;
    Insert(testnum, testerr, emptyThenFillHeap, 5);
    TipNRemove(testnum, testerr, emptyThenFillHeap, true, 5);
    Empty(testnum, testerr, emptyThenFillHeap, true);

    Insert(testnum, testerr, emptyThenFillHeap, 10);
    Insert(testnum, testerr, emptyThenFillHeap, 20);
    Size(testnum, testerr, emptyThenFillHeap, true, 2);
    TipNRemove(testnum, testerr, emptyThenFillHeap, true, 20);
    TipNRemove(testnum, testerr, emptyThenFillHeap, true, 10);
    Empty(testnum, testerr, emptyThenFillHeap, true);

    std::cout << "\n[Edge Case 11] Testing equality operator (==)..." << std::endl;
    lasd::PQHeap<int> eqHeap1;
    lasd::PQHeap<int> eqHeap2;

    EqualLinear(testnum, testerr, eqHeap1, eqHeap2, true);

    Insert(testnum, testerr, eqHeap1, 5);
    Insert(testnum, testerr, eqHeap1, 10);
    Insert(testnum, testerr, eqHeap1, 15);

    Insert(testnum, testerr, eqHeap2, 5);
    Insert(testnum, testerr, eqHeap2, 10);
    Insert(testnum, testerr, eqHeap2, 15);

    EqualLinear(testnum, testerr, eqHeap1, eqHeap2, true);

    Insert(testnum, testerr, eqHeap1, 20);
    EqualLinear(testnum, testerr, eqHeap1, eqHeap2, false);

    Insert(testnum, testerr, eqHeap2, 25);
    EqualLinear(testnum, testerr, eqHeap1, eqHeap2, false);

    RemoveTip(testnum, testerr, eqHeap1, true);
    RemoveTip(testnum, testerr, eqHeap2, true);
    EqualLinear(testnum, testerr, eqHeap1, eqHeap2, true);

    std::cout << "\n[Edge Case 12] Testing equality with different insertion order..." << std::endl;
    lasd::PQHeap<int> diffOrderHeap1;
    lasd::PQHeap<int> diffOrderHeap2;

    Insert(testnum, testerr, diffOrderHeap1, 30);
    Insert(testnum, testerr, diffOrderHeap1, 20);
    Insert(testnum, testerr, diffOrderHeap1, 10);

    Insert(testnum, testerr, diffOrderHeap2, 10);
    Insert(testnum, testerr, diffOrderHeap2, 20);
    Insert(testnum, testerr, diffOrderHeap2, 30);

    EqualLinear(testnum, testerr, diffOrderHeap1, diffOrderHeap2, false);

    RemoveTip(testnum, testerr, diffOrderHeap1, true);
    RemoveTip(testnum, testerr, diffOrderHeap2, true);
    EqualLinear(testnum, testerr, diffOrderHeap1, diffOrderHeap2, true);
}

void zMyTestPQHeapDouble(unsigned int& testnum, unsigned int& testerr) {
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

    lasd::PQHeap pqHeap(vec);
    Size(testnum, testerr, pqHeap, true, 10);
    TipNRemove(testnum, testerr, pqHeap, true, 9.5);
    Traverse(testnum, testerr, pqHeap, true, &TraversePrint<double>);
    RemoveTip(testnum, testerr, pqHeap, true);
    Size(testnum, testerr, pqHeap, true, 8);
    Tip(testnum, testerr, pqHeap, true, 7.5);

    Insert(testnum, testerr, pqHeap, 10.5);
    Insert(testnum, testerr, pqHeap, 11.5);
    Insert(testnum, testerr, pqHeap, 12.5);
    Insert(testnum, testerr, pqHeap, 13.5);
    Size(testnum, testerr, pqHeap, true, 12);

    Change(testnum, testerr, pqHeap, true, 4, 20.5);
    Change(testnum, testerr, pqHeap, true, 5, 21.5);
    Tip(testnum, testerr, pqHeap, true, 21.5);

    lasd::PQHeap pqHeap2(std::move(vec));
    Size(testnum, testerr, pqHeap2, true, 10);
    TipNRemove(testnum, testerr, pqHeap2, true, 9.5);
    Traverse(testnum, testerr, pqHeap2, true, &TraversePrint<double>);
    RemoveTip(testnum, testerr, pqHeap2, true);
    Size(testnum, testerr, pqHeap2, true, 8);
    Tip(testnum, testerr, pqHeap2, true, 7.5);
    Insert(testnum, testerr, pqHeap2, 10.5);
    Insert(testnum, testerr, pqHeap2, 11.5);
    Insert(testnum, testerr, pqHeap2, 12.5);
    Insert(testnum, testerr, pqHeap2, 13.5);
    Size(testnum, testerr, pqHeap2, true, 12);

    lasd::PQHeap pqHeap3(pqHeap2);
    Size(testnum, testerr, pqHeap3, true, 12);
    TipNRemove(testnum, testerr, pqHeap3, true, 13.5);
    Traverse(testnum, testerr, pqHeap3, true, &TraversePrint<double>);
    RemoveTip(testnum, testerr, pqHeap3, true);
    Size(testnum, testerr, pqHeap3, true, 10);

    lasd::PQHeap pqHeap4(std::move(pqHeap));
    Size(testnum, testerr, pqHeap4, true, 12);
    TipNRemove(testnum, testerr, pqHeap4, true, 21.5);
    Traverse(testnum, testerr, pqHeap4, true, &TraversePrint<double>);

    lasd::PQHeap<double> pqHeap5;
    pqHeap5 = std::move(pqHeap4);
    Empty(testnum, testerr, pqHeap4, true);
    Size(testnum, testerr, pqHeap4, true, 0);
    Size(testnum, testerr, pqHeap5, true, 11);
    TipNRemove(testnum, testerr, pqHeap5, true, 20.5);
    Traverse(testnum, testerr, pqHeap5, true, &TraversePrint<double>);

    pqHeap4 = pqHeap5;
    Size(testnum, testerr, pqHeap4, true, 10);
    TipNRemove(testnum, testerr, pqHeap4, true, 13.5);
    Traverse(testnum, testerr, pqHeap4, true, &TraversePrint<double>);
    RemoveTip(testnum, testerr, pqHeap4, true);
    Size(testnum, testerr, pqHeap4, true, 8);
    Tip(testnum, testerr, pqHeap4, true, 11.5);

    lasd::PQHeap<double> pqHeap6(std::move(pqHeap5));
    Size(testnum, testerr, pqHeap6, true, 10);
    TipNRemove(testnum, testerr, pqHeap6, true, 13.5);
    Traverse(testnum, testerr, pqHeap6, true, &TraversePrint<double>);
    RemoveTip(testnum, testerr, pqHeap6, true);
    Size(testnum, testerr, pqHeap6, true, 8);
    Tip(testnum, testerr, pqHeap6, true, 11.5);

    std::cout << "\n[Edge Case 13] Testing equality operator with doubles..." << std::endl;
    lasd::PQHeap<double> eqDoubleHeap1;
    lasd::PQHeap<double> eqDoubleHeap2;

    EqualLinear(testnum, testerr, eqDoubleHeap1, eqDoubleHeap2, true);

    Insert(testnum, testerr, eqDoubleHeap1, 3.14);
    Insert(testnum, testerr, eqDoubleHeap1, 2.71);
    Insert(testnum, testerr, eqDoubleHeap1, 1.618);

    Insert(testnum, testerr, eqDoubleHeap2, 1.618);
    Insert(testnum, testerr, eqDoubleHeap2, 3.14);
    Insert(testnum, testerr, eqDoubleHeap2, 2.71);

    EqualLinear(testnum, testerr, eqDoubleHeap1, eqDoubleHeap2, false);

    Change(testnum, testerr, eqDoubleHeap1, true, 0, 4.20);
    EqualLinear(testnum, testerr, eqDoubleHeap1, eqDoubleHeap2, false);

    std::cout << "\n[Edge Case 14] Testing equality after operations..." << std::endl;
    lasd::PQHeap<double> opHeap1;
    lasd::PQHeap<double> opHeap2;

    Insert(testnum, testerr, opHeap1, 10.5);
    Insert(testnum, testerr, opHeap1, 20.5);
    Insert(testnum, testerr, opHeap1, 30.5);
    RemoveTip(testnum, testerr, opHeap1, true);
    Insert(testnum, testerr, opHeap1, 15.5);

    Insert(testnum, testerr, opHeap2, 20.5);
    Insert(testnum, testerr, opHeap2, 10.5);
    Insert(testnum, testerr, opHeap2, 15.5);

    EqualLinear(testnum, testerr, opHeap1, opHeap2, true);

    std::cout << "\n[Edge Case 15] Testing equality with floating-point precision issues..." << std::endl;
    lasd::PQHeap<double> precHeap1;
    lasd::PQHeap<double> precHeap2;

    Insert(testnum, testerr, precHeap1, 1.0000001);
    Insert(testnum, testerr, precHeap1, 2.0000001);

    Insert(testnum, testerr, precHeap2, 1.0000002);
    Insert(testnum, testerr, precHeap2, 2.0000002);

    EqualLinear(testnum, testerr, precHeap1, precHeap2, false);
}

void zMyTestPQHeapString(unsigned int& testnum, unsigned int& testerr) {
    lasd::Vector<std::string> vec(10);
    SetAt(testnum, testerr, vec, true, 0, std::string("apple"));
    SetAt(testnum, testerr, vec, true, 1, std::string("banana"));
    SetAt(testnum, testerr, vec, true, 2, std::string("cherry"));
    SetAt(testnum, testerr, vec, true, 3, std::string("date"));
    SetAt(testnum, testerr, vec, true, 4, std::string("elderberry"));
    SetAt(testnum, testerr, vec, true, 5, std::string("fig"));
    SetAt(testnum, testerr, vec, true, 6, std::string("grape"));
    SetAt(testnum, testerr, vec, true, 7, std::string("honeydew"));
    SetAt(testnum, testerr, vec, true, 8, std::string("kiwi"));
    SetAt(testnum, testerr, vec, true, 9, std::string("lemon"));

    lasd::PQHeap pqHeap(vec);
    Size(testnum, testerr, pqHeap, true, 10);
    TipNRemove(testnum, testerr, pqHeap, true, std::string("lemon"));
    Traverse(testnum, testerr, pqHeap, true, &TraversePrint<std::string>);
    RemoveTip(testnum, testerr, pqHeap, true);
    Size(testnum, testerr, pqHeap, true, 8);
    Tip(testnum, testerr, pqHeap, true, std::string("honeydew"));

    Insert(testnum, testerr, pqHeap, std::string("mango"));
    Insert(testnum, testerr, pqHeap, std::string("nectarine"));
    Insert(testnum, testerr, pqHeap, std::string("orange"));
    Insert(testnum, testerr, pqHeap, std::string("pear"));
    Size(testnum, testerr, pqHeap, true, 12);

    Change(testnum, testerr, pqHeap, true, 4, std::string("watermelon"));
    Change(testnum, testerr, pqHeap, true, 5, std::string("zucchini"));
    Tip(testnum, testerr, pqHeap, true, std::string("zucchini"));

    lasd::PQHeap pqHeap2(std::move(vec));
    Size(testnum, testerr, pqHeap2, true, 10);
    TipNRemove(testnum, testerr, pqHeap2, true, std::string("lemon"));
    Traverse(testnum, testerr, pqHeap2, true, &TraversePrint<std::string>);
    RemoveTip(testnum, testerr, pqHeap2, true);
    Size(testnum, testerr, pqHeap2, true, 8);
    Tip(testnum, testerr, pqHeap2, true, std::string("honeydew"));
    Insert(testnum, testerr, pqHeap2, std::string("mango"));
    Insert(testnum, testerr, pqHeap2, std::string("nectarine"));
    Insert(testnum, testerr, pqHeap2, std::string("orange"));
    Insert(testnum, testerr, pqHeap2, std::string("pear"));
    Size(testnum, testerr, pqHeap2, true, 12);

    lasd::PQHeap pqHeap3(pqHeap2);
    Size(testnum, testerr, pqHeap3, true, 12);
    TipNRemove(testnum, testerr, pqHeap3, true, std::string("pear"));
    Traverse(testnum, testerr, pqHeap3, true, &TraversePrint<std::string>);
    RemoveTip(testnum, testerr, pqHeap3, true);
    Size(testnum, testerr, pqHeap3, true, 10);

    lasd::PQHeap pqHeap4(std::move(pqHeap));
    Size(testnum, testerr, pqHeap4, true, 12);
    TipNRemove(testnum, testerr, pqHeap4, true, std::string("zucchini"));
    Traverse(testnum, testerr, pqHeap4, true, &TraversePrint<std::string>);

    lasd::PQHeap<std::string> pqHeap5;
    pqHeap5 = std::move(pqHeap4);
    Empty(testnum, testerr, pqHeap4, true);
    Size(testnum, testerr, pqHeap4, true, 0);
    Size(testnum, testerr, pqHeap5, true, 11);
    TipNRemove(testnum, testerr, pqHeap5, true, std::string("watermelon"));
    Traverse(testnum, testerr, pqHeap5, true, &TraversePrint<std::string>);

    pqHeap4 = pqHeap5;
    Size(testnum, testerr, pqHeap4, true, 10);
    TipNRemove(testnum, testerr, pqHeap4, true, std::string("pear"));
    Traverse(testnum, testerr, pqHeap4, true, &TraversePrint<std::string>);
    RemoveTip(testnum, testerr, pqHeap4, true);
    Size(testnum, testerr, pqHeap4, true, 8);
    Tip(testnum, testerr, pqHeap4, true, std::string("nectarine"));

    lasd::PQHeap<std::string> pqHeap6(std::move(pqHeap5));
    Size(testnum, testerr, pqHeap6, true, 10);
    TipNRemove(testnum, testerr, pqHeap6, true, std::string("pear"));
    Traverse(testnum, testerr, pqHeap6, true, &TraversePrint<std::string>);
    RemoveTip(testnum, testerr, pqHeap6, true);
    Size(testnum, testerr, pqHeap6, true, 8);
    Tip(testnum, testerr, pqHeap6, true, std::string("nectarine"));

    std::cout << "\n[Edge Case 16] Testing equality operator with strings..." << std::endl;
    lasd::PQHeap<std::string> eqStrHeap1;
    lasd::PQHeap<std::string> eqStrHeap2;

    EqualLinear(testnum, testerr, eqStrHeap1, eqStrHeap2, true);

    Insert(testnum, testerr, eqStrHeap1, std::string("cat"));
    Insert(testnum, testerr, eqStrHeap1, std::string("dog"));
    Insert(testnum, testerr, eqStrHeap1, std::string("bird"));

    Insert(testnum, testerr, eqStrHeap2, std::string("bird"));
    Insert(testnum, testerr, eqStrHeap2, std::string("cat"));
    Insert(testnum, testerr, eqStrHeap2, std::string("dog"));

    EqualLinear(testnum, testerr, eqStrHeap1, eqStrHeap2, false);

    Insert(testnum, testerr, eqStrHeap1, std::string("elephant"));
    EqualLinear(testnum, testerr, eqStrHeap1, eqStrHeap2, false);

    std::cout << "\n[Edge Case 17] Testing equality with case sensitivity..." << std::endl;
    lasd::PQHeap<std::string> caseHeap1;
    lasd::PQHeap<std::string> caseHeap2;

    Insert(testnum, testerr, caseHeap1, std::string("Apple"));
    Insert(testnum, testerr, caseHeap1, std::string("Banana"));

    Insert(testnum, testerr, caseHeap2, std::string("apple"));
    Insert(testnum, testerr, caseHeap2, std::string("banana"));

    EqualLinear(testnum, testerr, caseHeap1, caseHeap2, false);

    std::cout << "\n[Edge Case 18] Testing equality with empty strings..." << std::endl;
    lasd::PQHeap<std::string> emptyStrHeap1;
    lasd::PQHeap<std::string> emptyStrHeap2;

    Insert(testnum, testerr, emptyStrHeap1, std::string(""));
    Insert(testnum, testerr, emptyStrHeap1, std::string("test"));

    Insert(testnum, testerr, emptyStrHeap2, std::string(""));
    Insert(testnum, testerr, emptyStrHeap2, std::string("test"));

    EqualLinear(testnum, testerr, emptyStrHeap1, emptyStrHeap2, true);

    Change(testnum, testerr, emptyStrHeap1, true, 0, std::string("changed"));
    EqualLinear(testnum, testerr, emptyStrHeap1, emptyStrHeap2, false);
}

void zMyTestPQHeapCoverage() {
    lasd::PQHeap<int> pq;
    try{
        pq.RemoveTip();
    } catch(const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        pq.TipNRemove();
    } catch(const std::length_error& e) {
        std::cout << "Out of range error: " << e.what() << std::endl;
    }
    try {
        pq.Insert(std::move(28));
        pq.Insert(std::move(29));
        pq.Insert(std::move(30));
        pq.Insert(std::move(31));
        pq.Change(2, 3);
    } catch(const std::out_of_range& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    try {
        pq.Change(1, std::move(2));
    } catch(const std::out_of_range& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
}

void zMyTestPQHeap(unsigned int& testnum, unsigned int& testerr) {
  std::cout << "\n~*~#~*~ Test PQHeap Container ~*~#~*~ " << std::endl;

  std::cout << "\n[Test 1] Testing PQHeap<int>..." << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  zMyTestPQHeapInt(testnum, testerr);
  std::cout << "Integer PQHeap tests completed" << std::endl;

  std::cout << "\n[Test 2] Testing PQHeap<double>..." << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  zMyTestPQHeapDouble(testnum, testerr);
  std::cout << "Double PQHeap tests completed" << std::endl;

  std::cout << "\n[Test 3] Testing PQHeap<string>..." << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  zMyTestPQHeapString(testnum, testerr);
  std::cout << "String PQHeap tests completed" << std::endl;

  std::cout << "\n[Test 4] Coverage tests... Expect exceptions - Tests not numbered" << std::endl;
  zMyTestPQHeapCoverage();
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Coverage PQHeap tests completed" << std::endl;

  std::cout << "----------------------------------------" << std::endl;
  std::cout << "\nAll PQHeap tests completed!" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
}

}
