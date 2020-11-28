/*
A conveyor belt has packages that must be shipped from one port to another within D days.
The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship
with packages on the conveyor belt (in the order given by weights). We may not load more weight
than the maximum weight capacity of the ship .
Return the least weight capacity of the ship that will result in all the packages
on the conveyor belt being shipped within D days.


Input: weights = [3,2,2,4,1,4], D = 3
Output: 6
A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
*/


bool isValid (vector<int>&weights , int n , int D , int maxWeight ) {
    int days = 1 ;
    int sum = 0 ;
    for (int &x : weights ) {
        if ( x > maxWeight) return false ;
        else if ( sum + x > maxWeight ) {
            days++ ;
            sum = x ;
            if ( days > D ) return false ;
        }
        else sum += x ;
    }
    return true ;
}

int shipWithinDays(vector<int>& weights, int D) {
    int n = weights.size( );
    // if ( D > n ) D = n ;
    int high = accumulate(weights.begin() , weights.end() , 0) ;
    int low = *max_element(weights.begin() , weights.end() ) ;
    int mid , res = high ;
    while ( low <= high ) {
        mid =  low + (high - low ) / 2 ;
        if (isValid(weights , n , D , mid )) {
            // res = min (res , mid ) ;
            res = mid ;
            high = mid - 1 ;
        }
        else low = mid + 1 ;
    }
    return res ;
}

