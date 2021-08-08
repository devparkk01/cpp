
/*
https://practice.geeksforgeeks.org/problems/page-faults-in-lru5603/1#

*/


#define iter  list<int>::iterator
class Solution {
public:
    int pageFaults(int N, int C, int pages[]) {
        // code here
        list<int>cache ;
        unordered_map<int , iter > address ;


        int faultsCount = 0 ;
        iter it ; int temp ;
        for (int i = 0 ; i < N ; ++i ) {
            int x = pages[i]  ;
            if (address.find(x) != address.end()) {
                it = address[x] ;
                cache.erase(it ) ;
                cache.push_front(x) ;
                address[x] = cache.begin() ;
            }
            else if ( cache.size() < C) {
                faultsCount++ ;
                cache.push_front(x) ;
                address[x] = cache.begin()   ;
            }
            else {
                faultsCount++ ;
                cache.push_front(x) ;
                address[x] = cache.begin() ;
                temp = cache.back() ;
                cache.pop_back() ;
                address.erase(temp) ;

            }
        }
        return faultsCount ;






    }
};