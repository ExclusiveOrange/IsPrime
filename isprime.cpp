// isprime.cpp - 2016.08.02 - Atlee Brink

#include "isprime.hpp"

#include <iostream>

using namespace std;

using namespace nprime;

int main( int argc, char *argv[] )
{
  uint64_t num;

  if( argc != 2 || 1 != sscanf( argv[1], "%lu", &num ) ) {
    cout << "usage: " << argv[0] << " <uint64>" << endl;
    return 0;
  }

  cout << num << " is..." << flush;

  bool is = isprime( num );

  cout << "\r";

  cout << num << " is " << (isprime( num ) ? "" : "not ") << "prime" << endl;

  return 0;
}
