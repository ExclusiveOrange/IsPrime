#include "isprime.hpp"

#include <cstdio>
#include <iostream>

using namespace std;
using namespace nprime;

int main( int argc, char *argv[] )
{
  uint64_t lo, hi;

  if( argc != 3
    || 1 != sscanf( argv[1], "%lu", &lo )
    || 1 != sscanf( argv[2], "%lu", &hi )
    || lo > hi
  ) {
    cout << "usage: " << argv[0] << " <lower bound> <upper bound>" << endl;
    return 0;
  }

  bool first = true;
  for( uint64_t num = lo; num <= hi; num++ ) {
    if( num ) cout << ",";
    cout << (isprime( num ) ? "1" : "0");
  }

  return 0;
}
