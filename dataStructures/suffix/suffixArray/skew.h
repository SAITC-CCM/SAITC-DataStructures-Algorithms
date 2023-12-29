/**
 * @file skew.h
 * @author Erno Mitrovic (ernesto.miranda@sa-itc.com)
 * @brief Implementation of a suffix array using skew algorithm.
 * @version 0.1
 * @date 2023-12-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SUFFIX_ARRAY_SKEW_H
#define SUFFIX_ARRAY_SKEW_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class SuffixArraySkew
{
private:
    std::vector<int> suffixArray;
    std::vector<int> text;
    int ALPHABET_SIZE;
    inline bool leq(int a1, int a2, int b1, int b2);
    inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3);
    static void radixPass(std::vector<int> &A, std::vector<int> &B, std::vector<int> &R, int offset, int n, int K);
    void skew(std::vector<int> &text, std::vector<int> &sa, int n, int k);

public:
    SuffixArraySkew(std::string text);
    void print();
};

#endif // SUFFIX_ARRAY_SKEW_H