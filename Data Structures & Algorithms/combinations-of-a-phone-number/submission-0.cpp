class Solution {
public:
    vector<string> result ;
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {} ;
        string curr = "" ;
        solve(digits,curr,0,0) ;
        return result ;
    }

    string getLetters(char num){
        switch(num){
            case '2' : return "abc" ;
            case '3' : return "def" ;
            case '4' : return "ghi" ;
            case '5' : return "jkl" ;
            case '6' : return "mno" ;
            case '7' : return "pqrs" ;
            case '8' : return "tuv" ;
            case '9' : return "wxyz" ;
        }
        return "" ;
    }

    void solve(string& digits, string& curr, int i,int j){
        if(i==digits.size()){
            result.push_back(curr) ;
            return ;
        }
        string letters = getLetters(digits[i]) ;
        for(int j=0;j<letters.size();j++){
            curr += letters[j] ;
            solve(digits,curr,i+1,j+1) ;
            curr.pop_back() ;
        }
    }
};
