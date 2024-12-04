/*
https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1


*/

#define ll long long 
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        if ( n == 1) return 0;
        
        priority_queue<ll, vector<ll>, greater<ll>>minHeap;
        
        for(int i =0 ; i < n ; ++i) {
            minHeap.push(arr[i]);
            
        }
        
        ll cost = 0 ;
        while( minHeap.size() > 1) {
            ll first = minHeap.top(); minHeap.pop();
            ll second = minHeap.top(); minHeap.pop();
            cost += (first + second);
            minHeap.push(first + second);
        }
        return cost; 
    }
};
