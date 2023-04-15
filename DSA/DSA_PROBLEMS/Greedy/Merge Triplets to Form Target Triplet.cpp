/*
Merge Triplets to Form Target Triplet

The triplet with any element that is greater than the corresponding element in target is USELESS. 

From rest triplets, if we have any corresponding element same as target, add its index to set. if set.size()==3 return true;
*/
class Solution {
    set<int> good;
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        for(int i=0;i<triplets.size();++i)
        {
            if(triplets[i][0]>target[0] or triplets[i][1]>target[1] or triplets[i][2]>target[2])
                continue;
            
            for(int j=0;j<3;++j)
            {
                if(triplets[i][j]==target[j])
                    good.insert(j);
            }
        }
        return good.size()==3;
    }
};
