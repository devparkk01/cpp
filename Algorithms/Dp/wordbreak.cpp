/*
Given a string 'A' and a dictionary 'dictWords' , find out if it is possible to segment 'A' into one or
many words given that these words must be present in the dictionary .

*/


#include<bits/stdc++.h>
using namespace  std ;


// recursive approach

// bool wordBreak(string A , vector<string>&dictWords ) {
// 	int n = A.length() ;
// 	if ( n == 0 )  return 1 ;
// 	for (int i = 1 ; i <= n ; ++i) {
// 		string prefix = A.substr(0 , i ) ;
// 		if ( find(dictWords.begin() , dictWords.end() , prefix ) != dictWords.end()) {
// 			if (wordBreak(A.substr(i) , dictWords) == 1 ) return 1 ;
// 		}
// 	}
// 	return 0 ;
// }


// top down approach


bool ifbreak(string A , unordered_set<string>&dict , unordered_map<string , int >&dp) {
	int n = A.length() ;
	if ( n == 0 ) return 1 ;
	if ( dp.find(A) != dp.end()) return dp[A] ;

	for (int i = 1 ; i <= n ; ++i) {
		string prefix = A.substr(0 , i) ;
		if ( dict.find(prefix) != dict.end()) {
			if (ifbreak(A.substr(i) , dict , dp)) {
				dp[A] = 1 ;
				return dp[A] ;
			}
		}
	}
	dp[A] = 0 ;
	return dp[A] ;

}

int wordBreak(string A, vector<string> &B) {
	int n = A.length() ;
	unordered_set<string> dict ;
	unordered_map<string , int>dp  ;
	for (string &x : B) dict.insert(x) ;

	return ifbreak(A , dict , dp ) ;
}



int main()
{

	vector<string> dictWords = { "this", "th", "is", "famous", "Word", "break",
	                             "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem"
	                           };

	// input string
	string A = "Wordbreakproblem";

	if (wordBreak(A , dictWords)) {
		cout << "The string can be segmented";
	}
	else {
		cout << "The string can't be segmented";
	}

	return 0;
}