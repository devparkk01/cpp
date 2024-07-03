/*
https://leetcode.com/problems/gas-station/description/?envType=problem-list-v2&envId=50f6p33i
*/



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // if total gas is less than total cost, then no ways we can complete the circuit/loop
        if ( accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(),  cost.end(), 0 ) ) {
            return  -1; 
        }

        int n = gas.size(); 
        int start = 0; // stores index of the gas station where we would start.
        // stores the total gas in the tank along the way if we started at `start` index/ gas station.
        int tank = 0; 
        for(int i = 0 ; i < n ; ++i ) {
            tank += (gas[i] - cost[i]); 
            // total gas got negative, that means we can't move to the next station if started from our
            //  previously selected `start`. Hence, move start to the next gas station.
            if ( tank < 0) {
                tank = 0 ; 
                start = i + 1; 
            }
        }
        return start ; 
    }
};