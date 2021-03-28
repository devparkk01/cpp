/*
https://cses.fi/problemset/task/1131
time : O(n)
*/
#include<bits/stdc++.h>
using namespace std ;
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
#define endl '\n'
#define ll long long
#define f(i , k , n ) for(int i = k ; i < n ; ++i)
#define ip pair<int , int >
#define um unordered_map<int , int >
#define us unordered_set<int >
#define vec vector
#define pb push_back

int findHeights(vec<int>tree[] , int src , int parent , int &dia , vec<int>& height ) {
	int firstmax = 0 , secondmax = 0 ;
	// finds max height and second max height among children nodes of src
	for (int &child : tree[src]) {
		if ( child != parent ) {
			height[child] = findHeights(tree, child , src , dia , height) ;
			if (height[child] > firstmax) {
				secondmax = firstmax ;
				firstmax = height[child] ;
			}
		}
	}

	int childrencount = tree[src].size() ; // count of the children nodes of src
	if ( src != 1) childrencount-- ; // removing parent node from the count


	// src is a leaf node
	if ( childrencount == 0) height[src] = 0 ;
	// src has only one child
	else if ( childrencount == 1 ) {
		height[src] = 1 + firstmax ;
		dia = max(dia , 1 + firstmax ) ;
	}
	else { // src has more than one children nodes
		height[src] = 1 + firstmax ;
		dia = max(dia , 2 + firstmax + secondmax ) ;
	}
	return height[src] ;

}


signed main () {
	int n ; cin >> n ;
	vec<int>tree[n + 1 ] ; int a , b ;
	f(i , 0 , n - 1 ) {
		cin >> a >> b ;
		tree[a].pb(b) ;
		tree[b].pb(a) ;
	}
	int dia = 0 ; // stores the diameter of the tree
	vec<int>height(n + 1 ) ;
	findHeights(tree , 1  , 0,  dia , height ) ; // assume that parent of node 1 is 0
	cout << dia << endl;
	return 0 ;

}

