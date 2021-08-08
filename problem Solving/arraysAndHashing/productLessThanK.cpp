/*
https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1#


just use two pointer approach , that's it

*/




class Solution {
public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long curprod = 1 ;
        int l = 0  ;
        long long ans = 0 ;
        for (int r = 0 ; r < n ; ++r) {
            curprod *= a[r] ;
            while (l < r  &&  curprod >= k ) {
                curprod = curprod / a[l] ;
                l++ ;
            }
            if (curprod < k) ans += (r - l + 1 ) ;

        }
        return ans ;
    }
};