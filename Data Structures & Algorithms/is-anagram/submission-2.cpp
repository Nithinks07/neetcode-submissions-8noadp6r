class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false ;

        int arr[26] = {0} ;

        for(char ch : s)
            arr[ch-'a']++ ;

        for(char ch : t){
            arr[ch-'a']-- ;
            if(arr[ch-'a']<0) return false ;
        }
        
        return true ;
    }
};
