/*Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the
rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed 
as they appear in level order traversal of the tree.

time : O(nlog n ) space : O(n )
*/

#include<bits/stdc++.h>
using namespace std ; 

class Node {
	public :
	int data ; 
	Node *left ; 
	Node *right ; 
	Node (int data ) {
		this->data = data ; 
		left = NULL ; right = NULL ; 
	}
};

vector<int> verticalOrder(Node *root)
{
    vector<int> v ; 
    if (root == NULL ) return v ; 
    
    queue<pair<int , Node *> >q ; // queue will store horizontal distance along with the node . so
        // that we can remember what is the horizontal distance of this node . 
    q.push(make_pair(0 , root )) ; 
    map<int , vector<int> > m ;  
    pair<int , Node *> elem ; 
    int hd ; Node * curr ; 
    
    while (!q.empty() ) {
        elem = q.front() ;  q.pop() ; 
        hd = elem.first ; curr = elem.second  ; 
        m[hd].push_back(curr->data) ; 
        if (curr->left ) q.push(make_pair(hd-1  , curr->left)) ;
        if (curr->right ) q.push(make_pair(hd+1 , curr->right )) ; 
    }
    for(auto it = m.begin() ; it != m.end() ; ++it ) {
        for(int elem : it->second ) {
            v.push_back(elem) ; 
        }
    }
    return v ; 
    
}