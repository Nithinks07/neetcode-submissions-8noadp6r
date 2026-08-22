class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length() ;
        vector<int> dp(n+1,-1) ;
        dp[n] = 1 ;
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end()) ;
        int k = 0 ;
        for(string word : wordDict){
            k = max(k,int(word.size())) ;
        }
        return dfs(s,wordSet,k,0,dp) ;
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
