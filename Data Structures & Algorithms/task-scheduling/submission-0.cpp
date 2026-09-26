class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0} ;
        for(char task : tasks){
            freq[task - 'A' ]++ ;
        }
        priority_queue<int> maxHeap ;
        for(int f : freq){
            if(f>0) maxHeap.push(f) ;
        }
        queue<pair<int,int>> q ;

        int time = 0 ;

        while(!maxHeap.empty() || !q.empty()){
            time++ ;
            if(!maxHeap.empty()){
                int cnt = maxHeap.top() ;
                maxHeap.pop() ;
                cnt-- ;
                if(cnt>0){
                    q.push({cnt,time+n}) ;
                }
            }
            if(!q.empty() && q.front().second==time){
                maxHeap.push(q.front().first) ;
                q.pop() ;
            }
        }
        return time ;
            
    }
};
