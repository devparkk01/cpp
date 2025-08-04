/*Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.
A[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13} , k = 4
output : 10 10 10 15 15 90 90

naive approach : brute force : time : O(n*k)
window sliding method : time : O(n)

*/

#include<bits/stdc++.h>
using namespace std;

// Easy to understand code 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans; ans.reserve(n);

        deque<int>dq; 

        // process first k elements
        for(int r=0 ; r < k ; ++r) {
            while(!dq.empty() && nums[r] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(r);
        }
        // get the result for first window 
        ans.push_back(nums[dq.front()]);

        // process rest of the elements
        for(int r = k ; r < n; ++r){
            // extend the boundary towards the right 
            while(!dq.empty() && nums[r] > nums[dq.back()]) {
                dq.pop_back(); 
            }
            dq.push_back(r);

            // move the window from left
            if ( dq.front() == r-k ) {
                dq.pop_front();
            }

            // get the result for current window 
            ans.push_back(nums[dq.front()]);
        }
        return ans; 
 
    }
};

vector<int>max_of_subarrays(int arr[], int n, int k)
{
	vector<int>ans ;
	int i = 0 , j = 0 ;
	int window ;
	deque<int>candidate ;
	while (j < n) {
		window = j - i + 1 ;
		if (window < k ) {
			while (!candidate.empty() && arr[candidate.back()] <= arr[j]) candidate.pop_back() ;
			candidate.push_back(j) ;
			j++ ;
		}
		else if (window == k ) {
			while (!candidate.empty() && arr[candidate.back()] <= arr[j]) candidate.pop_back() ;
			candidate.push_back(j) ;

			ans.push_back(arr[candidate.front()]) ;
			if (candidate.front() == i ) candidate.pop_front() ;
			i++ ; j++ ;

		}
	}

	return ans ;

}

signed main () {
	int A[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13} ;
	int n = sizeof(A) / sizeof(int) ;
	int k = 4 ;
	vector<int>ans = max_of_subarrays(A, n , k ) ;
	for (int &x : ans ) {
		cout << x << " " ;
	}
	return 0 ;
}