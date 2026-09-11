/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0 ;
        int lHeight = height(root->left) ;
        int rHeight = height(root->right) ;
        int diameter =  lHeight + rHeight ;
        int sub = max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)) ;
        return max(diameter, sub) ;
    }
    int height(TreeNode* root){
        if(!root) return 0 ;
        int left = height(root->left) ;
        int right = height(root->right) ;
        return 1 + max(left,right) ;
    }
};
