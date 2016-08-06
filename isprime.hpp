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

    // spend some time up-front finding the stopping point,
    //   to avoid an extra boundary check every iteration.
    const auto bound = lower_bound( primeList.begin(), primeList.end(), root2Floor );
    for( auto it = primeList.begin(); it != bound; ++it ) {
      if( num % *it == 0 ) return false;
    }

    // check all the other odd numbers that may or may not be prime
    for( uint64_t p = primeList.back() + 2; p <= root2Floor; p += 2 ) {
      if( num % p == 0 ) {
        return false;
      }
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
