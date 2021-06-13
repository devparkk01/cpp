/*
https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1

*/

#define vec vector

struct tri {
	int e , i , j ;
};

class compare {
public :
	bool operator()(tri &a , tri &b) {
		return a.e > b.e ;
	}
};



int kthSmallest(int mat[MAX][MAX], int n, int k)
{

	priority_queue<tri , vector<tri> , compare > pq ;
	for (int i = 0 ; i < n ; ++i) pq.push({mat[i][0] , i , 0 }) ;

	int e, i , j;

	while (k-- ) {
		e = pq.top().e ; i = pq.top().i ; j = pq.top().j;
		pq.pop() ;
		if (j < n - 1 ) {
			pq.push({mat[i][j + 1 ] , i , j + 1 }) ;
		}
	}
	return e ;


}




