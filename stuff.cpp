#include <bits/stdc++.h>
using namespace std;
#define ll long long
int  mod = 1000000007;

bool RabinKarp(string text, string pat)
{
    if (text.empty() || pat.empty()) return 0;

    ll pathash = 0;
    //finding the hash for the pattern
    int m = pat.length();

    ll texthash = 0; ll temp ;
    int n = text.length();
    for (int i = 0; i < pat.length(); i++)
    {   //cout << m - i -1 <<  " " << pat[i] - 'a' << endl;
        temp = (ll)pow(26 , m - i - 1 )   ;
        cout << temp << endl;
        temp = (pat[i] - 'a') * temp ;
        pathash =  (pathash  + temp  )  ;
        // cout << pathash << endl;

        ll temp1  = (ll )pow(26 , n - i - 1 ) % mod  ;
        temp1 = (text[i] - 'a') * temp1  ;
        texthash = (texthash % mod + temp1 % mod ) % mod ;
        // cout << texthash << endl ;

    }
    cout << texthash << endl;
    cout << pathash << endl;

    if (pathash == texthash) return 1;

    return 0;

}



int main() {
    cout << RabinKarp("abcde" ,  "abcde" ) << endl ;
    // ll x = (ll)pow(26 , 1 )   ;
    // x = x % mod ;
    // cout << x  << endl;


    return 0;
}