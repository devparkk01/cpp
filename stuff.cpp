#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& v) {
	for(auto x : v ) {
		cout << x << " " ; 
	}
	cout << endl; 
}


signed  main() {
	// your code goes here
	map<int , vector<int>> m ; 
	m[10] = {4,5,2,6} ; 
	m[20] = {9,3,-2,2 } ; 
	sort(m[10].begin() , m[10].end()) ; 
	print(m[10] ) ; 
	print(m[20] ) ; 

	for(auto it = m.begin() ; it != m.end() ; ++it) {
		sort(it->second.begin() , it->second.end()) ;

	}
	print(m[20]) ; 
	print(m[10]) ; 

	
	return 0;
}