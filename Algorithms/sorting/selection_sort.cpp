#include<iostream>
#include<time.h>
#define endl '\n'

using namespace std ; 
void selectionSort(int *arr , int n ) {
for (int i = 0 ; i < n-1; ++i ) {
	int minIndex = i  ; 
	for (int j = i+1 ; j < n ; ++j ) {
		if ( arr[j] < arr[minIndex]){
			minIndex = j ;
		}
	}
	int temp = arr[i] ; 
	arr[i] = arr[minIndex] ; 
	arr[minIndex] = temp ; 
}
}


void print (int arr[] , int n)
{
    for (int i = 0 ; i< n ; ++i) 
    {
        cout << arr[i] << " " ;
    }
    cout << endl ; 
}


int main()
{
	cout << "Enter the size of the array : " << endl; 
	int n ; cin >> n ; 
	int *arr = new int[n] ; 
	for (int i = 0 ; i < n ; ++i ) {
		arr[i] = n- i ;
	}
	print(arr , n ) ;
	clock_t start  = clock() ; 
    selectionSort(arr , n) ;
    clock_t finish = clock() ; 
    print(arr , n ) ;
    cout << "Time of execution : " << (float (finish - start )/CLOCKS_PER_SEC) << endl;
    return 0 ; 

}