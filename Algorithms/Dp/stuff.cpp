#include <iostream>
#include<queue>
using namespace std ; 

int main () {
	int  n ;  cin >> n  ;
	string bride , b ; cin >> bride >> b ; 
	queue<char> groom ; 
	for(char c : b) groom.push(c) ;

	for (int i = 0 ; i < bride.length() ; ++i ) {
		int j = 0 ; 
		while ( j < groom.size()  && bride[i] != groom.front() ) {
			j++ ;
			int x = groom.front() ; 
			groom.pop() ; 
			groom.push(x) ; 
		}
		if ( j == groom.size() ) {
			cout << bride.length() - i << endl; 
			return 0 ; 
		}
		else { 
			groom.pop() ; 
		}
	}
	cout <<  0 << endl; ; 
	return 0 ; 
}