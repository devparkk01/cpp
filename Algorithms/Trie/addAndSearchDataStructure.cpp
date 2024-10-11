/*
https://leetcode.com/problems/design-add-and-search-words-data-structure/

*/

class TrieNode {
    public:
    TrieNode *links[26];
    bool isEnd; 

    TrieNode () {
        for(int i= 0 ; i < 26 ; ++i) {
            links[i] = nullptr;
        }
        isEnd = false;
    }

    bool containsKey(char ch) {
        return ( links[ch - 'a'] != nullptr); 
    }

    TrieNode *get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode *node ) {
        links[ch - 'a'] = node ; 
    }

    void setEnd() {
        isEnd = true; 
    }

    bool isEndOfWord() {
        return (isEnd == true);
    }

};



class WordDictionary {
public:
    TrieNode *root; 
    WordDictionary() {
        root = new TrieNode();
    }
    
    // time: O(M), M is the length of the word 
    void addWord(string word) {
        TrieNode *node = root; 
        for(int i = 0 ; i < word.size();  ++i) {
            char ch = word[i];
            if ( !node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd(); 
    }
    /* time: O(M) if M exists as the normal string without any dots ( wildcard), M = length of the word
    for other cases, O(N * 26^M) => N is total no of words, M is the length of the word to be searched. 
    */
    bool search(string word) {
        TrieNode *node = root; 
        return searchWildCard(node, word, 0, word.size());
    }

    bool searchWildCard(TrieNode *node, string &word, int start, int size) {
        // base conditions 
        if ( node == nullptr) {
            return false; 
        }

        if ( start == size ) {
            return node->isEndOfWord(); 
        }

        if ( word[start] == '.') {
            for(int i = 0 ; i < 26; ++i) {
                if (node->links[i] != nullptr) {
                    if (searchWildCard(node->links[i] , word, start + 1, size)) {
                        return true; 
                    }
                }
            }
            return false;
        }
        else {
            if ( node->containsKey(word[start])) {
                return searchWildCard(node->get(word[start]), word, start + 1, size);
            }
            return false;
        }
        return false ; 

    }
};

