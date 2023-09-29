// Author: Moisés Adame-Aguilar
// Date: September 27th, 2023
// Description: Implementation of Standard Trie Data Structure.

#ifndef __Trie
#define __Trie
#pragma once

#include<vector>
#include<map>
using namespace std;

class TrieNode {
    public:
        map<char, TrieNode*> children;
        bool isEndOfWord;
       
        TrieNode(){
            isEndOfWord = false;
        }

        void setChild(char character, TrieNode* node){
            children[character] = node;
        }

        void setEndOfWord(bool isEndOfWord){
            this->isEndOfWord = isEndOfWord;
        }

        void print(){
            int i = 1;
            for(map<char, TrieNode*>::const_iterator it = children.begin(); it != children.end(); it++){
                cout << i << ".- " << it->first << endl;
            }
        }
};

class Trie {
    public:
        TrieNode* root;

        // Constructor method for the Trie Data Structure.
        Trie(){
            root = new TrieNode();
        }
        
        void print(){
            print(root);
        }

        void insert(string word){
            insert(word, 0, root, 0 == word.size() - 1);
        }

        bool find(string word){
            return find(word, 0, root, 0 == word.size() - 1);
        }

        void autocomplete(string incompleteWord){
            autocomplete(incompleteWord, 0, root, 0 == incompleteWord.size() - 1);
        }

        void formWords(){
            string wordsBulk = "";
            formWords(root, &wordsBulk);
            cout << wordsBulk << endl;
        }

    private:
        void insert(string word, int currentIndex, TrieNode* node, bool isEndOfWord){
            if(node->children.count(word[currentIndex]) == 0){
                node->children[word[currentIndex]] = new TrieNode();
                node->children[word[currentIndex]]->setEndOfWord(isEndOfWord);
            }

            currentIndex += 1;
            if(!isEndOfWord){
                insert(word, currentIndex, node->children[word[currentIndex - 1]], currentIndex == word.size() - 1);
            }
        }

        void print(TrieNode* node){
            for(map<char, TrieNode*>::const_iterator it = node->children.begin(); it != node->children.end(); it++){
                cout << it->first<< endl;
                print(it->second);
            }
        }

        void formWords(TrieNode* node, string* wordsBulk){
            for(map<char, TrieNode*>::const_iterator it = node->children.begin(); it != node->children.end(); it++){
                *wordsBulk += it->first;
                if(it->second->isEndOfWord){
                    *wordsBulk += "\n";
                }
                formWords(it->second, wordsBulk);
            }
        }
        
        bool find(string word, int currentIndex, TrieNode* node, bool isEndOfWord){
            if(node->children.count(word[currentIndex]) != 0){
                if(node->children[word[currentIndex]]->isEndOfWord && isEndOfWord){
                    return true;
                }else{
                    currentIndex += 1;
                    return find(word, currentIndex, node->children[word[currentIndex - 1]], currentIndex == word.size() - 1);
                }
            }else{
                return false;
            }
        }

        void autocomplete(string word, int currentIndex, TrieNode* node, bool isEndOfWord){
            if(node->children.count(word[currentIndex]) != 0){
                if(isEndOfWord){
                    string wordsBulk = "";
                    formWords(node->children[word[currentIndex]], &wordsBulk);
                    cout << wordsBulk;
                }else{
                    currentIndex += 1;
                    autocomplete(word, currentIndex, node->children[word[currentIndex - 1]], currentIndex == word.size() - 1);
                }
            }
        }
};

#endif