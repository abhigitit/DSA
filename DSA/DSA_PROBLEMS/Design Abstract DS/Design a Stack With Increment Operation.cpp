/*

1381 Design a Stack With Increment Operation

Intuition: If k elements from the down needs to be incremented, store the increment value on the k-1 the index and pass the value as legacy while popping.

https://www.youtube.com/watch?v=-CXN5Nh9jOA&ab_channel=Pepcoding

O(1)

*/
class CustomStack {
public:
    vector<int> value;
    vector<int> incr;
    int index;
    CustomStack(int maxSize) {
        value.resize(maxSize);
        incr.resize(maxSize);
        index=-1;
    }
    
    void push(int x) {
        if(index+1==value.size())
            return;
        index++;
        value[index] = x;
        incr[index] = 0;
    }
    
    int pop() {
        if(index==-1)
            return -1;
        
        int val = value[index];
        int inc = incr[index];
        index--;
        if(index>=0) incr[index] += inc;
    
        return val+inc;
    }
    
    void increment(int k, int val) {
        int ind = min(k-1,index);
        if(ind>=0)
            incr[ind]+=val;
    }
};
