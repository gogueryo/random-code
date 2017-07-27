//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//  Created by Richard Lee on 7/14/17.
//  Copyright © 2017 Richard Lee. All rights reserved.
#include "misc.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
int maxSum(const std::vector<int>& numbers) {
  int sum = 0;
  int maxSum = 0;
  
  for (int i=0; i < numbers.size(); ++i) {
    int newSum = sum + numbers[i];
    std::cout << "sum=" << sum << " newSum=" << newSum << "  == " << numbers[i] << std::endl;
    sum = newSum > sum ? newSum : 0;
    
    maxSum = std::max(sum, maxSum);
  }
  return maxSum;
}

int maxSum2(const int* numbers, int length) {
  int sum = 0;
  int maxSum = 0;
  
  for (int i=0; i < length; ++i) {
    int newSum = sum + numbers[i];
    std::cout << "sum=" << sum << " newSum=" << newSum << "  == " << numbers[i] << std::endl;
    sum = newSum > sum ? newSum : 0;
    
    maxSum = std::max(sum, maxSum);
  }
  return maxSum;
}

void test_maxSum() {
  const int a[] = {1,4,-2, 5,7};
  
  std::cout << sizeof(a)/sizeof(int) << std::endl;
  std::vector<int> numbers;
  numbers.push_back(5);
  numbers.push_back(-5);
  numbers.push_back(50);
  numbers.push_back(15);
  numbers.push_back(-20);
  numbers.push_back(2);
  
  std::cout << maxSum(numbers) << std::endl;
  std::cout << maxSum2(a, sizeof(a)/sizeof(int)) << std::endl;
  
}

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
int comp(const void* a, const void* b) {
  int ia = *(int*) a;
  int ib = *(int*) b;
  
  return ia - ib;
}
void test_pairSum(const int* numbers, int length, int sum) {
  qsort((void*)numbers, length, sizeof(int), comp);
  
//  for (int i =0; i < length; ++i) {
//    std::cout << " " << i << " = " << (int) numbers[i] << std::endl;
//  }
  int f = 0;
  int l = length-1;
  
  while (f < l) {
    int tmp = numbers[f] + numbers[l];
    if (sum == tmp) {
      std::cout << sum << " = " << numbers[f] << " + " << numbers[l] << std::endl;
      --l;
      ++f;
    } else {
      if (tmp < sum) {
        ++f;    // want bigger number
      } else {
        --l;    // want smaller number
      }
    }
  }
}

void test_pairSum2(const int* n, int length, int sum) {
  std::vector<int> numbers(n, n+length);
  
  std::sort(numbers.begin(), numbers.end());
  
  auto f = 0;
  auto l = length-1;
  
  while (f < l) {
    int tmp = numbers[f] + numbers[l];
    if (sum == tmp) {
      std::cout << sum << " = " << numbers[f] << " + " << numbers[l] << std::endl;
      --l;
      ++f;
    } else {
      if (tmp < sum) {
        ++f;    // want bigger number
      } else {
        --l;    // want smaller number
      }
    }
  }
}

void test_pairSum() {
  std::cout << "\ntest pair sums\n";
  int n[] = {1,5,3,6,-5,-6,14};
  test_pairSum(n, sizeof(n)/sizeof(int), 8);
  std::cout << std::endl;
  
  test_pairSum2(n, sizeof(n)/sizeof(int), 8);
}

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
int add_via_bits(int a, int b) { // not using add operator
  if (0 == b)
    return a;
  
  int sum = a^b;
  int carry = (a&b) << 1;
  return add_via_bits(sum, carry);
}

void test_add() {
  std::cout << add_via_bits(5,-3) << std::endl;
}
