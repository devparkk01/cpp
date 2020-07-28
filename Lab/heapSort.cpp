#include<iostream>
#include<windows.h>
#include<ctime>
#define endl '\n' 

using namespace std ; 

void swap ( int &a , int &b) {
    int temp = a ; 
    a = b ;
    b = temp ;
}

void heapify (int arr[] , int n , int i ) {
    int largest = i  ;
    int left = 2*i +1 ; 
    int right = 2*i + 2 ; 
    if (left < n && arr[largest ] < arr[left] ) {
        largest =  left ; 
    }
    if (right < n && arr[largest] < arr[right]) {
        largest = right ; 
    }
    if (largest != i ) {
        swap(arr[i] , arr[largest ]) ; 
        heapify(arr , n , largest) ; 
    }
}
// time : O(nlogn ) and space : O(1)
void heapSort(int arr[] , int n ) {
    // building the max heap , time complexity is O(n)
    for (int i = n/2 -1 ; i >=0 ; --i ) {
        heapify(arr , n , i) ; 
    }
    // deleting the root of the heap , and then perform heapify again . time complexity O(nlog n )
    for (int i = n-1 ; i >= 0 ; --i ) {
        // Sleep(1) ; 
        swap(arr[0] , arr[i]) ; 
        heapify(arr , i , 0) ; 
    }
}

void print(int arr[] , int n ) {
    for (int i = 0 ;i <n ; ++i ) {
        cout << arr[i] << " " ; 
    }
    cout << endl; 
}

int main () {
    int size ; 
    cout << "Enter size of the array : " << endl  ;
    cin >> size ; 
    int * arr = new int[size]  ;
    for (int i= 0 ; i < size ; ++i ) {
        arr[i] = size - i ; 
    }
    print(arr , size ) ; 
    clock_t start = clock() ; 
    heapSort(arr , size ) ; 
    clock_t finish = clock() ; 
    print(arr , size ) ; 
    cout << "Function execution time  : " << float((finish - start)/CLOCKS_PER_SEC )<< endl; 

    return 0 ; 
}