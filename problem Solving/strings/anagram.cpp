/*Given two strings a and b consisting of lowercase characters. The task is to check whether
two given strings are anagram of each other or not. An anagram of a string is another 
string that contains same characters, only the order of characters can be different. 
For example, “act” and “tac” are anagram of each other.

input : geeksforgeeks forgeeksgeeks
output : YES
*/

/* 
we can use array as a hashtable .
*/

#include <iostream>
#include<vector>
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 
using namespace std;

int main() {
	//code
	fastio  ;
	int t; cin >>t ; 
	while (t-- ) {
	    string a , b; 
	    cin >> a >> b; 
        vector<int >v(26) ; 
        for (char c : a ) {
            v[c - 'a']++ ; 
        }
        for (char c :b ) {
            v[c - 'a']-- ; 
        }
        int h = 0 ;
        for (int val : v)  {
            if (val != 0 ) {
                h = 1 ;break ; 
            }
        }
        if ( h == 1 ) cout << "NO" << endl; 
        else cout << "YES" << endl; 
        
	}
        
	return 0;
}