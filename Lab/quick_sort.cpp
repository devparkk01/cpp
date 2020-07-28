#include <iostream>
#include<time.h>
#include<windows.h>

using namespace std  ; 

int partition (int arr[] , int low , int high ) 
{
	int i = low + 1 , j = high , key = arr[low] ; 
	while (true ) 
	{
		while ( arr[i] <= key && i < high )
		{   i++ ; }
		while ( arr[j]  > key ) 
		{   j-- ; } 
		if (i < j ) 
		{
			int temp  = arr[i] ; 
			arr[i]  = arr[j] ;
			arr[j] = temp ; 

		}
		else 
		{
			int temp = arr[low] ; 
			arr[low] = arr[j] ; 
			arr[j] = temp  ;
			return j ; 
		}
	}
}

void quick_sort (int arr[] , int low , int high ) 
{
	if ( low < high ) 
	{
		int pa = partition(arr, low , high ) ;
		quick_sort(arr , low , pa-1 ) ;
		quick_sort (arr , pa+1 , high ) ; 
	}
					
}	

void print (int arr[] , int size ) 
{
	for (int i = 0 ;i < size ; ++i ) 
	{
		cout << arr[i] << " " ; 
	}
	cout << endl ; 

}


int main ()
{

	int size ; 
	cout << "Enter size of the array : "  ; 
	cin >> size ; 
	int * arr = new int [size] ;
	for (int i = 0 ;i< size; ++i ) 
	{
		arr[i] = size-i ; 
	}
	clock_t start = clock() ; 
	quick_sort(arr , 0 , size-1 ) ; 
	clock_t finish = clock() ; 
	print(arr ,size ) ; 
	cout << "Function execution time " << float(finish - start) / CLOCKS_PER_SEC  << endl ; 
	return 0 ; 

} 





		

