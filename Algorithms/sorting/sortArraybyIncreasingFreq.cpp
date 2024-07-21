/*https://leetcode.com/problems/sort-array-by-increasing-frequency/

time: O(n log n)
*/


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int , int> freq; 
        for(auto &num: nums) {
            freq[num]++;
        }
        /*lambda function
        [&freq] means we are capturing outside variable `freq` by reference for the lambda function.
        [&] means we wanna capture all outside variable by reference for the lambda function.
        [] means we don't wanna capture any variable from outside. 

        Capturing sometimes help because lambda function has only access to variables which are local to it. 
        That's why capturing external variables help in some cases. 
        */
        sort(nums.begin(), nums.end(), [&freq](int a, int b) {
            return freq[a] == freq[b] ? a > b : freq[a] < freq[b];
        });

        return nums; 
    }
};