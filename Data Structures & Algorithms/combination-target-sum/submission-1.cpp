class Solution {
private:
    void solve(int i, int sum, vector<int>& curr, vector<int>& nums, int target, vector<vector<int>>& ans){
        
       
        if(target==sum){
            ans.push_back(curr) ;
            return ;
        }

        for(int j=i;j<nums.size();j++){
            if(sum+nums[j]>target)
                return ;
            curr.push_back(nums[j]) ;
            solve(j,sum+nums[j],curr,nums,target,ans) ;
            curr.pop_back() ;
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans ;
        vector<int> curr ;
        int sum = 0 ;
        sort(nums.begin(),nums.end()) ;
        solve(0,sum,curr,nums,target,ans) ;
        return ans ;
    }
};
