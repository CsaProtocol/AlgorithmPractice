
#include <iostream>

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

#include "../stack/stack.hpp"
#include "../../stack/vec/stackvec.hpp"
#include "../../stack/lst/stacklst.hpp"

#include "../queue/queue.hpp"
#include "../../queue/vec/queuevec.hpp"
#include "../../queue/lst/queuelst.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

template <typename Stk>
void stestStackInt(Stk & stk, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Empty(loctestnum, loctesterr, stk, true);
    Size(loctestnum, loctesterr, stk, true, 0);

    Top(loctestnum, loctesterr, stk, false, 0);
    TopNPop(loctestnum, loctesterr, stk, false, 0);

    PushC(loctestnum, loctesterr, stk, 4);
    PushC(loctestnum, loctesterr, stk, 0);
    PushC(loctestnum, loctesterr, stk, 3);
    PushC(loctestnum, loctesterr, stk, 1);
    PushC(loctestnum, loctesterr, stk, 2);

    Empty(loctestnum, loctesterr, stk, false);
    Size(loctestnum, loctesterr, stk, true, 5);

    TopNPop(loctestnum, loctesterr, stk, true, 2);
    Top(loctestnum, loctesterr, stk, true, 1);
    Top(loctestnum, loctesterr, (const Stk) stk, true, 1);

    Stk copstk(stk);
    EqualStack(loctestnum, loctesterr, stk, copstk, true);
    PushC(loctestnum, loctesterr, stk, 5);
    NonEqualStack(loctestnum, loctesterr, stk, copstk, true);

    copstk = stk;
    EqualStack(loctestnum, loctesterr, stk, copstk, true);
    PushC(loctestnum, loctesterr, copstk, 6);
    NonEqualStack(loctestnum, loctesterr, stk, copstk, true);

    Top(loctestnum, loctesterr, copstk, true, 6);
    copstk = move(stk);
    TopNPop(loctestnum, loctesterr, copstk, true, 5);
    Pop(loctestnum, loctesterr, copstk, true);
    Top(loctestnum, loctesterr, copstk, true, 3);

    Stk movstk(move(stk));
    Top(loctestnum, loctesterr, stk, false, 0);

    movstk.Clear();
    Pop(loctestnum, loctesterr, movstk, false);
    Empty(loctestnum, loctesterr, movstk, true);
    Size(loctestnum, loctesterr, movstk, true, 0);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  testnum += loctestnum;
  testerr += loctesterr;
  cout << "End of Stack<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}
void stestStackInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  lasd::StackVec<int> stkvec;
  cout << endl << "Begin of StackVec<int> Test:" << endl;
  stestStackInt(stkvec, loctestnum, loctesterr);
  lasd::StackLst<int> stklst;
  cout << endl << "Begin of StackLst<int> Test:" << endl;
  stestStackInt(stklst, loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Stk>
void stestStackFloat(Stk & stk, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    PushC(loctestnum, loctesterr, stk, 5.9);
    PushC(loctestnum, loctesterr, stk, 4.4);
    PushC(loctestnum, loctesterr, stk, 9.5);

    Empty(loctestnum, loctesterr, stk, false);
    Size(loctestnum, loctesterr, stk, true, 3);

    TopNPop(loctestnum, loctesterr, stk, true, 9.5);
    Top(loctestnum, loctesterr, stk, true, 4.4);
    Pop(loctestnum, loctesterr, stk, true);
    TopNPop(loctestnum, loctesterr, stk, true, 5.9);
    Pop(loctestnum, loctesterr, stk, false);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  testnum += loctestnum;
  testerr += loctesterr;
  cout << "End of Stack<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}
void stestStackFloat(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  lasd::StackVec<double> stkvec;
  cout << endl << "Begin of StackVec<double> Test:" << endl;
  stestStackFloat(stkvec, loctestnum, loctesterr);
  lasd::StackLst<double> stklst;
  cout << endl << "Begin of StackLst<double> Test:" << endl;
  stestStackFloat(stklst, loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Stk>
void stestStackString(Stk & stk, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    PushM(loctestnum, loctesterr, stk, string("A"));
    PushM(loctestnum, loctesterr, stk, string("B"));

    Empty(loctestnum, loctesterr, stk, false);
    Size(loctestnum, loctesterr, stk, true, 2);

    TopNPop(loctestnum, loctesterr, stk, true, string("B"));
    Top(loctestnum, loctesterr, stk, true, string("A"));
    Pop(loctestnum, loctesterr, stk, true);
    Pop(loctestnum, loctesterr, stk, false);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  testnum += loctestnum;
  testerr += loctesterr;
  cout << "End of Stack<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}
void stestStackString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  lasd::StackVec<string> stkvec;
  cout << endl << "Begin of StackVec<string> Test:" << endl;
  stestStackString(stkvec, loctestnum, loctesterr);
  lasd::StackLst<string> stklst;
  cout << endl << "Begin of StackLst<string> Test:" << endl;
  stestStackString(stklst, loctestnum, loctesterr);
  cout << endl;
  try {
    lasd::Vector<string> vec(2);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));

    PushM(loctestnum, loctesterr, stkvec, string("A"));
    PushM(loctestnum, loctesterr, stkvec, string("B"));
    lasd::StackVec<string> newstkvec(vec);
    EqualStack(loctestnum, loctesterr, stkvec, newstkvec, true);

    PushM(loctestnum, loctesterr, stklst, string("B"));
    PushM(loctestnum, loctesterr, stklst, string("A"));
    lasd::StackLst<string> newstklst(vec);
    EqualStack(loctestnum, loctesterr, stklst, newstklst, true);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestStack(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  stestStackInt(loctestnum, loctesterr);
  stestStackFloat(loctestnum, loctesterr);
  stestStackString(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
  cout << endl << "Exercise 3A - Stack (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

/* ************************************************************************** */

template <typename Que>
void stestQueueInt(Que & que, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Empty(loctestnum, loctesterr, que, true);
    Size(loctestnum, loctesterr, que, true, 0);

    Head(loctestnum, loctesterr, que, false, 0);
    HeadNDequeue(loctestnum, loctesterr, que, false, 0);

    EnqueueC(loctestnum, loctesterr, que, 4);
    EnqueueC(loctestnum, loctesterr, que, 0);
    EnqueueC(loctestnum, loctesterr, que, 3);
    EnqueueC(loctestnum, loctesterr, que, 1);
    EnqueueC(loctestnum, loctesterr, que, 2);

    Empty(loctestnum, loctesterr, que, false);
    Size(loctestnum, loctesterr, que, true, 5);

    HeadNDequeue(loctestnum, loctesterr, que, true, 4);
    Head(loctestnum, loctesterr, que, true, 0);
    Head(loctestnum, loctesterr, (const Que) que, true, 0);

    Que copque(que);
    EqualQueue(loctestnum, loctesterr, que, copque, true);
    EnqueueC(loctestnum, loctesterr, que, 5);
    NonEqualQueue(loctestnum, loctesterr, que, copque, true);

    copque = que;
    EqualQueue(loctestnum, loctesterr, que, copque, true);
    EnqueueC(loctestnum, loctesterr, copque, 6);
    NonEqualQueue(loctestnum, loctesterr, que, copque, true);

    Head(loctestnum, loctesterr, copque, true, 0);
    copque = move(que);
    HeadNDequeue(loctestnum, loctesterr, copque, true, 0);
    Dequeue(loctestnum, loctesterr, copque, true);
    Head(loctestnum, loctesterr, copque, true, 1);

    Que movque(move(que));
    Head(loctestnum, loctesterr, que, false, 0);

    movque.Clear();
    Dequeue(loctestnum, loctesterr, movque, false);
    Empty(loctestnum, loctesterr, movque, true);
    Size(loctestnum, loctesterr, movque, true, 0);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  testnum += loctestnum;
  testerr += loctesterr;
  cout << "End of Queue<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}
void stestQueueInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  lasd::QueueVec<int> quevec;
  cout << endl << "Begin of QueueVec<int> Test:" << endl;
  stestQueueInt(quevec, loctestnum, loctesterr);
  lasd::QueueLst<int> quelst;
  cout << endl << "Begin of QueueLst<int> Test:" << endl;
  stestQueueInt(quelst, loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Que>
void stestQueueFloat(Que & que, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    EnqueueC(loctestnum, loctesterr, que, 5.9);
    EnqueueC(loctestnum, loctesterr, que, 4.4);
    EnqueueC(loctestnum, loctesterr, que, 9.5);

    Empty(loctestnum, loctesterr, que, false);
    Size(loctestnum, loctesterr, que, true, 3);

    HeadNDequeue(loctestnum, loctesterr, que, true, 5.9);
    Head(loctestnum, loctesterr, que, true, 4.4);
    Dequeue(loctestnum, loctesterr, que, true);
    HeadNDequeue(loctestnum, loctesterr, que, true, 9.5);
    Dequeue(loctestnum, loctesterr, que, false);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  testnum += loctestnum;
  testerr += loctesterr;
  cout << "End of Queue<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}
void stestQueueFloat(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  lasd::QueueVec<double> quevec;
  cout << endl << "Begin of QueueVec<double> Test:" << endl;
  stestQueueFloat(quevec, loctestnum, loctesterr);
  lasd::QueueLst<double> quelst;
  cout << endl << "Begin of QueueLst<double> Test:" << endl;
  stestQueueFloat(quelst, loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Que>
void stestQueueString(Que & que, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    EnqueueM(loctestnum, loctesterr, que, string("A"));
    EnqueueM(loctestnum, loctesterr, que, string("B"));

    Empty(loctestnum, loctesterr, que, false);
    Size(loctestnum, loctesterr, que, true, 2);

    HeadNDequeue(loctestnum, loctesterr, que, true, string("A"));
    Head(loctestnum, loctesterr, que, true, string("B"));
    Dequeue(loctestnum, loctesterr, que, true);
    Dequeue(loctestnum, loctesterr, que, false);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  testnum += loctestnum;
  testerr += loctesterr;
  cout << "End of Queue<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}
void stestQueueString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  lasd::QueueVec<string> quevec;
  cout << endl << "Begin of QueueVec<string> Test:" << endl;
  stestQueueString(quevec, loctestnum, loctesterr);
  lasd::QueueLst<string> quelst;
  cout << endl << "Begin of QueueLst<string> Test:" << endl;
  stestQueueString(quelst, loctestnum, loctesterr);
  cout << endl;
  try {
    lasd::Vector<string> vec(2);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));

    EnqueueM(loctestnum, loctesterr, quevec, string("A"));
    EnqueueM(loctestnum, loctesterr, quevec, string("B"));
    lasd::QueueVec<string> newquevec(vec);
    EqualQueue(loctestnum, loctesterr, quevec, newquevec, true);

    EnqueueM(loctestnum, loctesterr, quelst, string("A"));
    EnqueueM(loctestnum, loctesterr, quelst, string("B"));
    lasd::QueueLst<string> newquelst(vec);
    EqualQueue(loctestnum, loctesterr, quelst, newquelst, true);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestQueue(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  stestQueueInt(loctestnum, loctesterr);
  stestQueueFloat(loctestnum, loctesterr);
  stestQueueString(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
  cout << endl << "Exercise 3A - Queue (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

/* ************************************************************************** */

void testSimpleExercise3A(uint & testnum, uint & testerr) {
  stestStack(testnum, testerr);
  stestQueue(testnum, testerr);
  cout << endl << "Exercise 3A (Simple Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
