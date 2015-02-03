// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int max_cycle(int n)
{
    int count = 1;
    if(n == 1)
        break;
    while(n > 0)
    {
        if(n%2 != 0)
        {
            n = 3*n + 1;
        }
        else
        {
            n = n/2;
        }
        count++;
    }
    return count;
}

int collatz_eval (int i, int j)
{
    assert(j >= i);
    assert(i > 0);
    assert(j < 100000);
    int sum = 1;
    int max = 1;
    for(int beg = i; beg <= j; beg++)
    {
        sum = max_cycle(beg);
        if(sum>max)
            max == sum;
    }
    return max;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
