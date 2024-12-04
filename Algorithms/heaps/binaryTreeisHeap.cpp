/*check if given binary tree is heap of not .

time : O(n) , space : O(n)

*/


bool isHeap(struct Node * tree)
{
    queue<Node *> q;
    bool nullseen = 0 ;
    q.push(tree) ; Node *c ;
    while (!q.empty()) {
        c = q.front() ; q.pop() ;
        if (nullseen == 1 ) {
            if (c->left || c->right ) return 0 ;

        }
        if (nullseen == 0 ) {
            if (c->left && c->right ) {
                if (c->data >= c->left->data && c->data >= c->right->data) {
                    q.push(c->left) ;
                    q.push(c->right) ;
                }
                else return 0 ;
            }
            else {
                // null seen now
                nullseen = 1 ;
                if (c->left ) {
                    if (c->data >= c->left->data) q.push(c->left) ;
                    else return 0 ;
                }
                if (c->right) return 0  ;
            }
        }


    }
    return 1 ;
}