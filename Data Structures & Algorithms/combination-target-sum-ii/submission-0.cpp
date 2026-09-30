class Solution {
public:
    vector<vector<int>> result ;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr ;
        sort(candidates.begin(),candidates.end()) ;
        solve(0,curr,candidates,target) ;
        return result ;
    }
    void solve(int i, vector<int> curr, vector<int>& nums, int target){
        if(target==0){
            result.push_back(curr) ;
            return ;
        }
        int n = nums.size() ;
        if(i==n) return ;
        for(int st=i;st<n;st++){
            if(nums[i]>target) break ;
            if(st>i && nums[st]==nums[st-1]) continue ;
            curr.push_back(nums[st]) ;
            solve(st+1,curr,nums,target-nums[st]) ;
            curr.pop_back() ;
        }
    }
};
