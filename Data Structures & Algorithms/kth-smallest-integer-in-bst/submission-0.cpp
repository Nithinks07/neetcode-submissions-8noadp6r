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
void preorder(TreeNode* root, int& prev ,int& k){
    if(!root) return ;
   
    preorder(root->left,prev,k) ;
    
    if(k==0)
        return ;
    
    k-- ;
    if(k==0){
        prev = root->val ;
        return ;
    }
        
    
    preorder(root->right,prev,k) ; 
}
public:
    int kthSmallest(TreeNode* root, int k) {
        
        int prev ;
        preorder(root,prev,k)  ;
        return prev;
    }
};
