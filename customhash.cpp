#include<bits/stdc++.h>

using namespace std ; 

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


int main () {
    unordered_set<int  , custom_hash > uset ; 
    unordered_map<int,int, custom_hash > umap ; 

    uset.insert(10) ; 
    cout << uset.count(11) << endl; 

    umap.insert({34, 5}) ; 
    umap.insert(make_pair(40 , 8 )); 
    cout << umap[34] << endl;  
    cout << umap[40] << endl; 

    
    // we are good to go now . 
    return 0 ; 
}