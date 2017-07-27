//
//  bits.hpp
//  prep-tests
//
//  Created by Richard Lee on 7/14/17.
//  Copyright © 2017 Richard Lee. All rights reserved.
//

#ifndef bits_hpp
#define bits_hpp
#include <string>

std::string bitString(int b);
std::string bitString2(int b);

int flip(int v);
int sign(int v);
int getMaxValue(int a, int b);

void test_bits();

#endif /* bits_hpp */
