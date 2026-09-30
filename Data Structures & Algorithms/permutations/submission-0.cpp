class Solution {
public:
    vector<vector<int>> result ;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds ;
        int n = nums.size() ;
        vector<bool> used(n,false) ;
        solve(ds,used,nums) ;
        return result ;
    }
    
    void solve(vector<int>& ds,vector<bool>& used, vector<int>& nums){
        int n = nums.size() ;
        if(ds.size()==n){
            result.push_back(ds) ;
            return ;
        }
        for(int i=0;i<n;i++){
            if(used[i]) continue ;
            used[i] = true ;
            ds.push_back(nums[i]) ;
            solve(ds,used,nums) ;
            ds.pop_back() ;
            used[i] = false ;
        }
    }
};
