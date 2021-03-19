
/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, and the values x and y of two
different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.

*/

// Level order traversal
bool isCousins(Node* root, int x, int y) {
	queue<pair<Node * , Node *>>q ;
	q.push({root , NULL }) ;
	Node *c , *p  ;
	int size ;
	Node *p1 = NULL  , *p2 = NULL ;
	while ( !q.empty()) {
		size = q.size() ;
		while (size--) {
			c = q.front().first ; p = q.front().second ;
			q.pop() ;
			if ( c->val == x ) {
				p1 = p ;
			}
			else if ( c->val == y ) {
				p2 = p ;
			}
			if (c->left ) q.push({c->left , c }) ;
			if ( c->right ) q.push({c->right  , c }) ;

		}
		if ( p1 || p2 ) {
			if ( p1 && p2  ) {
				if (p1 != p2 ) return 1 ;
			}
			return 0 ;
		}

	}
	return 0 ;
}



// Recursive approach (depth wise )
bool isCousins(Node *root, int x, int y) {
	Node*p1 = NULL , *p2 =  NULL ;
	int d1 , d2 ;
	p1 = find(x , root , NULL ,  0 , d1 ) ;
	p2 = find(y , root , NULL ,  0 , d2) ;

	if ( (d1 == d2 ) && (p1 != p2 )) return 1 ;
	return 0 ;
}

Node* find(int x , Node *curr , Node *parent, int curdepth, int &realdepth) {
	if (curr == NULL ) return NULL ;
	if ( curr->data == x ) {
		realdepth = curdepth ;
		return parent   ;
	}
	Node *left = find(x , curr->left , curr , curdepth + 1 , realdepth) ;
	if ( left ) return left ;
	Node *right = find(x , curr->right , curr,  curdepth + 1 , realdepth) ;
	if ( right ) return right ;

	return NULL ;

}
