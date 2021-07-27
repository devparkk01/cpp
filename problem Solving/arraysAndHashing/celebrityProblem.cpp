/*
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#


think of using two pointer approach here

*/



class Solution
{
public:
	//Function to find if there is a celebrity in the party or not.
	int celebrity(vector<vector<int> >& M, int n)
	{
		// code here
		int i = 0 , j = n - 1 ;
		while ( i  < j  ) {
			if (M[i][j] == 1 ) i++ ;
			else j-- ;
		}
		int celebrity = i ;
		for (int j = 0 ; j < n ; ++j) {
			if ( j == celebrity ) continue ;
			else if (M[celebrity][j] == 1 || M[j][celebrity] == 0  ) return -1 ;
		}
		return celebrity ;
	}
};