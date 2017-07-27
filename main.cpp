//  Created by Richard Lee on 7/14/17.
//  Copyright © 2017 Richard Lee. All rights reserved.
#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include "bits.hpp"
#include "misc.hpp"

int get_a() {
  return 1;
}

template <typename T>
void show_vec(const std::vector<T>& cvec) {
  std::vector<T> vec = cvec;
  
  for (const auto &s : vec) {
    std::cout << s << std::endl;
  }
  std::cout << std::endl;
}

int test() {
  double d;
  int    i;
  int    e = -1;
  i = d = 3.5;
  i = e << 2;
  
  std::cout << (1 << 2) << ": " << bitString2(1 << 2) << std::endl;
  std::cout << i << ": " << bitString2(i) << std::endl;
  
  return 1;
  
  std::initializer_list<int> xxx = {1,2,3,4,};
//  auto xxx = {1,2,3,4,};
  std::vector<int> v = {1,2,3,4,};
  std::vector<int> v2(xxx.begin(), xxx.end());
  
  show_vec(v2);
  int a[2] = {1,2};
  int (*p)[2] = &a;
  
  std::cout << *p[0] << std::endl;
  return 0;
}


const int XX = get_a();

int main(int argc, const char * argv[]) {
  
  return test();
  
  std::vector<std::string> va{"1","2"};
  
  show_vec(va);
  show_vec(std::vector<std::string>{"1","5"});
  show_vec(std::vector<std::string>{"11","22", "9", "3", "1"});
  show_vec(std::vector<int>{11,22, 9, 3, 1});
  show_vec(std::vector<std::string>{11,"hi"});
  
  std::cout << (std::vector<int>{11,22, 9, 3, 1} > std::vector<int>{11,22, 9, 2}) << std::endl;
  return 0;
  
//  test_bits();
  test_maxSum();
  test_pairSum();
  test_add();
  
  
  const int t=0, * const &w = &t;
  
  int z = 0;
  int *const pz = &z;
  *pz = 12;
  
  int i = -3;
  
  // for (int i=0; i > -10; --i) {
  //   std::cout << i << " " << bitString2(i) << std::endl;
    
  // }

  int p = 10, q=20;
  int* ip, *&r = ip;
  
  ip = &q;
  r = &p;
  
  std::cout << *r << std::endl;
  //return 0;

  auto xx = 5+9;
  
  int a = INT_MIN+xx;
  int b = INT_MIN+10;
  
  std::cout << std::endl;
  std::cout << "a   = " << a     << std::endl;
  std::cout << "b   = " <<     b << std::endl;
  std::cout << "a+b = " << a + b << std::endl;
  std::cout << "a-b = " << a - b << std::endl;
  std::cout << std::endl;
  
  std::cout << bitString2(i) << std::endl;
  std::cout << bitString2(-i) << std::endl;
  std::cout << bitString2((unsigned char) i) << std::endl;
  std::cout << bitString2((char) i) << std::endl;

  std::cout << i << std::endl;
  std::cout << (int)(char) i << std::endl;
  std::cout << (int)(unsigned char) i << std::endl;
  return 0;
}
