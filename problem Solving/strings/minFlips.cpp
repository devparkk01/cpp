/*
https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1#
*/


int minFlips (string S)
{
	// your code here
	int ans = 0 ;
	int count1 = 0 ;
	for (int i = 0 ; i < S.length() ; ++i) {
		if (i % 2 == 0 ) {
			if (S[i] != '0') count1++ ;
		}
		else {
			if (S[i] != '1') count1++ ;
		}

	}
	ans = count1 ; count1 = 0;
	for (int i = 0 ; i < S.length() ; ++i) {
		if (i % 2 == 0 ) {
			if (S[i] != '1') count1++ ;
		}
		else {
			if (S[i] != '0') count1++ ;
		}
	}
	ans = min(ans , count1 ) ;
	return ans;


}