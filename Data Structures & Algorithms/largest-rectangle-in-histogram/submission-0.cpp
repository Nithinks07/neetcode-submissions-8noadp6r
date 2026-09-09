class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0 ;
        stack<pair<int,int>> st ;
        int n = heights.size() ;

        for(int i=0;i<n;i++){
            
            int start = i ;
            while(!st.empty() && st.top().first>heights[i]){
                int area = (i - st.top().second) * st.top().first ;
                maxArea = max(maxArea,area) ;
                start = st.top().second ;
                st.pop() ;
            }
            st.push({heights[i],start}) ;
        }
            while(!st.empty()){
                int area = st.top().first * (n-st.top().second) ;
                maxArea = max(maxArea,area) ;
                st.pop() ;
            }
        return maxArea ;
    }
};
