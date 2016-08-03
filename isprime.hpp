// isprime.hpp - 2016.08.02 - Atlee Brink
//
// isprime( uint64_t num ) -> bool
//
// Employs an algorithm I came up with today that uses memoization to check primality of a number.
//
// Notes about nprime::memLimit
//   To check a single, 20-digit prime, only primes less than 2^16 should be memorized.
//   There are exactly 6542 primes in [0, 65536], so even conservatively we only need a few
//     kibibytes to compute 20-digit primes.

#pragma once

#include <cmath>
#include <cstdint>
#include <unordered_set>
#include <vector>

namespace nprime {

  static std::vector<uint64_t> primeList = {2, 3}; // largest number must be odd for the following algorithm
  static std::unordered_set<uint64_t> primeSet = {2, 3};
  static size_t memCount = 0; 
  static const size_t memLimit = 6542; // the number of primes in [0, sqrt(sqrt(2^64))]

  bool isprime( uint64_t num )
  {
    // quick checks
    if( primeSet.count( num ) > 0 ) return true; // known
    if( !(num & 1) ) return false; // even and not 2
    if( num < primeList.back() ) return false; // less than greatest known prime and not a known prime

    const uint64_t root2Floor = (uint64_t)std::sqrt( num );

    // check if any known prime is a factor
    for( const uint64_t p : primeList ) {
      if( p > root2Floor ) break;       // might be prime
      if( num % p == 0 ) return false; // definitely isn't prime
    }

    // otherwise starting from the odd number next after the largest known prime,
    //   check each odd number to see if it's a factor,
    //   and for non-factors, if we haven't reached memLimit, check and remember primality.
    //   This last part is where the fastness comes from, since it is likely that remembered
    //     numbers will be checked again before we're done.
    for( uint64_t p = primeList.back() + 2; p <= root2Floor; p += 2 ) {
      if( num % p == 0 ) return false;
      if( memCount < memLimit && isprime( p ) ) {
        primeList.push_back( p );
        primeSet.insert( p );
        memCount++;
      }
    }

    // if we made it this far, num must be prime
    return true;
  }
}
