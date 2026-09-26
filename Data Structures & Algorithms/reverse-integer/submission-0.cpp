class Solution {
public:
    int reverse(int x) {
        long long num = 0 ;
        int sign = 1 ;
        if(x<0) sign = -1 ;
        x = abs(x) ;
        while(x>0){
            num = num*10 + x%10 ;
            x /= 10 ;
            if(num>INT_MAX) return 0 ;
        }
        return sign*num ;
    }
};
