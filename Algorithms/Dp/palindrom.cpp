#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string str){
    map<char,int> frequencyChar;
    for(int i=0;i<str.length();i++){
        frequencyChar[str[i]]++;
    }
    char middle_character;
    string leftStr;
    bool mid_char_chosen = false;
    for(auto it: frequencyChar){
        char currentChar=it.first;
        int frequencyCurrentChr = it.second;
        if(!mid_char_chosen and frequencyCurrentChr%2!=0){
            middle_character=currentChar;
            mid_char_chosen = true;
        }
        leftStr.append(1*(frequencyCurrentChr/2),currentChar);
    }
    string rightStr(leftStr.rbegin(),leftStr.rend());
    if (mid_char_chosen)
        return leftStr + middle_character + rightStr;
    else
        return leftStr +  rightStr;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
    cout<<longestPalindrome(str) << endl;
    }
}