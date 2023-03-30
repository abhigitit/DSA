/*

Push Dominoes

The dominos which start with left or right are gonna stay same because they will fall off and the fall off state is 
also considered the same because they are pushed like that. 


The dominos which are left or right knock off other dominos, the dots wont do anything unless their state is changed.

When we are on the right domino, and the next is a straight domino, can we change the state of the straight domino to right? NO
Check the next index of straight domino and if it has left domino, it neutralizes.

Do check for all right dominos like this and no need to check for left dominos if index-2 is right.

*/

class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<char> domino(dominoes.begin(), dominoes.end());

        queue<pair<int,char>> q;
        for(int i=0; i<domino.size(); ++i)
        {
            if(domino[i]!='.')
                q.push({i,domino[i]});
        }

        while(!q.empty())
        {
            pair<int,char> temp = q.front();
            q.pop();
            int idx = temp.first;
            char c = temp.second;

            if(c=='L' and idx>0 and domino[idx-1]=='.')
            {
                domino[idx-1]='L';
                q.push({idx-1,'L'});
            }

            else if(c=='R' and idx+1<domino.size() and domino[idx+1]=='.')
            {
                if(idx+2<domino.size() and domino[idx+2]=='L')
                    q.pop();
                else
                    {
                        domino[idx+1]='R';
                        q.push({idx+1,'R'});
                    }
            }
        }
        string res(domino.begin(),domino.end());
        return res;
    }
};
