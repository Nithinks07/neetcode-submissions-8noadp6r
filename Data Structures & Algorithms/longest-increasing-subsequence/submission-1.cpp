class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
       
        int n = nums.size() ;
        vector<vector<int>> dp(n,vector<int>(n+1,-1)) ;
        return dfs(nums,0,-1,dp) ;
    }

    int dfs(vector<int>& nums, int i,int j,vector<vector<int>>& dp){
        int n = nums.size() ;
        if(i==n)
            return 0 ;
        if(dp[i][j+1]!=-1)
            return dp[i][j+1] ;

        int ans = dfs(nums,i+1,j,dp) ;

        if(j==-1 || nums[j]<nums[i]){
            ans = max(ans,1+dfs(nums,i+1,i,dp)) ;
        }
        return dp[i][j+1]=ans ;
    }
};
