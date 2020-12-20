/* Given a list of jobs where each job has a start and finish time , and also has a profit
associated with it , find maximum profit subset of non-overlapping jobs .

*/
// Dynamic programming approach (bottom up )
// time : O(n log n ) , space : O(n)


#include<bits/stdc++.h>
using namespace std ;
#define vec vector

struct job {
	int start , end , profit ;
};

bool compare(job&a , job&b ) {
	return  a.end < b.end ;
}


/*
function to find last non conflicting job ( using binary search )
*/

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


int maxProfit(vec<job>&jobs , int n ) {
	sort(jobs.begin() , jobs.end() , compare ) ;
	vector<int>dp(n) ;
	// dp[i] stores the max profit when we have jobs from 0 to ith index
	dp[0] = jobs[0].profit ;
	for (int i = 1; i < n ; ++i ) {
		// index stores the index of last non conflicting job with the ith index job
		int index = lastNonConflictingJob(jobs , i) ;
		int inc = jobs[i].profit ;
		if ( index != -1 ) {
			inc += dp[index] ;
		}
		int exc = dp[i - 1] ;
		dp[i] = max(inc , exc ) ;
	}
	return dp[n - 1] ;

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
	cout << maxProfit(jobs , n ) << endl;

	return 0 ;

}