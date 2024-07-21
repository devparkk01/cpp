/*
https://leetcode.com/problems/sender-with-largest-word-count/description/


*/


class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int>wordsCount; 
        int n = senders.size();
        int largestWordCount = 0 ; 
        string ans = "";
        for(int i = 0 ; i < n ; ++i) {
            auto sender = senders[i];
            auto message = messages[i];

            int count = 0 ; 
            stringstream ss(message);
            string word; 
            while( ss >> word ) {
                count++;
            }
            wordsCount[sender] += count; 
            if ( wordsCount[sender] > largestWordCount) {
                largestWordCount = wordsCount[sender];
                ans = sender; 
            } else if ( wordsCount[sender] == largestWordCount) {
                ans = max(ans, sender);
            }
        }

        return ans; 
    }
};