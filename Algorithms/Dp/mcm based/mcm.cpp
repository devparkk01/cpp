/*

time : O(n * n * n) , space : O(n *n )

*/


class Solution {
public:
    int mem[101][101] ;
    int matrixMultiplication(int N, int arr[])
    {
        memset(mem , -1 , sizeof(mem)) ;
        int ans = util(arr , 1 , N - 1  ) ;
        return ans ;
    }
    // cost to multiply matrices starting from 'ending at ith index' to 'ending at jth index'
    int util(int arr[] , int i , int j ) {
        if (i == j )return 0 ;
        if ( mem[i][j] != -1 ) return mem[i][j] ;

        int temp = INT_MAX ;
        for (int k = i ; k < j ; ++k) {
            int operation = util(arr , i , k ) + util(arr , k + 1 , j) +
                            arr[i - 1] * arr[k] * arr[j] ;
            temp = min(temp , operation) ;
        }
        mem[i][j] = temp ;
        return mem[i][j] ;

    }
};