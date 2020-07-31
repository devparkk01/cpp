/*Given a string, find the longest substring which is palindrome.
*/
/*
first technique is brute force .we can generate all possible substrings of this string in O(n*n) . 
then we can iterate through each in O(n) to check whether they are palindrome or not . 
total time complexity : O(n*n*n) . 

second technique is expand around center . its time complexity is O(n*n) and space complexity is O(1) . 
*/

#include<iostream>
#include<cstring>

using namespace std ; 

int getPalindrome(string x ,int n ,  int left , int right ) {
	while ( left >= 0 && right < n && x[left] == x[right]) {
		left-- ; right++ ; 
	}
	return right - left - 1 ; 
}

int longestPalindromicSubstring(string x , int n  ) {
	if ( n == 0 ) return 0 ; 
	if (n == 1 ) return 1 ;
	int maxLen = 1 ;  int start = 0 ; 
// maxLen stores the length of longest palindrome,start stores the start index of that longest palindrome.

	for (int i =1 ;i < n ; ++i ) {
		int oddLenPalin = getPalindrome(x , n , i-1 , i+1) ; //get odd length palindrome
		int evenLenPalin = getPalindrome(x , n , i-1 , i) ; // get even length palindrome 

		int len = max(oddLenPalin , evenLenPalin) ; 
		if ( len > maxLen) {  
			maxLen = len ;   		// update maxLen 
			start = i - len / 2;  	// update start 
		}
	}

	cout << "Longest palindrome : " <<  x.substr(start , maxLen) << endl  ; 
	return maxLen ; 
}


int main() {
	string x = "forgeeksskeegfor" ; int n = x.length() ; 
	cout << longestPalindromicSubstring(x , n ) << endl ; 
	return 0 ; 
}