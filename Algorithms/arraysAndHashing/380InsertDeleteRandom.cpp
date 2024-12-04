
/*
https://leetcode.com/problems/insert-delete-getrandom-o1/

*/

class RandomizedSet {
public:
    // { number, index} 
    unordered_map<int, int > hashmap; 
    vector<int>v; 
    RandomizedSet() {
    }
    
    bool insert(int val) {
        // item present
        if ( hashmap.count(val) > 0) {
            return false; 
        } 
        // item not present 
        v.push_back(val);
        // index of the current element
        int index = v.size() - 1; 
        hashmap[val] = index; 
        return true; 
    }
    
    bool remove(int val) {
        // item present
        if ( hashmap.count(val) > 0) {
            int index = hashmap[val];
            int last = v.size() - 1; 
            swap(v[index], v[last]);
            hashmap[v[index]] = index;  // update the index of the element which was at last

            hashmap.erase(val); // remove val from the hashmap
            v.pop_back();   // remove it from the vector 

            return true; 
        }
        // item not present 
        return false; 
    }
    
    int getRandom() {
        int randIndex = rand() % v.size();
        return v[randIndex];
    }
};

