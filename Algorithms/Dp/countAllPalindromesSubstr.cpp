/*
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different
substrings even they consist of same characters.
*/


/*  first approach
brute force . Check all substrings of this string if it's a palindrome .
time : O(n *n *n ) , space : O(1)
*/
bool check(string s, int start , int end ) {
	while ( start < end && s[start] == s[end]) {
		start++ ; end-- ;
	}
	if ( start < end) return 0 ;
	else return 1 ;

}
int countSubstrings(string s) {
	int n = s.length() ; long long count = 0 ;
	for (int i = 0  ; i < n; ++i) {
		for (int j = i ; j < n ; ++j ) {
			if ( check(s , i , j ) ) count++ ;
		}
	}
	return count ;

}

/* approach 2 : expand around center
time : O(n*n) , space : O(1)

*/

int getpalindrome(string s , int n , int left , int right ) {
	int c = 0 ;
	while ( left >= 0 && right < n && s[left ] == s[right ]) {
		left-- ; right++ ;
		c++ ;
	}
	return c ;


}
int countSubstrings(string s) {
	int n = s.length() ;
	long long count = 1 ; // first character is directly included in the palindrome count
	for (int i = 1  ; i < n; ++i) {
		int odd = getpalindrome(s , n , i , i ) ;
		int even = getpalindrome(s , n , i - 1 , i ) ;
		count += (odd + even ) ;
	}
	return count ;

}


// 3rd approach , dp

