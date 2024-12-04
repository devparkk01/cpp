/*Given a string , check if it is a pangram . A pangram contains all letters of english alphabet . 
Ignore the case ( both lowercase and uppercase are treated as same )

*/

#include<iostream>
#include<vector>
using namespace std ; 


bool isPangram(string s ) {
	vector<int>check(26) ; 
	for (char c : s ) {
		if ( c >= 'a' && c <= 'z') check[c-'a']++ ; 
		else if ( c >= 'A' && c <= 'Z') check[c - 'A']++ ; 
	}
	for (int c : check ) {
		if ( c == 0 ) return false ; 
	}
	return  true ; 
}


int main() {
	string s = "The quick brown fox jumps over the lazy dog" ; 
	string x = "The job requires extra pluck and zeal from every young wage earner" ;
	string z = "There is no way you will find zebra circulating and singing in your home" ; 
	cout << isPangram(s) << endl;  
	cout << isPangram(x) << endl; 
	cout << isPangram(z) << endl;
	return 0 ; 
}