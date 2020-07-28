#include <iostream>

using namespace std ;

int partition (int arr[] , int low , int high ) 
{
    int pivot = arr[high] ;
    int border = low -1 ;
    for (int i = low ; i < high ; ++i) 
    {
        if (arr[i] < pivot) 
        {
            border ++ ; 
            auto temp = arr[i] ;
            arr[i] = arr[border] ;
            arr[border] = temp ; 
        }
    }
    auto temp = arr[high] ; 
    arr[high] = arr[border + 1] ; 
    arr[border + 1] = temp ;


    return border+ 1 ; 
}

void quick_sort (int arr[] , int low , int high) 
{
    if (low < high) 
    {
        int pi = partition(arr , low , high) ;
        quick_sort(arr , low , pi-1) ;
        quick_sort(arr, pi+1 , high) ; 
    }
}

void print(int arr[], int size)  
{
    for (int i= 0 ; i< size ; ++i) {
        cout << arr[i] << " " ;
    }
    cout << endl; 
}


int main()
{
    int arr[] = {2,3,5,2,-2,7,3,6,1,0,4,66,5} ;
    int size = sizeof(arr) / sizeof(arr[0]) ;
    cout << "Before sorting : " << endl ; 
    print(arr , size) ;
    cout << "Post sorting : " << endl ; 
    quick_sort(arr , 0 , size-1 ) ; 
    print(arr, size) ;

    
}