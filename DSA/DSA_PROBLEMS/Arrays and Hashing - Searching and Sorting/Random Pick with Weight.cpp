/*

Random Pick with Weight
[1,2,3] let line length be the weight, the total len would be 6
Can represent with [1,3,6] and the distance between each element will be its bucket size.

Nothing but prefix sum or cumulative sum.
A bucket is a gap between two elements.

If your bucket size or chunk is of greater size, you will have probability of being selected.
 O(N + queries*logN)
 */

class Solution {
public:
vector<int> prefix;
int running_sum;
    Solution(vector<int>& w) {
        running_sum = 0;
        for(auto i:w)
        {
            running_sum+=i;
            prefix.push_back(running_sum);
        }
    }
    
    int pickIndex() {
        int rand_wt = rand()%running_sum;
        return upper_bound(prefix.begin(),prefix.end(),rand_wt) - prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
