class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double,vector<int>>> result ;
        for(auto& p : points){
            double dist = sqrt(p[0]*p[0] + p[1]*p[1]) ;
            result.push_back({dist,p}) ;
        }
        sort(result.begin(),result.end()) ;
        vector<vector<int>> ans ;
        for(int i=0;i<k;i++){
            ans.push_back(result[i].second) ;
        }
        return ans ;

    }
};
