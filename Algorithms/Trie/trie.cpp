#include<iostream>

using namespace std;


class TrieNode {
    private:
    TrieNode *links[26];
    bool isEnd;

    public: 
    TrieNode() {
        // initialize all links to null 
        for(int i = 0 ; i < 26 ; ++i) {
            links[i] = nullptr; 
        }
        // isEnd set to false 
        isEnd = false; 
    }
    // whether this node contains key ch 
    bool containsKey(char ch) {
        if (links[ch - 'a'] != nullptr) return true;
        return false; 
    }
    void put(char ch, TrieNode *node) {
        links[ch - 'a'] = node ; 
    }

    TrieNode *get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        isEnd = true; 
    }

    bool isEndOfWord() {
        return isEnd == true; 
    }
};


class Trie {
public:
    TrieNode *root ; 
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root; 
        for(int i = 0 ; i < word.size() ; ++i) {
            // if the node does not contain this character
            if ( !node->containsKey(word[i])) {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd() ; 
    }
    
    bool search(string word) {
        TrieNode *node = root ; 

        for(int i= 0 ; i < word.size() ; ++i ) {
            if ( !node->containsKey(word[i])) {
                return false; 
            }
            node = node->get(word[i]);
        }
        return   node->isEndOfWord() ; 
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root; 

        for(int i = 0 ; i < prefix.size(); ++i) {
            if ( !node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true; 
        
    }
};

