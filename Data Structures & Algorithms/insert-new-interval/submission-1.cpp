class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size() ;
        if(n==0){
            return {newInterval} ;
        }
        for(int i=0;i<n;i++){
            if(newInterval[0]<intervals[i][0]){
                intervals.insert(intervals.begin()+i,newInterval) ;
                break ;
            }
            if(i==n-1)
                intervals.push_back(newInterval) ;
        }
        vector<vector<int>> ans ;

        for(auto & interval : intervals){
            if(ans.empty() || ans.back()[1]<interval[0])
                ans.push_back(interval) ;
            else 
                ans.back()[1] = max(ans.back()[1],interval[1]) ;
        }
        return ans ;
    }
};
