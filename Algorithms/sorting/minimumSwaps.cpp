/*
https://practice.geeksforgeeks.org/problems/minimum-swaps/1#

Given an array of n distinct elements. Find the minimum number of swaps required to sort
 the array in strictly increasing order.




time : O(nlogn) , space : O(n)

*/

class Solution
{
public:
	//Function to find the minimum number of swaps required to sort the array.
	int minSwaps(vector<int>&nums)
	{
		// Code here
		vector<int>copy(nums.begin() , nums.end()) ;
		sort(copy.begin() , copy.end()) ;
		unordered_map<int , int> position ;
		for (int i = 0 ; i < copy.size() ; ++i) {
			position[copy[i] ] = i ;
		}
		int count = 0 ;
		bool visited[nums.size()] = {0} ;

		for (int i = 0 ; i < nums.size() ; ++i ) {
			if (visited[i] == true ) continue ;
			int j = position[nums[i]] ;
			if (j == i ) continue ;
			count += countSwapsInCycle(i , nums , position , visited ) ;

		}

		return count ;

	}
	int countSwapsInCycle(int i , vector<int>&nums, unordered_map<int , int>&position , bool visited[]) {
		int j ;
		int count = 0 ;
		while (visited[i] == false ) {
			count++ ;
			visited[i] = 1 ;
			j = position[nums[i]] ;
			i = j ;
		}
		return count - 1 ;


	}

};