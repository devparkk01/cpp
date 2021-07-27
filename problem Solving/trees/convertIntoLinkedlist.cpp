/*
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/


given a binary tree, we have to convert them into linked list , in the preorder fashion .


*/


class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *head = NULL , *tail = NULL ;
        convert(root , head , tail ) ;
        // tail->right = NULL ;

    }
    void convert(TreeNode *node , TreeNode *&head , TreeNode *&tail) {
        if (node == NULL) return ;
        if (head == NULL ) {
            head = node ;
            tail = node ;
        }
        else {
            tail->right = node ;
            tail->left = NULL ;
            tail = node ;
        }
        TreeNode *right = node->right ;
        convert(node->left , head , tail ) ;
        convert(right , head, tail ) ;


    }

};