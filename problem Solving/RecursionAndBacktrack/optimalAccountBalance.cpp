/*
Rippling coding interview question
https://leetcode.com/problems/optimal-account-balancing/description/

backtracking
*/

#include<bits/stdc++.h>

class Solution {
public:
    // debts stores positive and negative debts that needs to be settled 
    vector<int> debts;
    int minTransfers(vector<vector<int>>& transactions) {
        // stores amount each person has. Positive amount represents he net borrowed money from others, negative
        // amount represents he net lent money to others.
        unordered_map<int, int> hashmap;
        for (auto &t : transactions) {
            int lender = t[0], borrower = t[1], amount = t[2];
            hashmap[lender] -= amount;
            hashmap[borrower] += amount;
        }  
        // find all the person for who's got non-zero debts 
        for (auto &p : hashmap) {
            if (p.second != 0) debts.push_back(p.second);
        }
        sort(debts.begin(), debts.end());

        return dfs(0);
    }
    
    int dfs(int start) {
        // stores min no of transacations required
        int transactionCount = INT_MAX;
        // Skip until we get to a non-zero current Debt
        while (start < debts.size() && debts[start] == 0) start++;
        // Settle debt using next values
        for (int i = start + 1; i < debts.size(); i++) {
            // debts[i] * debts[start] is negative means, 
            // 1. debts[start] is positive and debts[i] is negative, so start can give money to i, making one transaction
            // 2. debts[start] is negative and debts[i] is positive, so start can take money from i, making one transaction
            if (debts[i] * debts[start] < 0) {
                debts[i] += debts[start]; // we made a transaction here
                // recur for next debt
                transactionCount = min(transactionCount, 1 + dfs(start + 1));
                debts[i] -= debts[start];
            }
        }
        return transactionCount == INT_MAX ? 0 : transactionCount;
    }
};