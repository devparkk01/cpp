/*
https://leetcode.com/problems/rotate-image/
*/

class Solution {
public:
	// Time : O(n*n), space : O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        // transpose the matrix
        for(int i = 0 ; i < n ; ++i) {
            for(int j = i ; j < n ; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reverse each row 
        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < n/2 ; ++j) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
        
    }
};