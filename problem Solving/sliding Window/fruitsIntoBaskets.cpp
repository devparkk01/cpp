/*
https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1



brute force: O(n*n)
sliding window = o(n)
*/

#include<bits/stdc++.h>
using namespace std; 

int totalFruits(int n, vector<int> &fruits) {
    int maxFruits = 0 ;
    int l = 0 ;
    
    // key: fruit type, value: no of fruit of that type 
    // hashFruits store the count of fruit of a particular type currently in the basket
    unordered_map<int, int > hashFruits; 


    for(int r  = 0 ; r < n ; ++r) {
        hashFruits[fruits[r]]++; 

        // keep removing elements from the hashFruits until its size becomes 2
        while(l < r && hashFruits.size() > 2) {
            hashFruits[fruits[l]]--;
            if (hashFruits[fruits[l]] == 0) {
                hashFruits.erase(fruits[l]);
            }
            l++; 
        }
        maxFruits = max(maxFruits, r - l + 1) ;
    }
    
    
    return maxFruits; 
    
    
}



