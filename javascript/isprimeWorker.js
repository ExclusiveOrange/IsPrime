// isprimeWorker.js - 2016.08.05 - Atlee Brink

importScripts('isprime.js');

onmessage = function( event ) {
  var num = Number( event.data );
  var boolIsPrime = isPrime( num );
  postMessage( boolIsPrime );
};
