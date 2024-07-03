/* Problem link

https://leetcode.com/problems/implement-stack-using-queues/

Implement a last-in-first-out (LIFO) stack using only two queues. 
The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

*/

#include<bits/stdc++.h>
using namespace std;


/* Approach 1: 
we have to compromise on some operation, here we do it for push. Push operation will become O(n), rest
will be in constant time.
we maintain 2 queues, q1 and q2. q1 is the primary queue, while q2 is the auxillary or support queue.
The idea is to always have the newly pushed item at the front of the queue. 

We first push newly item to the q2, then pop all items one by one from q1 and push them to q2. 
Now, q2 has the newly item added to the front of the queue. we can swap q1 and q2, so that q1 which is 
our primary queue points to the q2 and vice versa. 
*/

class MyStack {
public:
    queue<int>q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        // If q1 is empty then push the item to the q1. 
        if ( q1.empty()) {
            q1.push(x);
        }
        else {
            // push the item to the q2. 
            q2.push(x);
            // Pop all items one by one from q1 and push them to q2
            while ( !q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
            // swap q1 and q2. 
            swap(q1, q2);
        }
    }
    
    int pop() {
        int e = q1.front();
        q1.pop();
        return e; 
        
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty(); 
    }
};

/*Second approach 
Uses only one queue here q1.  
Push operation is compromised to have time complexity of O(n).

The idea remains same here, to always have the newly pushed item at the front of the queue. 
Whenever we are about to push a new item x to the q1, we take the size of the q1 first, say n, then push
the new item. After that we pop all of the first n items from the queue, and push it one by one to
the queue again. Like this, the newly item x is at the front and all of the previously added items
goes to the back.

*/

class MyStack {
public:
    queue<int>q1 ;
    MyStack() {
        
    }
    
    void push(int x) {
        if ( q1.empty()) {
            q1.push(x);
        }
        else {
            // get the size of the stack
            int n = q1.size();
            // push the item
            q1.push(x);
            // Pop all n items one by one and push them to the back of the queue. 
            for( int i = 0 ; i < n ; ++i){
                q1.push(q1.front());
                q1.pop();
            }
        } 
    }
    
    int pop() {
        int e = q1.front();
        q1.pop();
        return e; 
        
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty(); 
    }
};
