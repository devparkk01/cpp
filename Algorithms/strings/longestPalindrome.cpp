/*  https://leetcode.com/problems/longest-palindrome/



time: O(n), space: O(n)

*/


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char ,int > hashmap; 

        for(char &x: s) {
            hashmap[x]++;
        }
        int totalEven = 0, totalOdd = 0; 
        int countOdd = 0; 
        for(auto &it: hashmap) {
            if ( it.second % 2 == 0) {
                totalEven += it.second; 
            }
            else {
                countOdd++; 
                totalOdd += it.second - 1;
            }
        }
        return totalEven + (countOdd == 0 ? 0 : totalOdd + 1); 
    }
};