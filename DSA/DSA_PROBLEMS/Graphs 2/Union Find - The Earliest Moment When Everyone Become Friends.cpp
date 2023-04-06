/*
The Earliest Moment When Everyone Become Friends

Union Find

https://www.youtube.com/watch?v=2tYgeuNUpiA&ab_channel=CodewithAkhil

*/

class Solution {
public:
    vector<int> representative;
    vector<int> size;
    
    int find(int i)
    {
        if(i==representative[i])
            return i;
        return find(representative[i]);
    }
    
    int Union(int a, int b)
    {
        a = find(a);
        b = find(b);
        
        if(a==b)
            return 0;
        
        if(size[a]>size[b])
        {
            representative[b]=a;
            size[a]+=size[b];
        }
        else
        {
           representative[a]=b;
            size[b]+=size[a];  
        }
        
        return 1;
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end());
        for(int i=0;i<n;++i)
        {
            representative.push_back(i);
            size.push_back(1);
        }
        int groups = n;
        for(auto log:logs)
        {
          groups -= Union(log[1],log[2]);
            if(groups==1)
                return log[0];
        }
        
        return -1;
    }
    
    
};
