class Solution {
public:
    vector<vector<int>> result ;
    unordered_map<int,int> count ;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr, nums ;
        for(int num : candidates){
            if(!count[num])
                nums.push_back(num) ;
            count[num]++ ;
        }
        solve(0,curr,nums,target) ;
        return result ;
    }
    void solve(int i, vector<int> curr, vector<int>& nums, int target){
        if(target==0){
            result.push_back(curr) ;
            return ;
        }
        int n = nums.size() ;

        if(i>=n || target<0) return ;

        if(count[nums[i]]){
            curr.push_back(nums[i]) ;
            count[nums[i]]-- ;
            solve(i,curr,nums,target-nums[i]) ;
            count[nums[i]]++ ;
            curr.pop_back() ;
        }

        solve(i+1,curr,nums,target) ;
    }
};
