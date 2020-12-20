/* Given a list of jobs where each job has a start and finish time , and also has a profit
associated with it , find maximum profit subset of non-overlapping jobs .

*/

// Recursive approach is discussed here, time : O(logn * (2 ^n) )

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
	int low = 0 , high = n ;
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

int maxProfit (vec<job>&jobs , int n ) {
	if ( n == 0 ) return jobs[0].profit ; // there is only one job

	int i = lastNonConflictingJob(jobs , n ); // finds the index of last non conflicting job
	int included = jobs[n ].profit ;
	if ( i != -1 ) {
		included += maxProfit(jobs , i ) ;
	}
	int excluded = maxProfit(jobs , n - 1 ) ;
	return max(included , excluded) ;
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

	sort(jobs.begin() , jobs.end() , compare ) ;
	int n = jobs.size()  ;
	// passing the index of the last job ,rather than passing the total no of jobs
	cout << maxProfit(jobs , n - 1  ) << endl;

	return 0 ;

}