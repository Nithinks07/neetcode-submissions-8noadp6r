class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length() ;
        vector<int> dp(n+1,-1) ;
        dp[n] = 1 ;
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end()) ;
        return dfs(s,wordSet,0,dp) ;
    }
    bool dfs(string s , unordered_set<string>& wordSet , int i,vector<int>& dp){
        if(i==s.length())
            return true ;
        if(dp[i]!=-1)
            return dp[i] ;
        
        for(int j=i;j<s.length();j++){
            if(wordSet.find(s.substr(i,j-i+1))!=wordSet.end()){
                if(dfs(s,wordSet,j+1,dp))
                    return dp[i] = true ;
            }
        }
        return dp[i] = false ;
    }
};
