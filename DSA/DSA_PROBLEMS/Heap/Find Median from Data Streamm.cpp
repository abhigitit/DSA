/*
Find Median from Data Stream
*/
class MedianFinder {
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double> ,greater<double>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);

        if(!minHeap.empty() and maxHeap.top()>minHeap.top())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if(minHeap.size()>maxHeap.size()+1)
        {
            int shift = minHeap.top();
            minHeap.pop();
            maxHeap.push(shift);
           
        }
         if(maxHeap.size()>minHeap.size()+1)
        {
            int shift = maxHeap.top();
            maxHeap.pop();
            minHeap.push(shift);
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size())
        {
            return maxHeap.top()/2+minHeap.top()/2;
        }
        
        return maxHeap.size()>minHeap.size() ? maxHeap.top() : minHeap.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
