/*Given an array of integers where each element represents the max number of steps that can be made
forward from that element . The task is to find the minimum number of jumps to reach the end of the 
array.If it's not possible return -1 . 
arr = {1 , 3 ,5 , 8 , 9 , 2 ,6, 7, 6, 8 , 9 }, n = 11 ,   jumps = 3
arr = {3 , 4 , 2 , 1 , 2 , 3 , 7 , 1,1 , 1 ,3  } n = 11  , jumps = 4
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MAX 2147483647

using namespace std ;
// dynamic programming approach, time : O(n * n) , space = O(n)

// int minJumps(int *arr , int n ) {
//     vector<int>jumps(n , INT_MAX) ; 
//     // jumps[i] stores the minimum number of jumps needed to reach ith index from index 0 
//     jumps[0] = 0 ;   
//     // number of jumps needed to reach 0th index is 0 , since we are already at  index 0 
    
//     // start from index 1 to last index 
//     for (int i =1 ; i < n ; ++i ) {
//         for (int j = 0 ; j < i ;++j ) {
//             if (arr[j] + j >= i ) {
//                 jumps[i] = min(jumps[i] , jumps[j] + 1 ) ; 
//             }
//         }
//     }
//     return jumps[n-1] == INT_MAX ? -1 : jumps[n-1]  ;
// }


// greedy method  time : O(n) , space : O(1) 

int minJumps (int *arr ,int n ) {
    if (n <= 1 ) return 0 ; 
    if ( arr[0] == 0) return -1 ; 

    int maxReach = arr[0];  int steps = maxReach - 0 ; int jump =1 ; 

    for (int i =1 ; i < n ; ++i)  {
        if ( i == n-1) return jump ; 

        maxReach = max(maxReach , arr[i] + i ) ; 
        steps-- ; 

        if  ( steps == 0 ) {
            jump++ ; 
            if (i >= maxReach ) return -1 ; 

            steps = maxReach - i ; 
        }
    }
    return -1 ; 
}




int main() {
    int n ; cin >> n; 
    int arr[n] ; 
    for(int i = 0 ; i < n; ++i ) cin>> arr[i] ; 
    cout << minJumps(arr,  n ) << endl ; 




}