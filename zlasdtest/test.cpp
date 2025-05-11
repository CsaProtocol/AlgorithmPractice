
#include "./exercise1a/test.hpp"
#include "./exercise1b/test.hpp"

/* ************************************************************************** */

#include <iostream>

using namespace std;

/* ************************************************************************** */

void lasdtest() {
  cout << endl << "~*~#~*~ Welcome to the LASD Test Suite ~*~#~*~ " << endl;

  uint loctestnum, loctesterr;
  uint stestnum = 0, stesterr = 0;

  loctestnum = 0; loctesterr = 0;
  testSimpleExercise1A(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  testSimpleExercise1B(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  cout << endl << "Exercise 1 (Simple Test) (Errors/Tests: " << stesterr << "/" << stestnum << ")";

  cout << endl << "Goodbye!" << endl;
}
