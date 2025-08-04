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

#define ip pair<int, int> 
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();

        vector<ip> start(n), departure(n);

        for(int i = 0; i < n ; ++i) {
            start[i] = {trips[i][1], trips[i][0]};
            departure[i] = {trips[i][2], trips[i][0]};
        }

        sort(start.begin(), start.end());
        sort(departure.begin(), departure.end());

        int count = 0 ; 
        int i = 0, j = 0 ; 
        while( i < n && j < n ) {
            if (start[i].first < departure[j].first) {
                count+=(start[i].second);
                i++; 
            } else {
                count -= (departure[j].second);
                j++;
            }
            
            if( count > capacity) return false; 
        }

        return true; 

    }
};




// Most optimised approach based on bucket sort. 

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size(); 
        vector<int>timeStamps(1001);

        for(auto &trip: trips) {
            auto passenger = trip[0];
            auto intime = trip[1];
            auto outtime = trip[2];

            timeStamps[intime] += passenger; 
            timeStamps[outtime] -= passenger; 
        }

        int curCapacity = 0 ;
        for(int i = 0 ; i <= 1000; ++i) {
            curCapacity += timeStamps[i];
            if ( curCapacity > capacity) return false;
        }
        return true; 
    }
};