#include <iostream>

#include "Caesar.h"
#include "OneTimePad.h"
//~ #include "RowsColumns.h"
//~ #include "ZigZag.h"
//~ #include "CipherPipeline.h"

/*
  The following main tests the functionality of various ciphers. Intended usage:

  make run < input.txt

  The makefile (provided) compiles the code, and "< input.txt"
  redirects file input to direct input (all inputs are read from the
  input file provided)

  Use at your own discretion, and feel free to extend and/or modify in any way.

  This file will be overwritten by Fitchfork if submitted.
 */

int main() {
  string text="Hello, World!..";

  string longText="Emily Elizabeth Dickinson was an American poet. Dickinson was born in Amherst, Massachusetts. Although part of a prominent family with strong ties to its community, Dickinson lived much of her life highly introverted.";

  string encoded;
  
  /************** Task 1 ***************/

  Caesar caes;
  
  encoded = caes.encode(text); // will yield a prompt to enter a positive value;
  // ENTER 0
  // ENTER 98
  // ENTER -3
  // ENTER 3
  cout << encoded << endl;
  cout << caes.decode(encoded) << endl;

  caes.setShift(15);
  encoded = caes.encode(text);
  cout << encoded << endl;
  cout << caes.decode(encoded) << endl;

  caes.setShift(66);
  encoded = caes.encode(text);
  cout << encoded << endl;
  cout << caes.decode(encoded) << endl;

  caes.setShift(94);
  encoded = caes.encode(text);
  cout << encoded << endl;
  cout << caes.decode(encoded) << endl;
  
  cout << endl;

  cout << "Longer text:\n";
  encoded = caes.encode(longText);
  cout << encoded << endl;
  cout << caes.decode(encoded) << endl;
  
  cout << endl;

  OneTimePad pad(1);
  encoded = pad.encode(text);
  cout << encoded << endl;
  cout << pad.decode(encoded) << endl;

  pad.setSeed(2);
  encoded = pad.encode(text);
  cout << encoded << endl;
  cout << pad.decode(encoded) << endl;

  pad.setSeed(9999);
  encoded = pad.encode(text);
  cout << encoded << endl;
  cout << pad.decode(encoded) << endl;
  
  cout << endl;
  
  cout << "Longer text:\n";
  encoded = pad.encode(longText);
  cout << encoded << endl;
  cout << pad.decode(encoded) << endl;

  //~ /************** Task 2 ***************/

  //~ cout << endl;

  //~ RowsColumns rc;
  //~ encoded = rc.encode(text);
  //~ cout << encoded << endl;
  //~ cout << rc.decode(encoded) << endl;
  //~ try {
    //~ cout << rc.decode(text) << endl;
  //~ } catch (const char * e) {
    //~ cout << e << endl;
  //~ }
  
  //~ encoded = rc.encode(longText);
  //~ cout << encoded << endl;
  //~ cout << rc.decode(encoded) << endl;
  //~ try {
    //~ cout << rc.decode(longText) << endl;
  //~ } catch (const char * e) {
    //~ cout << e << endl;
  //~ }
  
  //~ cout << endl;

  //~ ZigZag zz;
  //~ encoded = zz.encode(text);
  //~ cout << encoded << endl;
  //~ cout << zz.decode(encoded) << endl;
  
  //~ try {
    //~ cout << zz.decode(text) << endl;
  //~ } catch (const char * e) {
    //~ cout << e << endl;
  //~ }
  
  //~ encoded = zz.encode(longText);
  //~ cout << encoded << endl;
  //~ cout << zz.decode(encoded) << endl;
  
  //~ try {
    //~ cout << zz.decode(longText) << endl;
  //~ } catch (const char * e) {
    //~ cout << e << endl;
  //~ }

  //~ /************** Task 3 ***************/

  //~ cout << endl;

  //~ CipherPipeline pipe;
  //~ pipe += &caes;
  //~ pipe += &pad;

  //~ encoded = pipe.encode(text);
  //~ cout << encoded << endl;
  //~ cout << pipe.decode(encoded) << endl;

  //~ cout << endl;

  //~ encoded = pipe.encode(longText);
  //~ cout << encoded << endl;
  //~ cout << pipe.decode(encoded) << endl;

  //~ cout << endl;

  //~ pipe += rc + zz;
  //~ encoded = pipe.encode(text);
  //~ cout << encoded << endl;
  //~ cout << pipe.decode(encoded) << endl;
  
  //~ pipe = zz + pad;
  //~ encoded = pipe.encode(text);
  //~ cout << encoded << endl;
  //~ cout << pipe.decode(encoded) << endl;
  
  return 0;
}
