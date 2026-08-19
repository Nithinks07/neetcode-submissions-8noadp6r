class Solution {
private:
    bool isPalindrome(string&s , int l, int r){
        if(l>=r)
            return true ;
        
        if(s[l]!=s[r])
            return false ;
        
        return isPalindrome(s,l+1,r-1) ;
    }

public:
    string longestPalindrome(string s) {
        int st = 0 , maxLen = 0 ;
        int n = s.size() ;
        vector<vector<bool>> dp(n,vector<bool>(n,false)) ;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                bool valid = s[i] == s[j] && (j-i<=2 || dp[i+1][j-1]) ;
                if(valid){
                    dp[i][j] = true ;
                    if(maxLen<j-i+1){
                        maxLen = j - i + 1 ;
                        st = i ;
                    }
                }
            }
        }
        return s.substr(st,maxLen) ;
    }
};
