#include<iostream>
#include<queue>
#define endl '\n'
using namespace std ; 

class Node {
    public :
    int data ; 
    Node * left  ; 
    Node * right  ; 

    Node (int data ) {
        this->data = data ; 
        this->left  = nullptr ; 
        this->right = nullptr ; 
    }
} ; 

class BST {
    public : 
    Node * root ; 
    BST() {
        root = nullptr ; 
    }
} ; 

bool search(Node* root , int item ) {
    if (root == nullptr )
        return false ; // item not found 
    else if ( item < root->data )
        return search(root->left , item ) ; 
    else if ( item > root->data ) 
        return search(root->right , item ) ;
    else // found the item 
        return true ; 
}

Node * insert (Node* root , int item ) {
    if ( root ==  nullptr ) 
        root = new Node(item ) ; 
    else if  ( item < root->data )
        root->left = insert(root->left , item ) ;
    else if ( item > root->data  ) 
        root->right = insert(root->right , item ) ; 

    return root  ; 
}
// finds the min Node in the tree 
Node * findMin(Node * root ) {
    while ( root->left != nullptr) {
        root = root->left ; 
    }
    return root ; 
}

Node * Delete (Node * root , int item ) {
    // first we need to search the node to be deleted , then delete the node 
    // searching begins 
    if ( root == nullptr ) return root ; 
    else if (item < root->data ) {
        root->left = Delete(root->left , item ) ; 
    }
    else if ( item > root->data ) {
        root->right = Delete(root->right , item ) ; 
    }

    // found the node , now the deletion begins 
    else {
        // case 1 , no child 
        if ( root->left == nullptr && root->right == nullptr ) {
            delete root ; 
            root = nullptr ; 
        }
        // case 2 no left child 
        else if ( root->left == nullptr ) {
            Node * temp = root ; 
            root = root->right ; 
            delete temp ; 
        }
        // case 2 no right child 
        else if ( root->right == nullptr ) {
            Node * temp = root ; 
            root = root->right ; 
            delete temp  ; 
        }
        // case 3 , two children 
        else {
            Node * temp = findMin(root->right ) ; 
            root->data = temp->data ; 
            root->right = Delete(root->right , temp->data ) ; 
        }

    }

    return root ; 
}

// first left then the node and finally the right  
void inorder (Node * root ) {
    if ( root != nullptr) {
        inorder(root->left ) ; 
        cout << root->data << " " ;
        inorder(root->right) ; 
    }
}

// node then left and finally the right 
void preorder(Node * root ) {
    if (root != nullptr ) {
        cout << root->data << " " ; 
        preorder(root->left ) ; 
        preorder(root->right ) ; 
    }
}

// left then right and finally the node 
void postorder (Node * root ) {
    if ( root != nullptr ) {
        postorder(root->left ) ; 
        postorder(root->right) ;
        cout << root->data << " " ; 
    }
}

void levelorder (Node * root ) {
    queue<Node *> q ; 
    q.push(root) ; 
    while (!q.empty()) {
        Node * temp = q.front() ; 
        q.pop() ; 
        cout << temp->data << " " ; 
        if (temp->left != nullptr ) 
            q.push(temp->left ) ;
        if ( temp->right != nullptr ){
            q.push(temp->right ) ; 
        }
    }
    cout << endl  ;
}

int height (Node * root ) {
    if ( root == nullptr ) 
        return -1 ; 
    int left = height(root->left ) ; 
    int right = height (root->right ) ; 
    return (left > right ) ? left + 1 : right + 1 ; 

}
// calculates depth of a node (given as int value ) 
// if the node doesn't exist , returns -1 

int depth ( Node* root , int item , int count  ) {
    if (root == nullptr ) 
        return -1; 
    else if (item < root->data ) {
        count = depth(root->left , item , ++count ) ; 
    }
    else if (item > root->data ) {
        count = depth(root->right , item , ++count ) ; 
    }
    return count ; 

}

int Min (Node * root ) {
    if ( root == nullptr ) {
        return -1  ; 
    }
    while (root->left != nullptr )
        root = root->left ; 
    return root->data ; 
}
int Max(Node * root ) {
    if ( root == nullptr ) {
        return -1 ; 
    }
    while ( root->right != nullptr ) {
        root = root->right  ; 
    }
    return root->data ; 
}

int countNodes (Node * root ) {
    if (root == nullptr ) {
        return 0 ; 
    }
    return countNodes(root->left ) + countNodes(root->right ) + 1 ; 
}


