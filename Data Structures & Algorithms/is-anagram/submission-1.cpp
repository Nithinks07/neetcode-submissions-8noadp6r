class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr1(27,0) ;
        vector<int> arr2(27,0) ;
        for(char ch : s){
            arr1[ch-'a']++ ;
        }
        for(char ch : t){
            arr2[ch-'a']++ ;
        }
        if(arr1==arr2) 
            return true ;
        else 
            return false ;
    }
};
