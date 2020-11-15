#include<bits/stdc++.h>
using namespace std ; 

#define print(v) for(int i = 0 ; i<v.size() ; ++i) cout << v[i] << " " 
#define input(v , i ) cin >> v[i]  
#define f(i , k , n ) for(int i = k ; i < n; ++i )
#define add(a ,b) a+b 
#define mul(a, b) a*b 
#define endl '\n'
#define INF pow(2,31)-1 


signed main() {
	cout << "Enter 5 elements " << endl ; 
	vector<int>v(5) ;
	f(i , 0 , 5 ) input(v , i) ; 

	cout << "Printing elements " << endl; 
	print(v) ; 
	cout << endl ; 

	int a=4;  int b = 5 ; 
	int c = mul(a, b ) ;
	cout << add(a , b ) << "  "  <<  c << endl ; 

	cout << "INFINITY : " << INF << endl; 

	return 0  ; 
}