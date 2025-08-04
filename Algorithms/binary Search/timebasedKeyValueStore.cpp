
/*
https://leetcode.com/problems/time-based-key-value-store/description/

*/
class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto &values = store[key]; // important here that we retrieve the referance, else it gives tle. 
        string value = "";

        int left =0 , right = values.size() - 1; 
        int mid ;
        while( left <= right ) {
            mid = left + (right - left) / 2; 
            if (values[mid].first == timestamp) {
                return values[mid].second;
            } else if ( values[mid].first < timestamp) {
                value = values[mid].second; 
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }
        return value ;

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */