class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mpp ;
        int l = 0 ;
        int maxLen = 0 ;
        for(int r = 0 ; r<s.size();r++){
            if(mpp.find(s[r])!=mpp.end()){
                l = max(mpp[s[r]]+1,l) ;
            }
            mpp[s[r]] = r ;
            maxLen = max(maxLen,r-l+1) ;
        }
        
        return maxLen ;

    }
};
