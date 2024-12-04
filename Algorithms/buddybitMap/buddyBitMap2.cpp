
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int>arr; 
int n = 14;

int parent(int index) {
    return (index - 1)/ 2; 
}
 
int leftChild(int index) {
    return 2 * index + 1; 
}

int rightChild(int index) {
    return 2 * index + 2; 
}


void set_bit_recursive(int level, int start, int end) {
    if ( level < 0 ) return ; 
    int nextStart = parent(start);
    int nextEnd = parent(end);
    for(int i = start; i <= end ; ++i) {
        int lc = leftChild(i);  // get left child 
        int rc = rightChild(i); // get right child 
        if ( lc < n && rc < n) { // if both are under the range 
            arr[i] = arr[lc] & arr[rc];
        } else if ( lc < n) { // if it has only left child, it's value will be equal to left child 
            arr[i] = arr[lc];
        } else if ( rc < n) {  // if it has only right child, it's value will be equal to right child 
            arr[i] = arr[rc];
        } else { // if it does not have any child, then it's a leaf node, set it to 1 
            arr[i] = 1; 
        }
    }
    set_bit_recursive(level - 1, nextStart, nextEnd);
}

void set_bit(int offset, int length) {
    int start = offset, end = offset + length -1;
    int level = ceil(log2(n));   
    set_bit_recursive(level -1 , start, end);
}


void clear_bit_recursive(int level, int start, int end) {
    if ( level < 0 )return ; 
    int nextStart = parent(start);
    int nextEnd = parent(end);

    for(int i = start ; i <= end ; ++i) {
        arr[i] = 0 ; 
    }
    clear_bit_recursive(level - 1, nextStart, nextEnd);
}
void clear_bit(int offset, int length) {
    int start = offset, end = offset + length -1 ;
    int level = ceil(log2(n));
    clear_bit_recursive(level, start, end);
}

void print() {
    for(int i = 0 ; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl; 
}
int main() {
    arr.resize(n, 0);
    // Set bits from 7 to 9
    set_bit(7, 5);
    print();
    // Clear bits from 7 to 8
    clear_bit(9,2);
    print();
    return 0;
}
