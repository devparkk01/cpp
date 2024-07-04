/*Given an input stream of n integers . The task is to insert these numbers into a new stream and find
the median of the stream formed by insertion of each element into the stream .
*/
#include<bits/stdc++.h>
using namespace std ; 

/* Approach 1  : 
Insertion sort :


*/

void sorting(int a[] , int n , int i ) {
    while(i > 0 && a[i] < a[i-1])  {
        swap(a[i] , a[i-1]) ; 
        i-- ; 
    }
}

void medianOne(int a[] , int n) {
	cout << a[0] << endl; 
	for(int i = 1 ; i  < n;  ++i ) {
	    sorting(a , n , i ) ; 
	    if (i%2 == 0) {
	        cout << a[i/2] << endl; 
	    }
	    else {
	        cout << (a[i/2] + a[i/2 +1 ] )/ 2 << endl  ; 
	    }
	}
}



/* Approach 2 : 
Heaps 
time : O(n log n) , space : O(1)
we will maintain two heaps .one max heap on left side to represent elements that are less than effective
median ,and one min heap to represent elements that are greater than effective median .
*/
void medianTwo(int a[] , int n ) {
	priority_queue<int> q1 ; // max heap 
	priority_queue<int , vector<int> , greater<int> > q2 ; // min heap 

	double med  ;
	for(int i = 0 ;i < n ; ++i) {
		// push the element to the q1
		if ( q1.empty() || q1.top() > a[i]) 
			q1.push(a[i]) ; 
		// push the element to the q2
		else q2.push(a[i]) ; 

		// balancing the heaps
		if ( q1.size() > q2.size() + 1 ) {
			q2.push(q1.top()) ; 
			q1.pop() ; 
		}
		else if (q2.size() > q1.size() + 1  ) {
			q1.push(q2.top() ) ;
			q2.pop() ; 
		}
		// calculating the median 
		if ( q1.size() == q2.size()) {
			med = (q1.top() + q2.top() )/ 2.0 ; 
		}
		else if ( q1.size() > q2.size()) {
			med = q1.top() ; 
		}
		else med = q2.top() ; 
		cout << med << endl; 
	}


}

int main() {
	int a[] = {2, 4, 1 , 5, 12 , 3 } ; 
	medianTwo(a , sizeof(a)/sizeof(int)) ; 

	return 0 ; 
}