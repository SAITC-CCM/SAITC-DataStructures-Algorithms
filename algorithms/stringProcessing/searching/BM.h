// Author: Moisés Adame-Aguilar
// Date: September 25th, 2023
// Description: Implementation of the  Boyer-Moore Algorithm.

#ifndef __BM
#define __BM
#pragma once

#include<vector>
#include<map>
using namespace std;

class BM {
    public:
        string mainString;
        string substring;
        vector<int> indexes;

        // Constructor for the Knuth–Morris–Pratt Algorithm
        BM(string mainString, string substring){
            this->mainString = mainString;
            this->substring = substring;
        }
        
        // Function that prints the Main String and the substring
        void print(){
            cout << this->mainString << endl;
            cout << this->substring << endl;
        }
        
        // Function that returns a bool that represents the existance of the substring 
        // inside the mainString.
        // Complexity: O(m + n)
        bool compare(){
            // Bad Match Table with displacement values.
            map<char, int> badMatchTable = buildMap();

            // Variables of string sizes.
            int substringSize = substring.size();
            int mainStringSize = mainString.size();

            // Variables of displacement, indexes (i, j), matchExists and stop.
            int displacement = 0;
            int j = substringSize - 1, i = substringSize - 1;
            int stop = i;
            bool matchExists = false;
            
            // While loop that stops only when i is out of the mainString.
            while(i < mainStringSize){
                if(mainString[i] == substring[j]){
                    if(j == 0){
                        // Check if we've reached the end, if we do restart from were we left
                        matchExists = true;
                        indexes.push_back(i);
                        j = substringSize - 1;
                        i = stop + substringSize;
                    }else if(j == substringSize - 1){
                        // Assign i to stop to keep in memory where i was.
                        stop = i;
                        j--;
                        i--;
                    }else{
                        j--;
                        i--;
                    }
                }else{
                    // Look for the displacement, if it is 0 means that the char isn't in the badMatchTable
                    if(j != substringSize - 1){
                        j = substringSize - 1;
                        i = stop + 1;
                    }else{
                        displacement = badMatchTable[mainString[i]];
                        if(displacement != 0){
                            i += displacement;
                        }else{
                            i += substringSize;
                        }
                    }
                }
            }
            return matchExists;
        }

    private:
        // Function that returns the max between two integers.
        int max(int num1, int num2){
            return num1 >= num2 ? num1 : num2;
        }

        // Function that builds the badMatchTable, based on 
        // the following the next equation: max{1, len(pattern) - index - 1}
        // Complexity: O(n)
        map<char, int> buildMap(){

            map<char, int> badMatchTable;
            int substringSize = substring.size();

            for(int i = 0; i < substringSize; i ++){
                badMatchTable[substring[i]] = max(1, substringSize - i - 1);
            }

            return badMatchTable;
        }
};

#endif