class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1 ;
        int r = piles[0] ;
        int n = piles.size() ;
        for(int i=1;i<n;i++){
            r = max(r,piles[i]) ;
        }
        while(l<r){
            int m = l + (r-l)/2 ;
            if(valid(m,piles,h))
                r = m ;
            else 
                l = m + 1 ;
        }
        return l ;
    }

    bool valid(int k, vector<int>& piles, int h){
        for(int pile : piles){
            h -= ceil((double)pile/k) ;
        }
        return h>=0 ;
    }
};
