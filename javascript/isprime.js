// isprime.js - 2016.08.05 - Atlee Brink

function isPrime( num ) {

  if( num < 2 ) return false;
  if( num < 4 ) return true;
  if( num % 2 == 0 ) return false;

  const rt = Math.floor(Math.sqrt( num ));

  for( n = 3; n <= rt; n++ ) {
    if( num % n == 0 ) return false;
  }

  return true;
}
