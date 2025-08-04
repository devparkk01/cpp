/*

https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters

it's a sliding window problem. It takes time to understand.


Take a look at this solution https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/solutions/2821874/why-sliding-window-works-for-this-qustion-and-how-it-works-simple-analysis/?envType=problem-list-v2&envId=nqt6l0hg. 


time: O(count of unique Character * n)

*/


class Solution {
public:
    int getUniqueChar(string s) {
        int uniqueCharCount = 0 ; 
        bool seen[26] = {0};

        for(auto &c: s) {
            // if we have not seen this character
            if ( !seen[c - 'a'] ) {
                uniqueCharCount++;
            } else {
                seen[c - 'a'] = true; // mark this character as seen 
            }
        }
        return uniqueCharCount; 
    }
    int longestSubstring(string s, int k) {
        int maxUniqueCharCount = getUniqueChar(s);
        int longestStringLength = 0 ; 
        int freq[26] = {0}; // stores frequency of each character currently in the window 

        for(int uniqueCharCount = 1 ; uniqueCharCount <= maxUniqueCharCount; uniqueCharCount++) {
            int left =0;
            int uniqueCount = 0; // count of unique characters in the window 
            int countAtleastK = 0 ; // count of characters having frequency atleast k in the window 
            memset(freq, 0, sizeof(freq)); // reset freq array 
            int index ; 

            for(int right = 0; right < s.size() ; right++) {
                if ( uniqueCount <= uniqueCharCount) {
                    index = s[right] - 'a';
                    if ( freq[index] == 0) {
                        // we found a new unique character in the window
                        uniqueCount++; 
                    }
                    freq[index]++; 

                    if (freq[index] == k ) {
                        countAtleastK++; // increment countAtleastK,becuase there is a new character whose freq is k. 
                    }
                }

                while( uniqueCount > uniqueCharCount) {
                    // we have to shrink window from left 
                    index = s[left]  - 'a'; 
                    if( freq[index] == k) {
                        countAtleastK--; // one of the character having freq k is getting removed
                    }
                    freq[index]--; 
                    if( freq[index] == 0 ) {
                        uniqueCount--; // decrement the uniqueCount, because the character is no longer in the window.
                    }
                    left++; 

                }

                if ( uniqueCount == countAtleastK) {
                    longestStringLength = max(longestStringLength, right - left + 1);
                }

            }

        }
        return longestStringLength; 
    }
};