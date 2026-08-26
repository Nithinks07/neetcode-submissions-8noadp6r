/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> st,end ;
        for(Interval& interval : intervals){
            st.push_back(interval.start) ;
            end.push_back(interval.end) ;
        }
        sort(st.begin(),st.end()) ;
        sort(end.begin(),end.end()) ;

        int s = 0 , e = 0 ;
        int ans = 0 , cnt = 0 ;

        while(s<intervals.size()){
            if(st[s]<end[e]){
                s++ ;
                cnt++ ;
            } else {
                e++ ;
                cnt-- ;
            }
            ans = max(ans,cnt) ;
        } 
        return ans ;
    }
};
