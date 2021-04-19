/*
https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1#

Given a palindromic number N in the form of string. The task is to find the smallest palindromic
number greater than N using the same set of digits as in N.

N = 1730371 , answer : 3170713

*/

string nextPalin(string N) {
	//complete the function here
	int l = N.length() ;
	int mid = l / 2  ;

	string half = N.substr(0 , mid ) ;
	if (next_permutation(half.begin() , half.end())) {
		string res = "" ;
		res += half ;
		if (  l & 1 ) res += (N[mid]) ;
		reverse(half.begin() , half.end()) ;
		res += half ;
		return res;
	}
	else return "-1" ;


}