class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true ;

        stack<char> st ;
        for(char c : s){
            if(c=='{' || c=='(' || c=='[')
                st.push(c) ;
            if(c=='}'){
                
                if(!st.empty() && st.top()=='{')
                    st.pop() ;
                else 
                    return false ;
            } 
            if(c==']'){
                if(!st.empty() && st.top()=='[')
                    st.pop() ;
                else 
                    return false ;
            } 
            if(c==')'){
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else 
                    return false ;
            } 
        }
        return st.empty() ;
    }
};
