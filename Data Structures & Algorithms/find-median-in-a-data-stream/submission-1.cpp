class MedianFinder {
private:
    priority_queue<int,vector<int>,greater<int>> minHeap ;
    priority_queue<int> maxHeap ;
    
public:
    MedianFinder() {
       
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num<=maxHeap.top())
            maxHeap.push(num) ;
        else 
            minHeap.push(num) ;
        int n1 = minHeap.size() ;
        int n2 = maxHeap.size() ;
        if(n2>n1+1){
            minHeap.push(maxHeap.top()) ;
            maxHeap.pop() ;
        } else if(n1>n2){
            maxHeap.push(minHeap.top()) ;
            minHeap.pop() ;
        }
    }
    
    double findMedian() {
        if(minHeap.size()==maxHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0 ;
        return maxHeap.top() ;
    }
};
