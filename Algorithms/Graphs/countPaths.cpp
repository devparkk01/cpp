/*Given a directed graph and two vertices source and destination, your task is to complete 
the function countPaths(), whose function is to count the total number of ways or paths that 
exist between two vertices in a directed graph. Also print all paths .

The Graph may be disconnected or may contain cycles, but the paths should not contain cycles.

*/
#include<bits/stdc++.h>
using namespace std ; 

void printPath(vector<int>&path) {
	for(int v : path) {
		cout << v << " " ;
	}
	cout << endl; 
}
// vector is slower than array , that's y I'm using array for visited 
void dfs(vector<int>adj[],bool visited[] ,vector<int>&path, int s ,int d,int&count ) {
    visited[s] = true ; 
    path.push_back(s) ; 
    if(s == d ) {
        count++  ;
        printPath(path) ;
        //  backtracking
        visited[s] = false ; 
        path.pop_back() ; 
        return ; 
    }
    else {
        for(int v : adj[s]) {
            if(!visited[v]) {
                dfs(adj,visited,path , v , d , count) ; 
            }
        }
        // backtracking
        visited[s] = false;  
        path.pop_back() ; 
    }
}

int countPaths(vector<int>adj[] , int V , int s, int d)
{
    bool visited[V] = {false } ; 
    vector<int>path  ; path.reserve(V) ; 
    int count = 0 ; 
    dfs(adj , visited ,path ,s, d,count) ; 
    return count ; 
}

signed main () {
	int V =  5 ; int E = 7 ; 
	vector<int>adj[V] ;
	int u , v ; 
	for(int i = 0 ; i < E ; ++i) {
		cin >> u >> v ; 
		adj[u].push_back(v) ;
	}
	int s , d ; cin >> s >> d ; 
	cout << countPaths(adj , V, s , d ) ; 


	return 0 ; 
}
/*
input : 
V = 5 , E = 7
0 1 
0 3 
2 0 
2 1 
2 4
4 0
1 3
s = 2,d = 3

*/


