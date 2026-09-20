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
    int goodNodes(TreeNode* root) {
       
       return dfs(root,INT_MIN) ; 
    }

    int dfs(TreeNode* node,int maxEle){
        if(!node) return 0 ;
        int cnt = 0 ;
        if(node->val >= maxEle){
            cnt++ ;
            maxEle = node->val ;
        } 
       
        cnt += dfs(node->left,maxEle) ;
        cnt += dfs(node->right,maxEle) ;

        return cnt ;
    }
};
