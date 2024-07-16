/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/

*/


#include<bits/stdc++.h>
using namespace std; 


// stores flight information which will be later put into the queue
class flight {
    public:
    int node, price; 

    flight(int node, int price) {
        this->node = node;
        this->price = price;
    }

    // flight() {}
};


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // build the graph
        vector<vector<pair<int, int > >>graph(n);
        for(auto &flight: flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        // store the minimum price taken to reach i the city from src, such that total no of stops does not exceed k.
        vector<int>prices(n , INT_MAX);
        prices[src]  = 0 ; 
        queue<flight>q; 
        q.push(flight(src, prices[src]));

        // stores total no of stops taken so far
        int stopsTaken = 0 ; 

        // run while the q is not empty or stopsTaken does not exceed k.
        while(!q.empty() && stopsTaken <= k ) {
            int size = q.size(); 
            // for each node in this level.
            while(size--) {
                auto [u, price] = q.front(); 
                q.pop(); 
                // check if there is a shorter path to reach neighbouring node. 
                for(auto &[neighbour, nprice]: graph[u]) {
                    if ( prices[neighbour] > price + nprice ) {
                        prices[neighbour] = price + nprice; 
                        q.push(flight(neighbour, prices[neighbour]));
                    }
                }
            }
            // increment stopTaken 
            stopsTaken++; 
        }

        return ( prices[dst] == INT_MAX) ? -1: prices[dst];
 
    }
};