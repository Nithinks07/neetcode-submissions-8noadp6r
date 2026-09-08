class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st ;
        for(string token : tokens){
            bool op = token=="+" || token=="-" || token=="*" || token=="/" ;
            if(!op) st.push(stoi(token)) ;
            else {
                int num2 = st.top() ;
                st.pop() ;
                int num1 = st.top() ;
                st.pop() ;
                st.push(eval(num1,num2,token)) ;
            }
        }
        return st.top() ;
    }

    int eval(int num1, int num2, string op){
        if(op=="+") return num1+num2 ;
        if(op=="-") return num1-num2 ;
        if(op=="*") return num1*num2 ;
        if(op=="/") return num1/num2 ;
    }
};
