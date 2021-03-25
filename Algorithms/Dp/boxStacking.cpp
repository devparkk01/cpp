/*You are given a set of N types of rectangular 3-D boxes, where the ith box has height h,
width w and length l. You task is to create a stack of boxes which is as tall as possible,
but you can only stack a box on top of another box if the dimensions of the 2-D base of the
lower box are each strictly larger than those of the 2-D base of the higher box. Of course,
you can rotate a box so that any side functions as its base.It is also allowable to use
multiple instances of the same type of box. You task is to complete the function maxHeight
which returns the height of the highest possible stack so formed.
Note:
Base of the lower box should be strictly larger than that of the new box we're going to place.
This is in terms of both length and width, not just in terms of area. So, two boxes with same
base cannot be placed one over the other.

*/


#include<bits/stdc++.h>
using namespace std ;


struct box {
	int h , w , l ;

} ;


bool compare(box &a  , box &b) {
	if ( a.w * a.l < b.w * b.l ) return 1 ;
	return 0 ;
}


int maxHeight(int height[], int width[], int length[], int n) {

	int len = 3 * n ;

	box config[len] ;
	int index = 0 ;

	for (int i = 0 ; i < n ; ++i ) {
		config[index].h = height[i] ;
		config[index].w = max(width[i] , length[i]) ;
		config[index].l = min(width[i] , length[i]) ;
		index++ ;
		config[index].h = width[i] ;
		config[index].w = max(height[i] , length[i]) ;
		config[index].l = min(height[i] , length[i]) ;
		index++ ;
		config[index].h = length[i] ;
		config[index].w = max(width[i] , height[i]) ;
		config[index].l = min(width[i] , height[i]) ;
		index++ ;

	}

	sort(config , config + len , compare ) ;

	int msh[len] ;
	for (int i = 0 ; i < len ; ++i ) { msh[i] = config[i].h ; }


	for (int i = 1 ; i < len ; ++i ) {
		int temp = 0 ;
		for (int j = 0 ; j < i ; ++j ) {
			if ( config[j].w < config[i].w && config[j].l < config[i].l )
				temp = max(temp , msh[j] )  ;
		}
		msh[i] += temp ;
	}

	return *max_element(msh , msh  + len ) ;

}


signed main() {
	int n = 4 ;
	int height[] = {4, 1, 4, 10} ;
	int width[] = {6, 2, 5, 12} ;
	int length[] = {7, 3, 6, 32} ;

	cout << maxHeight(height , width , length , n ) ;

	return 0 ;


}