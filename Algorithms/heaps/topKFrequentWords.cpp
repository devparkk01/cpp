/*

https://leetcode.com/problems/top-k-frequent-words/description/

Approach 1: Do simple sorting 

Approach 2: Use minHeap

*/

// Approach 1: time: O(n log n). Not efficient 
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashmap; 
        // stores the frequency of each string 
        for(auto &str: words) {
            hashmap[str]++;
        }

        sort(words.begin() , words.end(), [&](string a, string b) {
            return hashmap[a] == hashmap[b] ? a < b : hashmap[a] > hashmap[b] ;
        });
        vector<string>ans; 
        ans.reserve(k);
        int index = 0 ;
        for(int i = 0 ; i < k ; ++i) {
            ans.push_back(words[index]);
            index += (hashmap[words[index]]);
        }

        return ans;
    }
};


// Approach 2 ( optimal ) : Time: O(n log k )

#define ip pair<int, string>

// custom Compare class for minHeap ( priority queue)
class Compare {

    public:
    // return true if you wanna place a below b. 
    // return false if you wanna place b below a.
    // it's all about which element should come at the bottom.
    bool operator() (ip &a, ip&b) {
        if ( a.first == b.first) {
            return a.second < b.second; 
        }        
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // stores final answer
        vector<string>ans; ans.reserve(k);
        // stores the frequency of each word
        unordered_map<string, int> counts; 
        for(auto &str: words) {
            counts[str]++;
        }
        // ip => pair< int, string> => pair<frequency, word>
        priority_queue<ip, vector<ip>, Compare > minHeap; 

        int i = 0 ;
        for( auto &it: counts) {
            if ( i < k ) {
                minHeap.push({it.second, it.first});
                i++;
            } else {
                minHeap.push({it.second, it.first});
                minHeap.pop();
            }
        }

        // Empty the heap, and put all words one by one into the ans vector
        while(!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        // reverse the answer vector. 
        reverse(ans.begin() , ans.end());
        return ans; 
    }
};