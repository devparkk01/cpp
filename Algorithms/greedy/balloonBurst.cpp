/*https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

For each balloon their start and end coordinate(points) is given .
sort the array based on their start coordinate .
endCod = end cordinate of the first balloon
start traversing the array from index 1  .
if start coordinate of the newly added balloon is less than(or equal to) the endCod then that
means we can burst  this balloon with the same arrow .
then update endCod = min(endCod , endcoordinate of this balloon)

else increment count . and set endCod equal to end cordinate of this balloon


*/

class Solution {
public:
	static bool compare(vector<int>&a , vector<int>&b) {
		return a[0] < b[0] ;
	}
	int findMinArrowShots(vector<vector<int>>& points) {
		int n = points.size() ;
		if ( n == 0 ) return 0 ;
		sort(points.begin() , points.end() , compare ) ;
		int count = 1 ;
		int endCod = points[0][1] ;
		for (int i = 1 ; i < n; ++i ) {
			if (points[i][0] <= endCod) {
				endCod = min(endCod , points[i][1])
			}
			else {
				count++ ;
				endCod = points[i][1] ;
			}
		}

		return count ;
	}
};