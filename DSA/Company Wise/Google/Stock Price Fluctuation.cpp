
class StockPrice {
public:
    map<int,int> records;
    map<int,int> prices;;
    int c = -1;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {

        if(records.count(timestamp) and prices.count(records[timestamp]))
        {
            prices[records[timestamp]]--;
            if(prices[records[timestamp]]==0)
                prices.erase(records[timestamp]);
            
        }
        prices[price]++;
        records[timestamp] = price;

        if(timestamp>c)
        c = timestamp;
    }
    
    int current() {
        return records[c];
    }
    
    int maximum() {
        return prices.rbegin()->first;
    }
    
    int minimum() {
        return prices.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
