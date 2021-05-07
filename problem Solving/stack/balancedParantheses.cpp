/*  https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#

very nice problem .

*/


bool ispar(string x)
{
    stack<int>s ;
    for (char c : x ) {
        if (c == '[' || c == '(' || c == '{')  s.push(c) ;
        else {
            if ( s.empty()) return 0 ;
            char t = s.top() ;
            if ( t == '[' && c  == ']') {
                s.pop();
            }
            else if ( t == '{' && c  == '}') {
                s.pop() ;
            }
            else if ( t == '(' && c  == ')') {
                s.pop() ;
            }
            else return 0 ;
        }
    }
    if (!s.empty()) return 0 ;
    else return 1 ;

}