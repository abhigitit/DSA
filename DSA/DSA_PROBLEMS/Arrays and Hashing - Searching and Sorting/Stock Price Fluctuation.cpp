/*
Stock Price Fluctuation

*/

class StockPrice {
public:
    
    map<int,int> timeCache;
    map<int,int> priceCache;
    int latest=-1;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
       if(timeCache.count(timestamp))
       {
           int prev_price = timeCache[timestamp];
           priceCache[prev_price]--;
           
           if(priceCache[prev_price]==0)
               priceCache.erase(prev_price);
       }
       timeCache[timestamp] = price;
        priceCache[price]++;
        if(timestamp>latest)
            latest=timestamp;
    }
    
    int current() {
        return timeCache[latest];
    }
    
    int maximum() {
        return priceCache.rbegin()->first;
    }
    
    int minimum() {
        return priceCache.begin()->first;
    }
};
