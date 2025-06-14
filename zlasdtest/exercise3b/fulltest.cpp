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

void testBinaryTreeInt(lasd::MutableBinaryTree<int> & bt, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Traverse(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    Fold(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 45);
    FoldPreOrder(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 45);
    TraversePostOrder(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    FoldPostOrder(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 45);
    TraverseInOrder(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    FoldInOrder(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 45);
    TraverseBreadth(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    FoldBreadth(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 45);
    MapBreadth(loctestnum, loctesterr, bt, true, &MapIncrement<int>);
    Fold(loctestnum, loctesterr, bt, true, &FoldMultiply<int>, 1, 3628800);
    FoldPreOrder(loctestnum, loctesterr, bt, true, &FoldMultiply<int>, 1, 3628800);
    FoldPostOrder(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 55);
    MapPostOrder(loctestnum, loctesterr, bt, true, &MapDouble<int>);
    FoldInOrder(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 110);
    TraverseBreadth(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    MapPostOrder(loctestnum, loctesterr, bt, true, &MapHalf<int>);
    MapPostOrder(loctestnum, loctesterr, bt, true, &MapParityInvert<int>);
    TraverseBreadth(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    FoldBreadth(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 5);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BinaryTree<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void testBinaryTreeInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of BinaryTree<int> Test" << endl;
  try {
    lasd::Vector<int> vec(10);
    SetAt(loctestnum, loctesterr, vec, true, 0, 9);
    SetAt(loctestnum, loctesterr, vec, true, 1, 8);
    SetAt(loctestnum, loctesterr, vec, true, 2, 7);
    SetAt(loctestnum, loctesterr, vec, true, 3, 6);
    SetAt(loctestnum, loctesterr, vec, true, 4, 5);
    SetAt(loctestnum, loctesterr, vec, true, 5, 4);
    SetAt(loctestnum, loctesterr, vec, true, 6, 3);
    SetAt(loctestnum, loctesterr, vec, true, 7, 2);
    SetAt(loctestnum, loctesterr, vec, true, 8, 1);
    SetAt(loctestnum, loctesterr, vec, true, 9, 0);

    lasd::BinaryTreeVec<int> btvec(vec);
    cout << endl << "Begin of BinaryTreeVec<int> Test:" << endl;
    testBinaryTreeInt(btvec, loctestnum, loctesterr);
    lasd::BinaryTreeLnk<int> btlnk(vec);
    cout << endl << "Begin of BinaryTreeLnk<int> Test:" << endl;
    testBinaryTreeInt(btlnk, loctestnum, loctesterr);
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

void testBinaryTreeFloat(lasd::MutableBinaryTree<double> & bt, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Traverse(loctestnum, loctesterr, bt, true, &TraversePrint<double>);
    TraversePreOrder(loctestnum, loctesterr, bt, true, &TraversePrint<double>);

    lasd::BTPreOrderMutableIterator<double> itr1(bt);
    GetItrValue(loctestnum, loctesterr, itr1, true, 4.6);
    ++itr1;++itr1;++itr1;++itr1;
    GetItrValue(loctestnum, loctesterr, itr1, true, 6.4);
    SetItrValue(loctestnum, loctesterr, itr1, true, 9.1);
    ++itr1;++itr1;
    GetItrValue(loctestnum, loctesterr, itr1, true, 5.5);
    ++itr1;++itr1;
    GetItrValue(loctestnum, loctesterr, itr1, true, 9.1);
    SetItrValue(loctestnum, loctesterr, itr1, true, 6.4);
    ++itr1;
    GetItrValue(loctestnum, loctesterr, itr1, true, 8.2);
    Terminated(loctestnum, loctesterr, itr1, false);
    ++itr1;
    Terminated(loctestnum, loctesterr, itr1, true);
    itr1.Reset();
    lasd::BTPreOrderMutableIterator<double> newitr1(move(itr1));
    Terminated(loctestnum, loctesterr, itr1, true);
    GetItrValue(loctestnum, loctesterr, itr1, false, 4.6);
    Terminated(loctestnum, loctesterr, newitr1, false);
    ++newitr1;++newitr1;++newitr1;++newitr1;
    GetItrValue(loctestnum, loctesterr, newitr1, true, 9.1);
    newitr1.Reset();
    ++newitr1;++newitr1;++newitr1;++newitr1;++newitr1;++newitr1;
    GetItrValue(loctestnum, loctesterr, newitr1, true, 5.5);
    ++newitr1;++newitr1;
    GetItrValue(loctestnum, loctesterr, newitr1, true, 6.4);
    ++newitr1;
    Terminated(loctestnum, loctesterr, newitr1, false);
    newitr1.Reset();
    itr1.Reset();

    TraverseBreadth(loctestnum, loctesterr, bt, true, &TraversePrint<double>);

    lasd::BTBreadthMutableIterator<double> itr2(bt);
    GetItrValue(loctestnum, loctesterr, itr2, true, 4.6);
    ++itr2;++itr2;++itr2;++itr2;
    GetItrValue(loctestnum, loctesterr, itr2, true, 0.0);
    SetItrValue(loctestnum, loctesterr, itr2, true, 9.1);
    ++itr2;++itr2;
    GetItrValue(loctestnum, loctesterr, itr2, true, 8.2);
    ++itr2;++itr2;
    GetItrValue(loctestnum, loctesterr, itr2, true, 9.1);
    SetItrValue(loctestnum, loctesterr, itr2, true, 0.0);
    ++itr2;
    GetItrValue(loctestnum, loctesterr, itr2, true, 5.5);
    Terminated(loctestnum, loctesterr, itr2, false);
    ++itr2;
    Terminated(loctestnum, loctesterr, itr2, true);
    itr2.Reset();
    lasd::BTBreadthMutableIterator<double> newitr2(move(itr2));
    Terminated(loctestnum, loctesterr, itr2, true);
    GetItrValue(loctestnum, loctesterr, itr2, false, 4.6);
    Terminated(loctestnum, loctesterr, newitr2, false);
    ++newitr2;++newitr2;++newitr2;++newitr2;
    GetItrValue(loctestnum, loctesterr, newitr2, true, 9.1);
    newitr2.Reset();
    ++newitr2;++newitr2;++newitr2;++newitr2;++newitr2;++newitr2;
    GetItrValue(loctestnum, loctesterr, newitr2, true, 8.2);
    ++newitr2;++newitr2;
    GetItrValue(loctestnum, loctesterr, newitr2, true, 0.0);
    ++newitr2;
    Terminated(loctestnum, loctesterr, newitr2, false);
    newitr2.Reset();
    itr2.Reset();

    TraverseInOrder(loctestnum, loctesterr, bt, true, &TraversePrint<double>);

    lasd::BTInOrderMutableIterator<double> itr3(bt);
    GetItrValue(loctestnum, loctesterr, itr3, true, 7.3);
    ++itr3;++itr3;++itr3;++itr3;
    GetItrValue(loctestnum, loctesterr, itr3, true, 5.5);
    SetItrValue(loctestnum, loctesterr, itr3, true, 2.8);
    ++itr3;++itr3;
    GetItrValue(loctestnum, loctesterr, itr3, true, 4.6);
    ++itr3;++itr3;
    GetItrValue(loctestnum, loctesterr, itr3, true, 2.8);
    SetItrValue(loctestnum, loctesterr, itr3, true, 5.5);
    ++itr3;
    GetItrValue(loctestnum, loctesterr, itr3, true, 8.2);
    Terminated(loctestnum, loctesterr, itr3, false);
    ++itr3;
    Terminated(loctestnum, loctesterr, itr3, true);
    itr3.Reset();
    lasd::BTInOrderMutableIterator<double> newitr3(move(itr3));
    Terminated(loctestnum, loctesterr, itr3, true);
    GetItrValue(loctestnum, loctesterr, itr3, false, 7.3);
    Terminated(loctestnum, loctesterr, newitr3, false);
    ++newitr3;++newitr3;++newitr3;++newitr3;
    GetItrValue(loctestnum, loctesterr, newitr3, true, 2.8);
    newitr3.Reset();
    ++newitr3;++newitr3;++newitr3;++newitr3;++newitr3;++newitr3;
    GetItrValue(loctestnum, loctesterr, newitr3, true, 4.6);
    ++newitr3;++newitr3;
    GetItrValue(loctestnum, loctesterr, newitr3, true, 5.5);
    ++newitr3;
    Terminated(loctestnum, loctesterr, newitr3, false);
    newitr3.Reset();
    itr3.Reset();

    TraversePostOrder(loctestnum, loctesterr, bt, true, &TraversePrint<double>);

    lasd::BTPostOrderMutableIterator<double> itr4(bt);
    GetItrValue(loctestnum, loctesterr, itr4, true, 7.3);
    ++itr4;++itr4;++itr4;++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, 9.1);
    SetItrValue(loctestnum, loctesterr, itr4, true, 5.5);
    ++itr4;++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, 6.4);
    ++itr4;++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, 5.5);
    SetItrValue(loctestnum, loctesterr, itr4, true, 9.1);
    ++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, 4.6);
    Terminated(loctestnum, loctesterr, itr4, false);
    ++itr4;
    Terminated(loctestnum, loctesterr, itr4, true);
    itr4.Reset();
    lasd::BTPostOrderMutableIterator<double> newitr4(move(itr4));
    Terminated(loctestnum, loctesterr, itr4, true);
    GetItrValue(loctestnum, loctesterr, itr4, false, 7.3);
    Terminated(loctestnum, loctesterr, newitr4, false);
    ++newitr4;++newitr4;++newitr4;++newitr4;
    GetItrValue(loctestnum, loctesterr, newitr4, true, 5.5);
    newitr4.Reset();
    ++newitr4;++newitr4;++newitr4;++newitr4;++newitr4;++newitr4;
    GetItrValue(loctestnum, loctesterr, newitr4, true, 6.4);
    ++newitr4;++newitr4;
    GetItrValue(loctestnum, loctesterr, newitr4, true, 9.1);
    ++newitr4;
    Terminated(loctestnum, loctesterr, newitr4, false);
    newitr4.Reset();
    itr4.Reset();

    TraversePostOrder(loctestnum, loctesterr, bt, true, &TraversePrint<double>);

    Fold(loctestnum, loctesterr, bt, true, &FoldAdd<double>, 0.0, 49.5);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BinaryTree<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void testBinaryTreeFloat(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of BinaryTree<double> Test" << endl;
  try {
    lasd::List<double> lst;
    InsertAtFront(loctestnum, loctesterr, lst, true, 0.0);
    InsertAtBack(loctestnum, loctesterr, lst, true, 9.1);
    InsertAtFront(loctestnum, loctesterr, lst, true, 1.9);
    InsertAtBack(loctestnum, loctesterr, lst, true, 8.2);
    InsertAtFront(loctestnum, loctesterr, lst, true, 2.8);
    InsertAtBack(loctestnum, loctesterr, lst, true, 7.3);
    InsertAtFront(loctestnum, loctesterr, lst, true, 3.7);
    InsertAtBack(loctestnum, loctesterr, lst, true, 6.4);
    InsertAtFront(loctestnum, loctesterr, lst, true, 4.6);
    InsertAtBack(loctestnum, loctesterr, lst, true, 5.5);

    lasd::BinaryTreeVec<double> btvec(lst);
    cout << endl << "Begin of BinaryTreeVec<double> Test:" << endl;
    testBinaryTreeFloat(btvec, loctestnum, loctesterr);
    lasd::BinaryTreeLnk<double> btlnk(lst);
    cout << endl << "Begin of BinaryTreeLnk<double> Test:" << endl;
    testBinaryTreeFloat(btlnk, loctestnum, loctesterr);
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

void testBinaryTreeString(lasd::MutableBinaryTree<string> & bt, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Traverse(loctestnum, loctesterr, bt, true, &TraversePrint<string>);
    TraversePreOrder(loctestnum, loctesterr, bt, true, &TraversePrint<string>);
    FoldPreOrder(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string("?"), string("?ABDHPQIREJKCFLMGNO"));
    TraversePostOrder(loctestnum, loctesterr, bt, true, &TraversePrint<string>);
    FoldPostOrder(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string("?"), string("?PQHRIDJKEBLMFNOGCA"));
    TraverseInOrder(loctestnum, loctesterr, bt, true, &TraversePrint<string>);
    FoldInOrder(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string("?"), string("?PHQDRIBJEKALFMCNGO"));
    TraverseBreadth(loctestnum, loctesterr, bt, true, &TraversePrint<string>);
    FoldBreadth(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string("?"), string("?ABCDEFGHIJKLMNOPQR"));
    MapInOrder(loctestnum, loctesterr, bt, true, [](string & str) { MapStringAppend(str, string("X")); });
    FoldPreOrder(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string("?"), string("?AXBXDXHXPXQXIXRXEXJXKXCXFXLXMXGXNXOX"));
    FoldPostOrder(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string("?"), string("?PXQXHXRXIXDXJXKXEXBXLXMXFXNXOXGXCXAX"));
    FoldInOrder(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string("?"), string("?PXHXQXDXRXIXBXJXEXKXAXLXFXMXCXNXGXOX"));
    FoldBreadth(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string("?"), string("?AXBXCXDXEXFXGXHXIXJXKXLXMXNXOXPXQXRX"));
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BinaryTree<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void testBinaryTreeString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of BinaryTree<string> Test" << endl;
  try {
    lasd::Vector<string> vec(18);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));
    SetAt(loctestnum, loctesterr, vec, true, 2, string("C"));
    SetAt(loctestnum, loctesterr, vec, true, 3, string("D"));
    SetAt(loctestnum, loctesterr, vec, true, 4, string("E"));
    SetAt(loctestnum, loctesterr, vec, true, 5, string("F"));
    SetAt(loctestnum, loctesterr, vec, true, 6, string("G"));
    SetAt(loctestnum, loctesterr, vec, true, 7, string("H"));
    SetAt(loctestnum, loctesterr, vec, true, 8, string("I"));
    SetAt(loctestnum, loctesterr, vec, true, 9, string("J"));
    SetAt(loctestnum, loctesterr, vec, true, 10, string("K"));
    SetAt(loctestnum, loctesterr, vec, true, 11, string("L"));
    SetAt(loctestnum, loctesterr, vec, true, 12, string("M"));
    SetAt(loctestnum, loctesterr, vec, true, 13, string("N"));
    SetAt(loctestnum, loctesterr, vec, true, 14, string("O"));
    SetAt(loctestnum, loctesterr, vec, true, 15, string("P"));
    SetAt(loctestnum, loctesterr, vec, true, 16, string("Q"));
    SetAt(loctestnum, loctesterr, vec, true, 17, string("R"));
    lasd::List<string> lst(vec);
    Size(loctestnum, loctesterr, lst, true, 18);

    cout << endl << "Begin of BinaryTreeVec<string> Test A:" << endl;
    lasd::BinaryTreeVec<string> btvec1(vec);
    testBinaryTreeString(btvec1, loctestnum, loctesterr);
    cout << endl << "Begin of BinaryTreeVec<string> Test B:" << endl;
    lasd::BinaryTreeVec<string> btvec2(lst);
    testBinaryTreeString(btvec2, loctestnum, loctesterr);
    cout << endl << "Begin of BinaryTreeLnk<string> Test A:" << endl;
    lasd::BinaryTreeLnk<string> btlnk1(vec);
    testBinaryTreeString(btlnk1, loctestnum, loctesterr);
    cout << endl << "Begin of BinaryTreeLnk<string> Test B:" << endl;
    lasd::BinaryTreeLnk<string> btlnk2(lst);
    testBinaryTreeString(btlnk2, loctestnum, loctesterr);
    cout << "\n";

    EqualBT(loctestnum, loctesterr, btvec1, btvec2);
    EqualBT(loctestnum, loctesterr, btvec1, btlnk1);
    EqualBT(loctestnum, loctesterr, btvec1, btlnk2);
    EqualBT(loctestnum, loctesterr, btvec2, btvec1);
    EqualBT(loctestnum, loctesterr, btvec2, btlnk1);
    EqualBT(loctestnum, loctesterr, btvec2, btlnk2);
    EqualBT(loctestnum, loctesterr, btlnk1, btvec1);
    EqualBT(loctestnum, loctesterr, btlnk1, btvec2);
    EqualBT(loctestnum, loctesterr, btlnk1, btlnk2);
    EqualBT(loctestnum, loctesterr, btlnk2, btvec1);
    EqualBT(loctestnum, loctesterr, btlnk2, btvec2);
    EqualBT(loctestnum, loctesterr, btlnk2, btlnk2);

    Traverse(loctestnum, loctesterr, btvec2, true, &TraversePrint<string>);
    MapPreOrder(loctestnum, loctesterr, btvec2, true, &TraversePrint<string>);
    btvec2.Root().LeftChild().RightChild().RightChild().Element() = string("S");
    TraversePreOrder(loctestnum, loctesterr, btvec2, true, &TraversePrint<string>);
    btvec2.Root().RightChild().LeftChild().RightChild().Element() = string("Z");
    TraversePreOrder(loctestnum, loctesterr, btvec2, true, &TraversePrint<string>);
    TraversePreOrder(loctestnum, loctesterr, btlnk1, true, &TraversePrint<string>);
    btlnk1.Root().LeftChild().RightChild().RightChild().Element() = string("S");
    TraversePreOrder(loctestnum, loctesterr, btlnk1, true, &TraversePrint<string>);
    btlnk1.Root().RightChild().LeftChild().RightChild().Element() = string("Z");
    TraversePreOrder(loctestnum, loctesterr, btlnk1, true, &TraversePrint<string>);

    NonEqualBT(loctestnum, loctesterr, btvec1, btvec2);
    NonEqualBT(loctestnum, loctesterr, btvec1, btlnk1);
    NonEqualBT(loctestnum, loctesterr, btvec2, btvec1);
    EqualBT(loctestnum, loctesterr, btvec2, btlnk1);
    NonEqualBT(loctestnum, loctesterr, btvec2, btlnk2);
    NonEqualBT(loctestnum, loctesterr, btlnk1, btvec1);
    EqualBT(loctestnum, loctesterr, btlnk1, btvec2);
    NonEqualBT(loctestnum, loctesterr, btlnk1, btlnk2);
    NonEqualBT(loctestnum, loctesterr, btlnk2, btvec2);
    NonEqualBT(loctestnum, loctesterr, btlnk2, btlnk1);

    btvec1.Clear();
    Empty(loctestnum, loctesterr, btvec1, true);
    Size(loctestnum, loctesterr, btvec1, true, 0);
    NonEqualBT(loctestnum, loctesterr, btvec1, btlnk2);
    btlnk2.Clear();
    Empty(loctestnum, loctesterr, btlnk2, true);
    Size(loctestnum, loctesterr, btlnk2, true, 0);
    EqualBT(loctestnum, loctesterr, btlnk2, btvec1);
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

void testFullExercise3B(uint & testnum, uint & testerr) {
  testBinaryTreeInt(testnum, testerr);
  testBinaryTreeFloat(testnum, testerr);
  testBinaryTreeString(testnum, testerr);
  cout << endl << "Exercise 3B (Full Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
