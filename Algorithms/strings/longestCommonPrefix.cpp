/*
https://leetcode.com/problems/longest-common-prefix
*/


/* basic approach: 
pick any string( preferably first string), and compare it's character one by one with 
rest of the strings. do it until this character matches with the other character in all other 
strings.
time: O(n * minsizeof any string) 
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size(); 
        int i = 0;
        while( i < strs[0].length()) {
            for(int j = 0 ; j < n ; ++j ) {
                if( strs[0][i] != strs[j][i]) {
                   return ans; 
                }
            }
            ans += strs[0][i];
            i++;
        }
        return ans; 

    }
};

/* Optimised approach
Sort the given array. Compare first string with the last one. This is because these two strings
are going to be the most diverse strings. Count the no of matching characters in these two strings
and we will get the answer.
time: O(n log n) + size of a string
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size(); 

        string first = strs[0];
        string last = strs[n -1 ];
        int i = 0;
        while( i < first.length() && i < last.length()) {
            if( first[i] == last[i]) {
                i++;
            } else {
                return first.substr(0,i);
            }
        }
        return first.substr(0,i);
    }
};
