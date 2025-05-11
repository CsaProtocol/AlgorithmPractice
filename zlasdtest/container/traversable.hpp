
#ifndef TRAVERSABLETEST_HPP
#define TRAVERSABLETEST_HPP

#include "../../container/traversable.hpp"

/* ************************************************************************** */

// TraversableContainer member functions!

template <typename Data>
void Traverse(uint & testnum, uint & testerr, const lasd::TraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::TraverseFun fun) {
  bool tst = true;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing traverse - ";
    con.Traverse(fun);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data, typename Value>
void Fold(uint & testnum, uint & testerr, const lasd::TraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::FoldFun<Value> fun, const Value & inival, const Value & finval) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing fold - ";
    Value val = con.Fold(fun, inival);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void TraversePrint(const Data & dat) {
  std::cout << dat << " ";
}

template <typename Data>
Data FoldAdd(const Data & dat, const Data & acc) {
  return (acc + dat);
}

template <typename Data>
Data FoldMultiply(const Data & dat, const Data & acc) {
  return (acc * dat);
}

int FoldParity(const int &, const int &);

std::string FoldStringConcatenate(const std::string &, const std::string &);

/* ************************************************************************** */

// PreOrderTraversableContainer member functions!

template <typename Data>
void TraversePreOrder(uint & testnum, uint & testerr, const lasd::PreOrderTraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::TraverseFun fun) {
  bool tst = true;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing traverse in pre order - ";
    con.PreOrderTraverse(fun);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data, typename Value>
void FoldPreOrder(uint & testnum, uint & testerr, const lasd::PreOrderTraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::FoldFun<Value> fun, const Value & inival, const Value & finval) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing fold in pre order - ";
    Value val = con.PreOrderFold(fun, inival);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

/* ************************************************************************** */

// PostOrderTraversableContainer member functions!

template <typename Data>
void TraversePostOrder(uint & testnum, uint & testerr, const lasd::PostOrderTraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::TraverseFun fun) {
  bool tst = true;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing traverse in post order - ";
    con.PostOrderTraverse(fun);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data, typename Value>
void FoldPostOrder(uint & testnum, uint & testerr, const lasd::PostOrderTraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::FoldFun<Value> fun, const Value & inival, const Value & finval) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing fold in post order - ";
    Value val = con.PostOrderFold(fun, inival);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

/* ************************************************************************** */

#endif
