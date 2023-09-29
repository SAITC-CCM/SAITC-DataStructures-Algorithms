// Author: Moisés Adame-Aguilar
// Date: September 26th, 2023
// Description: Implementation of the Z-Function String Pattern Algorithm.

#ifndef __ZPattern
#define __ZPattern
#pragma once

#include<vector>
using namespace std;

class ZPattern {
    public:
        string mainString;
        string substring;
        vector<int> indexes;

        // Constructor for the Z-Function String Pattern Algorithm. 
        ZPattern(string mainString, string substring){
            this->mainString = mainString;
            this->substring = substring;
            this->combinationString = substring + "$" + mainString;
        }
        
        // Function that prints the mainString, substring and the combinationString
        void print(){
            cout << this->mainString << endl;
            cout << this->substring << endl;
            cout << this->combinationString << endl;
        }

        // Function that returns a bool that represents the existance of the substring 
        // inside the mainString using the Z-Function Algorithm.
        // Complexity: O(m + n)
        bool compare(){
            int combinationStringSize = combinationString.size();
            int substringSize = substring.size();

            vector<int> zfunctionArray = buildZFunction();

            // Check if in the zfunctionArray there is a value equal to the substringSize.
            for(int i = substringSize + 1; i < combinationStringSize; i++){
                if(zfunctionArray[i] == substringSize){
                    indexes.push_back(i - substringSize - 1);
                }
            }
            
            // If the indexes vector is empty, there was no match.
            return !indexes.empty();
        }

        int getIndexLongestSimilarity(){
            int combinationStringSize = combinationString.size();
            int substringSize = substring.size();
            int indexLongestSimilarity = 0;
            int longestSimilaritySize = 0;
            int valueArray = 0;

            vector<int> zfunctionArray = buildZFunction();
            for(int i = substringSize + 1; i < combinationStringSize; i++){
                valueArray = zfunctionArray[i];
                if(valueArray > longestSimilaritySize){
                    longestSimilaritySize = valueArray;
                    indexLongestSimilarity = i - substringSize - 1;
                }
            }
            return indexLongestSimilarity;
        }

    private:
        string combinationString;

        // Function that builds the zfunctionArray of the combinationString.
        // Complexity: O(n + m)
        vector<int> buildZFunction(){
            // Generate the zfunctionArray with it's respective values.
            int combinationStringSize = combinationString.size();
            int substringSize = substring.size();
            vector<int> zfunctionArray;
            zfunctionArray.resize(combinationStringSize);
            fill(zfunctionArray.begin(), zfunctionArray.end(), 0);

            int left = 0, right = 0;
            for(int i = 1; i < combinationStringSize; i++){
                if(i < right){
                    zfunctionArray[i] = min(right - i, zfunctionArray[i - left]);
                }

                while(i + zfunctionArray[i] < combinationStringSize && combinationString[i + zfunctionArray[i]] == combinationString[zfunctionArray[i]]){
                    zfunctionArray[i]++;
                }

                if(i + zfunctionArray[i] > right){
                    left = i;
                    right = i + zfunctionArray[i];
                }
            }
            return zfunctionArray;
        }

        // Function that returns the max between min integers.
        int min(int num1, int num2){
            return num1 <= num2 ? num1 : num2;
        }
};

#endif