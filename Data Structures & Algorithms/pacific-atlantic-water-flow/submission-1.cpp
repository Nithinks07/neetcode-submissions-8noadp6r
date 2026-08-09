class Solution {
private: 
    int dir[4][2] = {
            {1,0} , {-1,0} , {0,1} , {0,-1}
        } ;
    void bfs(queue<pair<int,int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        int m = heights.size() ;
        int n = heights[0].size() ;
        while(!q.empty()){
            auto [r,c] = q.front() ;
            q.pop() ;
            ocean[r][c] = true ;
            for(auto& d : dir){
                int nr = r + d[0] ;
                int nc = c + d[1] ;
                if(
                    nr>=0 && nr<m && nc>=0 && nc<n &&
                    !ocean[nr][nc] && 
                    heights[nr][nc] >= heights[r][c]
                )
                q.push({nr,nc}) ;
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size() ;
        int n = heights[0].size() ;
        vector<vector<bool>> pac(m,vector<bool>(n,false)) ;
        vector<vector<bool>> atl(m,vector<bool>(n,false)) ;

        queue<pair<int,int>> pacQ , atlQ ;

        for(int j=0;j<n;j++){
            pacQ.push({0,j}) ;
            atlQ.push({m-1,j});
        }
        for(int i=0;i<m;i++){
            pacQ.push({i,0}) ;
            atlQ.push({i,n-1}) ;
        }
        bfs(pacQ,pac,heights) ;
        bfs(atlQ,atl,heights) ;

        vector<vector<int>> ans ;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j}) ;
            }
        }
        return ans ;
    }
};
