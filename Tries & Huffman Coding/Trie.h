#include <iostream>
#include "TrieNode.h"
#include <string>
using namespace std;

class Trie {
    TrieNode *root;

    public :
    Trie() {
        root = new TrieNode('\0');
    }

    void insertWord(string word) {
        // Base Case
        if(word.size() == 0) {}
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL) {
            child = root->chidlren[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->chidlren[index] = child;
        }

        // Recursive Call
        insertWord(child, word.substr(1));
    }

    // For User
    void insertWord(string word) {
        insertWord(root, word);
    }
};