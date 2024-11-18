/*
https://leetcode.com/problems/evaluate-division/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void traversal(string first, string second,unordered_map<string, vector<pair<string, double>>>& relations, double curProd, double &ans, unordered_set<string>&visited ) {
        visited.insert(first);
        if ( first == second) {
            ans = curProd;
            return ;
        }
        for(auto [node, prod]: relations[first]) {
            if ( visited.count(node) == 0 ) {
                traversal(node, second, relations, curProd * prod, ans , visited);
            }
        }

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size(); 
        unordered_map<string, vector<pair<string, double>>> relations; 
        for(int i = 0 ; i < n ; ++i) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            double result = values[i];
            relations[dividend].push_back({divisor, result});
            relations[divisor].push_back({dividend, 1/ result});
        }
        int qsize = queries.size(); 
        vector<double>ans(qsize);
        unordered_set<string> visited; 
        for(int i = 0 ; i < qsize ; ++i) {
            double result = -1; 
            if ( relations.count(queries[i][0]) == 0 || relations.count(queries[i][1]) == 0) {
                ans[i] = -1.0; 
            }
            else if (queries[i][0] == queries[i][1] ) {
                ans[i] = 1.0;
            } else {
                traversal(queries[i][0], queries[i][1], relations, 1, result , visited);
                visited.clear();
                ans[i] = result; 
            }
        }

        return ans; 

    }
};