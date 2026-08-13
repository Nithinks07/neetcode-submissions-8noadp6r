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
private: 
    TreeNode* helper(int pSt, int pEnd, vector<int>& preorder,
    int inSt, int inEnd, vector<int>& inorder, unordered_map<int,int>& mpp ){
        if(pSt>pEnd || inSt>inEnd)
            return nullptr ;

        TreeNode* node = new TreeNode(preorder[pSt]) ;
        int ind = mpp[preorder[pSt]] ;
        int numsLeft = ind - inSt ;

        node->left = helper(pSt+1,pSt+numsLeft,preorder,inSt,ind-1,inorder,mpp) ;
        node->right = helper(pSt+numsLeft+1,pEnd,preorder,ind+1,inEnd, inorder, mpp) ;
        return node ;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp ;
        int n = inorder.size() ;
        for(int i=0;i<n ; i++)
            mpp[inorder[i]] = i ;
        
        int st = 0 ;

        TreeNode* root = helper(0,n-1,preorder,0,n-1,inorder,mpp) ;
        return root ;
    }
};
