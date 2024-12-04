/*Given a Binary Tree, Print the corner nodes at each level. The node at the leftmost and 
the node at the rightmost of each level.

time : O(n) , space : O(max nodes in any level ) 

*/

void printCorner(Node *root)
{
    if(root == NULL ) return; 
    queue<Node*> q ; q.push(root) ;
    int size ; Node * curr ; 
    
    while (!q.empty()) {
        size = q.size() ;
        for(int i =0 ;i < size ; ++i ) {
            curr = q.front() ; q.pop() ;
            if (i == 0 || i == size -1 ) {
                cout << curr->data << " " ; 
            }
            if ( curr->left ) q.push(curr->left ) ; 
            if ( curr->right ) q.push(curr->right ) ; 
        }
    }

}