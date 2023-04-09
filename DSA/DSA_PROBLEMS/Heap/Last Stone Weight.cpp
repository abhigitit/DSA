/*
Last Stone Weight
*/
class Solution {
public:
priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        for(auto i:stones)
        {
            pq.push(i);
        }

        while(pq.size()>=2)
        {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            int x = abs(stone1-stone2);
            pq.push(x);
        }
        return pq.top();
    }
};
