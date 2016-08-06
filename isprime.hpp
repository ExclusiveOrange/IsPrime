// isprime.hpp - 2016.08.05 - Atlee Brink
//
// isprime( uint64_t num ) -> bool
// isprimedumb( uint64_t num ) -> bool
//
// Now with a boolean lookup table for [0, 65535], and a prime list for the same.

#pragma once

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace nprime {

  const std::vector<uint16_t> primeList = {
    #include "primeList.txt"
  };

  // todo: use a binary map instead of a char map:
  //      it means more computation to extract the value, but less total memory used,
  //      therefore more cacheable and maybe faster.
  const uint8_t primeMap[65536] = {
    #include "primeMap.txt"
  };

  bool isprime( uint64_t num )
  {
    // check if a small, known prime
    if( num <= UINT16_MAX ) {
      return primeMap[num];
    }

    // todo: make go faster - we don't need this to be very accurate
    const uint64_t root2Floor = (uint64_t)std::sqrt( num );

    // since primeList is constant, we might benefit from hard-coded unrolled loops,
    //   so we first check if we'll need to look at the entire list.
    const auto bound = lower_bound( primeList.begin(), primeList.end(), root2Floor );
    if( bound == primeList.end() ) {

      // we need to look at the entire list of known primes, and maybe more

      // check all known primes for factorization
      // this rules out all potential factors in [0, 65536] by only checking 6542 of them.
      for( const auto p : primeList ) {
        if( num % p == 0 ) {
          return false;
        }
      }

      // check all odd numbers after the largest known prime,
      //   up to sqrt(num).
      for( uint64_t p = primeList.back() + 2; p <= root2Floor; p += 2 ) {
        if( num % p == 0 ) {
          return false;
        }
      }

    } else {

      // else we only need to check a subset of the known primes
      auto it = primeList.begin();
      do {
        if( num % *it == 0 ) {
          return false;
        }
      } while( ++it != bound );
    }


    // if we made it this far, num must be prime
    return true;
  }

  // in theory, this version should be slower on average
  bool isprimedumb( uint64_t num )
  {
    // get all the obvious stuff out of the way
    if( num < 2 ) return false;
    if( num < 4 ) return true;
    if( num % 2 == 0 ) return false;

    // check all odd numbers up to the square root of num
    uint32_t root2 = (uint32_t)sqrt( num );
    for( uint64_t n = 3; n <= root2; n++ ) {
      if( num % n == 0 ) return false;
    }

    return true;
  }
}
