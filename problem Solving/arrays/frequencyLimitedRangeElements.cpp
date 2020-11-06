/*
Given an array A[] of N positive integers which can contain integers from 1 to N
 where elements can be repeated or can be absent from the array. 
 Your task is to count the frequency of all elements from 1 to N.

*/

void frequencycount(vector<int>& arr,int n) { 
	
    for(int i = 0 ; i < n ; ++i )  arr[i]-=1 ; 
    for(int i = 0 ; i < n ; ++i ) {
        arr[arr[i] % n]+=n ;
    }
    for(int i = 0 ; i < n ; ++i ) arr[i]/=n; 
    
}