/*

Leetcode: 953

TC:O(N)

*/
class Solution {
public:
    unordered_map<char,int> rank;
    bool isAlienSorted(vector<string>& words, string order) {
      
        int r=0;
        for(auto i:order)
        {
                rank[i] = r;
                r++;
        }
        
        for(int i=0;i<words.size()-1;++i)
        {
            string word1 = words[i];
            string word2 = words[i+1];
            
            if(compare(word1,word2)>0)
                return false;
            
        }
        return true;
    }
    
    int compare(string word1,string word2)
    {
        int l=0;
        int val =0;
        while(l<min(word1.size(),word2.size()) and val==0)
        {
            val = rank[word1[l]] - rank[word2[l]];
            l++;
        }
        
        if(val==0 and word1.size()>word2.size()) return 1;
        return val;
    }
};
