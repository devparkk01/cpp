/*
https://leetcode.com/problems/replace-words

*/

#include<iostream>
using namespace std; 

class TrieNode {
    public:
    TrieNode *links[26];
    bool isEnd; 

    TrieNode () {
        for(int i = 0 ; i < 26; ++i) {
            links[i] = nullptr;
        }
        isEnd = false; 
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != nullptr); 
    }

    TrieNode *get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode *node) {
        links[ch - 'a'] = node;
    }
    bool isEndOfWord() {
        return (isEnd == true);
    }

    void setEnd() {
        isEnd = true; 
    }
};

class Trie {
    public:
    TrieNode *root ;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *node = root ; 
        for(int i = 0 ; i < word.size(); ++i) {
            if ( !node->containsKey(word[i])) {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd(); 
    }

    string getSmallestWord(string word) {
        TrieNode *node = root; 
        for(int i = 0 ; i < word.size() ; ++i) {
            if ( !node->containsKey(word[i])) {
                return "";
            }
            node = node->get(word[i]);
            if ( node->isEndOfWord()) {
                return word.substr(0, i + 1); 
            }
        }
        return "";
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        

        string ans;
        Trie *trie = new Trie();

        for( string &word : dictionary) {
            trie->insert(word);
        }

        stringstream ss(sentence);
        string word ;
        while( ss >> word) {
            string smallWord = trie->getSmallestWord(word);
            (smallWord == "") ? ans.append(word ) : ans.append(smallWord);

            ans += " ";
        }

        ans.pop_back(); 

        return ans; 
    }
};






