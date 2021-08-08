/*
https://practice.geeksforgeeks.org/problems/equivalent-sub-arrays3731/1/

*/


class Solution
{
public:
	int countDistinctSubarray(int arr[], int n)
	{
		unordered_map<int , int >hash ;
		unordered_set<int> set ;
		for (int i = 0 ; i < n ; ++i) set.insert(arr[i]) ;
		int k = set.size() ;


		int count = 0 ;
		int l = 0 ;
		for (int r = 0 ; r < n ; ++r ) {
			hash[arr[r]]++ ;
			if (hash.size() == k ) {
				while (hash.size() == k ) {
					count += (n - r  ) ;
					hash[arr[l]]-- ;
					if (hash[arr[l]] == 0 ) {
						hash.erase(arr[l]) ;
					}
					l++ ;
				}
			}


		}

		return count ;

	}
};