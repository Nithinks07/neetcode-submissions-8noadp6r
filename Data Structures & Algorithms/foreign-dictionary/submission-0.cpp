class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> adj ;
        unordered_map<char,int> indegree ;
        for(string w : words){
            for(char ch : w){
                adj[ch] = unordered_set<char>() ;
                indegree[ch] = 0 ;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string w1 = words[i] ;
            string w2 = words[i+1] ;
            int n1 = w1.size() ;
            int n2 = w2.size() ;
            int minLen = min(n1,n2) ;
            if(n1>n2 && w1.substr(0,minLen)==w2.substr(0,minLen))
                return "" ;
            for(int j=0;j<minLen;j++){
                if(w1[j]!=w2[j]){
                    if(!adj[w1[j]].count(w2[j])){
                        adj[w1[j]].insert(w2[j]) ;
                        indegree[w2[j]]++ ;
                    }
                    break ;
                }
            }
        }
        queue<char> q;
        for(auto&[c,deg] : indegree){
            if(deg==0)
                q.push(c) ;
        }
        string ans = "" ;
        while(!q.empty()){
            char node = q.front() ;
            q.pop() ;
            ans += node ;
            for(char neigh:adj[node]){
                if(--indegree[neigh]==0)
                    q.push(neigh) ;
            }
        }
        return ans.size()==indegree.size() ? ans : "" ;
    }
};
