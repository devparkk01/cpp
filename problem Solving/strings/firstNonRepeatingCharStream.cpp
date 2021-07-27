/*
https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#


time : O(n) , space : O(26)

*/



string FirstNonRepeating(string A) {
	// Code here
	queue<char > q ;
	int freq[26] = {0} ;
	string ans ; ans.reserve(A.length()) ;

	for (char &c : A ) {
		if (freq[c - 'a'] == 0 ) {
			q.push(c) ;
			freq[c - 'a']++ ;
		}
		else freq[c - 'a']++ ;

		while (!q.empty() && freq[q.front() - 'a'] != 1 ) {
			q.pop() ;
		}
		if (q.empty() ) ans.push_back('#') ;
		else ans.push_back(q.front()) ;
	}
	return ans ;
}
