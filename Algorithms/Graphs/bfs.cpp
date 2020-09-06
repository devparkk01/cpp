// Given a graph , find the bfs for that graph

#include<bits/stdc++.h>
using namespace std ; 


// time complexity 0(V+E) , space complexity 0(V)
vector <int> bfs(vector<int> g[], int N) {
    vector<int> trav ; trav.reserve(N) ; 
    queue<int> q ; q.push(0) ;
    vector<bool>seen(N) ; seen[0] = 0 ; 
    int temp ; 
    while (!q.empty() ) {
        temp = q.front() ; q.pop() ;
        trav.push_back(temp) ;
        for(int x : g[temp]) {
            if ( ! seen[x]) {
                q.push(x) ;
                seen[x] = 1 ; 
            }
        }
    }
    return trav ; 
}

