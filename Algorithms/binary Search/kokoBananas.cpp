/* https://leetcode.com/problems/koko-eating-bananas/

Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.
The guards have gone and will come back in H hours.
Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some
pile of bananas, and eats K bananas from that pile.  If the pile has less than K bananas,
she eats all of them instead, and won't eat any more bananas during this hour.

Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards
come back.
Return the minimum integer K such that she can eat all the bananas within H hours.

Input: piles = [30,11,23,4,20], H = 6
Output: 23
*/


// if it's possible to finish all the piles within H hours if she eats bananas at the rate
// of maxSpeed
bool isvalid(vector<int>&piles , int  n, int H , int maxSpeed ) {
	int hours = 0 ;
	for (int &x : piles ) {
		hours += ( ceil(double(x) / maxSpeed )) ;
		if ( hours > H) return false ;
	}
	return true ;
}


int minEatingSpeed(vector<int>& piles, int H) {
	int n = piles.size() ;
	// given that H >= n always
	int low = 1 ; int high = *max_element(piles.begin() , piles.end()) ;
	int mid , ans ;
	while (low <= high ) {
		mid = low + ( high - low ) / 2 ;
		if ( isvalid(piles , n , H , mid )) {
			ans = mid ;
			high = mid - 1;
		}
		else low = mid + 1 ;
	}
	return ans ;

}

