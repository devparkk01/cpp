/*
Given a String of length S, reverse the whole string without reversing the individual words in it.
Words are separated by dots.
input : i.like.this.program.very.much
output : much.very.program.this.like.i
*/
#include<iostream>
#include<cstring>
using namespace std ; 

void reverseWords(char *s) {
    string str= "" ; string c = "" ; 
    // Your code here
    int  i = strlen(s) -1; 
    while(true) {
        while ( i >= 0  && s[i] != '.' ) {
            c=  s[i] + c; 
            i-- ; 
        }
        if ( i == -1 ) {
            str = str + c ;  break ; 
        }
        else {
            str = str + c + '.' ; i-- ; 
            c = "" ;
        }
    }
    cout << str ;
}

int main () {
	char str[] = "i.like.this.program.very.much"  ; 
	reverseWords(str) ; 

	return 0 ; 
}