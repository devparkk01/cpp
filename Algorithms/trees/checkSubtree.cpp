/*Given two binary trees with head reference as T and S having at most N nodes. The task is to check
if S is present as subtree in T. 

*/


bool isIdentical(Node * root1 , Node*root2 ) {
    if ( !root1 && !root2) return true ; 
    if ( !root1 || !root2 ) return false ; 
    if (root1->data == root2->data ) {
        bool left = isIdentical(root1->left , root2->left ) ; 
        bool right = isIdentical(root1->right ,root2->right ) ; 
        return left &&right ; 
    }
    return false ; 
}


bool isSubTree(Node* T, Node* S) {
    queue<Node*> q; 
    q.push(T) ; 
    Node *temp ; 
    while (!q.empty() ) {
        temp = q.front() ; q.pop() ; 
        if(temp->data == S->data ) {
            if( isIdentical(temp , S) ) return true ; 
        }
        if (temp->left ) q.push(temp->left ) ;
        if (temp->right ) q.push(temp->right ) ;
    }
    return false ; 

}
