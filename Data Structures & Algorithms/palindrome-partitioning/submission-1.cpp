class Solution {
public:
    vector<vector<string>> result ;
    vector<vector<string>> partition(string s) {
        vector<string> part ;
        solve(0,s,part) ;
        return result ;
    }
    bool isPalindrome(string& s, int l, int r){
        while(l<r){
            if(s[l++]!=s[r--])
                return false ;
        }
        return true ;
    }

    void solve(int i, string& s, vector<string>& part){
        if(i==s.length()){
            result.push_back(part) ;
            return ;
        }
        for(int j=i+1;j<=s.length();++j){
            
            if(isPalindrome(s,i,j-1)){
                part.push_back(s.substr(i,j-i)) ;
                solve(j,s,part) ;
                part.pop_back() ;
            }
        }
    }
};
