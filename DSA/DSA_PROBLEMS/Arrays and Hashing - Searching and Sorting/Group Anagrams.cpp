/*
Leetcode Group Anagrams

Intuition: Use sorted string as key to group words.

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> res;
        map<string,vector<string>> store;
        for(auto i:strs)
        {
            string temp = i;
            sort(temp.begin(),temp.end());
            store[temp].push_back(i);
        }
        for(auto s:store)
        {
            res.push_back(s.second);
        }
        return res;
    }
};
