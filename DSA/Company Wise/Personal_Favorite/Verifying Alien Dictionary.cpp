class Solution {
public:
     unordered_map<char,int> ranking;
    bool isAlienSorted(vector<string>& words, string order) {
      
       int rank = 0;
       for(auto& c:order)
       {
           ranking[c] = rank;
           rank++;
       } 

       for(int i=0;i<words.size()-1;++i)
       {
           string word1 = words[i];
           string word2 = words[i+1];

           if(verifyDic(word1,word2)>0)
                return false;
       }

       return true;
    }

    int verifyDic(string& word1, string& word2)
    {
        int temp = 0;
        int i =0;
        int j =0;
        while(i<word1.size() and j<word2.size() and temp==0)
        {
            temp = ranking[word1[i++]] - ranking[word2[j++]];
        }

        if(temp==0 and word1.size()>word2.size())
            return 1;
        
        return temp;
    }
};
