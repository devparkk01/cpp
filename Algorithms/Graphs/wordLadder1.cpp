/*
https://leetcode.com/problems/word-ladder/

just do bfs

Approach:
keep a queue which stores a pair ( word and no of steps needed to transform word)
put the beginWord into the queue along with the no steps as 1. => q.push({beginWord, 1})

Whenever we pop a new element(word, steps) from the queue, we need to check what all possible transformation
of the popped string is available in the wordList. we can do that by changing each character of the popped
string from `a` to `z`.  if the new word exists in the wordList, then push it into the queue with 
total no steps as `steps + 1`. 

*/


#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<pair<string, int >> q; 
		// stores all wordList in a hashSet. It can be also used to find out if a word 
		// already been transformed, so we don't need to transform it again.
		unordered_set<string>hashWordList(wordList.begin() , wordList.end());
		// we can keep a hashset to keep track of words that have been transformed(similar to visited)
        // unordered_set<string>transformed;

        q.push({beginWord, 1});
        hashWordList.erase(beginWord);
        // transformed.insert(beginWord);

        while(!q.empty()) {
            auto [word, steps] = q.front(); q.pop(); 

            if (word == endWord) {
                return steps; 
            }

            for(int i = 0 ; i < word.size() ; ++i) {
                int originalChar = word[i];
                for(int c = 'a' ; c <= 'z' ; ++c) {
                    word[i] = c;
                    if ( hashWordList.find(word) != hashWordList.end()) {
                        q.push({word, steps + 1});
                        // transformed.insert(word);
                        hashWordList.erase(word);
                    }
                }
                word[i] = originalChar;
            }


        }
        return 0; 

    }
};