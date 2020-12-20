
#include<bits/stdc++.h>
using namespace std ;
#define vec vector

struct job {
	int start , end , profit  ;
};

bool compare (job&a , job&b ) {
	return a.end < b.end ;
}

int lastNonConflictingJob(vec<job>&jobs , int n ) {
	int low = 0 , high = n  ;
	int ans = -1 ;  int endTime = jobs[high].start ;
	while (low <= high ) {
		int mid = low + (high - low ) / 2 ;
		if ( jobs[mid].end <= endTime ) {
			ans = mid ;
			low = mid + 1 ;
		}
		else high = mid - 1 ;
	}
	return ans ;
}


int maxProfit(vec<job>&jobs , int n , vec<int>&mem) {
	if ( n == 0 ) return jobs[0].profit ;
	if ( mem[n] != -1 ) return mem[n] ;
	else {
		int inc = jobs[n].profit ;
		int i = lastNonConflictingJob(jobs , n) ;
		if ( i != -1 ) {
			inc += maxProfit(jobs , i , mem ) ;
		}
		int exc = maxProfit(jobs , n - 1 , mem ) ;
		mem[n] = max(inc , exc ) ;
		return mem[n] ;
	}
}



signed main () {
	vec<job> jobs = {
		{ 0, 6, 60 },
		{ 1, 4, 30 },
		{ 3, 5, 10 },
		{ 5, 7, 30 },
		{ 5, 9, 50 },
		{ 7, 8, 10 }
	};

	int n = jobs.size() ;
	vec<int>mem(n , -1 )  ;
	sort(jobs.begin() , jobs.end() , compare ) ;
	// passing the index of the last job ,rather than passing the total no of jobs
	cout << maxProfit(jobs , n - 1 , mem  ) << endl;

	return 0 ;

}