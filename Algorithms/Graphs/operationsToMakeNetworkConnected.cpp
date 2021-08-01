/*
https://leetcode.com/problems/number-of-operations-to-make-network-connected/
*/



class Solution {
public:
	int makeConnected(int n, vector<vector<int>>& connections) {
		int m = connections.size() ;
		if (m < n - 1 ) return -1 ;

		vector<vector<int>>adj(n ) ;
		for (vector<int>  x : connections) {
			adj[x[0]].push_back(x[1]) ;
			adj[x[1]].push_back(x[0]) ;
		}

		int components = 0 ;
		vector<bool>visited(n) ;
		for (int i = 0 ; i < n ; ++i) {
			if (!visited[i]) {
				dfs(i , adj , visited  ) ;
				components++ ;
			}
		}
		return components - 1 ;
	}

	void dfs(int i , vector<vector<int>>&adj , vector<bool>&visited) {
		visited[i] = 1 ;
		for (int &v : adj[i]) {
			if (!visited[v]) {
				dfs(v , adj , visited) ;
			}
		}
	}
};