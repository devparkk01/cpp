
#include<bits/stdc++.h>
using namespace std ;

#define ip pair<int , int>
#define pb push_back
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0) ; cin.tie(NULL) ;


bool compare(ip &a , ip &b) {
	if (a.second >= b.second ) return 1 ;
	return 0 ;
}

void solve(vector<int>&a , int &m) {
	int sz = a.size() ;

	unordered_map<int , int  > freq ;
	for (int &x : a ) freq[x]++ ;
	vector<ip>temp ;
	for (auto &t : freq) {
		temp.pb(t) ;
	}
	sort(temp.begin() , temp.end() , compare ) ;

	vector<int>ff ;
	for (int i = 0 ; i <  m ; ++i) {
		ff.push_back(temp[i].first) ;
	}
	sort(ff.begin()  , ff.end() ) ;
	for (int i = 0 ; i < ff.size() ; ++i) {
		cout << ff[i] << " " ;
	}
	cout << endl;
}



int main() {
	int n , m ;
	cin >> n >> m ;
	vector<int>a[n] ; int u, v , x  ;
	for (int i = 0 ; i < n ; ++i) {
		cin >> u >> v ;
		u-- ;
		for (int i = 0 ; i < v ; ++i) {
			cin >> x ;
			a[u].pb(x) ;
		}
	}
	for (int i = 0 ; i < n ; ++i) {
		cout << i + 1 << endl;
		solve(a[i] , m ) ;
	}



	return 0 ;
}

