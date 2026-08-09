class Solution {
private: 
    int dir[4][2] = {
            {1,0} , {-1,0} , {0,1} , {0,-1}
        } ;
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        int m = heights.size() ;
        int n = heights[0].size() ;
        ocean[r][c] = true ;
        for(auto& d : dir){
            int nr = r + d[0] ;
            int nc = c + d[1] ;
            if(
                nr>=0 && nr<m && nc>=0 && nc<n
                && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]
            )
            dfs(nr,nc,ocean,heights) ;
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size() ;
        int n = heights[0].size() ;
        vector<vector<bool>> pac(m,vector<bool>(n,false)) ;
        vector<vector<bool>> atl(m,vector<bool>(n,false)) ;
        for(int j=0;j<n;j++){
            dfs(0,j,pac,heights) ;
            dfs(m-1,j,atl,heights) ;
        }
        for(int i=0;i<m;i++){
            dfs(i,0,pac,heights) ;
            dfs(i,n-1,atl,heights) ;
        }
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
