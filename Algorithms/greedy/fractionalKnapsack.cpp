/*Given weights and profits of n items, we need to put these items in a knapsack of capacity W to get
 the maximum total profit in the knapsack.
we can break items for maximizing the total profit of knapsack.
This problem in which we can break an item is also called the fractional knapsack problem.


arr[] = {{60, 10}, {100, 20}, {120, 30}} => {profit , weight }
Knapsack Capacity, W = 50;

Output:
Maximum profit  = 240
by taking items of weight 10 and 20 kg and 2/3 fraction
of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240
time : O(n log n )
*/


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
	int n = arr.size() ;
	int w = 50 ;

	cout << fractionalKnapsack(arr , n , w ) << endl;

	return 0 ;
}