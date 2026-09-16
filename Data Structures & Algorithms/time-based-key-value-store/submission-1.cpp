class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp ;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp}) ;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "" ;
        int l = 0 ;
        int r = mp[key].size() - 1 ;
        int ans = -1 ;
        while(l<=r){
            int m = l + (r-l)/2 ;
            if(mp[key][m].second<=timestamp){
                ans = m ;
                l = m + 1 ;
            } else 
                r = m - 1 ;
        }
        if(ans==-1) return "" ;
        return mp[key][ans].first ;
    }
};
