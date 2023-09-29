// Author: Moisés Adame-Aguilar
// Date: September 28th, 2023
// Description: 

#ifndef __LCS
#define __LCS
#pragma once

#include<vector>
using namespace std;

class LCS {
    public:
        string word1;
        string word2;
        vector<vector<int> > lcsMatrix;
        
        LCS(string word1, string word2){
            this->word1 = word1;
            this->word2 = word2;

            lcsMatrix.resize(word2.size());
            vector<int> innerVector(word1.size());
            fill(lcsMatrix.begin(), lcsMatrix.end(), innerVector);
        }

        pair<int, int> getIndexLongestSimilarity(){
            populateMatrix();
            int indexLongestSimilarityWord1 = 0;
            int indexLongestSimilarityWord2 = 0;
            int longestSimilaritySize = 0;

            for(int i = 0; i < word2.size(); i++){
                for(int j = 0; j < word1.size(); j++){
                    if(lcsMatrix[i][j] > longestSimilaritySize){
                        longestSimilaritySize = lcsMatrix[i][j];
                        indexLongestSimilarityWord1 = j - longestSimilaritySize;
                        indexLongestSimilarityWord2 = i - longestSimilaritySize;
                    }
                }
            }

            pair<int, int> indexLongestSimilarity;
            indexLongestSimilarity.first = indexLongestSimilarityWord1;
            indexLongestSimilarity.second = indexLongestSimilarityWord2;

            return indexLongestSimilarity;
        }

        void printMatrix(){
            for(int i = 0; i < word2.size(); i++){
                for(int j = 0; j < word1.size(); j++){
                    cout << lcsMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        void printShape(){
            cout << "(" << lcsMatrix.size() << ", " << lcsMatrix[0].size() << ")" << endl;
        }

    private:
        void populateMatrix(){
            for(int i = 0; i < word2.size(); i++){
                for(int j = 0; j < word1.size(); j++){
                    if(word2[i] == word1[j]){
                        if(i > 0 && j > 0){
                            lcsMatrix[i][j] += lcsMatrix[i - 1][j - 1] + 1;
                        }else{
                            lcsMatrix[i][j]++;
                        }
                    }
                }
            }
        }

};

#endif