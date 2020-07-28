#include<iostream>
#define endl '\n' ; 
using namespace std ;

void merge (int*arr , int low , int high , int mid) {
    int * temp = new int[high -low + 1]  ; 
    int i = low ; int j = mid + 1; 
    int k = 0 ; 
    while ( i <= mid && j <= high) {
        if (arr[i] < arr[j]) 
            temp[k++] = arr[i++] ; 
        else 
            temp[k++] = arr[j++] ;
        
    }
    while ( i <= mid) 
        temp[k++] = arr[i++] ;
    while ( j <= high) 
        temp[k++] = arr[j++] ; 
    
    k = 0  ; 
    for (int i = low ; i <= high  ; ++i) {
        arr[i] = temp[k++] ; 
    }

}


void merge_sort(int * arr , int low , int high) {
    if (low < high ) {
        int mid = (low + high) / 2 ; 
        merge_sort(arr , low , mid ) ; 
        merge_sort(arr , mid+1 , high) ; 
        merge(arr , low , high , mid) ;
    }
}

void print(int * arr , int size ) {
    for (int i = 0 ; i < size ; ++i) {
        cout << arr[i] << " " ; 
    }
    cout << endl ; 

}


int main () {
    int arr[10] = {46, 4,6,2,7,0, -3 ,4,6,2} ; 
    print(arr ,10) ; 
    merge_sort(arr , 0 , 9 ) ;
    print (arr , 10) ;
    return 0 ; 


}
