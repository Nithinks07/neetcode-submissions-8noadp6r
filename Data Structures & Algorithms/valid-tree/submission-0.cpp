class Solution {
private: 
    bool dfs(int node, int parent, vector<bool>& visited, 
    vector<vector<int>>& adj){
        if(visited[node])
            return false ;
        
        visited[node] = true ;

        for(int neigh:adj[node]){
            if(neigh==parent)
                continue ;
            if(!dfs(neigh,node,visited,adj)) 
                return false ;
        }
        return true ;
    }
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

        if(!dfs(0,-1,visited,adj))
            return false ;

        for(auto val : visited){
            if(!val)
                return false ;
        }
        return true ;

    }
};
