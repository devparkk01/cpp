#include<iostream>
#include<time.h>
#include<windows.h>

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
        Sleep(1) ; 
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


int main () 
{
	int size ; 
	cout << "Enter the size of array : " ; 
	cin >> size ; 
	int * arr = new int [size] ;
	for ( int i = 0 ; i < size ; ++i ) 
	{
		arr[i] = size - i ; 
        // rand()%100 ; 
	}

    print(arr , size) ;
	clock_t start = clock() ; 
	merge_sort ( arr , 0 , size- 1 ) ;
	clock_t finish = clock() ; 
	for ( int i = 0 ; i< size ; ++i ) 
	{
		cout << arr[i] << " " ; 	
	} 
	cout << endl << "Function execution time : " << float(finish - start)/CLOCKS_PER_SEC  << endl  ; 
	return 0 ; 

}