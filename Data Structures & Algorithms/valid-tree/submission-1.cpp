class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1)
            return false ;
        
        vector<vector<int>> adj(n) ;

        for(auto& ed : edges){
            adj[ed[0]].push_back(ed[1]) ;
            adj[ed[1]].push_back(ed[0]) ;
        }

        vector<bool> visited(n,false) ;

        queue<pair<int,int>>q ;
        q.push({0,-1}) ; //{curr node, parent node}
        visited[0] = true ;

        while(!q.empty()){
            auto [node,parent] = q.front() ;
            q.pop() ;

            for(int neigh:adj[node]){
                if(neigh==parent)
                    continue ;
                if(visited[neigh])
                    return false ;
                
                visited[neigh] = true ;
                q.push({neigh,node}) ;
            }
        }

        
        for(auto val : visited){
            if(!val)
                return false ;
        }
        return true ;

    }
};
