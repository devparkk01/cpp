/*Given a Binary Search Tree and a target sum. Check whether there's a pair of Nodes in the BST with
value summing up to the target sum.

*/

/* first approach  is to do inorder traversal and then check if pairs exist
time : O(n) , space : O(n) */

void inorder(Node *root , vector<int > &v ) {
    if (root != NULL ) {
        inorder(root->left , v ) ;
        v.push_back(root->data ) ;
        inorder(root->right , v ) ;
    }
}

int isPairPresent(struct Node *root, int target)
{
    vector<int> v ;
    inorder(root , v ) ;
    int i = 0 , j = v.size() - 1 ;
    while ( i < j ) {
        if ( v[i] + v[j] == target ) return true ;
        else if ( v[i] + v[j] < target ) i++ ;
        else j-- ;

    }
    return false ;
}

/* 2nd approach , using hashset , time : O(n) ,space : O(n) , but a better solution.
It's a better solution(in average case ) because once a pair has been found there will be no
further function calls */

void traverse(Node * root , int target , unordered_set<int> &us , bool &found ) {
    if (root == NULL ) return ;
    if ( found == false ) {
        if ( us.find(target - root->data) != us.end() ) {
            found = true;
        }
        us.insert(root->data ) ;
        traverse(root->left , target , us , found ) ;
        traverse(root->right , target , us , found ) ;
    }
}

int isPairPresent(Node *root , int target ) {
    unordered_set<int> us ;
    bool found = false ;
    traverse(root , target , us , found ) ;
    return found ;
}
