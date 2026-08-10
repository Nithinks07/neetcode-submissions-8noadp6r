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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root ;
        
        if(root->left && root->right){
            TreeNode* temp = root->right ;
            root->right = root->left ;
            root->left = temp ;
        }
        else if(root->left){
            root->right = root->left ;
            root->left = nullptr ;
        } else if(root->right){
            root->left = root->right ;
            root->right = nullptr ;
        }
        TreeNode* left = invertTree(root->left) ;
        TreeNode* right = invertTree(root->right) ;

        return root ;
    }
};
