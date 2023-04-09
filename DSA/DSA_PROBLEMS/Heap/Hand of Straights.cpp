/*
Hand of Straights
*/


class Solution {
    map<int,int> store;
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)
            return false;
        for(auto i:hand)
        {
            store[i]++;
            minHeap.push(i);
        }

        while(!minHeap.empty())
        {
            int curr_min = minHeap.top();
            
            int count = 1;
            store[curr_min]--;
             if(store[curr_min]==0)
                store.erase(curr_min);
            while(count!=groupSize)
            {

                curr_min++;
                if(store.count(curr_min))
                    {
                        store[curr_min]--;
                        if(store[curr_min]==0)
                            store.erase(curr_min);
                        count++;
                    }
                    else
                        return false;
            }
        
        while(!minHeap.empty() and !store.count(minHeap.top()))
        {
            minHeap.pop();
        }

               
        }
        return true;
        
    }
};
