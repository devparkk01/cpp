
/*
https://leetcode.com/problems/min-stack/description/
*/

#include<bits/stdc++.h>
using namespace std; 

// first approach
class MinStack {
public:
    stack<pair<int, int>>stk; 
    MinStack() {
        
    }
    
    void push(int val) {
        if ( stk.empty() ){
            stk.push({val, val});
        } else {
            int prevMin = stk.top().second; 
            stk.push({val, min(prevMin, val)});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first; 
    }
    
    int getMin() {
        return stk.top().second; 
    }
};


// second approach
class MinStack {
public:
    stack<int>stk;
    stack<int>minStack; 
    
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        if (minStack.empty()) minStack.push(val);
        else if ( val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        int elem = stk.top(); 
        stk.pop(); 

        if (elem == minStack.top()) {
            minStack.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStack.top(); 
    }
};
