#include <bits/stdc++.h>

using namespace std;


int getmedian(int count[] , int d ) {
	if (d / 2 == 1 ) {
		d = d / 2 + 1;
		int c = 0; int i = 0 ;
		while (c + count[i] < d) {
			c += count[i] ;
			i++ ;
		}
		return 2 * i ;

	}
	else {
		d = d / 2 ;
		int c = 0 ; int i = 0 ; int first , second ;
		while (c + count[i] < d ) {
			c += count[i] ;
			i++ ;
		}
		first = i ;
		i = 200 ;
		c = 0;
		while (c + count[i] < d ) {
			c += count[i] ;
			i--;
		}
		second = i ;
		// cout << first <<  " " << second << " " ;
		return first + second ;
	}
	return -1 ;
}



int activityNotifications(vector<int> expenditure, int d) {
	int count[201] = {0} ;
	for (int i = 0 ; i < d ; ++i) count[expenditure[i]]++ ;
	int n = expenditure.size() ;
	// int c = 0 ;
	int ans = 0 ;

	for (int i = d ; i < n; ++i ) {
		int me = getmedian(count , d) ;
		// cout << me << " "  ;
		if ( expenditure[i] >= me ) ans++ ;
		count[expenditure[i - d]]-- ;
		count[expenditure[i]]++ ;
	}

	return ans;


}

int main() {
	int n , d; cin >> n >> d;
	vector<int>expenditure(n) ;
	for (int i = 0 ; i < n ; ++i) cin >> expenditure[i] ;

	cout << activityNotifications(expenditure , d) ;

	return 0 ;
}


