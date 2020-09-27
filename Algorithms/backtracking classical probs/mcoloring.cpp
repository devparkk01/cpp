/*Given an undirected graph and a number m, determine if the graph can be coloured with 
at most m colours such that no two adjacent vertices of the graph are colored with the 
same color. Here coloring of a graph means the assignment of colors to all vertices.

time : O(m^V) 
space : O(V)
*/

#include<bits/stdc++.h>
using namespace std ; 

//check if we can assign color c to u . 
bool isSafe(vector<vector<int>>&adj , int V , vector<int>&color, int u , int c ){ // c is for color 
	for(int i = 0 ;  i < V ; ++i ) {
		if ( adj[u][i] && color[i] == c )
			return false; 
	}
	return true ; 
}

bool graphColoringUtil(vector<vector<int>>&adj , int V , int m , vector<int>&color , int u ) {
	for(int c  = 1 ; c <= m ; ++c ) {
		if (isSafe(adj , V, color , u ,c)) {
			color[u] = c ; // assigning
			if (u == V-1) { // we reached the end 
				return true ; 
			}
			if (graphColoringUtil(adj , V , m ,color , u+1) )// explore 
				return true ; 
			color[u] = 0 ; // unassigning 
		}
	}
	return false ; // backtrack (couldn't find a color that can be assigned to u )
}

void print(vector<int>&color ) {
	for(int  &x : color ) {
		cout << x << " " ;
	}
	cout << endl ; 
}
bool graphColoring(vector<vector<int>>&adj , int V , int m ) {
	vector<int>color(V ) ;// initialize with 0 
	if ( graphColoringUtil(adj , V , m , color , 0 )) {
		print(color) ; 
		return true ;
	}
	else return false ; 

}

signed main(){
	int V = 4 ; 
	vector<vector<int>>adj = { 
        { 0, 1, 1, 1 }, 
        { 1, 0, 1, 0 }, 
        { 1, 1, 0, 1 }, 
        { 1, 0, 1, 0 }, 
    };  
    int m = 3 ; 
    cout << graphColoring(adj , V , m) << endl; 
    return 0 ; 

}