
#ifndef ITERATORTEST_HPP
#define ITERATORTEST_HPP

#include "../../iterator/iterator.hpp"

/* ************************************************************************** */

template <typename Data>
void GetItrValue(uint & testnum, uint & testerr, const lasd::Iterator<Data> & itr, bool chk, const Data & val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The value pointed by the iterator is \"" << *itr << "\": ";
    std::cout << ((tst = ((*itr == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::out_of_range & exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void SetItrValue(uint & testnum, uint & testerr, lasd::MutableIterator<Data> & itr, bool chk, const Data & val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Setting the value pointed by the iterator to \"" << val << "\": ";
    *itr = val;
    std::cout << ((tst = ((*itr == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::out_of_range & exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void Terminated(uint & testnum, uint & testerr, const lasd::Iterator<Data> & itr, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The iterator is " << ((tst = itr.Terminated()) ? "" : "not ") << "terminated: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

/* ************************************************************************** */

#endif
