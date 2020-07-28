// Insertion sort has worst time complexity of O(n*n) 

#include<iostream> 
#include <vector>
using namespace std; 

void insertion_sort (vector<int> &arr ) 
{
    if (arr.size() == 1 || arr.size() == 0) return  ; 
    else 
    {
        for (int i = 1 ; i < arr.size() ; ++i) 
        {
            auto value = arr[i] ;
            int j = i-1 ; 
            while ( j >= 0 && arr[j] > value) 
            {
                // auto temp = arr[j] ;
                // arr[j] = arr[j+1] ;
                // arr[j+1] = temp ;
                arr[j] = arr[j+1] ^ arr[j]  ;
                arr[j+1] = arr[j+1] ^ arr[j] ;
                arr[j] = arr[j+1] ^ arr[j] ; 
                --j ; 
            }
        }
    }
}

void display( vector<int> arr) 
{
    if (!arr.empty()) 
    {
        for ( int i = 0 ; i< arr.size() ; i++) 
        {
            cout << arr[i] << " " ; 
        }
        cout << endl ; 
    }
}

int main ()
{
    vector <int> arr  ; 
    arr.push_back(5) ; 
    arr.push_back(2) ;
    arr.push_back(77) ; 
    arr.push_back(8) ; 
    arr.push_back(0) ; 
    arr.push_back(6)  ; 
    cout << "Array before sorting : "  ; 
    display(arr) ;
    insertion_sort(arr)  ; 
    cout << "Array post sorting : " ;
    display(arr) ; 
    return 0  ; 

}