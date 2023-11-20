#include <iostream>
#include "TrieNode.h"
using namespace std;

class Trie {
    TrieNode *root;

  public :
    
    Trie() {
        root = new TrieNode('\0');
    }

    bool search(TrieNode *root, string word) {
        if(word.size() == 0) {
           return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return false;
        }       

       return search(child, word.substr(1));
    }

    bool search(string word) {
        // Write your code here
        return search(root, word);
    }

    void insertWord(TrieNode* root, string word) {
        // Base Case
        if(word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive Call 
        insertWord(child, word.substr(1));
    }

    // For User
    void insertWord(string word) {
        insertWord(root, word);
    }

    void removeWord(TrieNode *root, string word) {
        // Base Case
        if(word.size() == 0) {
            root->isTerminal = false;
            return;
        }

        // Small Calculation meri
        TrieNode *child;
        int index = word[0] - 'a';
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            // Word not found !!
            return;
        }

        // Recursive Call
        removeWord(child, word.substr(1));

        // Remove child node if it is useless
        if(child->isTerminal == false) {
            for(int i = 0; i < 26; i++) {
                if(child->children[i] != NULL) {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    // For User
    void removeWord(string word) {
        removeWord(root, word);
    }
};



         
     
        
        