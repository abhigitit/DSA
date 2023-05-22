class Solution {
public:
    map<string,vector<string>> pattern_store;
    
    unordered_set<string> visited;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordList_set(wordList.begin(),wordList.end());
        if(!wordList_set.count(endWord))
            return 0;
        
        wordList.push_back(beginWord);
        for(auto i:wordList)
        {
            for(int j=0;j<i.size();++j)
            {
                string pattern = i;
                pattern[j]='*';
                pattern_store[pattern].push_back(i);
            }
        }
        queue<string> BFS;
        BFS.push(beginWord);
        visited.insert(beginWord);
        int res = 1;
        while(!BFS.empty())
        {
            int n = BFS.size();
            for(int i=0;i<n;++i)
            {
                string word = BFS.front();
                BFS.pop();
                if(word==endWord)
                    return res;
                for(int j=0;j<word.size();++j)
                {
                    string pattern = word;
                    pattern[j]='*';
                    for(auto nei:pattern_store[pattern])
                    {
                        if(!visited.count(nei))
                        {
                            visited.insert(nei);
                            BFS.push(nei);
                        }
                            
                    }
                }
            }
            res++;
        }
        return res;
    }
};
