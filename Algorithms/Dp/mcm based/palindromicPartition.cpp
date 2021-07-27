class Solution {
public:
    int mem[501][501] ;
    int palindromicPartition(string str)
    {
        memset(mem , -1 , sizeof(mem)) ;
        int ans = util(str , 0 , str.length() - 1 ) ;
        return ans ;
    }
    int util(string &str , int i , int j ) {
        if (i == j ) return 0 ;
        if (mem[i][j] != -1) return mem[i][j] ;
        if (ispal(str, i , j)) return 0 ;
        int temp = j - i ;
        for (int k = i ; k < j ; ++k) {
            temp = min(util(str, i , k) + util(str , k + 1 , j) + 1 , temp) ;
        }
        mem[i][j] = temp ;
        return mem[i][j] ;

    }
    bool ispal(string &str , int i , int j) {
        while (i < j ) {
            if (str[i] != str[j]) return false ;
            i++ ; j-- ;
        }
        return true ;
    }
};