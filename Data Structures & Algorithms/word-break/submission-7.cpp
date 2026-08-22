class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length() ;
        vector<bool> dp(n+1,false) ;
        dp[n] = true ;
        
        for(int i=n-1;i>=0;i--){
            for(string w : wordDict){
                if((i+w.size())<=n && s.substr(i,w.length())==w){
                    dp[i] = dp[i+w.length()] ;
                }
                if(dp[i])
                    break ;
            }
           
        }
        return dp[0] ;
    }
    bool dfs(string s , unordered_set<string>& wordSet,int k , int i,vector<int>& dp){
        if(i==s.length())
            return true ;
        if(dp[i]!=-1)
            return dp[i] ;
        
        for(int j=i;j<min(int(s.length()),i+k);j++){
            if(wordSet.find(s.substr(i,j-i+1))!=wordSet.end()){
                if(dfs(s,wordSet,k,j+1,dp))
                    return dp[i] = true ;
            }
        }
        return dp[i] = false ;
    }
};
