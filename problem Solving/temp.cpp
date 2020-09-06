#include<bits/stdc++.h>
using namespace std ; 



signed  main () {
	vector<int> v =  {3 , 3, 4 , 4 , 4, 1 , 0 , 5} ; 
	cout << v.size() << endl; 
	cout << accumulate(v.begin() , v.end() , 0) ; 
	return 0 ; 
}