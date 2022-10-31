/*

Custom Sort String

Intuition : Use the given order to print characters stored in map

*/

class Solution {
public:
    string customSortString(string order, string s) {
        string temp;
        map<char,int> store;  
         for(auto c:s)
        {
            store[c]++;
        }
        
        for(auto c:order)
        {
                int cnt = store[c];
                for(int i=0;i<cnt;++i)
                {
                    temp+=c;
                }
            store.erase(c);
         }
        
        for(auto c:store)
        {
                int cnt = store[c.first];
                for(int i=0;i<cnt;++i)
                {
                    temp+=c.first;
                }
        }
        
        return temp;
    }
};
