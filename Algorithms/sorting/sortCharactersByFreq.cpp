/*https://leetcode.com/problems/sort-characters-by-frequency/description/


*/
class Solution {
public:
    string frequencySort(string s) {
        int n = s.size(); 
        unordered_map<char, int>hashmap; 

        for(auto &c: s) {
            hashmap[c]++;
        }

        vector<pair<int, int>> freq(n);

        for( auto &it: hashmap) {
            freq.push_back({it.second, it.first});
        }

        sort(freq.begin(), freq.end(), greater());

        string ans = "";
        ans.reserve(n);

        for(auto &it: freq) {
            int times = it.first; char c = it.second ;
            ans.append(times, c);
        }

        return ans;

    }
};