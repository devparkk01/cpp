/*
https://leetcode.com/problems/design-hit-counter/


using queue is biggest hint

*/

#include<iostream>
#include<queue>

using namespace std; 

class HitCounter {
public:
    queue<int>counter;
    HitCounter() {
        
    }
    // time: O(1)
    void hit(int timestamp) {
        counter.push(timestamp);
        
    }
    // time: O(n)
    int getHits(int timestamp) {
        int startTime = timestamp - 300; 
        while( !counter.empty() && counter.front() <= startTime ){
            counter.pop();
        }
        return counter.size(); 
  
    }
};