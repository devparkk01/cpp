/*
 https://www.hackerrank.com/challenges/cipher/problem
// really nice problem . Do solve it . It uses concepts of xor and prefixXor  .

*/


string cipher(int n , int k, string s) {
	int l = s.length() ;
	// int n = l - k + 1 ;
	string original ; original.reserve(n) ;
	bool prefixXor[n] ;
	prefixXor[0] = s[0] - '0' ;
	original.push_back(s[0] ) ;
	for (int i = 1 ; i < n ; ++i ) {
		if ( i < k ) {
			prefixXor[i] = s[i] - '0' ;
		} else {
			prefixXor[i] = (s[i] - '0') ^ prefixXor[i - k ] ;
		}
		original.push_back('0' + prefixXor[i ] ^ prefixXor[ i - 1 ]) ;

	}
	return original ;

}

int main()
{
	int n , k ; cin >> n >> k ;
	string s ; cin >> s;
	cout << cipher(n , k , s) << endl;
	return 0;
}
