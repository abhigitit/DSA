class HitCounter {
    vector<int> hits;
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        hits.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        int low = 0;
        int high = hits.size()-1;
        int target = timestamp-300;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(hits[mid]<=target)
            {
                low = mid+1;
            }
            else
            {
                 high = mid-1;
            }
               
        }
        return hits.size()-low;
    }
};
