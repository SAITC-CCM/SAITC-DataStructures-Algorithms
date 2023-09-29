// Author: Moisés Adame-Aguilar
// Date: September 26th, 2023
// Description: Implementation of Manacher's Longest Palindromic Substring Algorithm

#ifndef __Manacher
#define __Manacher
#pragma once

#include <utility>
#include <vector>
using namespace std;

class Manacher {
    public:
        // Constructor for the Manacher Longest Palindromic Substring Algorithm. 
        Manacher(string text){
            this->text = text;

            centers.resize(text.size() + 2);
            fill(centers.begin(), centers.end(), 1);
        }
        
        // Function that prints the text to be analyzed.
        void print(){
            cout << this->text << endl;
        }
        
        // Method that returns the Longest Palindromic Substring using the 
        // centers array built with help of the search() method.
        string getLongestPalindromicSubstring(){
            // Find center index of the Longest Palindromic Substring.
            int maxIndex = getLongestPalindromicIndex();

            // Build and return the Longest Palindromic Substring.
            string longestPalindromicSubstring(1, text[maxIndex]);
            for(int i = 1; i < centers[maxIndex + 1]; i++){
                longestPalindromicSubstring = text[maxIndex - i] + longestPalindromicSubstring + text[maxIndex + i];
            }

            return longestPalindromicSubstring;
        }
        
        // Method that returns the indexes of start and stop of the 
        // Longest Palindromic Substring inside a pair<int, int>
        pair<int, int> getLongestPalindromicSubstringStartStop(){
            // Find center index of the Longest Palindromic Substring.
            int maxIndex = getLongestPalindromicIndex();

            // Prepare and return the indexes of start and stop
            pair<int, int> indexes;
            int offset = centers[maxIndex + 1];
            if(offset == 1){
                indexes.first = maxIndex;
                indexes.second = maxIndex;
            }else{
                offset -= 1;
                indexes.first = maxIndex - offset;
                indexes.second = maxIndex + offset;
            }
            return indexes;
        }

    private:
        // Private attributes
        string text;
        vector<int> centers;
        
        // Function that returns the max between two integers.
        int max(int num1, int num2){
            return num1 >= num2 ? num1 : num2;
        }

        // Function that returns the max between min integers.
        int min(int num1, int num2){
            return num1 <= num2 ? num1 : num2;
        }

        // Function that performs the search of the palindromic substrings.
        // Complexity: O()
        void search(){
            // Generate alteredText to break possible palindrome.
            string alteredText = "}" + text + "{";
            int alteredTextSize = alteredText.size();

            // Define variables left and right for the subset analysis.
            int left = 1, right = 1;

            // Iterate over the "known text" and not over alteredText.
            for(int i = 1; i < alteredTextSize - 1; i++){
                if(i < right){
                    centers[i] = max(0, min(centers[left + right - i], right - i));
                }

                // Apply naive seacrh.
                while(alteredText[i - centers[i]] == alteredText[i + centers[i]]){
                    centers[i]++;
                }

                // Redifine subset's borders with respect to i.
                if(i + centers[i] > right){
                    left = i - centers[i];
                    right = i + centers[i];
                }
            }
        }

        // Method that walks through centers array and returns the index of 
        // the center of the Longest Palindromic Substring.
        int getLongestPalindromicIndex(){
            // Get the size of the alteredText string.
            int alteredTextSize = text.size();

            // Apply search over our text.
            search();

            // Find center index of the Longest Palindromic Substring.
            int maxIndex = 1;
            for(int i = 1; i < alteredTextSize - 1; i++){
                if(centers[i] > centers[maxIndex]){
                    maxIndex = i;
                }
            }
            return maxIndex - 1;
        }
};

#endif