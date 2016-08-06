importScripts('isprime.js');

onmessage = function( event ) {
  var num = Number( event.data );
  var boolIsPrime = isPrime( num );
  postMessage( boolIsPrime );
};
