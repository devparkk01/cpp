/*  Given a String. Reverse each word in it where the words are separated by dots.
Input:
S = "i.like.this.program.very.much"
Output: i.ekil.siht.margorp.yrev.hcum

time : O(s.length()) , space : O(s.length())
*/

string reverseWords (string s)
{
	//code here.
	stack<char>st ; string ans ;
	int i = 0, n = s.length() ; ans.reserve(n) ;
	while ( i < n ) {
		while (i < n && s[i] != '.') {
			st.push(s[i]);
			i++  ;
		}
		// i++ ;
		while (!st.empty()) {
			ans.push_back(st.top()) ;
			st.pop() ;
		}

		if ( i != n) ans.push_back('.') ;
		i++ ;
	}
	return ans;

}