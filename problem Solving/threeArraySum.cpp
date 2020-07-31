/*Write a function that takes in a non empty array of distinct integers and an integer
representing target sum . The function should find all triplets in the array that sum
up to the target sum and return a two-dimensional array of all these triplets. The numbers
in each triplet should be ordered in ascending order , and the triplets themselves should
be ordered with respect to the numbers they hold . 
if no three numbers sum up to the target sum , return an empty array . 

arr = {12 , 3 , 1 , 2, -6 , 5, -8 , 6 } , targetSum = 0 
{ {-8 , 2, 6} , {-8 , 3 ,5 } , {-6 , 1 , 5 }}

*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ; 

// time complexity : O(n*n ) , space : O(1) (extra space is only for the vector to be returned )

vector<vector<int>> findTriplets (int arr[] , int n , int targetSum) {
	sort(arr , arr + n ) ; 
	vector<vector<int>> result ; 

	for (int k = 0 ; k < n-2 ; ++k ) {
		int i = k+1 , j = n-1 ; 
		while (i < j ) {
			if (arr[k] + arr[i] + arr[j] > targetSum) j--; 
			else if  ( arr[k] + arr[i] + arr[j] < targetSum) i++ ; 
			else {   // when arr[k] + arr[i] + arr[j] == targetSum 
				result.push_back( {arr[k] , arr[i] , arr[j]}) ; 
				i++ ; j-- ; 
			}
		}
	}
	return result ; 

}

int main () {
	int arr[] = {12 , 3 , 1 , 2, -6 , 5, -8 , 6 } ;
	int n = 8 ; 

	auto triplet = findTriplets(arr , 8 , 0) ;
	for (int i = 0 ;i < triplet.size() ; i++ ) {
		for (int j = 0 ; j < triplet[i].size() ; ++j ) {
			cout << triplet[i][j]  << " " ; 
		}
		cout << endl; 
	}
	return 0 ; 
}