// having no child 
int countLeafNodes (Node * root ) {
    if ( root == nullptr ) 
        return 0 ; 
    else if ( root->left == nullptr && root->right == nullptr )
        return 1 ; 
    else 
        return countLeafNodes(root->left ) + countLeafNodes(root->right ) ; 
}
// having two children 
int countFullNodes (Node * root  ) {
    if ( root == nullptr ) 
        return 0 ; 
    else if ( root->left != nullptr && root->right != nullptr )  // found a full node
        return 1 + countFullNodes(root->left ) + countFullNodes(root->right ) ; 
    else 
        return countFullNodes(root->left ) + countFullNodes(root->right ) ; 

}
// nodes having only 1 child 
int countSingleNodes (Node *root ) {
    if (root == nullptr || root->left == nullptr && root->right == nullptr  ) // found a leaf node or a nullptr 
        return 0 ;
    else if ( root->left != nullptr && root->right != nullptr  ) // found a full node
        return countSingleNodes(root->left ) + countSingleNodes(root->right ) ; 
    else { // found a single node 
        return 1 + countSingleNodes(root->left ) + countSingleNodes(root->right  ) ;
    }

}


int main () {
    BST bst  ;
    bst.root = insert(bst.root  , 19 ) ;
    bst.root = insert(bst.root , 23) ; 
    bst.root = insert(bst.root , 10 ) ; 
    bst.root = insert(bst.root , 40 ) ; 
    bst.root = insert(bst.root , 10 ) ; // inserting duplicate item 
    bst.root = insert(bst.root , 20 ) ;
    bst.root = insert(bst.root , 12) ; 
    bst.root = insert(bst.root , 22 ) ;
    bst.root = insert(bst.root , 21 ) ; 
    bst.root = insert(bst.root , 4) ; 
    bst.root = insert(bst.root , 4) ;   // inserting duplicate item 
    bst.root = insert(bst.root , 9 ) ; 
    bst.root = insert(bst.root , 6 ) ; 
    cout << "Inorder : "  ;
    inorder(bst.root ) ; 
    cout << endl << "Preorder : "  ; 
    preorder(bst.root ) ; 
    cout << endl << "Postorder : " ; 
    postorder(bst.root )  ;
    cout << endl << "Levelorder : " ;
    levelorder(bst.root ) ;
    cout << endl ;  

    cout << "Depth of 19 : " << depth(bst.root , 19 , 0 )  << endl;  
    cout << "Depth of 12 : " << depth(bst.root , 12 , 0 )  << endl;
    cout << "Depth of 5 : " << depth(bst.root , 5 , 0 )  << endl;  // 5 is not in the BST , threfore it returns -1 
    cout << "Depth of 40 : " << depth(bst.root , 40 , 0 )  << endl;
    cout << "Depth of 22 : " << depth(bst.root , 22 , 0 )  << endl; 

    cout << "Height of the tree : "<< height(bst.root ) << endl ; 
    cout << "Min element : " << Min(bst.root ) << endl; 
    cout << "Max element : " << Max(bst.root ) << endl << endl ; 
    cout << "Total no of nodes : " << countNodes(bst.root) << endl; 
    cout << "Total leaf nodes : " << countLeafNodes(bst.root ) << endl; 
    cout << "Total full nodes : " << countFullNodes(bst.root ) << endl; 
    cout << "Total single nodes : " << countSingleNodes(bst.root ) << endl << endl  ; 
    cout << "Searching 22 : " << search(bst.root , 22) << endl ; 
    cout << "Searching 11 : " << search(bst.root , 11) << endl ; 
    cout << "Searching 30 : " << search(bst.root , 30 ) << endl ; 
    cout << "Searching 6 : " << search(bst.root , 6 ) << endl ; 

    cout << endl <<  "Deleting 10 : " ;
    bst.root = Delete(bst.root , 10 )  ; 
    inorder(bst.root ) ; 
    
    cout << endl <<  "Deleting 10 again : " ; 
    bst.root = Delete(bst.root , 10 ) ; 
    inorder(bst.root ) ; 

    cout << endl << "Deleting 20 : " ;
    bst.root = Delete(bst.root , 20 ) ;
    inorder(bst.root ) ; 

    cout << endl << "Deleting 19 : " ;
    bst.root = Delete(bst.root , 19) ; 
    inorder(bst.root ) ; 

    return 0 ;


}
