#include<iostream>
#include<vector>

using namespace std ; 

void bubble_sort (vector <int> &arr) 
{
    if (arr.size() == 1 || arr.size() == 0 )  return ;
    else 
    {
        for (int i = 0 ; i < arr.size()-1 ; ++i) 
        {
            for (int j = 0 ; j < arr.size()-1 -i ; ++j) 
            {
                if (arr[j] > arr[j+1])
                {
                    int temp = arr[j] ;
                    arr[j] = arr[j+1] ;
                    arr[j+1] = temp ; 
                }
            }
        }
    }
}

void print (vector <int> &arr) 
{
    for (int i= 0 ; i<arr.size() ; ++i)
    {
        cout << arr[i] << " " ; 
    }
    cout << endl; 
}

int main() 
{
    vector<int> arr({2,4,1,6,3,4,7}) ;
    cout << "Before sorting: " << endl ;
    print(arr) ; 
    cout << "Post Sorting:  " << endl ; 
    bubble_sort(arr) ;
    print(arr) ; 

    return 0 ; 
}