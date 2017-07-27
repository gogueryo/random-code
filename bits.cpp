// --------------------------------------------------------------------------------
//  Created by Richard Lee on 7/14/17.
//  Copyright © 2017 Richard Lee. All rights reserved.
// --------------------------------------------------------------------------------
/*
    - swap 2 numbers without temp
    - add 2 numbers without using addition
    - detect overflow and underflow 
 */
// --------------------------------------------------------------------------------
#include "bits.hpp"
#include <iostream>
#include <climits>

// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
std::string bitString(int b) {
  std::string r;
  size_t l = 8;
  while (b && l-- > 0) {
    r = (b & 1 ? "1" : "0") + r;
    b >>= 1;
    b &= INT_MAX; // need to clear sign
  }
  return r;
}

// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
std::string bitString2(int b) {
  std::string r;
  int l = sizeof(int)*8;
  l = 8;

  for (int i=0; i < l; ++i) {
    r = (b & 1 ? "1" : "0") + r;
    b >>= 1;
  }
  return r;
}

int flip(int v) {
  return v ^ 1;
}

int sign(int v) {
  return flip((v >> 31) & 1);
}


int getMaxValue(int a, int b) {
  int sa = sign(a);
  int sb = sign(b);
  
  int k = sign(a-b);
  
  if (sa ^ sb)  // overflow condition
    k = sa;
  
  int q = flip(k);
  return a*k + b*q;
}

// insert code here...
void test_bits() {
  int a = -INT_MIN;
  int b = -5;
  
  std::cout << "a: " << a << " b = " << b << std::endl;
  std::cout << "max is " << getMaxValue(a,b) << std::endl;  
}
