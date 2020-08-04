/*Given a String S and an integer k we need to find that whether the string can be changed into 
Pangram string by performing at most k changes and that changes can be only modification in 
a string (i.e In one change we can remove existing character and add new character).
if yes return 1 , else return 0 
*/

#include<iostream>
#include<vector>
using namespace std ; 

int check(string s , int k ) {
	int n = s.length() ; 
	if ( n < 26) return 0 ; 
	vector<int > freq(26) ; 
	for(char c : s ) freq[c - 'a']++ ; 

	int count = 0 ; // count stores the count of characters which are not there in the string
	for (int e : freq) {
		if ( e == 0 ) count++ ; 
	}
	if( k >= count)return 1 ; 
	else return 0 ; 
}

int main () {
	string s=  "qwqqwqeqqwdsdadsdasadsfsdsdsdasasas" ; int k = 4 ; 
	cout << check(s , k ) << endl; 
	k = 19; 
	cout << check(s , k ) << endl ; 
	k = 24 ; 
	cout << check(s , k ) << endl; 

	return 0 ; 
}