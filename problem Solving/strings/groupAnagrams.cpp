/* https://leetcode.com/problems/group-anagrams/
Given an array of strings strs, group the anagrams together. You can return
the answer in any order.

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

/* approach 1 : sorting each string .

time : O(n * klogk) , where n is the total no of strings , and k is the length of each string

*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string , vector<string>>ump ;
	vector<vector<string>>ans ;
	for (auto &x : strs ) {
		string temp = x ;
		sort(x.begin() , x.end()) ;
		ump[x].push_back(temp) ;
	}
	for (auto &p : ump) {
		ans.push_back(p.second) ;
	}
	return ans ;
}

/* second approach : Efficient
calculate frequency of each character in a string .

time : O(n*k) , where n is the total no of strings , and k is the length of each string

*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	int freq[26] = {0} ; // vector<int>freq(26) ;
	vector<vector<string>> ans ;
	unordered_map<string , vector<string>> ump ;

	for (string &x : strs ) {
		// start taking frequency of each string
		for (char &c : x ) {
			freq[c - 'a']++ ;
		}
		string key = "" ;

		for (int i = 0 ; i < 26 ; ++i ) {
			if ( freq[i]) {
				char temp = 'a' + i ;
				key.push_back(temp) ;
				key.push_back('0' + freq[i]) ;
				freq[i] = 0  ;
			}
		}
		// cout << key << endl;
		ump[key].push_back(x) ;
	}

	for (auto &p : ump) {
		ans.push_back(p.second ) ;
	}

	return ans ;
}