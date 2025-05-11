
#ifndef VECTORTEST_HPP
#define VECTORTEST_HPP

#include "../../vector/vector.hpp"

/* ************************************************************************** */

template <typename Data>
void EqualVector(uint & testnum, uint & testerr, const lasd::Vector<Data> & vec1, const lasd::Vector<Data> & vec2, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two vectors are " << ((tst = (vec1 == vec2)) ? "" : "not ") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void NonEqualVector(uint & testnum, uint & testerr, const lasd::Vector<Data> & vec1, const lasd::Vector<Data> & vec2, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two vectors are " << ((tst = (vec1 != vec2)) ? "not " : "") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

/* ************************************************************************** */

#endif
