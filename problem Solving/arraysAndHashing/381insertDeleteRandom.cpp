
/*
https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
*/


class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> hashmap; 
    vector<int>v;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        v.push_back(val);
        int index = v.size() - 1; 
        hashmap[val].insert(index);

        if ( hashmap[val].size() == 1 ) {
            return true; 
        }
        return false; 
        
    }
    
    bool remove(int val) {
        // if the val does not exist 
        if ( !hashmap.count(val)) {
            return false;
        }
        // get the first index corresponding to val
        int index = *(hashmap[val].begin());
        // lastIndex in the vector v
        int lastIndex = v.size() - 1 ; 

        if ( v[index] == v[lastIndex]) {
            hashmap[v[index]].erase(lastIndex);
        }
        else {
            // swap these two elements
            swap(v[index], v[lastIndex]);
            // v[index] now stores the new element which was at the end of the vector previously
            hashmap[v[index]].erase(lastIndex);
            hashmap[v[index]].insert(index);
            hashmap[val].erase(index);
        }

        if ( hashmap[val].size() == 0 ) {
            hashmap.erase(val);
        }
        v.pop_back(); 
        return true; 

    }
    
    int getRandom() {
        int index = rand() % v.size();
        return v[index];
    }
};

