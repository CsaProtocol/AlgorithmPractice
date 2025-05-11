
#include <iostream>

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/traversable.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../set/set.hpp"

#include "../../set/lst/setlst.hpp"
#include "../../set/vec/setvec.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void stestSetInt(lasd::Set<int> & set, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {

    Empty(loctestnum, loctesterr, set, false);
    Size(loctestnum, loctesterr, set, true, 7);

    GetAt(loctestnum, loctesterr, set, true, 0, 0);

    TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);

    Min(loctestnum, loctesterr, set, true, 0);
    Max(loctestnum, loctesterr, set, true, 6);

    RemoveMin(loctestnum, loctesterr, set, true);
    MinNRemove(loctestnum, loctesterr, set, true, 1);

    InsertC(loctestnum, loctesterr, set, true, -1);
    InsertC(loctestnum, loctesterr, set, true, 1);

    Min(loctestnum, loctesterr, set, true, -1);
    MaxNRemove(loctestnum, loctesterr, set, true, 6);
    Size(loctestnum, loctesterr, set, true, 6);

    InsertC(loctestnum, loctesterr, set, true, 7);

    Size(loctestnum, loctesterr, set, true, 7);

    Max(loctestnum, loctesterr, set, true, 7);

    InsertC(loctestnum, loctesterr, set, true, 8);

    Size(loctestnum, loctesterr, set, true, 8);

    Exists(loctestnum, loctesterr, set, true, 7);
    Exists(loctestnum, loctesterr, set, false, 9);
    Exists(loctestnum, loctesterr, set, false, 0);
    Exists(loctestnum, loctesterr, set, true, -1);
    Exists(loctestnum, loctesterr, set, true, 2);

    TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);

    Remove(loctestnum, loctesterr, set, false, 6);
    Remove(loctestnum, loctesterr, set, true, 2);

    TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);

    Exists(loctestnum, loctesterr, set, false, 6);
    Exists(loctestnum, loctesterr, set, false, 2);

    RemoveMax(loctestnum, loctesterr, set, true);
    Max(loctestnum, loctesterr, set, true, 7);

    TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);

    Predecessor(loctestnum, loctesterr, set, true, 4, 3);
    Predecessor(loctestnum, loctesterr, set, true, 5, 4);

    Successor(loctestnum, loctesterr, set, true, 2, 3);
    Successor(loctestnum, loctesterr, set, true, 4, 5);

    SuccessorNRemove(loctestnum, loctesterr, set, true, 0, 1);
    Min(loctestnum, loctesterr, set, true, -1);

    TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);

    PredecessorNRemove(loctestnum, loctesterr, set, true, 7, 5);
    Max(loctestnum, loctesterr, set, true, 7);

    TraversePostOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);

    FoldPreOrder(loctestnum, loctesterr, set, true, &FoldAdd<int>, 0, 13);
    FoldPostOrder(loctestnum, loctesterr, set, true, &FoldAdd<int>, 0, 13);

    TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);

    set.Clear();

    Empty(loctestnum, loctesterr, set, true);
    Size(loctestnum, loctesterr, set, true, 0);

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Set<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestSetInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Set<int> Test" << endl;
  try {
    lasd::Vector<int> vec(7);
    SetAt(loctestnum, loctesterr, vec, true, 0, 3);
    SetAt(loctestnum, loctesterr, vec, true, 1, 1);
    SetAt(loctestnum, loctesterr, vec, true, 2, 6);
    SetAt(loctestnum, loctesterr, vec, true, 3, 5);
    SetAt(loctestnum, loctesterr, vec, true, 4, 0);
    SetAt(loctestnum, loctesterr, vec, true, 5, 2);
    SetAt(loctestnum, loctesterr, vec, true, 6, 4);

    /* ********************************************************************** */

    cout << endl << "Begin of SetVec<int> Test:" << endl;
    lasd::SetVec<int> setvec(vec);
    stestSetInt(setvec, loctestnum, loctesterr);
    cout << endl << "Begin of SetLst<int> Test:" << endl;
    lasd::SetLst<int> setlst(vec);
    stestSetInt(setlst, loctestnum, loctesterr);
    cout << "\n";

    /* ********************************************************************** */

    setvec.InsertAll(vec);
    lasd::SetVec<int> setvec1(setvec);

    EqualSetVec(loctestnum, loctesterr, setvec, setvec1, true);

    Remove(loctestnum, loctesterr, setvec1, true, 4);

    NonEqualSetVec(loctestnum, loctesterr, setvec, setvec1, true);

    InsertC(loctestnum, loctesterr, setvec1, true, 4);

    EqualSetVec(loctestnum, loctesterr, setvec, setvec1, true);

    lasd::SetVec<int> setvec2 = setvec1;

    EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);

    RemovePredecessor(loctestnum, loctesterr, setvec1, true, 9);

    EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, false);

    lasd::SetVec<int> setvec3(move(setvec2));

    Empty(loctestnum, loctesterr, setvec2, true);
    Size(loctestnum, loctesterr, setvec2, true, 0);

    Empty(loctestnum, loctesterr, setvec3, false);
    Size(loctestnum, loctesterr, setvec3, true, 7);

    setvec2 = move(setvec1);

    Empty(loctestnum, loctesterr, setvec1, true);
    Size(loctestnum, loctesterr, setvec1, true, 0);

    Empty(loctestnum, loctesterr, setvec2, false);
    Size(loctestnum, loctesterr, setvec2, true, 6);

    NonEqualSetVec(loctestnum, loctesterr, setvec3, setvec2, true);

    Traverse(loctestnum, loctesterr, setvec2, true, &TraversePrint<int>);
    Traverse(loctestnum, loctesterr, setvec3, true, &TraversePrint<int>);

    InsertC(loctestnum, loctesterr, setvec2, true, 6);

    EqualSetVec(loctestnum, loctesterr, setvec3, setvec2, true);

    /* ********************************************************************** */

    setlst.InsertAll(vec);
    lasd::SetLst<int> setlst1(setlst);

    EqualSetLst(loctestnum, loctesterr, setlst, setlst1, true);

    Remove(loctestnum, loctesterr, setlst1, true, 4);

    NonEqualSetLst(loctestnum, loctesterr, setlst, setlst1, true);

    InsertC(loctestnum, loctesterr, setlst1, true, 4);

    EqualSetLst(loctestnum, loctesterr, setlst, setlst1, true);

    lasd::SetLst<int> setlst2 = setlst1;

    EqualSetLst(loctestnum, loctesterr, setlst1, setlst2, true);

    RemovePredecessor(loctestnum, loctesterr, setlst1, true, 9);

    EqualSetLst(loctestnum, loctesterr, setlst1, setlst2, false);

    lasd::SetLst<int> setlst3(move(setlst2));

    Empty(loctestnum, loctesterr, setlst2, true);
    Size(loctestnum, loctesterr, setlst2, true, 0);

    Empty(loctestnum, loctesterr, setlst3, false);
    Size(loctestnum, loctesterr, setlst3, true, 7);

    setlst2 = move(setlst1);

    Empty(loctestnum, loctesterr, setlst1, true);
    Size(loctestnum, loctesterr, setlst1, true, 0);

    Empty(loctestnum, loctesterr, setlst2, false);
    Size(loctestnum, loctesterr, setlst2, true, 6);

    NonEqualSetLst(loctestnum, loctesterr, setlst3, setlst2, true);

    Traverse(loctestnum, loctesterr, setlst2, true, &TraversePrint<int>);
    Traverse(loctestnum, loctesterr, setlst3, true, &TraversePrint<int>);

    InsertC(loctestnum, loctesterr, setlst2, true, 6);

    EqualSetLst(loctestnum, loctesterr, setlst3, setlst2, true);

    /* ********************************************************************** */

    EqualLinear(loctestnum, loctesterr, setvec3, setlst2, true);
    NonEqualLinear(loctestnum, loctesterr, setlst3, setvec2, false);

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Set<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestSetFloat(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Set<double> Test" << endl;
  try {
    lasd::List<double> lst;
    InsertAtFront(loctestnum, loctesterr, lst, true, 4.0);
    InsertAtBack(loctestnum, loctesterr, lst, true, 0.4);
    InsertAtFront(loctestnum, loctesterr, lst, true, 1.2);
    InsertAtBack(loctestnum, loctesterr, lst, true, 2.1);
    InsertAtFront(loctestnum, loctesterr, lst, true, 3.5);
    InsertAtBack(loctestnum, loctesterr, lst, true, 5.3);

    TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);

    /* ********************************************************************** */

    lasd::SetVec<double> setvec1(lst);

    Empty(loctestnum, loctesterr, setvec1, false);
    Size(loctestnum, loctesterr, setvec1, true, 6);

    TraversePreOrder(loctestnum, loctesterr, setvec1, true, &TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, setvec1, true, &TraversePrint<double>);

    lasd::SetVec<double> setvec2;

    InsertC(loctestnum, loctesterr, setvec2, true, 2.1);
    InsertC(loctestnum, loctesterr, setvec2, true, 0.4);
    InsertC(loctestnum, loctesterr, setvec2, true, 1.2);
    InsertC(loctestnum, loctesterr, setvec2, true, 3.5);
    InsertC(loctestnum, loctesterr, setvec2, true, 5.3);
    InsertC(loctestnum, loctesterr, setvec2, true, 4.0);

    EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);
    NonEqualSetVec(loctestnum, loctesterr, setvec1, setvec2, false);

    setvec1.Clear();
    setvec2.Clear();

    InsertC(loctestnum, loctesterr, setvec1, true, 0.2);
    InsertC(loctestnum, loctesterr, setvec1, true, 1.1);
    InsertC(loctestnum, loctesterr, setvec1, true, 2.1);

    InsertC(loctestnum, loctesterr, setvec2, true, 2.1);
    InsertC(loctestnum, loctesterr, setvec2, true, 1.1);
    InsertC(loctestnum, loctesterr, setvec2, true, 0.2);

    EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);
    NonEqualSetVec(loctestnum, loctesterr, setvec1, setvec2, false);

    /* ********************************************************************** */

    lasd::SetLst<double> setlst1(lst);

    Empty(loctestnum, loctesterr, setlst1, false);
    Size(loctestnum, loctesterr, setlst1, true, 6);

    TraversePreOrder(loctestnum, loctesterr, setlst1, true, &TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, setlst1, true, &TraversePrint<double>);

    lasd::SetLst<double> setlst2;

    InsertC(loctestnum, loctesterr, setlst2, true, 2.1);
    InsertC(loctestnum, loctesterr, setlst2, true, 0.4);
    InsertC(loctestnum, loctesterr, setlst2, true, 1.2);
    InsertC(loctestnum, loctesterr, setlst2, true, 3.5);
    InsertC(loctestnum, loctesterr, setlst2, true, 5.3);
    InsertC(loctestnum, loctesterr, setlst2, true, 4.0);


    EqualSetLst(loctestnum, loctesterr, setlst1, setlst2, true);
    NonEqualSetLst(loctestnum, loctesterr, setlst1, setlst2, false);

    setlst1.Clear();
    setlst2.Clear();

    InsertC(loctestnum, loctesterr, setlst1, true, 0.2);
    InsertC(loctestnum, loctesterr, setlst1, true, 1.1);
    InsertC(loctestnum, loctesterr, setlst1, true, 2.1);

    InsertC(loctestnum, loctesterr, setlst2, true, 2.1);
    InsertC(loctestnum, loctesterr, setlst2, true, 1.1);
    InsertC(loctestnum, loctesterr, setlst2, true, 0.2);

    EqualSetLst(loctestnum, loctesterr, setlst1, setlst2, true);
    NonEqualSetLst(loctestnum, loctesterr, setlst1, setlst2, false);

    /* ********************************************************************** */

    EqualLinear(loctestnum, loctesterr, setvec1, setlst2, true);
    NonEqualLinear(loctestnum, loctesterr, setlst2, setvec2, false);

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Set<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestSetString(lasd::Set<string> & set, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<string>);
    FoldPreOrder(loctestnum, loctesterr, set, true, &FoldStringConcatenate, string("?"), string("?ABCDE"));
    FoldPostOrder(loctestnum, loctesterr, set, true, &FoldStringConcatenate, string("?"), string("?EDCBA"));
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Set<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestSetString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Set<string> Test" << endl;
  try {
    lasd::Vector<string> vec(5);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("C"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("A"));
    SetAt(loctestnum, loctesterr, vec, true, 2, string("E"));
    SetAt(loctestnum, loctesterr, vec, true, 3, string("D"));
    SetAt(loctestnum, loctesterr, vec, true, 4, string("B"));

    /* ********************************************************************** */

    cout << endl << "Begin of SetVec<string> Test:" << endl;
    lasd::SetVec<string> setvec(vec);
    stestSetString(setvec, loctestnum, loctesterr);
    cout << endl << "Begin of SetLst<string> Test:" << endl;
    lasd::SetLst<string> setlst(vec);
    stestSetString(setlst, loctestnum, loctesterr);
    cout << "\n";

    /* ********************************************************************** */

    EqualLinear(loctestnum, loctesterr, setvec, setlst, true);

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Set<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void testSimpleExercise1B(uint & testnum, uint & testerr) {
  stestSetInt(testnum, testerr);
  stestSetFloat(testnum, testerr);
  stestSetString(testnum, testerr);
  cout << endl << "Exercise 1B (Simple Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
