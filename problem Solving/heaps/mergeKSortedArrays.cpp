/*https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1#

time : O(k*k log k) where K is equal to the no of rows and columns
space : O(k)


*/


#define vec vector

struct tri {
    int e , i , j ;
} ;

class compare {
public :
    bool operator()(tri &a , tri &b) {
        return a.e > b.e ;
    }
};

class Solution
{
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {

        vec<int>res ; res.reserve(K * K ) ;
        // creating a min heap
        priority_queue<tri , vec<tri> , compare>pq ;
        for (int i = 0 ; i < K ; ++i ) pq.push({arr[i][0] , i , 0}) ;

        tri t ; int e , i , j;
        while (!pq.empty()) {
            t  = pq.top() ; pq.pop() ;
            e = t.e ; i  = t.i ; j = t.j ;
            res.push_back(e) ;
            if (j + 1 < K) pq.push({arr[i][j + 1] ,  i , j + 1 }) ;
        }
        return res ;



    }
};
