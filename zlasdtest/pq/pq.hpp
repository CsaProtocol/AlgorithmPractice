
#ifndef PQTEST_HPP
#define PQTEST_HPP

#include "../../pq/pq.hpp"

/* ************************************************************************** */

// PQ member functions!

template <typename Data>
void Tip(uint & testnum, uint & testerr, lasd::PQ<Data> & pq, bool chk, const Data & val) {
  testnum++;
  bool tst;
  try {
    std::cout << " " << testnum << " Tip of the priority queue with value \"" << pq.Tip() << "\": ";
    std::cout << ((tst = ((pq.Tip() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::length_error & exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void RemoveTip(uint & testnum, uint & testerr, lasd::PQ<Data> & pq, bool chk) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " Remove tip from the priority queue: ";
    pq.RemoveTip();
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::length_error & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void TipNRemove(uint & testnum, uint & testerr, lasd::PQ<Data> & pq, bool chk, const Data & val) {
  testnum++;
  bool tst;
  try {
    std::cout << " " << testnum << " TipNRemove from the priority queue with value \"" << pq.Tip() << "\": ";
    std::cout << ((tst = ((pq.TipNRemove() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::length_error & exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void Insert(uint & testnum, uint & testerr, lasd::PQ<Data> & pq, const Data & val) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " Insert on the priority queue of the value \"" << val << "\": ";
    pq.Insert(val);
    std::cout << "Correct!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
    tst = false;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void Change(uint & testnum, uint & testerr, lasd::PQ<Data> & pq, bool chk, ulong idx, const Data & val) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " Change the value \"" << pq[idx] << "\" at index << \"" << idx << "\" to the value \"" << val << "\" in the priority queue: ";
    pq.Change(idx, val);
    std::cout << (chk ? "Correct" : "Error") << "!" << std::endl;
    tst = chk;
  }
  catch (std::exception & exc) {
    std::cout << exc.what() << "\": " << (!chk ? "Correct" : "Error") << "!" << std::endl;
    tst = !chk;
  }
  testerr += (1 - (uint) tst);
}

/* ************************************************************************** */

#endif
