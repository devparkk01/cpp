/*
nice problem
https://leetcode.com/problems/sort-features-by-popularity/description/


*/


class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        // unordered_set<string>features_set;

        unordered_map<string, int> countFeatures;
        for(auto &feature: features) {
            countFeatures[feature] = 0;
        }
        unordered_set<string>seen ;

        for(auto &response: responses) {
            seen.clear();
            stringstream ss(response);
            string word;
            while ( ss >> word) {
                if (seen.find(word) == seen.end())  {
                    if (countFeatures.find(word) != countFeatures.end()) {
                        countFeatures[word]++;
                    }
                    seen.insert(word);
                }
            }
        }
        // stable sort keeps the order of equal elements same as in original array
        stable_sort(features.begin(), features.end(), [&countFeatures](const string &a, const string &b) {
            return countFeatures[a] > countFeatures[b];
        });

        return features;

    }
};


