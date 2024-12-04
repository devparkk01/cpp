/*
Given a string of brackets, determine whether each sequence of brackets is balanced. 
If a string is balanced, return YES. Otherwise, return NO.
input = {[()]}  , output = YES
input = {[(])}       output = NO
input = {{[[(())]]}} output =  YES

*/
#include<iostream>
#include <stack>

using namespace std;

string isBalanced(string s) {
    stack<char> brackets  ;
    for (int i = 0 ;i < s.length() ; ++i) 
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') brackets.push(s[i]) ;
        else 
        {
            if (brackets.empty ())  return "NO" ;
            char top = brackets.top() ; 
            if ((top == '{' && s[i] == '}') || (top == '[' && s[i] == ']') || (top == '(' && s[i] == ')'))
            brackets.pop() ;
            else return "NO" ;
        }
    }

    if (brackets.empty()) return "YES" ;
    else return "NO" ;

}
