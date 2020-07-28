#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>

#define endl '\n'

using namespace std ; 

void print ( unordered_map<string , int  > & umap) {
    for ( auto it = umap.begin() ; it!= umap.end() ; ++it) {
        cout << it->first << " : " << it->second << endl  ; 
    }
}

void findMax (unordered_map<string , int > &umap ) {
    string strMax ; int max = 0 ;  
    for (auto it = umap.begin() ; it!= umap.end() ; ++it) {
        if (it->second > max) {
            max = it->second  ; 
            strMax = it->first ; 
        }
        else if (it->second == max && strMax > it->first ) {
            strMax = it->first ; 
        }

    }
    cout << strMax << " : " << max << endl ; 
}



int main () {
    unordered_map<string , int > umap ; 
    umap["Dev"] = 98 ; 
    umap["Ravi"] = 98 ;
    umap["Sohan"] = 97 ; 
    umap["Hasan"] = 90 ; 
    umap["uttam"] = 98 ; 
    umap["kapoor"] = 98 ;
    print(umap) ; 


    findMax(umap) ; 


    return 0 ; 

}
