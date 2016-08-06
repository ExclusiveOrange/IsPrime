// countprimes.cpp - 2016.08.02 - Atlee Brink

#include "isprime.hpp"

#include <iostream>

using namespace std;

using namespace nprime;

uint64_t estimatePrimeCount( uint64_t hi )
{
  if( hi < 3 ) return 0;
  const long double hiD = (long double)hi;
  return hiD / ( log(hiD) - 1.0 );
}

int main( int argc, char *argv[] )
{
  uint64_t lo, hi;

  if( argc != 3
    || 1 != sscanf( argv[1], "%lu", &lo )
    || 1 != sscanf( argv[2], "%lu", &hi )
    || lo > hi
  ) {
    cout << "usage: " << argv[0] << " <low: uint64> <high: uint64>" << endl;
    return 0;
  }

  cout << "estimated number of primes: "
    << ( estimatePrimeCount( hi ) - estimatePrimeCount( lo ) )
    << endl;

  cout << "counting... " << flush;

  uint64_t count = 0;

  for( uint64_t n = lo; n <= hi; n++ ) count += isprimedumb( n );

  cout << "the interval [ " << lo << ", " << hi << " ] contains exactly " << count << " primes" << endl;

  return 0;
}
