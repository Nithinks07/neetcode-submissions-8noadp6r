class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int ans = nums[0] ;
       int curMax = 1 , curMin = 1 ;
       
       for(int num : nums){
        int tmp1 = curMax*num ;
        int tmp2 = curMin*num ;
        curMax = max(max(tmp1,tmp2),num) ;
        curMin = min(min(tmp1,tmp2),num) ;
        ans = max(ans,curMax) ;
       }
       return ans ;
    }
};
