class MedianFinder {
private:
    vector<int> arr ;
    int size = 0;
public:
    MedianFinder() {
       
    }
    
    void addNum(int num) {
        int ind = 0 ;
        while(ind<size && arr[ind]<num)
            ind++ ;
        
        arr.insert(arr.begin()+ind,num) ;
        size++;
    }
    
    double findMedian() {
        if(size%2==0){
            return (arr[size/2-1] + arr[size/2]) / 2.0 ;
        }
        return arr[size/2] ;
    }
};
