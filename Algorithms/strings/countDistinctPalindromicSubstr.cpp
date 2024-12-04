/*
Given a string str of lowercase ASCII characters, Count the number of distinct continuous
 palindromic sub-strings which are present in the string str.

https://practice.geeksforgeeks.org/problems/distinct-palindromic-substrings5141/1/


time : O(n * n ) , space : O(n * n )
*/
#include<bits/stdc++.h>
using namespace std ;

void getPalin(string s , int l , int r , unordered_set<string>&hash) {
	string x = "" ;
	if (l == r) {
		x = s[l] ;
		hash.insert(x) ;
		l-- ; r++ ;
	}

	while (l >= 0 && r < s.length()) {
		if (s[l] != s[r]) return ;
		x += s[l] ; x += s[r];
		hash.insert(x) ;
		l-- ; r++ ;
	}
}

int palindromeSubStrs(string str) {
	unordered_set<string>hash ;
	string x = "" ;
	x += str[0] ;
	hash.insert(x) ;

	for (int i = 1 ; i < str.length() ; ++i) {
		getPalin(str , i , i , hash) ;
		getPalin(str , i - 1 , i , hash) ;
	}
	return hash.size() ;

}

signed main() {
	string str = "geek" ;
	cout << palindromeSubStrs(str) << endl;
	return 0 ;
}

