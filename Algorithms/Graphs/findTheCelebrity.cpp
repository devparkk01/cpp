
/*https://leetcode.com/problems/find-the-celebrity/

 The knows API is defined for you.
      bool knows(int a, int b); */

/* Approach 1 :

We can solve this problem by calculating indegree and outdegree of each node(person). 
for a person to be candidate, his indegree should be equal to (n -1) and outdegree should be 0.
time: O(n * n), space: O(n).  calculating indegree and outdegree will be (n *n)


Approach 2 : 
we can optimise it further by keeping a candidate celebrity. 
Let's say candidate celebrity is 0. we iterate for i=1 --> n-1. we ask a question whether i knows candidateCelebrity.
If i does not know our assumed candidateCelebrity then we can be surely say that candidateCelebrity is not the 
celebrity, but we do not know for sure whether i is celebrity or not, therefore we will change i to become the
candidateCelebrity.  
At last, we will have one candidateCelebrity, we need to check if candidateCelebrity is the celebrity or not.
for this, we will start to iterate for each node(people), if any person does not know candidateCelebrity or if 
candidateCelebrity knows any person, then there is no candidateCelebrity and we return -1. otherwise, our picked
candidateCelebrity is correct and we have found the celebrity. 
This approach has minimum no calls made to the `knows() api`. Total calls: 3n.
Time: O(n) and space: O(1). 

*/

class Solution {
public:
    int findCelebrity(int n) {
        int candidateCelebrity = 0 ; 

        for(int i = 1; i < n ; ++i) {
            if ( !knows(i, candidateCelebrity )) {
                candidateCelebrity = i;
            }
        }

        for(int i = 0 ; i < n ; ++i) {
            // skip if i is the candidateCelebrity. 
            if ( i == candidateCelebrity) continue; 
            if ( !knows(i , candidateCelebrity ) || knows(candidateCelebrity, i) ) {
                return -1;
            }
        }
        return candidateCelebrity; 


    }
};