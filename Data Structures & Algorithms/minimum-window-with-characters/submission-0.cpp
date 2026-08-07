class Solution {
public:
    string minWindow(string s, string t) {
        int need[128] = {0} ;
        int window[128] = {0} ;

        for(char ch : t)
            need[ch]++ ;
        
        int l = 0 ;
        int ansLen = INT_MAX ;
        int st = 0 , matched = 0;

        for(int r=0;r<s.size();r++){
            char c = s[r] ;
            window[c]++ ;
            if(window[c]<=need[c])
                matched++ ;

            while(matched==t.size()){
                if(r-l+1<ansLen){
                    ansLen = r - l + 1 ;
                    st = l ;
                }
                char ch = s[l] ;
                window[ch]-- ;
                if(window[ch]<need[ch])
                    matched-- ;
                
                l++ ;
            }
        }
        return ansLen==INT_MAX ? "" : s.substr(st,ansLen) ;
    }
};
