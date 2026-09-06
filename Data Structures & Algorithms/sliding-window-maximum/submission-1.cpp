class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int> lMax(n) ;
        vector<int> rMax(n) ;
        lMax[0] = nums[0] ;
        rMax[n-1] = nums[n-1] ;
        for(int i=1;i<n;i++){
            if(i%k==0){
                lMax[i] = nums[i] ;
            } else {
                lMax[i] = max(nums[i],lMax[i-1]) ;
            }
            int rInd = n - 1 - i ;
            if(rInd%k==0)
                rMax[rInd] = nums[rInd] ;
            else
                rMax[rInd] = max(rMax[rInd+1],nums[rInd]) ;
        }
        vector<int> ans(n-k+1) ;
        for(int i=0;i<=n-k;i++){
            ans[i] = max(lMax[i+k-1],rMax[i]) ;
        }
        return ans ;
    }
};
