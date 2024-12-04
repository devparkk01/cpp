/*
 given a string of words, find frequencies of individual words.
*/

//  will be using unordered_map and stringstream 

#include<iostream>
#include<sstream>
#include<unordered_map>
#define endl '\n'
#define um unordered_map<string , int > 
#define iter um::iterator 
using namespace std ; 

void print(um &umap){
    for(iter it = umap.begin() ; it!= umap.end() ; ++it  ) {
        cout << it->first << " : " << it->second << endl ; 
    }
}


int main () {
    string sentence ; 
    cout << "Enter the sentence : " << endl ; 
    getline(cin , sentence ) ; 
    stringstream ss(sentence) ; 
    um umap ;
    string word ; 
    while (ss >> word ) {
        umap[word]++ ; 
    }

    print(umap) ; 

    return 0 ; 


}
