/*
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites,
 for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P,
 find if it is possible to finish all tasks.

*/
/*
The root of the problem is to find if there is a cycle in the graph or not . if there is any cycle
then we can't finish all tasks,else we can finish them .
Therefore check if cycle exists . We can do this via bfs or dfs .
 Both are good .Bfs approach is also called kahn's algorithm .
 I'd still recommend kahn's algo for cycle detection .

*/

// bfs approach
bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	// Code here
	vector<int>adj[N] ; vector<int>indegree(N) ;
	pair<int , int > t;
	for (auto t : prerequisites ) {
		adj[t.second].push_back(t.first) ;
		indegree[t.first]++ ;
	}

	queue<int>q ;// q stores nodes whose indegree is 0
	int count = 0  ;
	// count stores the count of vertices which has been included
	for (int i = 0 ; i < N ; ++i ) {
		if (indegree[i] ==  0  ) q.push(i) ;
	}

	while (!q.empty()) {
		int u = q.front() ; q.pop() ;
		count++ ;
		for (int &v : adj[u]) {
			indegree[v]-- ;
			if (indegree[v] == 0 ) q.push(v) ;
		}
	}
	return (count == N) ? 1 : 0 ;

}

// dfs approach
bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	// Code here
	vector<int>adj[N] ;
	// pair<int , int > t;
	for (auto t : prerequisites ) {
		adj[t.second].push_back(t.first) ;
	}
	bool visited[N] = {0} , recstack[N] = {0} ;

	for (int i = 0 ; i <  N ; ++i ) {
		if (!visited[i]) {
			if (iscyclic(adj , visited , recstack , i)) return false; // that means it contains a cycle
		}
	}
	return 1 ; // it does not contain a cycle

}

bool iscyclic(vector<int>adj[] , bool visited[] , bool recstack[] , int u ) {
	visited[u] = 1 ;
	recstack[u] = 1 ;

	for (int &v : adj[u]) {
		if (!visited[v]) {
			if (iscyclic(adj , visited , recstack , v ) == 1 ) return 1 ;
		}
		else if (visited[v] == 1 && recstack[v] == 1 ) return 1 ;
	}
	recstack[u] = 0 ;
	return false  ;
}