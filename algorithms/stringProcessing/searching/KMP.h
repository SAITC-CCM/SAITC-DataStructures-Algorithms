// Author: Moisés Adame-Aguilar
// Date: September 25th, 2023
// Description: Implementation of the  Knuth–Morris–Pratt Algorithm.

#ifndef __KMP
#define __KMP
#pragma once

#include<vector>
using namespace std;

class KMP {
    public:
        string mainString;
        string substring;
        vector<int> indexes;

        // Constructor for the Knuth–Morris–Pratt Algorithm
        KMP(string mainString, string substring){
            this->mainString = mainString;
            this->substring = substring;
        }
        
        // Function that prints the Main String and the substring
        void print(){
            cout << this->mainString << endl;
            cout << this->substring << endl;
        }

        // Function that returns a bool that represents the existance of the substring 
        // inside the mainString and aditionally, determines the index of incidence.
        // Complexity: O(m + n)
        bool compare(){
            // Generate the prefixArray with it's respective values.
            int substringSize = substring.size();
            int mainStringSize = mainString.size();
            int prefixArray[substringSize];
            buildPrefixArray(prefixArray, substringSize);

            // Using the prefixArray check if a match exists between the strings.
            int i = 0, j = 0;
            bool matchExists = false;
            
            // If the mainStringSize is smaller than substringSize, there is no match!
            if(mainStringSize < substringSize){
                return matchExists;
            }

            while(i < mainStringSize){
                if(mainString[i] == substring[j]){
                    // If j has managed to arrive to the end of the prefixArray, there's a match!
                    if(j == substringSize - 1){
                        matchExists = true;
                        indexes.push_back(i - j);
                    }
                    j++;
                    
                }else{
                    j = prefixArray[j - 1] + 1;
                }
                i++;
            }
            return matchExists;
        }

    private:
        // Function that builds the prefixArray of the substring.
        // Complexity: O(n)
        void buildPrefixArray(int prefixArray[], int substringSize){
            // Instatiate and fill up with 0's.
            for(int i = 0; i < substringSize; i++){
                prefixArray[i] = 0;
            }
            
            bool isBuilt = false;
            int i = 1, j = 0;
            while(i < substringSize && !isBuilt ){
                if(substring[j] == substring[i]){
                    // Mark the ith term as j + 1
                    prefixArray[i++] = ++j;

                    // If that happens and i is already out of the array, break the loop.
                    if(i == substringSize){
                        isBuilt = true;
                    }
                    
                }else{
                    // If j is already and it was not equal to the array, break the loop.
                    if(j == 0 && i == substringSize - 1){
                        isBuilt = true;
                    }

                    // Set j as the value of the previus number in the array.
                    j = prefixArray[j - 1];

                    // Only incremet i if it is inside the array.
                    if(i != substringSize - 1){
                        i++;
                    }
                }
            }
        }
};

#endif