
#include <iostream>

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"

#include "../heap/heap.hpp"

#include "../../heap/heap.hpp"
#include "../../heap/vec/heapvec.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void stestHeapInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Heap<int> Test:" << endl;
  try {

    lasd::Vector<int> vec(14);
    SetAt(loctestnum, loctesterr, vec, true, 0, 4);
    SetAt(loctestnum, loctesterr, vec, true, 1, 3);
    SetAt(loctestnum, loctesterr, vec, true, 2, 1);
    SetAt(loctestnum, loctesterr, vec, true, 3, 0);
    SetAt(loctestnum, loctesterr, vec, true, 4, 2);
    SetAt(loctestnum, loctesterr, vec, true, 5, 5);
    SetAt(loctestnum, loctesterr, vec, true, 6, 0);
    SetAt(loctestnum, loctesterr, vec, true, 7, 8);
    SetAt(loctestnum, loctesterr, vec, true, 8, 10);
    SetAt(loctestnum, loctesterr, vec, true, 9, 11);
    SetAt(loctestnum, loctesterr, vec, true, 10, 7);
    SetAt(loctestnum, loctesterr, vec, true, 11, 3);
    SetAt(loctestnum, loctesterr, vec, true, 12, 9);
    SetAt(loctestnum, loctesterr, vec, true, 13, 6);

    lasd::HeapVec<int> heap1(vec);

    Traverse(loctestnum, loctesterr, heap1, true, &TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<int>);

    IsHeap(loctestnum, loctesterr, heap1, true);

    SetAt(loctestnum, loctesterr, vec, true, 0, 11);
    SetAt(loctestnum, loctesterr, vec, true, 1, 10);
    SetAt(loctestnum, loctesterr, vec, true, 2, 9);
    SetAt(loctestnum, loctesterr, vec, true, 3, 8);
    SetAt(loctestnum, loctesterr, vec, true, 4, 7);
    SetAt(loctestnum, loctesterr, vec, true, 5, 6);
    SetAt(loctestnum, loctesterr, vec, true, 6, 5);
    SetAt(loctestnum, loctesterr, vec, true, 7, 4);
    SetAt(loctestnum, loctesterr, vec, true, 8, 3);
    SetAt(loctestnum, loctesterr, vec, true, 9, 3);
    SetAt(loctestnum, loctesterr, vec, true, 10, 2);
    SetAt(loctestnum, loctesterr, vec, true, 11, 1);
    SetAt(loctestnum, loctesterr, vec, true, 12, 0);
    SetAt(loctestnum, loctesterr, vec, true, 13, 0);

    lasd::HeapVec<int> heap2(vec);

    IsHeap(loctestnum, loctesterr, heap2, true);

    EqualLinear(loctestnum, loctesterr, heap1, heap2, false);

    heap1.Sort();

    IsHeap(loctestnum, loctesterr, heap1, false);

    EqualLinear(loctestnum, loctesterr, heap1, heap2, false);

    lasd::HeapVec<int> heap3(heap2);

    EqualLinear(loctestnum, loctesterr, heap2, heap3, true);

    Empty(loctestnum, loctesterr, heap3, false);
    Size(loctestnum, loctesterr, heap3, true, 14);

    lasd::HeapVec<int> heap4(std::move(heap3));

    EqualLinear(loctestnum, loctesterr, heap2, heap3, false);
    EqualLinear(loctestnum, loctesterr, heap2, heap4, true);

    Empty(loctestnum, loctesterr, heap3, true);
    Size(loctestnum, loctesterr, heap3, true, 0);

    Empty(loctestnum, loctesterr, heap4, false);
    Size(loctestnum, loctesterr, heap4, true, 14);

    heap2.Sort();

    EqualLinear(loctestnum, loctesterr, heap2, heap4, false);
    EqualLinear(loctestnum, loctesterr, heap1, heap2, true);

    heap3 = heap4;

    EqualLinear(loctestnum, loctesterr, heap2, heap3, false);
    EqualLinear(loctestnum, loctesterr, heap3, heap4, true);

    heap3 = std::move(heap2);

    EqualLinear(loctestnum, loctesterr, heap2, heap3, false);
    EqualLinear(loctestnum, loctesterr, heap2, heap4, true);
    EqualLinear(loctestnum, loctesterr, heap3, heap4, false);

    TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);

    FoldPreOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<int>, 0, 69);
    FoldPostOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<int>, 0, 69);

    MapPreOrder(loctestnum, loctesterr, heap2, true, &MapInvert<int>);
    TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);

    IsHeap(loctestnum, loctesterr, heap2, false);

    FoldPreOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<int>, 0, -69);
    FoldPostOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<int>, 0, -69);

    MapPostOrder(loctestnum, loctesterr, heap2, true, &MapInvert<int>);
    TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);

    MapPostOrder(loctestnum, loctesterr, heap2, true, &MapParityInvert<int>);
    TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);

    heap2.Heapify();

    TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);

    FoldPreOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<int>, 0, -9);
    FoldPostOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<int>, 0, -9);

    MapPreOrder(loctestnum, loctesterr, heap2, true, &MapParityInvert<int>);
    TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);

    heap2.Heapify();

    TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);

    EqualLinear(loctestnum, loctesterr, heap1, heap2, false);

    heap2.Sort();

    EqualLinear(loctestnum, loctesterr, heap1, heap2, true);

    IsHeap(loctestnum, loctesterr, heap3, false);

    heap3.Heapify();

    IsHeap(loctestnum, loctesterr, heap3, true);

    heap3.Sort();

    IsHeap(loctestnum, loctesterr, heap3, false);

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Heap<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestHeapDouble(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Heap<double> Test:" << endl;
  try {

    lasd::Vector<double> vec(14);
    SetAt(loctestnum, loctesterr, vec, true, 0, 4.5);
    SetAt(loctestnum, loctesterr, vec, true, 1, 3.25);
    SetAt(loctestnum, loctesterr, vec, true, 2, 1.125);
    SetAt(loctestnum, loctesterr, vec, true, 3, 0.0);
    SetAt(loctestnum, loctesterr, vec, true, 4, 2.25);
    SetAt(loctestnum, loctesterr, vec, true, 5, 5.5);
    SetAt(loctestnum, loctesterr, vec, true, 6, 0.0);
    SetAt(loctestnum, loctesterr, vec, true, 7, 8.25);
    SetAt(loctestnum, loctesterr, vec, true, 8, 10.5);
    SetAt(loctestnum, loctesterr, vec, true, 9, 11.5);
    SetAt(loctestnum, loctesterr, vec, true, 10, 7.25);
    SetAt(loctestnum, loctesterr, vec, true, 11, 3.125);
    SetAt(loctestnum, loctesterr, vec, true, 12, 9.5);
    SetAt(loctestnum, loctesterr, vec, true, 13, 6.25);

    lasd::HeapVec<double> heap(vec);

    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<double>);
    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<double>);

    heap.Sort();

    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, heap, true, &TraversePrint<double>);

    heap.Heapify();

    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<double>);
    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<double>);

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Heap<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestHeapString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Heap<string> Test:" << endl;
  try {

    lasd::Vector<string> vec(14);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("E"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("D"));
    SetAt(loctestnum, loctesterr, vec, true, 2, string("B"));
    SetAt(loctestnum, loctesterr, vec, true, 3, string("A"));
    SetAt(loctestnum, loctesterr, vec, true, 4, string("C"));
    SetAt(loctestnum, loctesterr, vec, true, 5, string("F"));
    SetAt(loctestnum, loctesterr, vec, true, 6, string("A"));
    SetAt(loctestnum, loctesterr, vec, true, 7, string("I"));
    SetAt(loctestnum, loctesterr, vec, true, 8, string("K"));
    SetAt(loctestnum, loctesterr, vec, true, 9, string("L"));
    SetAt(loctestnum, loctesterr, vec, true, 10, string("H"));
    SetAt(loctestnum, loctesterr, vec, true, 11, string("D"));
    SetAt(loctestnum, loctesterr, vec, true, 12, string("J"));
    SetAt(loctestnum, loctesterr, vec, true, 13, string("G"));

    lasd::HeapVec<string> heap(vec);

    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);

    MapPreOrder(loctestnum, loctesterr, heap, true, [](string & str) { MapStringAppend(str, string("*")); });
    MapPreOrder(loctestnum, loctesterr, heap, true, [](string & str) { MapStringAppend(str, string(" ")); });

    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);

    FoldPostOrder(loctestnum, loctesterr, heap, true, &FoldStringConcatenate, string("?"), string("?A* B* D* D* C* A* E* G* F* H* I* J* K* L* "));
    FoldPreOrder(loctestnum, loctesterr, heap, true, &FoldStringConcatenate, string("?"), string("?L* K* J* I* H* F* G* E* A* C* D* D* B* A* "));

    heap.Sort();

    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);

    FoldPostOrder(loctestnum, loctesterr, heap, true, &FoldStringConcatenate, string("?"), string("?L* K* J* I* H* G* F* E* D* D* C* B* A* A* "));
    FoldPreOrder(loctestnum, loctesterr, heap, true, &FoldStringConcatenate, string("?"), string("?A* A* B* C* D* D* E* F* G* H* I* J* K* L* "));

    heap.Heapify();

    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);

    FoldPostOrder(loctestnum, loctesterr, heap, true, &FoldStringConcatenate, string("?"), string("?B* D* A* D* A* C* F* E* J* H* G* K* I* L* "));
    FoldPreOrder(loctestnum, loctesterr, heap, true, &FoldStringConcatenate, string("?"), string("?L* I* K* G* H* J* E* F* C* A* D* A* D* B* "));

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Heap<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void testSimpleExercise2A(uint & testnum, uint & testerr) {
  stestHeapInt(testnum, testerr);
  stestHeapDouble(testnum, testerr);
  stestHeapString(testnum, testerr);
  cout << endl << "Exercise 2A (Simple Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
