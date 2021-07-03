/*  https://practice.geeksforgeeks.org/problems/alien-dictionary/1

approach is discussed at the bottom
*/




class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        unordered_map<char , vector<char>> adj ;
        unordered_map<char , int > indegrees ;
        for (int i = 0 ; i < N - 1 ; ++i) {
            string word1 = dict[i] ;
            string word2 = dict[i + 1 ] ;
            for (int j = 0 ; j < min(word1.length() , word2.length()) ; ++j) {
                if (word1[j] == word2[j]) continue ;
                else {
                    adj[word1[j]].push_back(word2[j]) ;
                    indegrees[word2[j]]++ ;
                    if (indegrees.find(word1[j]) == indegrees.end()) {
                        indegrees[word1[j]] = 0 ;
                    }
                    break;
                }
            }
        }

        string output = topsort(adj , indegrees , K );

        return output   ;


    }
    string topsort(unordered_map<char , vector<char>>&adj , unordered_map<char , int>&indegrees, int K ) {
        queue<char>q ;
        for (auto x : indegrees ) {
            if (x.second == 0 ) q.push(x.first) ;
        }
        string ans = ""  ;
        while (!q.empty()) {
            char t = q.front() ; q.pop() ;
            ans.push_back(t) ;
            for (char &x : adj[t]) {
                indegrees[x]-- ;
                if (indegrees[x] == 0 ) q.push(x) ;
            }
        }
        return  ans ;

    }
};



/*
idea :
think of graph .
Try of create a dependency graph of characters .
Once you have the dependency graph , use topo sort to calculate the order of alphabets

used kahn's algo to calculate topo sort


*/