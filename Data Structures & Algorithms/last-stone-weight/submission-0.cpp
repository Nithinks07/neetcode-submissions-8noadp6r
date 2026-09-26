class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap ;
        for(int stone : stones){
            maxHeap.push(stone) ;
        }
        while(!maxHeap.empty() && maxHeap.size()>1){
            int s1 = maxHeap.top() ;
            maxHeap.pop() ;
            int s2 = maxHeap.top() ;
            maxHeap.pop() ;
            if(s1==s2) continue ;
            maxHeap.push(s1-s2) ;
        }
        return maxHeap.empty() ? 0 : maxHeap.top() ;
    }
};
