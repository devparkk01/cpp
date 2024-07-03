/*
https://leetcode.com/problems/car-pooling/description/?envType=problem-list-v2&envId=521bd3dv

*/




class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size(); 
        map<int, int > tpmap; 

        for( auto &trip: trips) {
            tpmap[trip[1]] += trip[0];
            tpmap[trip[2]] -= trip[0];
        }

        int curCap = 0 ;
        for( auto &p : tpmap) {
            curCap += p.second; 
            if ( curCap > capacity) return false; 
        }

        return true; 

    }
};