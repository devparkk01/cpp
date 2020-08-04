/* give an array ,reverse the blocks of even numbers only 

arr = {1 , 2 , 4 , 6 ,3 , 7 , 4 , 8 , 9 } =>  {1 , 6 ,  4,  2 , 3 , 7 , 8 , 4, 9 }
*/

#include<iostream>
#include<stack>
#define endl '\n'

using namespace std ; 


int main () {
    cout << "Enter the size of the array  :  " << endl ; 
    int size ; 
    cin >> size ; 
    cout << "Enter the elements : " << endl ; 
    int * arr = new int[size ] ; 
    for(int i = 0 ;i <size ; ++i ) {
        cin >> arr[i] ; 
    }
    

    stack<int> stk ; 
    for (int i = 0 ; i < size ; ++i ) {
        if ( arr[i]%2 == 0) 
            stk.push(arr[i]) ; 
        else {
            while(! stk.empty())  {
                cout<< stk.top() << " " ; 
                stk.pop()  ; 
            }
            cout << arr[i] << " "  ; 
        }
    }
    // This is very important  
    while (!stk.empty() ) {
        cout << stk.top() << " " ; 
        stk.pop() ; 
    }

    return 0 ; 


}