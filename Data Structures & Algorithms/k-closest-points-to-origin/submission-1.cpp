class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> maxHeap ;
        for(auto& p : points){
            double dist = sqrt(p[0]*p[0] + p[1]*p[1]) ;
            maxHeap.push({dist,p}) ;
            if(maxHeap.size()>k) maxHeap.pop() ;
        }
        
        vector<vector<int>> ans ;
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second) ;
            maxHeap.pop() ;
        }
        return ans ;

    }
};
