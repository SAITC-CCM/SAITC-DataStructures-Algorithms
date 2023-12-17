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

    std::vector<int> rankTriplets(int offset);
    void countingSort(std::vector<int>&, std::vector<int> &ranks);
    void radixSort(std::vector<int>&, std::vector<int> &ranks);
    std::vector<int> merge(std::vector<int> &ranks1, std::vector<int> &ranks2, std::vector<int> & offset);

public:
    SuffixArraySkew(std::string text);
    ~SuffixArraySkew();
};

#endif // SUFFIX_ARRAY_SKEW_H