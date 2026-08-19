class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0 ;
        int n = s.size() ;
        vector<vector<bool>> dp(n,vector<bool>(n,false)) ;

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                bool valid = s[i] == s[j] && (j-i<=2 || dp[i+1][j-1]) ;
                if(valid){
                    dp[i][j] = true ;
                    cnt++ ;
                }
            }
        }
        return cnt ;
    }
};
