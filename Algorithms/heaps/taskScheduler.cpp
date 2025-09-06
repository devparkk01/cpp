/*
https://leetcode.com/problems/task-scheduler/description/


*/

class Solution {
private:

public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int > freq;
        priority_queue<int>pq; // maxheap (it just stores the frequencies)

        for(char &c: tasks) {
            freq[c]++;
        }

        // put all frequencies into maxHeap 
        for(auto it: freq) {
            pq.push(it.second);
        }

        vector<int>temp; temp.reserve(26);
        int cycleSize = n + 1; // this represents count of tasks that we can be added in each cycle
        int timeTaken = 0 ;
        int tasksAdded = 0 ; // total tasks added in each cycle  

        while(!pq.empty()) {
            temp.clear(); 
            tasksAdded = 0; 
            // take at max CycleSize elements out of pq to be considered in this cycle 
            while(tasksAdded < cycleSize && !pq.empty()) {
                auto top = pq.top(); 
                pq.pop(); 
                tasksAdded++ ; 
                if (top > 1) {
                    temp.push_back(top-1);
                }
            }
            // put all elements of temp back into pq 
            for(int &x : temp) pq.push(x);

            // this is the last cycle 
            if (pq.empty() ) {
                // no need to add idle time here 
                timeTaken += tasksAdded; 
            }else {
                timeTaken += n + 1   ; 
            }
        }

        return timeTaken; 
    }
        
};