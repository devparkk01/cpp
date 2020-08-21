/*The task is to print the top view of binary tree. Top view of
a binary tree is the set of nodes visible when the tree is viewed from the top. 

time : O(n) , space : O(n) 

The idea is to something similar to vertical order traversal.

*/



void topView( Node *root)
{
    if (root == NULL ) return ; 
    unordered_map<int , int > um ;  
    //It stores , key:Horizontal distance ,value : first node of the corresponding horizontal distance.
    queue<pair<int , Node *>> q ; // q stores information about the node as well as its horizontal distance.
    q.push(make_pair(0 , root )) ; 
    pair<int,  Node *> elem ; 
    Node *curr; int hd ; 
    int Min = 1 ; int Max = -1 ; 
    
    while (!q.empty() ) {
        elem = q.front() ;  q.pop() ; 
        hd = elem.first ; curr = elem.second ; 
        
        if ( um.find(hd ) == um.end () ) {
            um[hd] = curr ; 
            Min = min (hd , Min ) ; 
            Max = max (hd , Max ) ; 
        }
        
        if (curr->left ) q.push(make_pair(hd-1 , curr->left )) ; 
        if (curr->right ) q.push(make_pair(hd+ 1 , curr->right ) ) ; 
    
    }
    // printing top view 
    for(int i = Min ; i <= Max ; ++i ) {
        cout << umap[i] << " " ; 
    }
}
