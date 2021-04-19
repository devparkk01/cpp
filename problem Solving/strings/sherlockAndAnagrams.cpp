/* https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem

*/

int func(int a) {
	return a * (a - 1) / 2 ;
}

int sherlockAndAnagrams(string s) {
	int l = s.length() ;
	int ans = 0 ;
	unordered_map<string , int> um ;
	int c ;
	for (int i = 0 ; i < l ; ++i ) {
		c = 1 ;
		while ( i + c <= l) {
			string temp  = s.substr(i , c ) ;
			c++ ;
			sort(temp.begin() , temp.end())  ;
			um[temp]++ ;
		}
	}

	for (auto &x : um ) {
		ans += ( func(x.second)) ;
	}
	return ans ;

}
