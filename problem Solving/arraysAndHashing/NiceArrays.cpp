/*
https://leetcode.com/problems/count-number-of-nice-subarrays/

*/

/*
method 1 :
count the no of subarrays having at most odd numbers k = n1
count the no of subarrays having at most odd number k -1  = n2

return n1 - n2 ;

time : O(n) , space : O(1)


*/

class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		return countArrays(nums , k) - countArrays(nums , k - 1 ) ;
	}

	int countArrays(vector<int>&nums , int k ) {
		int res = 0 ;
		int l = 0 ;
		int count = 0 ;
		for (int r = 0 ; r < nums.size() ; ++r) {
			count += (nums[r] % 2 ) ;
			if (count > k ) {
				while (count > k ) {
					count -= (nums[l] % 2 ) ;
					l++ ;
				}
				res += (r - l + 1 )  ;
			}
			else res += (r - l  + 1 ) ;

		}
		return res ;
	}
};

/*
method 2  :
given , nums[] = { 1 , 2 , 3 , 1 , 1 , 2 , 5 , 7 }

change it to :  { 1 , 0 , 1 , 1 , 1 , 0 , 1 , 1 }
now find the number of subarrays having sum k

time : O(n) , space : O(n)

*/

class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		for (int i = 0 ; i < nums.size() ; ++i) nums[i] = nums[i] % 2 ;

		unordered_map<int , int > hash ;
		hash[0] = 1 ;
		int sum = 0 ;
		int ans = 0 ;
		for (int i = 0 ; i < nums.size() ; ++i) {
			sum += nums[i] ;
			if (hash.find(sum - k ) != hash.end() ) {
				ans += hash[sum - k]  ;
			}
			hash[sum]++ ;

		}
		return ans ;
	}


};


