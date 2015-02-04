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

int cache_size = 100000;
int cache[cache_size] = {0};

// -----
// Cache
// -----

void initialize_cache(){
    for(int i = 1; i <= cache_size; ++i)
    {
        cache[i] = max_cycle(i);
    }
}

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
    while(n > 1)
    {
        if(n <= cache_size && cache[n] != 0)
        {
            return cache[n] + (count - 1);
        }
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
    for(int beg = i; beg <= j; ++beg)
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


// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------
// ----
// main
// ----

int main () {
    using namespace std;
    initialize_cache();
    collatz_solve(cin, cout);
    return 0;}

/*
% g++-4.7 -pedantic -std=c++11 -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz



% cat RunCollatz.in
1 10
100 200
201 210
900 1000



% RunCollatz < RunCollatz.in > RunCollatz.out



% cat RunCollatz.out
1 10 1
100 200 1
201 210 1
900 1000 1



% doxygen -g
// That creates the file Doxyfile.
// Make the following edits to Doxyfile.
// EXTRACT_ALL            = YES
// EXTRACT_PRIVATE        = YES
// EXTRACT_STATIC         = YES
// GENERATE_LATEX         = NO



% doxygen Doxyfile
// That creates the directory html/.
*/
'