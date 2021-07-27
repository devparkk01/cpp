/*
https://practice.geeksforgeeks.org/problems/convert-level-order-traversal-to-bst/1#

*/


Node* constructBst(int arr[], int n)
{
	// Code here
	queue<tri> q;
	Node *root = new Node(arr[0]) ;
	Node *curr = root ;
	q.push({root , INT_MIN , INT_MAX}) ;
	int i = 1 ;
	int min , max ;
	while (!q.empty()) {
		curr = q.front().node ; min = q.front().min ; max = q.front().max ;
		q.pop() ;
		if (i < n && arr[i] < curr->data && arr[i] > min) {
			curr->left = new Node(arr[i]) ;
			q.push({curr->left , min , curr->data}) ;
			i++ ;
		}
		if (i < n && arr[i] > curr->data && arr[i] < max) {
			curr->right = new Node(arr[i]) ;
			q.push({curr->right , curr->data , max }) ;
			i++ ;
		}

	}
	return root ;
}