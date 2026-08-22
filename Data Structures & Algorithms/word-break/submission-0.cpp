class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length() ;
        vector<int> dp(n+1,-1) ;
        dp[n] = 1 ;
        return dfs(s,wordDict,0,dp) ;
    }
    bool dfs(string s , vector<string>& wordDict , int i,vector<int>& dp){
        if(i==s.length())
            return true ;
        if(dp[i]!=-1)
            return dp[i] ;
        for(string&  word : wordDict){
            int n = word.length() ;
            bool valid = (i+n<=s.length()) && s.substr(i,n)==word ;
            
            if(valid && dfs(s,wordDict,i+n,dp))
                return dp[i] = true ;
        }
        return dp[i] = false ;
    }
};
