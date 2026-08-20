class Solution {
public:
    int numDecodings(string s) {
        int n = s.size() ;
        
        int next2 = 1 ;
        int next1 = s[n-1]=='0' ? 0 : 1 ;
        int ans = next1 ;
        for(int i=n-2;i>=0;i--){

            if(s[i]=='0'){
                ans = 0 ;
                next2 = next1 ;
                next1 = ans ;
                continue ;
            }

            ans = next1 ;
            
            if(
                s[i]=='1' ||
                (s[i]=='2' && s[i+1]<='6')
            )
                ans += next2 ;
            next2 = next1 ;
            next1 = ans ;
        }
        return ans ;
    }
};
