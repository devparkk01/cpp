/* https://leetcode.com/problems/accounts-merge/description/


Perform dfs 

*/

#include<bits/stdc++.h>
using namespace std; 


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph = buildGraph(accounts);

        unordered_set<string>visited; 
        vector<vector<string>>ans; 
        ans.reserve(accounts.size());


        for(auto &account: accounts) {
            string name = account[0];
            string firstEmail = account[1];
            vector<string>emailList; emailList.reserve(account.size());
            emailList.push_back(name);
            if ( visited.find(firstEmail) == visited.end()) {
                dfs(firstEmail, graph, visited, emailList);
                sort(emailList.begin() + 1, emailList.end());
                ans.push_back(emailList);
            } 
        }

        return ans; 


    }

    void dfs(string email, unordered_map<string, vector<string>>&graph, unordered_set<string>&visited, vector<string>&emailList) {
        visited.insert(email);
        emailList.push_back(email);

        for(auto &v: graph[email]) {
            if ( visited.find(v) == visited.end()) {
                dfs(v, graph, visited, emailList);
            }
        }
    }

    unordered_map<string, vector<string>> buildGraph(vector<vector<string>>&accounts) {
        // Build the adjacency list consisting of emails only.
        unordered_map<string, vector<string>>graph ; 
        for(int i = 0 ; i < accounts.size() ; ++i) {
            for(int j = 2 ; j< accounts[i].size()  ; ++j) {
                graph[accounts[i][j]].push_back(accounts[i][j-1]);
                graph[accounts[i][j-1]].push_back(accounts[i][j]);
            }
        }
        return graph; 
    }
};