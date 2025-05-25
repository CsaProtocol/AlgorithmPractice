
#include <iostream>

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"

#include "../pq/pq.hpp"

#include "../../pq/pq.hpp"
#include "../../pq/heap/pqheap.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void stestPQInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of PQ<int> Test:" << endl;
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

    lasd::PQHeap<int> pq(vec);

    Traverse(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    Tip(loctestnum, loctesterr, pq, true, 11);
    RemoveTip(loctestnum, loctesterr, pq, true);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    Tip(loctestnum, loctesterr, pq, true, 10);
    RemoveTip(loctestnum, loctesterr, pq, true);
    TipNRemove(loctestnum, loctesterr, pq, true, 9);
    TipNRemove(loctestnum, loctesterr, pq, true, 8);
    TipNRemove(loctestnum, loctesterr, pq, true, 7);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    Insert(loctestnum, loctesterr, pq, 5);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    Tip(loctestnum, loctesterr, pq, true, 6);
    RemoveTip(loctestnum, loctesterr, pq, true);
    TipNRemove(loctestnum, loctesterr, pq, true, 5);
    TipNRemove(loctestnum, loctesterr, pq, true, 5);
    TipNRemove(loctestnum, loctesterr, pq, true, 4);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    Insert(loctestnum, loctesterr, pq, 3);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    TipNRemove(loctestnum, loctesterr, pq, true, 3);
    TipNRemove(loctestnum, loctesterr, pq, true, 3);
    TipNRemove(loctestnum, loctesterr, pq, true, 3);
    Tip(loctestnum, loctesterr, pq, true, 2);
    RemoveTip(loctestnum, loctesterr, pq, true);
    TipNRemove(loctestnum, loctesterr, pq, true, 1);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    Insert(loctestnum, loctesterr, pq, 10);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    TipNRemove(loctestnum, loctesterr, pq, true, 10);
    TipNRemove(loctestnum, loctesterr, pq, true, 0);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    Insert(loctestnum, loctesterr, pq, 8);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    Exists(loctestnum, loctesterr, pq, true, 8);
    Exists(loctestnum, loctesterr, pq, false, 12);

    GetAt(loctestnum, loctesterr, pq, true, 0, 8);

    TipNRemove(loctestnum, loctesterr, pq, true, 8);
    TipNRemove(loctestnum, loctesterr, pq, true, 0);
    RemoveTip(loctestnum, loctesterr, pq, false);

    Insert(loctestnum, loctesterr, pq, 7);
    Insert(loctestnum, loctesterr, pq, 6);
    Insert(loctestnum, loctesterr, pq, 5);
    Insert(loctestnum, loctesterr, pq, 4);
    Insert(loctestnum, loctesterr, pq, 3);
    Insert(loctestnum, loctesterr, pq, 2);
    Insert(loctestnum, loctesterr, pq, 1);
    Insert(loctestnum, loctesterr, pq, 0);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    Change(loctestnum, loctesterr, pq, 0, 8);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    Insert(loctestnum, loctesterr, pq, 1);
    Insert(loctestnum, loctesterr, pq, 0);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    Change(loctestnum, loctesterr, pq, 1, 2);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    Change(loctestnum, loctesterr, pq, 6, 6);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    Change(loctestnum, loctesterr, pq, 8, 10);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

    FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldAdd<int>, 0, 40);
    FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldAdd<int>, 0, 40);

    Empty(loctestnum, loctesterr, pq, false);
    Size(loctestnum, loctesterr, pq, true, 10);

    lasd::PQHeap<int> pq1(std::move(pq));

    Empty(loctestnum, loctesterr, pq, true);
    Size(loctestnum, loctesterr, pq, true, 0);

    Empty(loctestnum, loctesterr, pq1, false);
    Size(loctestnum, loctesterr, pq1, true, 10);

    EqualLinear(loctestnum, loctesterr, pq, pq1, false);

    TipNRemove(loctestnum, loctesterr, pq1, true, 10);
    TipNRemove(loctestnum, loctesterr, pq1, true, 8);
    Insert(loctestnum, loctesterr, pq1, 11);
    TipNRemove(loctestnum, loctesterr, pq1, true, 11);

    EqualLinear(loctestnum, loctesterr, pq, pq1, false);

    Empty(loctestnum, loctesterr, pq1, false);
    Size(loctestnum, loctesterr, pq1, true, 8);

    pq = pq1;

    EqualLinear(loctestnum, loctesterr, pq, pq1, true);

    lasd::PQHeap<int> pq2(pq);

    EqualLinear(loctestnum, loctesterr, pq1, pq2, true);

    TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);

    TipNRemove(loctestnum, loctesterr, pq2, true, 6);

    TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);

    Change(loctestnum, loctesterr, pq2, 0, -1);

    TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);

    TipNRemove(loctestnum, loctesterr, pq2, true, 4);

    Empty(loctestnum, loctesterr, pq1, false);
    Size(loctestnum, loctesterr, pq1, true, 8);

    pq2 = std::move(pq1);

    Empty(loctestnum, loctesterr, pq1, false);
    Size(loctestnum, loctesterr, pq1, true, 6);

    Empty(loctestnum, loctesterr, pq2, false);
    Size(loctestnum, loctesterr, pq2, true, 8);

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of PQ<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestPQDouble(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of PQ<double> Test:" << endl;
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

    lasd::PQHeap<double> pq(vec);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);

    Tip(loctestnum, loctesterr, pq, true, 11.5);
    RemoveTip(loctestnum, loctesterr, pq, true);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);

    Tip(loctestnum, loctesterr, pq, true, 10.5);
    RemoveTip(loctestnum, loctesterr, pq, true);
    TipNRemove(loctestnum, loctesterr, pq, true, 9.5);
    TipNRemove(loctestnum, loctesterr, pq, true, 8.25);
    TipNRemove(loctestnum, loctesterr, pq, true, 7.25);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);

    Insert(loctestnum, loctesterr, pq, 5.25);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);

    Change(loctestnum, loctesterr, pq, 4, -1.0);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);

    Change(loctestnum, loctesterr, pq, 2, 12.0);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of PQ<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestPQString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of PQ<string> Test:" << endl;
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

    lasd::PQHeap<string> pq(vec);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);

    FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?LKJIHFGEACDDBA"));
    FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?ABDDCAEGFHIJKL"));

    Tip(loctestnum, loctesterr, pq, true, string("L"));
    RemoveTip(loctestnum, loctesterr, pq, true);

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);

    Tip(loctestnum, loctesterr, pq, true, string("K"));
    RemoveTip(loctestnum, loctesterr, pq, true);
    Insert(loctestnum, loctesterr, pq, string("J"));
    Insert(loctestnum, loctesterr, pq, string("K"));
    TipNRemove(loctestnum, loctesterr, pq, true, string("K"));
    TipNRemove(loctestnum, loctesterr, pq, true, string("J"));
    TipNRemove(loctestnum, loctesterr, pq, true, string("J"));

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);

    FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?IHGEDFBAACD"));
    FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?DCAABFDEGHI"));

    Insert(loctestnum, loctesterr, pq, string("F"));

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);

    FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?IHGEDFBAACDF"));
    FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?FDCAABFDEGHI"));

    Change(loctestnum, loctesterr, pq, 4, string("X"));

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);

    FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?XIGEHFBAACDF"));
    FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?FDCAABFHEGIX"));

    Change(loctestnum, loctesterr, pq, 1, string("A"));

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);

    FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?XHGEDFBAACAF"));
    FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?FACAABFDEGHX"));

    Change(loctestnum, loctesterr, pq, 2, string("B"));

    TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);

    FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?XHFEDFBAACAB"));
    FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?BACAABFDEFHX"));

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of PQ<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void testSimpleExercise2B(uint & testnum, uint & testerr) {
  stestPQInt(testnum, testerr);
  stestPQDouble(testnum, testerr);
  stestPQString(testnum, testerr);
  cout << endl << "Exercise 2B (Simple Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
