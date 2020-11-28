#include<bits/stdc++.h>
using namespace std ;
#define endl '\n'

struct item {
	int profit , weight ;
};

bool compare(item &a , item & b ) {
	double r1 =  double(a.profit) / a.weight  ;
	double r2 =  double(b.profit) / b.weight ;
	return r1 > r2 ;
}

double fractionalKnapsack(vector<item>&arr , int n , int w ) {
	// sort(arr , arr + n , compare ) ;
	sort(arr.begin() , arr.end() , compare ) ;
	double totalProfit = 0 ;
	double totalWeight = 0 ;

	for (item x : arr ) {
		if ( totalWeight + x.weight <= w ) {
			totalProfit += x.profit ;
			totalWeight += x.weight ;
		}
		else {
			totalProfit += (w - totalWeight ) * double(x.profit ) / x.weight  ;
			break ;
		}
	}
	return totalProfit ;

}

signed main () {

	vector<item>arr  = { { 60, 10 }, { 100, 20 }, { 110, 30 } };

	// int n = sizeof(arr) / sizeof(item ) ;
	int n = arr.size() ;
	int w = 50 ;

	cout << fractionalKnapsack(arr , n , w ) << endl;

	return 0 ;
}