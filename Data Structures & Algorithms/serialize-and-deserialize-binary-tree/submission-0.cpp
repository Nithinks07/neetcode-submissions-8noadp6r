class Codec {

public:

    string serialize(TreeNode* root) {
        string ans  = "";
        if(!root)
            return ans ;
        queue<TreeNode*> q ;
        q.push(root) ;

        while(!q.empty()){
            TreeNode* node = q.front() ;
            q.pop() ;
            if(!node){
                ans += "N," ;
                continue ;
            }

            ans += (to_string(node->val) + ",") ;
            q.push(node->left) ;
            q.push(node->right) ;
        }

        return ans ;

    }

    TreeNode* deserialize(string data) {
        if(data=="")
            return nullptr ;
        stringstream ss(data) ;
        string token ;
        vector<string> nodes ;
        while(getline(ss,token,','))
            nodes.push_back(token) ;
        int ind = 0 ;    
        int nodeVal = stoi(nodes[ind++]) ;
        TreeNode* root = new TreeNode(nodeVal) ;
        queue<TreeNode*> q ;
        q.push(root) ;

        while(ind<nodes.size()){
            TreeNode* node = q.front() ;
            q.pop() ;
            
            if(nodes[ind]!="N"){
                node->left = new TreeNode(stoi(nodes[ind])) ;
                q.push(node->left) ;
            }
            ind++ ;
            if(nodes[ind]!="N"){
                node->right = new TreeNode(stoi(nodes[ind])) ;
                q.push(node->right) ;
            } 
            ind++ ;
        }
        return root ;
    }
};