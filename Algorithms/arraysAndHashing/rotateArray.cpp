/* https://leetcode.com/problems/rotate-array/

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

*/
#include<bits/stdc++.h>
using namespace std; 


// first solution: using space
// time: O(n), space: O(n)
/*Approach here is to maintain a copy of the array. Then move each element in the original array
by k position. 
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =  nums.size(); 
        k = k % n; 
        vector<int>copy(nums.begin(), nums.end());
        for(int i = 0 ; i < n ; ++i) {
            nums[(i+k)%n] = copy[i]; 
        }
    }
};




// Optimised solution: without using any space
// time: O(n), space: O(1)
/* Approach: Reverse the array. then reverse first k element, then reverse last (n-k) elements. 
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        int i = 0;
        while (i < k / 2) {
            swap(nums[i], nums[k - 1 - i]);
            i++;
        }
        i = 0;
        while (i < (n - k) / 2) {
            swap(nums[i + k], nums[n - 1 - i]);
            i++;
        }
    }
};