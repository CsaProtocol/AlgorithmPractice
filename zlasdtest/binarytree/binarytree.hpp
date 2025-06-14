
#ifndef BINARYTREETEST_HPP
#define BINARYTREETEST_HPP

#include "../../binarytree/binarytree.hpp"

/* ************************************************************************** */

template <typename Data>
void GetElement(uint & testnum, uint & testerr, const typename lasd::BinaryTree<Data>::Node & nod, bool chk, const Data & val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The data of the node is \"" << nod.Element() << "\": ";
    std::cout << ((tst = ((nod.Element() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void SetElement(uint & testnum, uint & testerr, typename lasd::MutableBinaryTree<Data>::MutableNode & nod, bool chk, const Data & val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Setting the data of the node to \"" << val << "\": ";
    nod.Element() = val;
    std::cout << ((tst = ((nod.Element() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void IsLeaf(uint & testnum, uint & testerr, const typename lasd::BinaryTree<Data>::Node & nod, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The node is " << ((tst = nod.IsLeaf()) ? "" : "not ") << "a leaf: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void HasLeftChild(uint & testnum, uint & testerr, const typename lasd::BinaryTree<Data>::Node & nod, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The node does " << ((tst = nod.HasLeftChild()) ? "" : "not ") << "have a left child: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void HasRightChild(uint & testnum, uint & testerr, const typename lasd::BinaryTree<Data>::Node & nod, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The node does " << ((tst = nod.HasRightChild()) ? "" : "not ") << "have a right child: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

/* ************************************************************************** */

template <typename Data>
void EqualBT(uint & testnum, uint & testerr, const lasd::BinaryTree<Data> & bt1, const lasd::BinaryTree<Data> & bt2) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two binary trees are " << ((tst = (bt1 == bt2)) ? "" : "not ") << "equal: ";
    std::cout << (tst ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void NonEqualBT(uint & testnum, uint & testerr, const lasd::BinaryTree<Data> & bt1, const lasd::BinaryTree<Data> & bt2) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two binary trees are " << ((tst = (bt1 != bt2)) ? "not " : "") << "equal: ";
    std::cout << (tst ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

/* ************************************************************************** */

template <typename Data>
void Root(uint & testnum, uint & testerr, const lasd::BinaryTree<Data> & bt, bool chk, const Data & val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Root of the tree with value \"" << bt.Root().Element() << "\": ";
    std::cout << ((tst = ((bt.Root().Element() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::length_error & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

/* ************************************************************************** */

#endif
