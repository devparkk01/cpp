/* All submissions for this problem are available.
Write a program that processes the following queries on a Binary Search Tree:
i x: Insert x in the BST
d x: Delete x from the BST

Input format
Line 1 contains an integer Q, the number of queries
The next Q lines are of the form i x or d x
Output format
For each query, print the position of x in the BST
If the position of a node is p, the positions of its left and right children are 2*p and 2*p+1 respectively
Position of the root node is 1   */


#include<iostream>
#include <chrono> 
using namespace std ;
using namespace std ::chrono ; 

class Node 
{
    public : 
    int data ; int pos ; Node * left ; Node * right ; 
    Node (int data ,int  pos) 
    {
        this->data = data  ; 
        this->pos = pos ; 
        left = NULL ; 
        right = NULL ;
    }
};

class BST 
{
    public : 
    Node * root  ;
    BST () 
    {
        root = NULL ; 
    }
} ;

Node * insert (Node * root , int item , int pos) 
{
    if (root == NULL) 
    {
        cout << pos << endl ;
        root = new Node(item , pos ) ;
    }
    else if (item < root->data ) 
    {
        root->left = insert( root->left , item , 2*pos)  ;
    }
    else if ( item > root->data ) 
    {
        root->right = insert(root->right , item , 2 * pos + 1) ; 
    }
    else  return root ; 

    return root ; 
}

Node * findMin (Node * root ) 
{
    while ( root->left != NULL ) 
        root = root->left ; 
    return root ; 
}

Node * del ( Node * root , int item ) 
{
    if ( root == NULL ) return root ; 
    else if ( item < root->data) 
    {
        root->left = del(root->left , item ) ; 
    }
    else if ( item > root->data) 
    {
        root->right = del(root->right , item ) ;
    }
    else 
    {
        cout << root->pos << endl ; 
        if (root->left == NULL && root->right == NULL) 
        {
            return NULL ; 
        }
        else if ( root->left == NULL ) 
        {
            root = root->right  ;
        }
        else if ( root->right == NULL ) 
        {
            root = root->left ; 
        }
        else 
        {
            Node * temp = findMin ( root->right ) ; 
            root->data = temp->data ;
            root->right = del(root->right , temp->data ) ; 
        }
    }

    return root ;
}

int main () 
{
    int n ; 
    BST tree = BST() ; 
    cin >> n ;
    for ( int i = 0 ; i < n ; ++i ) 
    {
        char opr ; int value  ;
        cin >> opr >> value ;
        if ( opr == 'i')
        {
            tree.root = insert(tree.root , value , 1) ; 
        }
        else 
        {
            tree.root = del(tree.root , value ) ; 
        }

    }
}