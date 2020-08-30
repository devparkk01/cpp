/*Given a binary tree, a target node in the binary tree, and an integer value k,
find all the nodes that are at distance k from the given target node.
No parent pointers are available.

*/
Node *findNode(Node *root , int target ) {
    if(root == NULL ) return NULL  ; 
    if (root->data == target ) return root ; 
    
    Node * left = findNode(root->left , target ) ;
    if (left ) return left ; 
    Node * right = findNode(root->right , target ) ; 
    if (right ) return right ; 
    
    return NULL ;    
}

void parent ( Node *root , Node * p , unordered_map<Node* , Node*> &um ) {
    if(root != NULL ) {
        um[root] = p ; 
        parent(root->left , root , um ) ;
        parent(root->right , root , um ) ; 
    }
}


vector <int> KDistanceNodes(Node* root, int target , int k){
    if (root == NULL ) return {} ; 
    Node *temp = findNode (root , target ) ;
    if (temp == NULL ) return {} ; 
    
    vector<int > v ; 
    unordered_map<Node * , Node *> um ; 
    parent(root , NULL , um ); 
    unordered_set<Node *> seen ; 
    queue<Node *> q  ; 
    q.push(temp ) ; 
    seen.insert(temp ) ; int count = 0 ; int size ; 
    
    while (!q.empty() ) {
        if (count == k ) {
            while (!q.empty() ) {
                temp = q.front() ; q.pop() ; 
                v.push_back(temp->data ) ; 
            }
        }
        else {
            size = q.size() ; count++ ; 
            for(int i = 0 ;i < size ; ++i ) {
                temp = q.front() ; q.pop() ; 
                if (temp->left && seen.find(temp->left ) == seen.end() ) {
                    q.push(temp->left ) ;
                    seen.insert(temp->left ) ;
                }
                if (temp->right && seen.find(temp->right ) == seen.end() ) {
                    q.push(temp->right ) ;
                    seen.insert(temp->right ) ; 
                }
                if(um[temp] && seen.find(um[temp]) == seen.end() ) {
                    q.push(um[temp]) ; 
                    seen.insert(um[temp]) ; 
                }
            }
        }
    }
    sort(v.begin() , v.end() ) ; // if we want output to be in sorted order 
    return v ; 
    
}

