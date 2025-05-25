
#ifndef HEAPTEST_HPP
#define HEAPTEST_HPP

#include "../../heap/heap.hpp"

/* ************************************************************************** */

// Heap member functions!

template <typename Data>
void IsHeap(uint & testnum, uint & testerr, const lasd::Heap<Data> & con, bool chk) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " (" << testerr << ") The structure is" << ((tst = con.IsHeap()) ? " " : " not ") << "a heap: ";
  std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  testerr += (1 - (uint) tst);
}

// /* ************************************************************************** */

#endif
