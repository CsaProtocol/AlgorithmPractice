
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
void testStackInt(Stk & stk, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Empty(loctestnum, loctesterr, stk, true);
    Size(loctestnum, loctesterr, stk, true, 0);

    Top(loctestnum, loctesterr, stk, false, 0);
    TopNPop(loctestnum, loctesterr, stk, false, 0);

    PushC(loctestnum, loctesterr, stk, 9);
    PushC(loctestnum, loctesterr, stk, 0);
    PushC(loctestnum, loctesterr, stk, 8);
    PushC(loctestnum, loctesterr, stk, 1);
    PushC(loctestnum, loctesterr, stk, 7);
    PushC(loctestnum, loctesterr, stk, 2);
    PushC(loctestnum, loctesterr, stk, 6);
    PushC(loctestnum, loctesterr, stk, 3);
    PushC(loctestnum, loctesterr, stk, 5);
    PushC(loctestnum, loctesterr, stk, 4);

    Empty(loctestnum, loctesterr, stk, false);
    Size(loctestnum, loctesterr, stk, true, 10);

    TopNPop(loctestnum, loctesterr, stk, true, 4);
    Top(loctestnum, loctesterr, stk, true, 5);
    Top(loctestnum, loctesterr, (const Stk) stk, true, 5);

    Stk copstk(stk);
    EqualStack(loctestnum, loctesterr, stk, copstk, true);
    PushC(loctestnum, loctesterr, stk, 10);
    NonEqualStack(loctestnum, loctesterr, stk, copstk, true);

    copstk = stk;
    EqualStack(loctestnum, loctesterr, stk, copstk, true);
    PushC(loctestnum, loctesterr, stk, 11);
    NonEqualStack(loctestnum, loctesterr, stk, copstk, true);

    Top(loctestnum, loctesterr, copstk, true, 10);
    copstk = move(stk);
    TopNPop(loctestnum, loctesterr, copstk, true, 11);
    Pop(loctestnum, loctesterr, copstk, true);
    Top(loctestnum, loctesterr, copstk, true, 5);
    Top(loctestnum, loctesterr, (const Stk) copstk, true, 5);

    Stk movstk(move(stk));
    Top(loctestnum, loctesterr, stk, false, 0);

    movstk.Clear();
    Pop(loctestnum, loctesterr, movstk, false);
    Empty(loctestnum, loctesterr, movstk, true);
    Size(loctestnum, loctesterr, movstk, true, 0);

    PushC(loctestnum, loctesterr, movstk, 5);
    TopNPop(loctestnum, loctesterr, movstk, true, 5);
    PushC(loctestnum, loctesterr, movstk, 1);
    PushC(loctestnum, loctesterr, movstk, 3);
    TopNPop(loctestnum, loctesterr, movstk, true, 3);
    PushC(loctestnum, loctesterr, movstk, 1);
    PushC(loctestnum, loctesterr, movstk, 7);
    TopNPop(loctestnum, loctesterr, movstk, true, 7);
    PushC(loctestnum, loctesterr, movstk, 1);
    PushC(loctestnum, loctesterr, movstk, 4);
    TopNPop(loctestnum, loctesterr, movstk, true, 4);
    PushC(loctestnum, loctesterr, movstk, 1);
    PushC(loctestnum, loctesterr, movstk, 1);
    TopNPop(loctestnum, loctesterr, movstk, true, 1);
    TopNPop(loctestnum, loctesterr, movstk, true, 1);
    TopNPop(loctestnum, loctesterr, movstk, true, 1);
    TopNPop(loctestnum, loctesterr, movstk, true, 1);
    PushC(loctestnum, loctesterr, movstk, 8);
    TopNPop(loctestnum, loctesterr, movstk, true, 8);
    TopNPop(loctestnum, loctesterr, movstk, true, 1);
    PushC(loctestnum, loctesterr, movstk, 2);
    PushC(loctestnum, loctesterr, movstk, 4);
    TopNPop(loctestnum, loctesterr, movstk, true, 4);
    PushC(loctestnum, loctesterr, movstk, 6);
    TopNPop(loctestnum, loctesterr, movstk, true, 6);
    TopNPop(loctestnum, loctesterr, movstk, true, 2);
    PushC(loctestnum, loctesterr, movstk, 2);
    PushC(loctestnum, loctesterr, movstk, 2);
    TopNPop(loctestnum, loctesterr, movstk, true, 2);
    TopNPop(loctestnum, loctesterr, movstk, true, 2);

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
void testStackInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  lasd::StackVec<int> stkvec;
  cout << endl << "Begin of StackVec<int> Test:" << endl;
  testStackInt(stkvec, loctestnum, loctesterr);
  lasd::StackLst<int> stklst;
  cout << endl << "Begin of StackLst<int> Test:" << endl;
  testStackInt(stklst, loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Stk>
void testStackFloat(Stk & stk, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Empty(loctestnum, loctesterr, stk, true);
    Size(loctestnum, loctesterr, stk, true, 0.0);

    Top(loctestnum, loctesterr, stk, false, 0.0);
    TopNPop(loctestnum, loctesterr, stk, false, 0.0);

    PushC(loctestnum, loctesterr, stk, 5.5);
    PushC(loctestnum, loctesterr, stk, 4.4);
    PushC(loctestnum, loctesterr, stk, 9.9);
    PushC(loctestnum, loctesterr, stk, 1.1);

    Empty(loctestnum, loctesterr, stk, false);
    Size(loctestnum, loctesterr, stk, true, 4);

    TopNPop(loctestnum, loctesterr, stk, true, 1.1);
    Top(loctestnum, loctesterr, stk, true, 9.9);
    Pop(loctestnum, loctesterr, stk, true);
    Pop(loctestnum, loctesterr, stk, true);
    TopNPop(loctestnum, loctesterr, stk, true, 5.5);
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
void testStackFloat(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  lasd::StackVec<double> stkvec;
  cout << endl << "Begin of StackVec<double> Test:" << endl;
  testStackFloat(stkvec, loctestnum, loctesterr);
  lasd::StackLst<double> stklst;
  cout << endl << "Begin of StackLst<double> Test:" << endl;
  testStackFloat(stklst, loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Stk>
void testStackString(Stk & stk, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Empty(loctestnum, loctesterr, stk, true);
    Size(loctestnum, loctesterr, stk, true, 0);

    PushM(loctestnum, loctesterr, stk, string("This "));
    PushM(loctestnum, loctesterr, stk, string("is "));
    PushM(loctestnum, loctesterr, stk, string("correct!"));

    Empty(loctestnum, loctesterr, stk, false);
    Size(loctestnum, loctesterr, stk, true, 3);

    TopNPop(loctestnum, loctesterr, stk, true, string("correct!"));
    Top(loctestnum, loctesterr, stk, true, string("is "));
    Pop(loctestnum, loctesterr, stk, true);
    TopNPop(loctestnum, loctesterr, stk, true, string("This "));
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
void testStackString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  lasd::StackVec<string> stkvec;
  cout << endl << "Begin of StackVec<string> Test:" << endl;
  testStackString(stkvec, loctestnum, loctesterr);
  lasd::StackLst<string> stklst;
  cout << endl << "Begin of StackLst<string> Test:" << endl;
  testStackString(stklst, loctestnum, loctesterr);
  cout << endl;
  try {
    lasd::Vector<string> vec(3);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("This"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("is"));
    SetAt(loctestnum, loctesterr, vec, true, 2, string("correct!"));
    lasd::List<string> lst(vec);

    Empty(loctestnum, loctesterr, stkvec, true);
    Size(loctestnum, loctesterr, stkvec, true, 0);
    PushM(loctestnum, loctesterr, stkvec, string("This"));
    PushM(loctestnum, loctesterr, stkvec, string("is"));
    PushM(loctestnum, loctesterr, stkvec, string("correct!"));
    lasd::StackVec<string> newstkvec1(vec);
    Empty(loctestnum, loctesterr, newstkvec1, false);
    Size(loctestnum, loctesterr, newstkvec1, true, 3);
    EqualStack(loctestnum, loctesterr, stkvec, newstkvec1, true);
    lasd::StackVec<string> newstkvec2(lst);
    Empty(loctestnum, loctesterr, newstkvec2, false);
    Size(loctestnum, loctesterr, newstkvec2, true, 3);
    EqualStack(loctestnum, loctesterr, newstkvec2, newstkvec1, true);
    EqualStack(loctestnum, loctesterr, stkvec, newstkvec2, true);

    Empty(loctestnum, loctesterr, stklst, true);
    Size(loctestnum, loctesterr, stklst, true, 0);
    PushM(loctestnum, loctesterr, stklst, string("correct!"));
    PushM(loctestnum, loctesterr, stklst, string("is"));
    PushM(loctestnum, loctesterr, stklst, string("This"));
    lasd::StackLst<string> newstklst1(vec);
    Empty(loctestnum, loctesterr, newstklst1, false);
    Size(loctestnum, loctesterr, newstklst1, true, 3);
    EqualStack(loctestnum, loctesterr, stklst, newstklst1, true);
    lasd::StackLst<string> newstklst2(lst);
    Empty(loctestnum, loctesterr, newstklst2, false);
    Size(loctestnum, loctesterr, newstklst2, true, 3);
    EqualStack(loctestnum, loctesterr, newstklst2, newstklst1, true);
    EqualStack(loctestnum, loctesterr, stklst, newstklst2, true);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  testnum += loctestnum;
  testerr += loctesterr;
}

void testStack(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  testStackInt(loctestnum, loctesterr);
  testStackFloat(loctestnum, loctesterr);
  testStackString(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
  cout << endl << "Exercise 3A - Stack (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

/* ************************************************************************** */

template <typename Que>
void testQueueInt(Que & que, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Empty(loctestnum, loctesterr, que, true);
    Size(loctestnum, loctesterr, que, true, 0);

    Head(loctestnum, loctesterr, que, false, 0);
    HeadNDequeue(loctestnum, loctesterr, que, false, 0);

    EnqueueC(loctestnum, loctesterr, que, 9);
    EnqueueC(loctestnum, loctesterr, que, 0);
    EnqueueC(loctestnum, loctesterr, que, 8);
    EnqueueC(loctestnum, loctesterr, que, 1);
    EnqueueC(loctestnum, loctesterr, que, 7);
    EnqueueC(loctestnum, loctesterr, que, 2);
    EnqueueC(loctestnum, loctesterr, que, 6);
    EnqueueC(loctestnum, loctesterr, que, 3);
    EnqueueC(loctestnum, loctesterr, que, 5);
    EnqueueC(loctestnum, loctesterr, que, 4);

    Empty(loctestnum, loctesterr, que, false);
    Size(loctestnum, loctesterr, que, true, 10);

    HeadNDequeue(loctestnum, loctesterr, que, true, 9);
    Head(loctestnum, loctesterr, que, true, 0);
    Head(loctestnum, loctesterr, (const Que) que, true, 0);

    Que copque(que);
    EqualQueue(loctestnum, loctesterr, que, copque, true);
    EnqueueC(loctestnum, loctesterr, que, 10);
    NonEqualQueue(loctestnum, loctesterr, que, copque, true);

    copque = que;
    EqualQueue(loctestnum, loctesterr, que, copque, true);
    EnqueueC(loctestnum, loctesterr, que, 11);
    NonEqualQueue(loctestnum, loctesterr, que, copque, true);

    Head(loctestnum, loctesterr, copque, true, 0);
    copque = move(que);
    HeadNDequeue(loctestnum, loctesterr, copque, true, 0);
    Dequeue(loctestnum, loctesterr, copque, true);
    Head(loctestnum, loctesterr, copque, true, 1);

    Que movque(move(que));
    Head(loctestnum, loctesterr, que, false, 0);
    Head(loctestnum, loctesterr, (const Que) que, false, 0);

    movque.Clear();
    Dequeue(loctestnum, loctesterr, movque, false);
    Empty(loctestnum, loctesterr, movque, true);
    Size(loctestnum, loctesterr, movque, true, 0);

    EnqueueC(loctestnum, loctesterr, movque, 5);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 5);
    EnqueueC(loctestnum, loctesterr, movque, 1);
    EnqueueC(loctestnum, loctesterr, movque, 3);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 1);
    EnqueueC(loctestnum, loctesterr, movque, 2);
    EnqueueC(loctestnum, loctesterr, movque, 4);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 3);
    EnqueueC(loctestnum, loctesterr, movque, 1);
    EnqueueC(loctestnum, loctesterr, movque, 7);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 2);
    EnqueueC(loctestnum, loctesterr, movque, 2);
    EnqueueC(loctestnum, loctesterr, movque, 2);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 4);
    EnqueueC(loctestnum, loctesterr, movque, 6);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 1);
    EnqueueC(loctestnum, loctesterr, movque, 8);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 7);
    EnqueueC(loctestnum, loctesterr, movque, 1);
    EnqueueC(loctestnum, loctesterr, movque, 4);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 2);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 2);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 6);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 8);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 1);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 4);
    EnqueueC(loctestnum, loctesterr, movque, 1);
    EnqueueC(loctestnum, loctesterr, movque, 1);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 1);
    HeadNDequeue(loctestnum, loctesterr, movque, true, 1);

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
void testQueueInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  lasd::QueueVec<int> quevec;
  cout << endl << "Begin of QueueVec<int> Test:" << endl;
  testQueueInt(quevec, loctestnum, loctesterr);
  lasd::QueueLst<int> quelst;
  cout << endl << "Begin of QueueLst<int> Test:" << endl;
  testQueueInt(quelst, loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Que>
void testQueueFloat(Que & que, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Empty(loctestnum, loctesterr, que, true);
    Size(loctestnum, loctesterr, que, true, 0);

    Head(loctestnum, loctesterr, que, false, 0.0);
    HeadNDequeue(loctestnum, loctesterr, que, false, 0.0);

    EnqueueC(loctestnum, loctesterr, que, 5.5);
    EnqueueC(loctestnum, loctesterr, que, 4.4);
    EnqueueC(loctestnum, loctesterr, que, 9.9);
    EnqueueC(loctestnum, loctesterr, que, 1.1);

    Empty(loctestnum, loctesterr, que, false);
    Size(loctestnum, loctesterr, que, true, 4);

    HeadNDequeue(loctestnum, loctesterr, que, true, 5.5);
    Head(loctestnum, loctesterr, que, true, 4.4);
    Dequeue(loctestnum, loctesterr, que, true);
    Dequeue(loctestnum, loctesterr, que, true);
    HeadNDequeue(loctestnum, loctesterr, que, true, 1.1);
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
void testQueueFloat(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  lasd::QueueVec<double> quevec;
  cout << endl << "Begin of QueueVec<double> Test:" << endl;
  testQueueFloat(quevec, loctestnum, loctesterr);
  lasd::QueueLst<double> quelst;
  cout << endl << "Begin of QueueLst<double> Test:" << endl;
  testQueueFloat(quelst, loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Que>
void testQueueString(Que & que, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Empty(loctestnum, loctesterr, que, true);
    Size(loctestnum, loctesterr, que, true, 0);

    EnqueueM(loctestnum, loctesterr, que, string("This "));
    EnqueueM(loctestnum, loctesterr, que, string("is "));
    EnqueueM(loctestnum, loctesterr, que, string("correct!"));

    Empty(loctestnum, loctesterr, que, false);
    Size(loctestnum, loctesterr, que, true, 3);

    HeadNDequeue(loctestnum, loctesterr, que, true, string("This "));
    Head(loctestnum, loctesterr, que, true, string("is "));
    Dequeue(loctestnum, loctesterr, que, true);
    HeadNDequeue(loctestnum, loctesterr, que, true, string("correct!"));
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
void testQueueString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  lasd::QueueVec<string> quevec;
  cout << endl << "Begin of QueueVec<string> Test:" << endl;
  testQueueString(quevec, loctestnum, loctesterr);
  lasd::QueueLst<string> quelst;
  cout << endl << "Begin of QueueLst<string> Test:" << endl;
  testQueueString(quelst, loctestnum, loctesterr);
  cout << endl;
  try {
    lasd::Vector<string> vec(3);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("This"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("is"));
    SetAt(loctestnum, loctesterr, vec, true, 2, string("correct!"));
    lasd::List<string> lst(vec);

    Empty(loctestnum, loctesterr, quevec, true);
    Size(loctestnum, loctesterr, quevec, true, 0);
    EnqueueM(loctestnum, loctesterr, quevec, string("This"));
    EnqueueM(loctestnum, loctesterr, quevec, string("is"));
    EnqueueM(loctestnum, loctesterr, quevec, string("correct!"));
    lasd::QueueVec<string> newquevec1(vec);
    Empty(loctestnum, loctesterr, newquevec1, false);
    Size(loctestnum, loctesterr, newquevec1, true, 3);
    EqualQueue(loctestnum, loctesterr, quevec, newquevec1, true);
    lasd::QueueVec<string> newquevec2(lst);
    Empty(loctestnum, loctesterr, newquevec2, false);
    Size(loctestnum, loctesterr, newquevec2, true, 3);
    EqualQueue(loctestnum, loctesterr, newquevec2, newquevec1, true);
    EqualQueue(loctestnum, loctesterr, quevec, newquevec2, true);

    Empty(loctestnum, loctesterr, quelst, true);
    Size(loctestnum, loctesterr, quelst, true, 0);
    EnqueueM(loctestnum, loctesterr, quelst, string("This"));
    EnqueueM(loctestnum, loctesterr, quelst, string("is"));
    EnqueueM(loctestnum, loctesterr, quelst, string("correct!"));
    lasd::QueueLst<string> newquelst1(vec);
    Empty(loctestnum, loctesterr, newquelst1, false);
    Size(loctestnum, loctesterr, newquelst1, true, 3);
    EqualQueue(loctestnum, loctesterr, quelst, newquelst1, true);
    lasd::QueueLst<string> newquelst2(lst);
    Empty(loctestnum, loctesterr, newquelst2, false);
    Size(loctestnum, loctesterr, newquelst2, true, 3);
    EqualQueue(loctestnum, loctesterr, newquelst2, newquelst1, true);
    EqualQueue(loctestnum, loctesterr, quelst, newquelst2, true);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  testnum += loctestnum;
  testerr += loctesterr;
}

void testQueue(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  testQueueInt(loctestnum, loctesterr);
  testQueueFloat(loctestnum, loctesterr);
  testQueueString(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
  cout << endl << "Exercise 3A - Queue (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

/* ************************************************************************** */

void testFullExercise3A(uint & testnum, uint & testerr) {
  testStack(testnum, testerr);
  testQueue(testnum, testerr);
  cout << endl << "Exercise 3A (Full Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
