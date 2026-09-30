class Solution {
public:
    vector<vector<int>> ans ;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()) ;
        solve(0,0,{},nums,target) ;
        return ans ;
    }

    void solve(int i, int sum, vector<int> curr, vector<int>& nums, int target){
        if(sum==target){
            ans.push_back(curr) ;
            return ;
        }
        for(int j=i;j<nums.size();j++){
            if(sum+nums[j]>target) return ;
            curr.push_back(nums[j]) ;
            solve(j,sum+nums[j],curr,nums,target) ;
            curr.pop_back() ;
        }
    }
};
