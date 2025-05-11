
#ifndef LISTTEST_HPP
#define LISTTEST_HPP

#include "../../list/list.hpp"

/* ************************************************************************** */

template <typename Data>
void InsertAtFront(uint & testnum, uint & testerr, lasd::List<Data> & lst, bool chk, const Data & val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Insert at the front of the list the value \"" << val << "\": ";
    lst.InsertAtFront(val);
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void RemoveFromFront(uint & testnum, uint & testerr, lasd::List<Data> & lst, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Remove from the list of \"" << lst.Front() << "\": ";
    lst.RemoveFromFront();
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::length_error & exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void FrontNRemove(uint & testnum, uint & testerr, lasd::List<Data> & lst, bool chk, const Data & val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") FrontNRemove from the list of \"" << lst.Front() << "\": ";
    std::cout << ((tst = ((lst.FrontNRemove() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::length_error & exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void InsertAtBack(uint & testnum, uint & testerr, lasd::List<Data> & lst, bool chk, const Data & val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Insert at the back of the list the value \"" << val << "\": ";
    lst.InsertAtBack(val);
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void RemoveFromBack(uint & testnum, uint & testerr, lasd::List<Data> & lst, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Remove from the list of \"" << lst.Back() << "\": ";
    lst.RemoveFromBack();
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::length_error & exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void BackNRemove(uint & testnum, uint & testerr, lasd::List<Data> & lst, bool chk, const Data & val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") BackNRemove from the list of \"" << lst.Back() << "\": ";
    std::cout << ((tst = ((lst.BackNRemove() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::length_error & exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void EqualList(uint & testnum, uint & testerr, const lasd::List<Data> & lst1, const lasd::List<Data> & lst2, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two lists are " << ((tst = (lst1 == lst2)) ? "" : "not ") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void NonEqualList(uint & testnum, uint & testerr, const lasd::List<Data> & lst1, const lasd::List<Data> & lst2, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two lists are " << ((tst = (lst1 != lst2)) ? "not " : "") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

/* ************************************************************************** */

#endif
