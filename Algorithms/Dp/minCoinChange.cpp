/*
Given an array of positive integers representing coin denomination and a single non negative integer n 
representing a target amount of money , write a function that returns the smallest number of coins needed to 
make change for that target amount using the given coin denomination .
if it's not possible simply return -1

*/

#include<bits/stdc++.h>
using namespace std ; 


// int minCoinChange ( int n , vector<int>&coins ) { 
//     int MAX = INT_MAX - 1 ; 
//     vector<int>nums(n+1 , MAX) ;
//     nums[0] = 0 ; 

//     for(int &coin : coins ) {
//         for(int amount = coin ; amount <= n ; ++amount ) {
//             if ( coin <= amount ) {
//                 nums[amount] = min(nums[amount] , 1 + nums[amount - coin]) ; 
//             }
//         }
//     }
//     return (nums[n] != MAX) ? nums[n] : -1 ;
// }

// The solution that I prefer 
int minCoinChange(int n , vector<int>&coins ) {
    int MAX = INT_MAX -1 ;
    vector<int>nums(n+1 , MAX) ;
    nums[0] = 0 ; 

    for(int amount = 0 ; amount <= n ; ++amount ) {
        for(int &coin : coins ) {
            if ( coin <= amount ) {
                nums[amount] = min(nums[amount] , 1 + nums[amount - coin ]);
            }
        }
    }
    return (nums[n] != MAX) ? nums[n] : -1 ;

}


/* time : O(d * n) , space : O(n)  where d is the no of different types of denominations we have  
and n is the target amount given 

denoms is a vector containing denomination . we will keep an array nums , The size of the nums will be n+1 . 
The ith index of nums will contain the number of coins needed to make change for i cents. 
first we will initialize this array with infinity . then set nums[0] = 0 , This is because number 
of coins needed to make change for 0 cent will be 0 . 
check if (denom <= amount ) then nums[amount] = min( nums[amount] ,1 + nums[amount - denom] )

At last , if nums[n] is not infinity then return nums[n] , else return -1 
*/

int main () {
    vector<int>coins = {2, 10 , 5} ; 
    cout << "Minimum coin needed to make change for 20 : " << minCoinChange(20 , coins) << endl ; 
    cout << "Minimum coin needed to make change for 9 : " << minCoinChange(9 , coins) << endl  ; 
    cout << "Minimum coin needed to make change for 22 : " << minCoinChange(22 , coins) << endl  ; 
    cout << "Minimum coin needed to make change for 0 : " << minCoinChange(0 , coins) << endl  ; 
    cout << "Minimum coin needed to make change for 3 : " << minCoinChange(3 , coins) << endl  ; 
    cout << "Minimum coin needed to make change for 1 : " << minCoinChange(1 , coins) << endl  ; 

    return 0 ; 
}