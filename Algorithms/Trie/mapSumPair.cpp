/*
https://leetcode.com/problems/map-sum-pairs

*/
#include <iostream>
#include<unordered_map>
using namespace std;

class TrieNode {
    public:
    TrieNode *links[26];
    int sum;

    // constructor
    TrieNode() {
        sum = 0 ; 
        for(int i = 0 ; i < 26; ++i) {
            links[i] = nullptr;
        }
    }

    // returns true if the current node contains a link to the given character
    bool containsKey(char ch) {
        if ( links[ch - 'a'] != nullptr) return true; 
        return false ;
    }

    // get the link corresponding to a particular character ( assumes the link exists)
    TrieNode *get(char ch) {
        return links[ch - 'a'];
    }

    // add a link correponding to the given character
    void put(char ch, TrieNode *node) {
        links[ch - 'a'] = node;
    }

    int getSum() {
        return sum ; 
    }

    void addSum(int sum) {
        this->sum += (sum);
    }
    

};


class MapSum {
public:
    unordered_map<string , int> hashmap; 
    TrieNode *root ; 
    MapSum() {
        root = new TrieNode(); 
    }
    
    void insert(string key, int val) {
        TrieNode *node = root; 
        // if the key already exist in the hashmap
        int diff = val; 
        if ( hashmap.find(key) != hashmap.end()) {
            diff = val - hashmap[key];
        }
        // add the value the hashmap
        hashmap[key] = val; 
        for(int i = 0 ; i < key.size() ; ++i) {
            // if the node does not contain this key
            if ( !node->containsKey(key[i])) {
                node->put(key[i], new TrieNode());
            } 
            node = node->get(key[i]);
            node->addSum(diff);
        }

    }
    
    int sum(string prefix) {
        TrieNode *node = root; 
        for(int i = 0 ; i < prefix.size(); ++i) {
            if( !node->containsKey(prefix[i])) {
                return 0;
            }
            node = node->get(prefix[i]);
        }
        return node->getSum(); 
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main () {
    cout << "Some" << endl; 
    return 0;
}