//  given an array , find all the duplicates that exist in  the array 
//  array {3 ,5, 2, 4, 6 , 7 , 2 , 3 ,4 ,1, ,4, 1}   =>  3 , 4 , 2 , 1 (order does not matter)

#include<iostream>
#include<unordered_set>
#include<time.h>
#include<vector> 
#define endl '\n' 
#define iter unordered_set <int> :: iterator 
using namespace std ; 


int main () { 
    int size ; 
    cout << "Enter the size of the array : " << endl ; 
    cin >> size ; 
    cout << "Enter the elements : " << endl ; 

    vector <int > vec ; 
    vec.reserve(size ) ; 
    int elem ; 
    for (int i = 0 ; i < size ; ++i) {
        cin >> elem ; 
        vec.push_back(elem ) ; 
    }
    clock_t start = clock() ; 
    unordered_set<int >setOne ; 
    unordered_set<int> setTwo ; 
    for (int i = 0 ; i < size ; ++i ) {
        if( setOne.find(vec[i])  == setOne.end() )
            setOne.insert(vec[i]) ; 
        else 
            setTwo.insert(vec[i]) ; 
    }
    for(iter it = setTwo.begin() ; it != setTwo.end() ; ++it) {
        cout << (*it) << " " ; 
    }
    clock_t finish = clock() ; 
    cout << endl <<"Total time : "  <<  float(finish - start) << endl ; 

    return 0 ; 

}


