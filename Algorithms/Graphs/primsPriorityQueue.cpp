/*
Prims is a greedy algorithm used to find Minimum spanning tree for a given graph. 
Here, we will see prims algorithm implementation using priority_queue, it is helpful especially when graph 
is representated in the form of Adjacency list. 
If the graph is given in the form of adjacency matrix or edge list, then first convert the graph into adjacency list
then apply this algorithm using priority queue. 


The algorithm starts with an empty spanning tree. The idea is to maintain two sets of vertices. 
The first set contains the vertices already included in the MST, and the other set contains the vertices not yet included. 
At every step, it considers all the edges that connect the two sets and picks the minimum weight edge from these edges. 
After picking the edge, it moves the other endpoint of the edge to the set containing MST. 
*/


#include<iostream>
#include<vector>
#include <queue>

using namespace std;

class Solution {

public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(vector<vector<pair<int, int>>>&adj) {

        int n = adj.size(); // no of nodes
        vector<bool>mstSet(n); // stores info about if a particular node is included in the mstSet or not.
        // minHeap, pair => {wt, node}
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > minHeap; 

        int totalEdgeWeight = 0 ; // stores sum of edge weights included in the MST.

        // start with the first node
        minHeap.push({0 , 0}); // {wt, node}


        while(!minHeap.empty()) {
            auto [wt, node] = minHeap.top() ; minHeap.pop();

            // if the node is already visited, then don't do anything
            if ( mstSet[node] == true) {
                continue; 
            }
            // Else, include the node in the mstSet
            mstSet[node] = true; 
            totalEdgeWeight += wt; // add the weight 

            // Explore all the adjacent nodes
            for( auto &[adjNode, adjWt]:  adj[node]) {
                // if the adjacent node is not included in the mstSet 
                if (mstSet[adjNode] == false) {
                    minHeap.push({adjWt, adjNode}); 
                }
            }
        }

        return totalEdgeWeight; 

	}
};

/*
Time Complexity: O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
The maximum size of the priority queue can be E, so after at most E iterations the priority queue will be empty 
and the loop will end. Inside the loop, there is a pop operation that will take logE time. 
This will result in the first O(E*logE) time complexity. 
Now, inside that loop, for every node, we need to traverse all its adjacent nodes where the number of 
nodes can be at most E. If we find any node unvisited, we will perform a push operation and for that, 
we need a logE time complexity. So this will result in the second O(E*logE). 

*/


int main() {

    int n = 5; // total no of nodes
    int e = 6; // total no of edges
	vector<vector<int>> edgeList = {
        {0, 1, 2}, 
        {0, 2, 1}, 
        {1, 2, 1}, 
        {2, 3, 2}, 
        {3, 4, 1}, 
        {4, 2, 2}
    };

    // Convert it into adjacency list

	vector< vector< pair<int, int> > >adj(n);
	for (auto &edge : edgeList) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back( {v, wt});
        adj[v].push_back({u, wt});
	}

	Solution obj;
	int sum = obj.spanningTree(adj);
	cout << "The sum of all the edge weights in the minimum spanning tree: " << sum << endl;

	return 0;
}