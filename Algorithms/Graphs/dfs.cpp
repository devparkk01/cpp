#include<iostream>
#include<vector>

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
void dfs (vector<int>*adj , vector<int> &visited , int start ) {
    visited[start ] = 1 ; 
    cout << start << " " ; 
    // for (int i = 0 ; i < adj[start].size() ; ++i) {
    //     if (visited[adj[start][i]] == 0) {
    //         dfs(adj , visited , adj[start][i]) ; 
    //     }
    // }

    //  Advanced for loop
    for ( int x : adj[start]) {
        if (visited[x] == 0 ) {
            dfs(adj , visited , x ) ; 
        }
    }

}

void dfsUtil (vector<int> * adj , int V, int start ) {
    vector<int>visited(V+1) ; 
    dfs(adj , visited , start ) ; 

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

    dfsUtil(adj , V , start) ; 
    return 0 ; 

}