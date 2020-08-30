/*Given a string S consisting of lowercase Latin Letters. Find the first non repeating 
character in S.
Print -1 if there is no non repeating character.

hello   :   h
zxvczbtxyzvy   :   c
xxyyzz   : -1


time : O(n)  , space : O(1)

*/



void solve(int n , string s ) {
    vector<int> seen(26 ) ; 
    for (char c : s) {
        seen[c-'a']++ ; 
    }
    for (char c : s ) {
        if ( seen[c-'a'] == 1) {
            cout << c << endl; 
            return ; 
        }
    }
    cout << -1   << endl ; 
    
}
