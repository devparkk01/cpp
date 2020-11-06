/*Given two unsorted arrays arr1[] and arr2[]. They may contain duplicates. For 
each element in arr1[] count elements less than or equal to it in array arr2[].

m = 5, n = 7
arr1[] = {4 , 8, 7 ,5 ,1}
arr2[] = {4,48,3,0,1,1,5}
Output: 5 6 6 6 3

logic : sort the second array .Then for each element x in first array , find the index of the
element just greater than this element x in the second array (using  binary search). This will
give us  the total no of elements less or equal to this element in the second array . 

time : O (nlogn+mlogn) = O((n+m)logn)
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ; 
// finds the index of the element just greater than x in the second array 
int nextHigherElement(int a[] , int n , int x ) {
    int low = 0 , high = n -1 ; 
    int mid ; 
    while (low < high) {
        mid = low + (high - low ) /2 ;
        if (a[mid] <= x ) low = mid + 1 ; 
        else if ( a[mid] > x ) high = mid ; 
    }
    return low ; // index of the next Higher element 
}


vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n )   {
    vector<int>res ; res.reserve(m) ; 
    sort(arr2 , arr2 + n ) ;// sort the array first 
    int index ; 
    for(int i = 0 ; i < m ; ++i ) {
    	// if element arr1[i] is greater than last element of arr2 then arr1[i] is greater 
    	// than all elements of arr2 .
        if ( arr1[i] >= arr2[n-1 ]) res.push_back(n) ; 
        // if this element is less than first element of arr2 then there are no element in arr2
        // which are less or equal to this element 
        else if (arr1[i] < arr2[0]) res.push_back(0) ; 
        // otherwise , find the index of the element just greater than this element 
        else {
            index = nextHigherElement(arr2 , n , arr1[i]) ; 
            res.push_back(index) ; 
        }
    }
    return res ; 
}

void print(vector<int> res) {
	for(int &x : res) 
		cout << x << " " ; 
	cout << endl;  
}

signed main () {
	int arr1[] = {4 , 8, 7 ,5 ,1}  ;
	int arr2[] = {4,48,3,0,1,1,5}  ;
	int m = sizeof(arr1)/sizeof(int) ; 
	int n = sizeof(arr2)/sizeof(int) ;
	vector<int>res = countEleLessThanOrEqual(arr1 , arr2 , m , n )  ; 
	print(res) ; 
	return 0 ; 
}