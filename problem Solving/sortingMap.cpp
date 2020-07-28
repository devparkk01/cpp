/*
Given student names and their respective marks , we need to sort this  marks in such a way that the student  
obtaining more marks come before the student obtaining less marks . in case when there is equal marks then the
student coming first in lexicographic order should come first .  

Eve 78
Bob 99
Alice 78

Result should be  : 

Bob 99
Alice 78
Eve 78

will use  vector for sorting 

*/


#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
#define fastio ios_base :: sync_with_stdio(false) ; cin.tie(NULL) ; 
#define v vector< pair<string , int > > 
#define iter v ::iterator 
using namespace std ; 


void print (v &vec ) {
    for ( iter it = vec.begin() ; it != vec.end() ; ++it) {
        cout << it->first << " " << it->second << endl ; 
    }

}

bool comparator (pair<string , int>&one , pair<string , int> &two ) {
    if ( one.second != two.second) 
        return one.second > two.second ; 
    else 
        return one.first < two.first ; 
}




int main () {
    fastio ; 
    int n ; cin >> n ;
    v marks ; 
    marks.reserve(n) ; 
    string name ; int mark ;
    for (int i = 0 ; i < n ; ++i ) {
        cin >> name ; cin >> mark ; 
        marks.push_back({name , mark}) ; 
    }
    sort(marks.begin() , marks.end() , comparator) ; 
    cout << "After sorting : " << endl ; 
    print(marks) ; 

 
    return 0 ; 
}






