class Twitter {
public:
    int count ;
    unordered_map<int,set<int>> followMap ;
    unordered_map<int,vector<vector<int>>> tweetMap ;

    Twitter() {
        count = 0 ;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++,tweetId}) ;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans ;
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0] ;
        } ;
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> minHeap(cmp) ;
        followMap[userId].insert(userId) ;
        for(int followeeId : followMap[userId]){
            if(tweetMap.count(followeeId)){
                const vector<vector<int>>& tweets = tweetMap[followeeId] ;
                int i = tweets.size() - 1 ;
                minHeap.push({tweets[i][0],tweets[i][1],followeeId,i}) ;
            }
        }
        while(!minHeap.empty() && ans.size()<10){
            vector<int> curr = minHeap.top() ;
            minHeap.pop() ;
            ans.push_back(curr[1]) ;
            int i = curr[3] ;
            if(i>0){
                const vector<int>& tweet = tweetMap[curr[2]][i-1] ;
                minHeap.push({tweet[0],tweet[1],curr[2],i-1}) ;
            }
        }
        return ans ;
    }
    
    void follow(int followerId, int followeeId) {
        
        followMap[followerId].insert(followeeId) ;
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId) ;
    }
};
