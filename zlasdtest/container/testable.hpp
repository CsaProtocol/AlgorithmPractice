
#ifndef TESTABLETEST_HPP
#define TESTABLETEST_HPP

#include "../../container/testable.hpp"

/* ************************************************************************** */

// TestableContainer member functions!

template <typename Data>
void Exists(uint & testnum, uint & testerr, const lasd::TestableContainer<Data> & con, bool chk, const Data & val) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " (" << testerr << ") Data \"" << val << "\" " << ((tst = con.Exists(val)) ? "does" : "does not") << " exist: ";
  std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  testerr += (1 - (uint) tst);
}

/* ************************************************************************** */

#endif
