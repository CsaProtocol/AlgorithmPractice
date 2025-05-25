#include "pq.hpp"
#include "../../zlasdtest/pq/pq.hpp"

#include "../../zlasdtest/container/linear.hpp"
#include "../../pq/heap/pqheap.hpp"
#include "../../zlasdtest/container/container.hpp"
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

    Change(testnum, testerr, pqHeap, 4, 20);
    Change(testnum, testerr, pqHeap, 5, 21);
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

    Change(testnum, testerr, pqHeap, 4, 20.5);
    Change(testnum, testerr, pqHeap, 5, 21.5);
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

    Change(testnum, testerr, pqHeap, 4, std::string("watermelon"));
    Change(testnum, testerr, pqHeap, 5, std::string("zucchini"));
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
