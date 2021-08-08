/*
https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1#

*/


class Solution
{
public:
	//Function to check if two strings are isomorphic.
	bool areIsomorphic(string str1, string str2)
	{

		// Your code here
		unordered_map<char , char > hash ;
		unordered_set<char > hashset ;
		if (str1.length() != str2.length()) return false ;
		for ( int i = 0 ; i <  str1.length() ; ++i) {
			if (hash.find(str1[i]) == hash.end()) {
				if (hashset.find(str2[i]) != hashset.end())return false ;
				hash[str1[i]] = str2[i] ;
				hashset.insert(str2[i]) ;
			}
			else {
				if (hash[str1[i]] != str2[i]) return false ;
			}
		}
		return true  ;

	}
};
