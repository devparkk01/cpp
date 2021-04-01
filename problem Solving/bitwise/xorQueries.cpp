/*  https://leetcode.com/problems/xor-queries-of-a-subarray/

Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri],
 for each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor
 ... xor arr[Ri] ). Return an array containing the result for the given queries.

*/

// time : O(n + q) , space : O(n )
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
	int n = arr.size() ; int q =  queries.size() ;
	vector<int>prefixXor(n) ;
	vector<int>res ; res.reserve(q) ;
	prefixXor[0] = arr[0]  ;

	for (int i = 1 ; i < n ; ++i ) {
		prefixXor[i] = prefixXor[i - 1 ] ^ arr[i] ;
	}
	int l , r ;
	for (vector<int>&a : queries ) {
		l = a[0] ; r = a[1] ;
		res.push_back(prefixXor[l] ^ prefixXor[r] ^ arr[l] ) ;
	}
	return res;
}