// Given a graph , find the bfs for that graph

#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'
using namespace std ; 


void printAdjList (vector<int> *adj , int V) {
    for (int i = 1 ;i <= V ; ++i) {
        cout << i << "- >" ; 
        for (int j = 0 ;j < adj[i].size() ; ++j) {
            cout << adj[i][j]  << "  " ; 
        }
        cout << endl ; 
    }
}
// time complexity 0(V+E) , space complexity 0(V)
void bfs ( vector<int> * adj , int V , int start ) {
    vector<int>visited(V+1) ; 
    queue<int> q ; 
    q.push(start ) ; 
    visited[start] = 1 ; 

    while (! q.empty()) {
        int front = q.front() ;
        cout << front << " " ; 
        q.pop() ;
        for (int i = 0 ; i<adj[front].size() ; ++i) {
            if ( visited[adj[front][i]] == 0 ) {
                visited[adj[front][i]] = 1 ;
                q.push(adj[front][i]) ; 
            }
        }
    }

}


int main () {
    int V , E ; 
    cout <<"Enter no of vertices : " << endl; 
    cin >> V ; 
    cout << "Enter no of edges : " << endl ; 
    cin >> E ; 
    cout << "Enter adjacency list : " << endl; 

    vector<int> * adj  = new vector<int>[V + 1] ; 
    for (int i = 0 ; i< E; ++i) {
        int x , y ; 
        cin >> x >> y ; 
        adj[x].push_back(y) ; 
    }
    printAdjList(adj , V) ; 
    int start ; 
    cout << "Enter start vertex : " << endl; 
    cin >> start ; 
    bfs(adj , V , start ) ;
    return 0 ; 

}