#include<iostream>
#include<cmath>
using namespace std ; 

class Node 
{
    public :
    int data ;
    Node * left ; 
    Node * right ; 

    Node(int item ) 
    {
        data = item ; left = nullptr ; right = nullptr ; 
    }
};

class BST 
{
    public :
    Node * root ;

    BST () 
    {
        root = NULL ; 
    }
} ;

Node * insert (Node * root , int item ) 
{
    if ( root == nullptr ) root = new Node(item) ;
    else if (item < root->data) 
        root->left = insert(root->left , item ) ;
    else if ( item > root->data) 
        root->right = insert(root->right , item ) ; 
    else   //Duplicate items
        return root ; 
    return root ; 
}

void preorder(Node * root ) 
{
    if( root!= nullptr) 
    {
        cout <<root->data << endl ;
        preorder(root->left ) ;
        preorder(root->right) ; 
    }
}

//  Recursive approach   , time : O(log(n)) , space : O(log(n))

int closestValue (Node * root  , int target  , int nearest ) 
{
    if (root == nullptr) return nearest  ;
    if (abs(root->data - target) < abs(target - nearest )) nearest  = root->data; 
    if (root->data < target ) 
        return closestValue(root->right , target , nearest) ;
    else if (root->data > target )
        return closestValue(root->left , target , nearest ) ;
    else   // root->data = target
        return root->data ;

}

int closest (Node *root , int target  ) 
{
    return closestValue(root , target , root->data ) ; 
}

//  Iterative approach 

int closest_iter ( Node * root  , int target ) 
{
    Node * curr = root ;
    int nearest = root->data ; 
    while (true) 
    {
        if ( curr == nullptr) break ; 
        if (abs(curr->data - target) < abs(target - nearest )) 
            nearest = curr->data ;
        if (curr->data < target ) 
            curr = curr->right  ;
        else if (curr->data > target ) 
            curr = curr->left ; 
        else  //  when curr->data = target
            break  ;
    }

    return nearest ; 
}


int main()

{
    BST tree = BST() ; 
    tree.root = insert(tree.root , 22) ;
    tree.root = insert(tree.root , 12) ;
    tree.root = insert(tree.root , 7) ;
    tree.root = insert(tree.root , 15) ;
    tree.root = insert(tree.root , 18) ;
    tree.root = insert(tree.root , 10) ;

    preorder(tree.root) ; 
    cout << "Closest value to 8 :" << closest_iter(tree.root , 8) ;

    return 0 ; 


}