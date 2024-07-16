/*https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

Awesome problem. 


Approach:
we will use dijkstra algo here. 

time: O(E log V + E) => E log v for dijkstra, extra E for buildling the graph.
*/

#include<bits/stdc++.h>
using namespace std; 


#define ll long long 
class Solution {
public:
    int mod = 1000000007;
    int countPaths(int n, vector<vector<int>>& roads) {
        // build the graph
        vector<vector<pair<ll, ll>>>graph(n);
        for(auto &road: roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        // pair< long long, int> -> pair<distance, node>
        priority_queue<pair<ll, ll>, vector<pair<ll , ll>>, greater<pair<ll ,ll>> >minHeap; 
        // dist arrays stores shortest distance to reach a particular node from 0 ( source)
        vector<ll>dist(n, LONG_MAX);
        // ways stores total no of ways to reach a particular node in the shortest amount of time 
        // from 0 (source)
        vector<ll >ways(n);
        dist[0] = 0;
        ways[0] = 1; 
        // push source node into the minHeap.
        minHeap.push({dist[0], 0 });

        while(!minHeap.empty()) {
            auto [dis, u] = minHeap.top() ; minHeap.pop(); 
            // explore the nodes adjacent to u.
            for(auto &[adjNode, edgWt]: graph[u]) {
                // this condition is very important
                // if there is another path to reach adjacent node such that the shortest distance
                // remains the same, that means we have got more ways to reach the adjacent node
                // for the same minimum distance.
                if ( dist[adjNode] == dis + edgWt) {
                    // total no of ways to reach adjacent node will get updated
                    ways[adjNode] = (ways[adjNode] + ways[u])% mod ;
                // normal dijkstra condition
                // if there is a shorter way to reach adjacent node, 
                } else if ( dist[adjNode] > dis + edgWt) {
                    dist[adjNode] = dis + edgWt;
                    // total no of ways to reach adjacent nodes will be equal to the no of ways 
                    // we could reach this current node. 
                    ways[adjNode] = ways[u];
                    minHeap.push({dist[adjNode], adjNode});
                }
            }
        }
        // cout << dist[n -1] << endl; 
        return ways[n - 1]; 
    }
};