class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hmap1 ;
        unordered_map<char,int> hmap2 ;
        for(char ch : s){
            hmap1[ch]++ ;
        }
        for(char ch : t){
            hmap2[ch]++ ;
        }
        if(hmap1==hmap2) 
            return true ;
        else 
            return false ;
    }
};
