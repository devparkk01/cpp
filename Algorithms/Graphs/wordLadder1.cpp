/*

https://practice.geeksforgeeks.org/problems/word-ladder/0

just do bfs
*/



#define ip pair<int , int >
int difference(string &a , string &b) {
	int m = a.length() ; int c = 0 ;
	for (int i = 0 ; i <  m ; ++i) {
		if (a[i] != b[i]) c++ ;
	}
	return c ;
}

int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
	int n = wordList.size() ;
	queue<ip> q ;
	q.push({ -1 , 1 }) ;
	bool visited[n] = {0} ;
	string s ;
	while (!q.empty()) {
		int index = q.front().first ; int steps = q.front().second ;
		q.pop() ;
		if (index == -1 ) s = startWord ;
		else {
			s = wordList[index] ;
			if (s == targetWord) return steps ;
		}


		for (int i = 0 ; i < n ; ++i ) {
			if (!visited[i] && difference(s , wordList[i]) == 1 ) {
				q.push({i ,  steps + 1 }) ;
				visited[i] = 1 ;
			}
		}
	}
	return 0  ;

}