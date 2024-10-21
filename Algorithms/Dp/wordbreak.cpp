/*
139: 
https://leetcode.com/problems/word-break/

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into 
a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/


#include<bits/stdc++.h>
using namespace  std ;


/*recursive approach
    Time Complexity : O(2^N), Given a string of length n, there are n+1 ways to split it into two parts. At each
    step, we have a choice: to split or not to split. In the worse case, when all choices are to be checked, that
    results in O(2^N).

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size() ; 
        unordered_set<string>dict(wordDict.begin(), wordDict.end());
        return util(s, n , dict, 0);
    }

    // Returns true if it's possible to segment substring starting from index `start` till end, into space separated sequence of one or more dictionary words
    bool util(string s, int n, unordered_set<string>&dict, int start) {
		// if we have reached the end of the string, then it's possible to segment, return true 
        if ( start == n) {
            return true;
        }

        for(int i = start ; i < n ; ++i) {
            string prefix = s.substr(start, i - start + 1);
            if (dict.find(prefix) != dict.end() && util(s, n, dict, i + 1)) {
                return true; 
            }
        }
        return false; 
    }
};

/* top down approach

Time: O(N^3 + M), where N  is length of string s, where M is length of wordDict.
There are total N dp states, they are dp[0], dp[1],.., dp[n], each dp state needs a loop O(N^2) to calculate the result.
Plus the time to build hashset from wordDict, which is O(M)
So total complexity is: O(N * N^2 + M) = O(N^3 + M)
*/ 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size() ; 
        unordered_set<string>dict(wordDict.begin(), wordDict.end());
		// mem[i] stores if it's possible to segment substring starting from index i till end, into space separated sequence of one or more dictionary words
        vector<int>mem(n , -1);
        return util(s, n , 0, dict, mem);
    }

    bool util(string s, int n, int start, unordered_set<string>&dict, vector<int>&mem) {
		// if we have reached the end of the string, then it's possible to segment, return true 
        if ( start == n) {
            return true;
        }
        if ( mem[start] != -1) {
            return mem[start];
        }
        for(int i = start ; i < n ; ++i) {
            string prefix = s.substr(start, i - start + 1);
            if (dict.find(prefix) != dict.end() && util(s, n, i + 1, dict, mem)) {
                mem[start] = true; 
                return mem[start];
            }
        }
        mem[start] = false ; 
        return mem[start];
    }
};


int main() {
	string s = "Wordbreakproblem";
	vector<string> wordDict = { "this", "th", "is", "famous", "Word", "break",
	                             "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem"
	                           };

    
    Solution test = Solution();

	if (test.wordBreak(s , wordDict)) {
		cout << "The string can be segmented";
	}
	else {
		cout << "The string can't be segmented";
	}

	return 0;
}