# Primality Checker

* [What](#what)
* [Building](#building)
* [Usage](#usage)
* [Example](#examples)

## What

A primality checker is a function that looks at a number and tells you whether or not it's prime.  
In this case, I consider a prime number to be a positive integer wholly divisible only by itself and 1.
The first few prime numbers are { 2, 3, 5, 7, 11, 13, 17, 19, ... }, and notably do not include 1.  

This particular primality checker for C++ uses two tables covering [0, 65535]:
a boolean prime map of that interval, and a list of primes in that interval.

## Building

I've provided a `Makefile` which should do the job.
After downloading this repository, get into its directory and do:

```
make
```

## Usage

### C++ function `isprime`

You access this function by including `isprime.hpp`, and calling `nprime::isprime()`.  
Here is the `isprime` function signature:

```
bool isprime( uint64_t num )
```

If `num` is a prime number, then `isprime` returns `true`, else it returns `false`.  

### `isprime.cpp` program

This compiles into a terminal program `isprime`.
You use it like so:

```
./isprime <unsigned integer up to 64 bits>
```

The program will do a check, which may take a few seconds for the very largest prime numbers,
and then it will tell you whether or not the number is prime.

### `countprimes.cpp` program

This compiles into a terminal program `countprimes`.
You use it like so:

```
./countprimes <lower integer in range> <upper integer in range>
```

First the program will immediately report an estimate of the number of primes within the range.
Then the program will exactly count all of the primes within the range, which may take some time depending
on both the size of the range and the bigness of the numbers in the range.
Finally the program will report its exact count.  
Be warned that numbers near 20 digits can take several seconds to check EACH, so it's unwise to request a count of a large range of very big numbers, though the program will gladly spend forever trying.

## Examples

### C++ function `isprime`

See `isprime.cpp` and `countprimes.cpp` for examples using the `nprime::isprime()` function in a C++ program.

### `isprime` terminal program

```
> ./isprime 990377764891511
990377764891511 is prime
```

### `countprimes` terminal program

```
> ./countprimes 1000 1000000
estimated number of primes: 77861
the interval [ 1000, 1000000 ] contains exactly 78330 primes
```
