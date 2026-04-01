class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hmap ;
        for(int i=0;i<nums.size();i++){
            int need = target - nums[i] ;
            if(hmap.find(need)!=hmap.end()){
                return {hmap[need],i} ;
            } else {
                hmap[nums[i]] = i ;
            }
        }
        return {} ;
    }
};
