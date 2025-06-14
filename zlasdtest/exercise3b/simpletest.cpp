#include <iostream>

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../iterator/iterator.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"

#include "../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void stestBinaryTreeInt(lasd::BinaryTree<int>& bt, uint& testnum, uint& testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Traverse(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    Fold(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 6);
    FoldPreOrder(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 6);
    FoldPostOrder(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 6);
    FoldInOrder(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 6);
    FoldBreadth(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 6);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BinaryTree<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestBinaryTreeInt(uint& testnum, uint& testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of BinaryTree<int> Test" << endl;
  try {
    lasd::Vector<int> vec(4);
    SetAt(loctestnum, loctesterr, vec, true, 0, 0);
    SetAt(loctestnum, loctesterr, vec, true, 1, 1);
    SetAt(loctestnum, loctesterr, vec, true, 2, 2);
    SetAt(loctestnum, loctesterr, vec, true, 3, 3);

    lasd::BinaryTreeVec<int> btvec(vec);
    cout << endl << "Begin of BinaryTreeVec<int> Test:" << endl;
    stestBinaryTreeInt(btvec, loctestnum, loctesterr);
    lasd::BinaryTreeLnk<int> btlnk(vec);
    cout << endl << "Begin of BinaryTreeLnk<int> Test:" << endl;
    stestBinaryTreeInt(btlnk, loctestnum, loctesterr);
    cout << "\n";

    lasd::BinaryTreeVec<int> copbtvec(btvec);
    EqualBT(loctestnum, loctesterr, copbtvec, btvec);
    btvec.Clear();
    btvec = move(copbtvec);
    NonEqualBT(loctestnum, loctesterr, copbtvec, btvec);
    Empty(loctestnum, loctesterr, copbtvec, true);

    lasd::BinaryTreeLnk<int> copbtlnk(btlnk);
    EqualBT(loctestnum, loctesterr, copbtlnk, btlnk);
    btlnk.Clear();
    btlnk = move(copbtlnk);
    NonEqualBT(loctestnum, loctesterr, copbtlnk, btlnk);
    Empty(loctestnum, loctesterr, copbtlnk, true);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BinaryTree<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestBinaryTreeFloat(lasd::MutableBinaryTree<double>& bt, uint& testnum, uint& testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    lasd::BTPreOrderIterator<double> itr1(bt);
    GetItrValue(loctestnum, loctesterr, itr1, true, 1.2);
    ++itr1;
    GetItrValue(loctestnum, loctesterr, itr1, true, 0.3);
    ++itr1;
    GetItrValue(loctestnum, loctesterr, itr1, true, 2.1);
    ++itr1;
    GetItrValue(loctestnum, loctesterr, itr1, true, 3.0);
    ++itr1;
    Terminated(loctestnum, loctesterr, itr1, true);
    itr1.Reset();
    Terminated(loctestnum, loctesterr, itr1, false);
    ++itr1;
    GetItrValue(loctestnum, loctesterr, itr1, true, 0.3);
    itr1.Reset();
    lasd::BTPreOrderIterator<double> newitr1(move(itr1));
    itr1.Reset();

    lasd::BTBreadthIterator<double> itr2(bt);
    GetItrValue(loctestnum, loctesterr, itr2, true, 1.2);
    ++itr2;
    GetItrValue(loctestnum, loctesterr, itr2, true, 0.3);
    ++itr2;
    GetItrValue(loctestnum, loctesterr, itr2, true, 3.0);
    ++itr2;
    GetItrValue(loctestnum, loctesterr, itr2, true, 2.1);
    ++itr2;
    Terminated(loctestnum, loctesterr, itr2, true);
    itr2.Reset();
    Terminated(loctestnum, loctesterr, itr2, false);
    ++itr2;
    GetItrValue(loctestnum, loctesterr, itr2, true, 0.3);
    itr2.Reset();
    lasd::BTBreadthIterator<double> newitr2(move(itr2));
    itr2.Reset();

    lasd::BTInOrderIterator<double> itr3(bt);
    GetItrValue(loctestnum, loctesterr, itr3, true, 2.1);
    ++itr3;
    GetItrValue(loctestnum, loctesterr, itr3, true, 0.3);
    ++itr3;
    GetItrValue(loctestnum, loctesterr, itr3, true, 1.2);
    ++itr3;
    GetItrValue(loctestnum, loctesterr, itr3, true, 3.0);
    ++itr3;
    Terminated(loctestnum, loctesterr, itr3, true);
    itr3.Reset();
    Terminated(loctestnum, loctesterr, itr3, false);
    ++itr3;
    GetItrValue(loctestnum, loctesterr, itr3, true, 0.3);
    itr3.Reset();
    lasd::BTInOrderIterator<double> newitr3(move(itr3));
    itr3.Reset();

    lasd::BTPostOrderIterator<double> itr4(bt);
    GetItrValue(loctestnum, loctesterr, itr4, true, 2.1);
    ++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, 0.3);
    ++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, 3.0);
    ++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, 1.2);
    ++itr4;
    Terminated(loctestnum, loctesterr, itr4, true);
    itr4.Reset();
    Terminated(loctestnum, loctesterr, itr4, false);
    ++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, 0.3);
    itr4.Reset();
    lasd::BTPostOrderIterator<double> newitr4(move(itr4));
    itr4.Reset();
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BinaryTree<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestBinaryTreeFloat(uint& testnum, uint& testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of BinaryTree<double> Test" << endl;
  try {
    lasd::List<double> lst;
    InsertAtFront(loctestnum, loctesterr, lst, true, 0.3);
    InsertAtBack(loctestnum, loctesterr, lst, true, 3.0);
    InsertAtFront(loctestnum, loctesterr, lst, true, 1.2);
    InsertAtBack(loctestnum, loctesterr, lst, true, 2.1);

    lasd::BinaryTreeVec<double> btvec(lst);
    cout << endl << "Begin of BinaryTreeVec<double> Test:" << endl;
    stestBinaryTreeFloat(btvec, loctestnum, loctesterr);
    lasd::BinaryTreeLnk<double> btlnk(lst);
    cout << endl << "Begin of BinaryTreeLnk<double> Test:" << endl;
    stestBinaryTreeFloat(btlnk, loctestnum, loctesterr);
    cout << "\n";

    lasd::BinaryTreeVec<double> copbtvec(move(btvec));
    Empty(loctestnum, loctesterr, btvec, true);
    NonEqualBT(loctestnum, loctesterr, copbtvec, btvec);
    btvec = copbtvec;
    EqualBT(loctestnum, loctesterr, copbtvec, btvec);

    lasd::BinaryTreeLnk<double> copbtlnk(move(btlnk));
    Empty(loctestnum, loctesterr, btlnk, true);
    NonEqualBT(loctestnum, loctesterr, copbtlnk, btlnk);
    btlnk = copbtlnk;
    EqualBT(loctestnum, loctesterr, copbtlnk, btlnk);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BinaryTree<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestBinaryTreeString(lasd::BinaryTree<string>& bt, uint& testnum, uint& testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    TraversePreOrder(loctestnum, loctesterr, bt, true, &TraversePrint<string>);
    FoldPreOrder(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string("?"), string("?ABDC"));
    FoldPostOrder(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string("?"), string("?DBCA"));
    FoldInOrder(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string("?"), string("?DBAC"));
    FoldBreadth(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string("?"), string("?ABCD"));
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BinaryTree<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestBinaryTreeString(uint& testnum, uint& testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of BinaryTree<string> Test" << endl;
  try {
    lasd::Vector<string> vec(4);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));
    SetAt(loctestnum, loctesterr, vec, true, 2, string("C"));
    SetAt(loctestnum, loctesterr, vec, true, 3, string("D"));

    cout << endl << "Begin of BinaryTreeVec<string> Test:" << endl;
    lasd::BinaryTreeVec<string> btvec(vec);
    stestBinaryTreeString(btvec, loctestnum, loctesterr);
    cout << endl << "Begin of BinaryTreeVec<string> Test:" << endl;
    lasd::BinaryTreeLnk<string> btlnk(vec);
    stestBinaryTreeString(btlnk, loctestnum, loctesterr);
    cout << "\n";

    EqualBT(loctestnum, loctesterr, btvec, btlnk);
    btvec.Root().LeftChild().LeftChild().Element() = string("S");
    NonEqualBT(loctestnum, loctesterr, btlnk, btvec);
    btlnk.Root().RightChild().Element() = string("X");
    NonEqualBT(loctestnum, loctesterr, btvec, btlnk);
    btvec.Root().RightChild().Element() = string("X");
    btlnk.Root().LeftChild().LeftChild().Element() = string("S");
    EqualBT(loctestnum, loctesterr, btlnk, btvec);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BinaryTree<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void testSimpleExercise3B(uint& testnum, uint& testerr) {
  stestBinaryTreeInt(testnum, testerr);
  stestBinaryTreeFloat(testnum, testerr);
  stestBinaryTreeString(testnum, testerr);
  cout << endl << "Exercise 3B (Simple Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
