class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
       
        int n = nums.size() ;
        vector<int> LIS(n,-1) ;
        
        int ans = 1 ;
        for(int i=0;i<n;i++)
            ans = max(ans,dfs(nums,i,LIS)) ;
        return ans ;
    }

    int dfs(vector<int>& nums, int i,vector<int>& LIS){
        if(LIS[i]!=-1)
            return LIS[i] ;
        
        int ans = 1 ;

        for(int j=i;j<nums.size();j++){
            if(nums[i]<nums[j])
                ans = max(ans, 1+dfs(nums,j,LIS)) ;
        }

        return LIS[i] = ans ;
    }
};
