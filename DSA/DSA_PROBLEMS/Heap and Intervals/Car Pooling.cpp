/*
Car Pooling

Intuition : Sort wrt to start location and add end locations to min heap to know which trip ends first and the respective passengers 
can be removed

O(NlogN)

*/

typedef pair<int,int> P;
bool compare(vector<int>& v1,vector<int>& v2)
{
    return v1[1]<v2[1];
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),compare);
        priority_queue<P, vector<P> , greater<P>> minHeap;
        int currPassengers = 0;
       for(auto& trip: trips)
       {
           int num = trip[0];
           int start = trip[1];
           int end = trip[2];
           
           while(!minHeap.empty() and minHeap.top().first<=start)
           {
               currPassengers-= minHeap.top().second;
               minHeap.pop();
           }
           
           currPassengers+=num;
           if(currPassengers>capacity)
               return false;
           
           minHeap.push({end,num});
           
       }
        return true;
    }
};
