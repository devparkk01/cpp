/*Here we will optimize the union find operation using path compression and union by rank . 

The question is same to detect cycle in an undirected graph . 

input :  
V = 5,E = 5  
edge list  
0 1
1 2
2 3 
4 0 
3 3
output : 1 

V = 5 , E = 4 
edge list 
0 1
1 2
2 3 
4 0
output : 0 

*/


#include<bits/stdc++.h>
using namespace std ; 
#define ipair pair<int, int> 


struct Node{
	int parent ; 
	int rank ; 
} ; 


int find (vector<Node> &subsets , int i ) {
	if ( subsets[i].parent == -1 )
		return i ; 
	return subsets[i].parent = find(subsets , subsets[i].parent ) ; 
}

void Union(vector<Node>&subsets , int i , int j ) {
	int ip = find(subsets , i ) ; 
	int jp = find(subsets , j ) ;

	if (subsets[ip].rank < subsets[jp].rank ) {
		subsets[ip].parent = jp ;
	}
	else if ( subsets[ip].rank > subsets[jp].rank ) {
		subsets[jp].parent = ip ; 
	}
	else {
		subsets[ip].parent = jp ; 
		subsets[jp].rank++ ; 
	}

}

bool isCyclic(vector<ipair>&edgeList , int V) {
	vector<Node>subsets(V) ; 
	for(int i = 0 ;i < V; ++i ) {
		subsets[i].parent = -1 ; 
		subsets[i].rank = 0 ; 
	}

	int ip , jp ; 
	for(ipair x : edgeList ) {
		ip = find(subsets , x.first ) ;
		jp = find(subsets , x.second ) ;

		if (ip == jp ) return true ; 
		Union(subsets , ip, jp ) ; 
	}
	return false; 
}



signed main () {
	int V  ; int E ; cin >> V >> E ;  
	vector<ipair> edgeList(E, {0 ,0 }) ; // contains list of edges 

	int u1 , u2 ; 
	for (int i = 0 ;i < E ;++i ) {
		cin >> u1 >> u2 ; 
		edgeList[i] = {u1 , u2 }  ; 
	}

	cout << isCyclic(edgeList ,V  ) ; 

	return 0 ; 
}
