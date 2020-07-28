/*
Given an array of positive integers representing coin denomination and a single non negative integer n 
representing a target amount of money , write a function that returns the smallest number of coins needed to 
make change for that target amount using the given coin denomination .
if it's not possible simply return -1

*/

#include<iostream>
#include<vector>
#define inf 50000 

using namespace std ; 

int min ( int a , int b) {
    return (a < b ) ? a : b ; 
}

int minCoinChange ( int n , vector<int>&denoms ) { 
    int * nums = new int[n+1] ;
    for (int i = 0 ; i <= n ; ++i ) {
        nums[i] = inf ; 
    }
    nums[0] = 0 ;
    for (int denom : denoms  ) {
        for (int i = 0 ; i <= n ; ++i ) {
            if ( denom <= i ) {
                nums[i] = min ( nums[i] ,nums[i- denom] + 1 ) ; 
            }
        }
    }
    return (nums[n] != inf) ? nums[n] : -1 ;

}
/* time : O(d * n) , space : O(n)  where d is the no of different types of denominations we have  
and n is the target amount given 

denoms is a vector containing denomination . we will keep an array nums , The size of the nums will be n+1 . 
The ith index of nums will contain the number of coins needed to make change for i cents. 
first we will initialize this array with infinity . then set nums[0] = 0 , This is because number 
of coins needed to make change for 0 cent will be 0 . 
check if (denom <= amount ) then nums[amount] = min( nums[amount] ,nums[amount - denom]+1)

At last , if nums[n] is not infinity then return nums[n] , else return -1 
*/

int main () {
    vector<int>vec = {2, 10 , 5} ; 
    cout << "Minimum coin needed to make change for 20 : " << minCoinChange(20 , vec) << endl ; 
    cout << "Minimum coin needed to make change for 9 : " << minCoinChange(9 , vec) << endl  ; 
    cout << "Minimum coin needed to make change for 22 : " << minCoinChange(22 , vec) << endl  ; 
    cout << "Minimum coin needed to make change for 0 : " << minCoinChange(0 , vec) << endl  ; 
    cout << "Minimum coin needed to make change for 3 : " << minCoinChange(3 , vec) << endl  ; 
    cout << "Minimum coin needed to make change for 1 : " << minCoinChange(3 , vec) << endl  ; 

    return 0 ; 
}