class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1)) ;
        dp[m-1][n-1] = 1 ;
        return solve(0,0,dp) ;
    }

    int solve(int i,int j,vector<vector<int>>& dp){
        int m = dp.size() ;
        int n = dp[0].size() ;
        if(i<0 || i>=m || j<0 || j>=n)
            return 0 ;
        if(i==m-1 && j==n-1)
            return 1 ;
        if(dp[i][j]!=-1)
            return dp[i][j] ;
        return dp[i][j] = solve(i+1,j,dp) + solve(i,j+1,dp) ;
    }
};
