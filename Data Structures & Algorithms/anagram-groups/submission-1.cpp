class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hmap ;

        for(string s : strs){
            int freq[26] = {0} ;
            for(char ch: s)
                freq[ch-'a']++ ;
            
            string key = "" ;
            for(int i=0;i<26;i++){
                key += (freq[i] + '#') ;
            }
            hmap[key].push_back(s) ;
        }
        vector<vector<string>> result ;
        for(auto &p : hmap){
            result.push_back(p.second);
        }
        return result ;
    }
};
