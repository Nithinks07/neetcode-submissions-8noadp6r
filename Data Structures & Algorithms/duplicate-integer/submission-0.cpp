class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hset ;
        for(int num : nums){
            if(hset.find(num)!=hset.end()){
                return true ;
            }
            hset.insert(num) ;
        }
        return false ;
    }
};