class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hmap ;

        for(string s : strs){
            string key = s ;
            sort(key.begin(),key.end()) ;
            hmap[key].push_back(s) ;
        }
        vector<vector<string>> result ;
        for(auto &p : hmap){
            result.push_back(p.second);
        }
        return result ;
    }
};
