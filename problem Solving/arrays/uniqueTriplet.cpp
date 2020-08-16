/*Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

nums = [-1, 0, 1, 2, -1, -4]
return [ [-1, 0, 1], [-1, -1, 2] ]

nums = [-1,0,1,-1]
return [[-1,0,1]] 

only return unique pairs 

we are gonna use two pointer technique here . 
time : O(n*n ) 
*/


#include<bits/stdc++.h>
using namespace std ; 

vector<vector<int>> countUniqueTriplets (vector<int>&nums ) {
	sort(nums.begin(),nums.end() ) ; // need to sort the array . 
	vector<vector<int>> res ;  // stores unique triplets 

	int n = nums.size() ; int j , k ; 
	for(int i = n-1 ; i>=2 ; --i ) {
		/* very important line , if we've seen nums[i] already then we would have considered its all 
		triplets before. So , here we can skip this nums[i] since it would lead to redundant triplet.
		*/
		if ( i < n-1 && nums[i] == nums[i+1]) 
			continue ; 
		j = 0 ; k = i-1 ; 
		while (j < k ) {
			if ( nums[j] + nums[k] + nums[i] == 0) {
				res.push_back({nums[j] , nums[k] , nums[i]}) ;
				// removing duplicates from left end 
				while ( j < k && nums[j] == nums[j+1]) 
					j++ ; 
				// removing duplicates  from right end 
				while ( j < k && nums[k] == nums[k-1])
					k-- ; 
				j++ ; k-- ; 
			}
			else if ( nums[j] + nums[k] + nums[i] < 0 )
				j++ ; 
			else k-- ; 
		}
	}

	return res ; 
}
	
void print ( vector<vector<int>>v ) {
	for(int i = 0 ;i < v.size() ; ++i ) {
		for(int j = 0 ; j < v[i].size() ; ++j ) {
			cout << v[i][j] << " " ; 
		}
		cout << endl; 
	}
}

signed main () {
	// vector<int>nums = {-1,0 ,1 ,-1 } ; 
	vector<int> nums = {-1, 0, 1, 2, -1, -4} ; 

	print(countUniqueTriplets(nums)) ; 
	return 0 ;
}


