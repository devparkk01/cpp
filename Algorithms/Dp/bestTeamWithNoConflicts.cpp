/*https://leetcode.com/problems/best-team-with-no-conflicts/description/


dp approach: variation of LIS(MSIS -> maximum sum increasing subsequence)
time: O(n log n + n * n)
*/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>>temp(n);
        for(int i = 0 ; i <n ; ++i) {
            temp[i] = {scores[i], ages[i]};
        }

        sort(temp.begin(),temp.end(), [](pair<int, int>&a, pair<int, int>&b) {
            return  (a.second == b.second ) ? a.first < b.first : a.second < b.second; 
        });


        vector<int>score(n); 
        // score[i] stores the max team score that can be achieved when we have players 
        // from [0...i] index without any conflict 
        score[0] = temp[0].first; 

        for(int i = 1 ; i < n ; ++i) {
            int maxscore = 0 ; 
            for(int j = 0 ; j < i ; ++j) {
                // if their ages are equal, no conflict
                // if ( temp[j].second == temp[i].second) {
                //     maxscore = max(maxscore, score[j]);
                // }

                // if the score is lesser 
                 if (temp[j].first <= temp[i].first) {
                    maxscore = max(maxscore, score[j]);
                }
            }
            score[i] = maxscore + temp[i].first; 
        }

        return *max_element(score.begin(), score.end()); 
    }
};