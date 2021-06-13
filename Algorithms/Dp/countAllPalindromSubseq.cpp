/*given a string , count all palindromic subsequences in this string modulo 1e9 + 7 .

time : O(n *n ) , space : O(n* n)
*/
#include<bits/stdc++.h>
using namespace std ;

int  mem[1000][1000];
int mod = 1e9 + 7 ;


long long int util(string& str , int start , int end ) {
    if ( start > end ) return 0 ;
    if ( start  == end ) return 1  ;
    if ( mem[start][end] != -1 ) return mem[start][end] ;
    if (str[start] == str[end]) {
        mem[start][end] = ( util(str , start + 1 , end) + util(str , start , end - 1 ) + 1 ) % mod ;
    }
    else mem[start][end] = (util(str, start + 1 , end) + util(str , start, end - 1) - util(str, start + 1 , end - 1 ) + mod) % mod ;
    return mem[start][end]  ;

}

long long int  countPS(string str)
{
    memset(mem , -1 , sizeof(mem)) ;
    return util(str , 0 , str.length() - 1 ) ;
}


signed main() {
    string s = "lolololol" ;
    cout <<  countPS(s) << endl;
    return 0 ;

}

