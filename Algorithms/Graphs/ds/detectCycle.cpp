/* Here we will see how we can use union-find algo to detect cycle in an undirected graph 
time : O( E * V)

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

void printGraph (vector<ipair>&edgeList ) {
	for (ipair x : edgeList) {
		cout << x.first <<  " , " << x.second << endl ; 
	}
}

int find(vector<int> &parent , int i ) {
	if( parent[i] ==  -1 ) 
		return i ;
	return find(parent , parent[i]) ; 
}

void Union (vector<int> &parent ,int i ,int  j ) {
	int ip = find(parent , i ) ;
	int jp = find(parent , j ) ; 
	parent[ip] = jp ;
}

bool isCyclic(vector<ipair>&edgeList , int V ) {
	vector<int>parent(V , -1) ; 
	int ip , jp ; 
	for(ipair edge : edgeList ) {
		ip = find(parent , edge.first ) ; 
		jp = find(parent , edge.second ) ; 
		if( ip == jp )
			return true ;
		Union(parent , ip , jp  ) ; 
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

	// printGraph(edgeList) ; 

	cout << isCyclic(edgeList, V ) ; 

	return 0 ; 
}
