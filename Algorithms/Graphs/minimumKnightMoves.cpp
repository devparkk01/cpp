
/*
https://leetcode.com/problems/minimum-knight-moves/description/


typical bfs problem with a catch.
How do we mark any cell as visited when the cells can be in all 4 quadrants.
we will use bitmap here. It's really good to use. 

The input is given that |x| + |y| <= 300.
It said that abs(x) + abs(y) = 300, that means we can say that minimum value of x and y can
be -300 and maximum value of x and y can be +300, but we have offsets of 
(2,1), (1,2), (-1, -2), (-2, -1).....etc which represents how a knight moves. 

so, -300 + (-2) = -302
and +300 + (2) = 302

So, we get -302 as new minimum and +302 as new maximum.

Thus, (-302, 302) is range and so array length should be 302*2 + 1 = 605, which means
now 0 corresponds to -302, and 604 corresponds to +302, and 605 ( in case to avoid index out of bounds)

Thus, to map any index, we add 302 to nextIndex, in this ways all of the cells in any of the quadrant
can be marked as visited. 


Time Complexity: O((max(∣x∣,∣y∣))2)
Due to the nature of BFS, before reaching the target, we will have covered all the neighborhoods 
that are closer to the start point. The aggregate of these neighborhoods forms a circle, 
and the area can be approximated by the area of a square with an edge length of max(2∣x∣,2∣y∣). 
The number of cells within this square would be (max(2∣x∣,2∣y∣))2.
Hence, the overall time complexity of the algorithm is O((max(2∣x∣,2∣y∣))2)=O((max(∣x∣,∣y∣))2).

*/


#include<bits/stdc++.h>
using namespace std; 



class Solution {
public:
    // knight movements in all 8 possible directions. 
    int dx[8] = {-2, -2, 2, 2, -1, 1, -1, 1};
    int dy[8] = {1, -1, 1, -1, 2, 2,-2, -2};
    int minKnightMoves(int x, int y) {
        bool visited[605][605] = {false}; 
        
        queue<pair<int, int>> q; 
        q.push({0, 0});
        visited[302][302] = 1; 
        int steps = 0 ;

        while( !q.empty()) {
            int size = q.size();
            while(size--) {
                auto [i, j] = q.front(); q.pop();
                if( i == x &&  j == y ) {
                    return steps; 
                }

                for(int c= 0 ; c < 8 ; ++c) {
                    int newx = i + dx[c];
                    int newy = j + dy[c];
                    if( visited[newx + 302][newy + 302] == 0) {
                        q.push({newx, newy});
                        visited[newx+ 302][newy+ 302] = 1;
                    }
                }

            }
            steps++; 
        }
        return steps ;

    }
};