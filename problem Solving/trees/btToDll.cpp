/*Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place.
The left and right pointers in nodes are to be used as previous and next pointers 
respectively in converted DLL. The order of nodes in DLL must be same as Inorder 
of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) 
must be the head node of the DLL.
       10
      /   \
     20   30      DLL  40<=>20<=>60<=>10<=>30.
   /   \
  40   60


time  : O(n) , space : O(h) 
*/

//iterative approach (iterative inorder traversal )

Node * bToDLL(Node *root)
{
    if (root == NULL ) return root ; 
    stack<Node *> s ; 
    Node *head = NULL ; Node * last ; Node *temp ;
    // last points to the last node of new DLL 
    Node *curr = root ; 
    
    while (curr != NULL || !s.empty() ) {
        while (curr != NULL ) {
            s.push(curr) ; 
            curr = curr->left ; 
        }
        temp = s.top() ; s.pop() ; 
        curr = temp->right ; 
        // Adding temp to DLL
        if ( head == NULL ) {
            head = temp ; 
            head->left = NULL ; 
            head->right = NULL ;
            last = head ; 
        }
        else {
            last->right = temp ; 
            temp->left = last ; 
            last = last->right ;
            last->right = NULL ; 
        }
    }
    return head ;     
}

/*

// recursive approach  
void bToDLLUtil(Node *root, Node **head_ref)
{
    // Base cases
    if(root == NULL)
        return;

    // Recursively convert right subtree
    bToDLLUtil(root->right, head_ref);

    // insert root into DLL
    root->right = *head_ref;

    // Change left pointer of previous head
    if (*head_ref != NULL)
        (*head_ref)->left = root;

    // Change head of Doubly linked list
    *head_ref = root;

    // Recursively convert left subtree
    bToDLLUtil(root->left, head_ref);
}

Node* bToDLL(Node *root)
{
    Node *head = NULL;
    bToDLLUtil(root,&head);
    return head;
    
}


*/