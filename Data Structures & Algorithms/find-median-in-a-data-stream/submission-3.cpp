class MedianFinder {
public:
priority_queue<int> maxHeap ;
priority_queue<int,vector<int>,greater<int>> minHeap ;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()){
            maxHeap.push(num) ;
        } else {
            minHeap.push(num) ;
        }
        int n1 = maxHeap.size() ;
        int n2 = minHeap.size() ;
        if(n1>n2+1){
            minHeap.push(maxHeap.top()) ;
            maxHeap.pop() ;
        } 
        else if(n2>n1){
            maxHeap.push(minHeap.top()) ;
            minHeap.pop() ;
        }
    }
    
    double findMedian() {
        
        if((maxHeap.size()+minHeap.size())&1) 
            return maxHeap.top() ;

        return (maxHeap.top() + minHeap.top())/2.0 ;
    }
};
