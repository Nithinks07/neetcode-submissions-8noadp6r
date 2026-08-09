class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses) ;
        vector<int> indegree(numCourses,0) ;
        for(const auto& it : prerequisites){
            adj[it[1]].push_back(it[0]) ;
            indegree[it[0]]++ ;
        }

        queue<int> q ;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i) ;
        }
        vector<int> topo ;  
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            topo.push_back(node) ;

            for(int neigh : adj[node]){
                if(--indegree[neigh]==0)
                    q.push(neigh) ;
            }
        }

        return topo.size()==numCourses ;

    }
};
