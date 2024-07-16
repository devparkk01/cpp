/*  https://leetcode.com/problems/alien-dictionary/

Really nice problem. 
It's based on topo sort. we will use kahn's algo to do topo sort here. 

First, we need to create dependency graph between character. 

*/


#include<bits/stdc++.h>
using namespace std; 


class Solution {
public:
    string alienOrder(vector<string>& words) {
        // build the graph 
        // each character will be considered nodes and their dependencies on each other will be represented as directed edge
        unordered_map<char, vector<char>>graph  ; 
        unordered_map<char, int>indegree;
        // insert all characters into indegree
        // otherwise, we might miss characters whose indegree are 0, at the time of pushing them into the queue for the first
        // time. 
        for(auto &word: words) {
            for(char &c: word) {
                indegree[c] = 0 ; 
            }
        }
        for(int i = 0; i < words.size() - 1 ; ++i) {
            string firstWord = words[i];
            string secondWord = words[i + 1];
            // edge case, this is when second word is a prefix of the first word
            // first word = "carpet", second_word = "car", this is not correct, as this does not represent lexographical 
            // order. "car" should come before "carpet". 
            if ( firstWord.size() > secondWord.size()  && firstWord.substr(0, secondWord.size()) == secondWord) {
                return "";
            }
            int j = 0;
            // compare each character one by one until we find a character which is not equal
            while( j < firstWord.size() && j < secondWord.size())  {
                if ( firstWord[j] == secondWord[j]) j++; 
                else {
                    // this means firstWord[j] should come before secondWord[j]. hence we can think of it as an directed edge
                    // from the first character to the latter. Hence, we also update the indegrees. 
                    graph[firstWord[j]].push_back(secondWord[j]);
                    indegree[secondWord[j]]++;
                    break; 
                }
            }

        }
        // start kahn's algo
        // consider 
        queue<char>q; 
        // push all the nodes/character whose indegree is 0 into the queue .
        for(auto &x: indegree) {
            if(x.second == 0) {
                q.push(x.first);
            }
        }
        // final string 
        string ans = "";
        while(!q.empty()) {
            auto c = q.front(); q.pop(); 
            ans += c;

            for(char &x: graph[c]) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        // if all character are not included in the ans, that means the given input string does not have lexicographic order
        // hence, return empty string "".
        return (ans.size() == indegree.size()) ? ans : ""; 
    }


};
