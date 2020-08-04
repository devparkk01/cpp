#include<iostream>
#include<unordered_map>

using namespace std ; 

int uniqueElements( int arr[] , int n , int k ) {
	unordered_map<int , int >freq;  
	for (int i = 0 ; i <n ;++i ) freq[arr[i]]++ ; 

	while ( k > 0 ) {
		int smallest = k ; int key ; int h = 0  ;
		for (auto it = freq.begin() ; it != freq.end() ; it++ ) {
			if ( it->second <= smallest ) {
				smallest = it->second  ; key = it->first ; h = 1  ;
			}
		}
		if ( h == 0 ) {
			k = 0 ; 
		}
		else {
			k-=smallest ; 
			freq.erase(key) ; 
		}
	}
	return freq.size() ; 

}


int main () {
	int arr[] = {3 , 3, 4 , 4 , 4, 1 , 0 , 5} ; 
	int n = sizeof  (arr) / sizeof ( int ) ; 
	int k = 4 ; 

	cout << uniqueElements( arr , n , k ) << endl ; 

	return 0 ; 
}