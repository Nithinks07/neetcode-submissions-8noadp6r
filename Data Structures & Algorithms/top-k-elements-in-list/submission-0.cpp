class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k<=0 || nums.empty()) return {} ;
        unordered_map<int,int> hmap ;
        for(int num : nums){
            hmap[num]++ ;
        }
        vector<pair<int,int>> hpairs(hmap.begin(),hmap.end()) ;
        sort(hpairs.begin(),hpairs.end(),[](const auto& a,const auto& b){
            return a.second > b.second ;
        }) ;

        vector<int> result ;
        for(int i=0;i<k && i<hpairs.size();i++){
            result.push_back(hpairs[i].first) ;
        }

        return result ;
    }
};
