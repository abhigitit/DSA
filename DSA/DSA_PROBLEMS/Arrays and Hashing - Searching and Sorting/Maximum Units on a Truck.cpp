/*

Maximum Units on a Truck

Intuition : Sort and use greedy approach

O(NlogN)

https://www.youtube.com/watch?v=qZUokf5dwYw&ab_channel=SehoLim
*/


bool compare(vector<int> &v1,vector<int> &v2)
{
    if(v1[1]>v2[1])
        return true;
    else
        return false;
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int res = 0;
        int total = 0;
        for(int i=0;i<boxTypes.size();++i)
        {
            if(truckSize<=boxTypes[i][0]) // if remaining truck size is less than available boxes, utilize all the truck space and break. its done
            {
                res+= truckSize*boxTypes[i][1]; 
                break;
            }
            res+= boxTypes[i][0]*boxTypes[i][1];
            truckSize-=boxTypes[i][0];
            
        }
        
        return res;
    }
};
