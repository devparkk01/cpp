/*
https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1#


just use two pointer approach , that's it

*/




class Solution {
public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long curprod = a[0] ;
        int i = 0 , j = 0 ;
        long long ans = 0 ;
        while (i <  n &&  j < n) {
            if (curprod < k ) {
                ans += (i - j + 1 ) ;
                i++ ;
                curprod *= a[i] ;
            }
            else {
                curprod /= a[j ] ;
                j++ ;
                if (j > i) {
                    i++;
                    curprod = a[i] ;
                }
            }
        }
        return ans ;
    }
};
