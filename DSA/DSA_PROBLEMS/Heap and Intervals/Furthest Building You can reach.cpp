

/*

Furthest Building You can reach

I will use all my bricks and save ladders for later use because i might get taller building.

When Im out of bricks and only ladders are left, i will check wherever I have used bricks and whats the max bricks i used in one instance. 
I could have used my ladder then instead of using it now for smaller length. So go back in time and use ladder there and get back your bricks.

*/
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int b, int l) {
        priority_queue<int> pq;
        int i=0;
        for(i;i<heights.size()-1;++i)
        {
            if(heights[i+1]<=heights[i]) continue;
            int d=heights[i+1]-heights[i];

            if(d<=b)
            {
                b-=d;
                pq.push(d);
            }

            else if(l>0)
            {
                if(pq.size())
                {
                    int hb = pq.top();
                    if(hb>d)
                    {
                        b+=hb;
                        pq.pop();
                        pq.push(d);
                        b-=d;
                    }
                }
                l--;
            }
            else break;
        }
        return i;
    }
};
