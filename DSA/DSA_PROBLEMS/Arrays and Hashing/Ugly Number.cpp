/*
Ugly Number
*/

class Solution {
public:
    vector<int> prime = {2,3,5};
    bool isUgly(int n) {
        if(n<1) return false;
        for(auto i:prime) while(n % i == 0) n/=i;
        return n==1;
    }
}
