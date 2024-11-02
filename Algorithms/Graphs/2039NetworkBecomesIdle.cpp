/*

https://leetcode.com/problems/the-time-when-the-network-becomes-idle/description/


*/

#include<bits/stdc++.h>


class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size(); 
        // build the graph
        vector<vector<int>>graph(n);
        for(auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // find the minimum distance of each server from the master server 
        vector<int>dis(n , 0 );
        vector<bool>visited(n, false);
        queue<int>q; 
        q.push(0);
        visited[0] = true;
        dis[0] = 0 ;

        while(!q.empty()) {
            auto node = q.front(); q.pop(); 
            for(auto &adjNode : graph[node]) {
                if (!visited[adjNode]) {
                    visited[adjNode] = true; 
                    q.push(adjNode);
                    dis[adjNode] = dis[node] + 1; 
                }
            }
        }

        // calculate when was the last message sent by each data server 
        for(int i = 0 ; i < n ; ++i){
            dis[i] = dis[i] * 2; // time when the ith data server receives the first message it sent

            // now calculate, how many extra messages this ith server sent to the master server 
            if ( patience[i] >= dis[i]) { // patience is more, so it did not send any extra message
                continue; 
            } else {
                int noOfMessages = (dis[i] / patience[i]) ; 
                int lastMessageSentTime = noOfMessages * patience[i];
                if ( dis[i] % patience[i] == 0 ) {
                    noOfMessages -= 1; // this subtraction is important
                    lastMessageSentTime = noOfMessages * patience[i];
                } 
                // add the time duration when ith data server will receive the last message it sent
                dis[i] += lastMessageSentTime;
            }
        }
        
        return *max_element(dis.begin(), dis.end()) + 1 ;

    }
};