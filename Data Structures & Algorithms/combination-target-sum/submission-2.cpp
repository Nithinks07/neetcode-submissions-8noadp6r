class Solution {
public:
    vector<vector<int>> ans ;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr ;
        solve(0,curr,target,nums) ;
        return ans ;
    }
    void solve(int i, vector<int>& curr, int target, vector<int>& nums){
        if(target==0){
            ans.push_back(curr) ;
            return ;
        }
        if(target<0 || i>=nums.size()) return ;
        curr.push_back(nums[i]) ;
        solve(i,curr,target-nums[i],nums) ;
        curr.pop_back() ;
        solve(i+1,curr,target,nums) ;
    }
};
