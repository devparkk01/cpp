


class Solution {
public:
	vector<string> permute(string s) {
		// code here
		int n = s.length() ;
		vector<string>ans ;
		string perm ;
		bool selection[n] = {0} ;

		getPerm(s , perm , ans , selection) ;

		return ans ;

	}

	void getPerm(string &s , string perm , vector<string>&ans , bool selection[]) {

		if (perm.length() == s.length()) {
			ans.push_back(perm) ;
			return ;
		}

		for (int i = 0 ; i < s.length() ;  ++i) {
			if (!selection[i]) {
				selection[i] = 1 ;
				perm.push_back(s[i]) ;
				getPerm(s , perm , ans , selection) ;
				selection[i] = 0 ;
				perm.pop_back() ;
			}
		}
	}

};
