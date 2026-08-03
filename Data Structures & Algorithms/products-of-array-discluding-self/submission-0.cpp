class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1 ;
        int n = nums.size() ;
        int zCnt = 0 ;
        for(int num : nums){
            if(num==0)
                zCnt++ ;
        }
        vector<int> ans (n,0) ;
        if(zCnt>1)
            return ans ;

        for(int num: nums){
            if(num!=0)
                product *= num ;
        }

        if(zCnt == 1){
            for(int i = 0; i<n ; i++){
                if(nums[i]==0)
                    ans[i] = product ;
            }
            return ans ;
        }    
        
        for(int i = 0 ; i<n ; i++){
            
            ans[i] = (product/nums[i]) ;
        }
        return ans ;
    }
};
