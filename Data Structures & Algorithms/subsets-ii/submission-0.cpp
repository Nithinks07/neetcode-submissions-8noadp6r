class Solution {
public:
    set<vector<int>> result ;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr ;
        sort(nums.begin(),nums.end()) ;
        solve(0,curr,nums) ;
        return vector<vector<int>>(result.begin(),result.end()) ;
    }

    void solve(int i, vector<int>& curr, vector<int>& nums){
        int n = nums.size() ;
        if(i==n){
            result.insert(curr) ;
            return ;
        }
        curr.push_back(nums[i]) ;
        solve(i+1,curr,nums) ;
        curr.pop_back() ;
        solve(i+1,curr,nums) ;
    }
};
