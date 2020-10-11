/* we will see how to handle really big integers values (of size more than 64 bits )

Finding factorial of a number here . 
for n = 100 ; 
facorial(100) = 93326215443944152681699238856266700490715968264381621468592963895217599
993229915608941463976156518286253697920827223758251185210916864000000000000000000000000

*/

#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int ;
using namespace std ; 

cpp_int factorial(int n ) {
	cpp_int res = 1 ; 
	for(int i = 1 ; i <= n ; ++i ) {
		res*=i ; 
	}
	return res ; 
}

signed main(){
	int n ; cin >>n ; 
	cout << factorial(n) ;
	return 0 ; 
}