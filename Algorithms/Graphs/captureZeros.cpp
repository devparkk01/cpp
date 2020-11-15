/*Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations 
just below, just above, just left and just right of it.

input : 
X X X X
X O O X
X X O X
X O X X

Output:
X X X X
X X X X
X X X X
X O X X

Surrounded regions shouldn’t be on the border, which means that any 'O' on the 
border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is
not connected to an 'O' on the border will be flipped to 'X'.	


*/

#include<bits/stdc++.h>
using namespace std;
#define f(i , n  ,k) for(int i = k ;i < n;  ++i ) 


void dfs(vector<vector<char>>&mat,int i,int j,int n,int m ,char oldC,char newC) {
    if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] != oldC) 
        return ; 
    mat[i][j] = newC ; 
    
    dfs(mat , i+1 , j , n , m , oldC , newC) ;
    dfs(mat , i-1 , j , n , m , oldC , newC) ;
    dfs(mat , i , j +1, n , m , oldC , newC) ;
    dfs(mat , i , j -1  , n , m , oldC , newC) ;

}

signed main() {
    int n , m ; cin >> n >> m ; 
    vector<vector<char>>mat(n , vector<char>(m)) ; 
    
    f(i , n , 0) {
        f(j , m , 0 ) {
            cin >> mat[i][j] ; 
        }
    }
    int i = 0 ; 
    f(j , m , 0) {
        if (mat[i][j] == 'O') {
            dfs(mat , i , j , n , m , 'O' , '-' ) ; 
        }
    }
    i = n-1 ; 
    f(j , m ,0 ) {
        if( mat[i][j] == 'O') {
            dfs(mat , i , j , n , m , 'O' , '-' ) ; 
        }
    }
    
    int j = 0 ; 
    f(i , n , 0 ) {
        if( mat[i][j] == 'O') {
            dfs(mat , i , j , n , m , 'O' , '-' ) ; 
        }
    }
    j = m-1 ; 
    f(i , n , 0) {
        if (mat[i][j] == 'O') {
            dfs(mat , i , j , n , m , 'O' , '-' ) ; 
        }
    }
    
    f(i , n , 0 ) {
        f(j , m , 0 ) {
            if ( mat[i][j] == 'O') {
                dfs(mat , i , j , n , m , 'O' , 'X') ; 
            }
        }
    }
    
    f(i , n , 0 ) {
        f(j , m , 0 ) {
            if ( mat[i][j] == '-') {
                mat[i][j] = 'O' ; 
            }
        }
    }
    f(i , n , 0) {
        f(j , m , 0) cout << mat[i][j] << " " ; 
        cout << endl ; 
    }

	return 0;
}