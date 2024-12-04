/*Given a binary tree, print the bottom view from left to right. If there are multiple 
bottom-most nodes for a horizontal distance , then print the later one in level traversal.

time : O(n) , space : O(n)

*/


void bottomView(Node *root)
{
	if (root == NULL ) return ; 
	unordered_map<int , int > um ; 

	queue<pair<int , Node *>> q ; 
	q.push(make_pair(0 , root )) ; 
	pair<int , Node *> elem ; int hd ; Node *curr ; 
	int Min = 1 , Max = -1 ; 

	while (!q.empty()) {
	   elem = q.front() ; q.pop() ; 
	   hd = elem.first; curr = elem.second ; 
	   um[hd] = curr->data ; 
	   Min = min (hd , Min ) ;
	   Max = max (hd , Max ) ; 
	   if (curr->left ) q.push(make_pair (hd -1 , curr->left )) ; 
	   if (curr->right ) q.push(make_pair(hd + 1  , curr->right )) ; 
	}

	for(int i = Min ; i <= Max ; ++i ) {
			cout << um[i] << " " ; 
	}
}