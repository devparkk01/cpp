/*
https://leetcode.com/problems/car-fleet/
*/


#define ip pair<int, double> 
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(); 
        vector<ip> cars(n); 
        for(int i = 0 ; i < n;  ++i) {
            cars[i] = {position[i], double(target - position[i]) / speed[i]};
        }

        sort(cars.begin(), cars.end(), greater<ip>()); 

        int fleet = 1 ; 
        double curFleetTime = cars[0].second; 

        for(int i = 1 ; i < n ; ++i) {
            if ( cars[i].second > curFleetTime ) {
                fleet++; // we get a new fleet 
                curFleetTime = cars[i].second; 
            } else if (cars[i].second <= curFleetTime) {
                // this car will join the existing fleet
                // this is because some previous car which is ahead of this car by position,
                // has slower speed and is slowing other cars behind it even though they have higher 
                // speed 
        
            }
        }
        return fleet; 


    }
};