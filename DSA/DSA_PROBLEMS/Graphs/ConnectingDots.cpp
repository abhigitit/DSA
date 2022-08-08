/*Connecting Dots
Send Feedback
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Output Format :
Return 1 if there is a cycle else return 0
Constraints :
2 ≤ N, M ≤ 50
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1 */

/*
Intution: Start numbering the same colors (alphabets) and when we reach already numbered cell, check if the current cell - already numbered cell + 1 >= minimum colors to form cycle.
*/
#include<bits/stdc++.h>
using namespace std;

int l=0;
class Graph
{
    
    vector<vector<int>> visited;
    public:
    Graph(int m,int n)
    {
      visited.resize(m,vector<int>(n));
      for(int i=0;i<m;++i)
      {
          for(int j=0;j<n;++j)
          {
              visited[i][j]=0;
          }
      }
    
        
    }
    
    void helper(vector<vector<char>> board,int i, int j,int t,char c)
    {
       print();
        if(i<0 || i>=visited.size() || j<0 || j>=visited[i].size() || board[i][j]!=c) return;
        if(visited[i][j]!=0)
        {
            
            if(t-visited[i][j]+1>=4)
            l++;
            return;
        }
        if(l>0) return;
        t++;
        visited[i][j] = t;
        helper(board,i+1,j,t,c);
        helper(board,i,j+1,t,c);
        helper(board,i-1,j,t,c);
        helper(board,i,j-1,t,c);
    }
    
    bool colors_cycle(vector<vector<char>> board)
    {
        
        for(int i=0;i<visited.size();++i)
        {
            for(int j=0;j<visited[i].size() and l==0;++j)
            {
                if(visited[i][j]==0)
                {
                    
                    helper(board,i,j,0,board[i][j]);
                    if(l>0) break;
                }
            }
        }
        return l==0 ? false : true;
    }
    
    void print()
    {
         for(int i=0;i<visited.size();i++)
        {
            for(int j=0;j<visited[i].size();++j)
            {
                cout<<visited[i][j];
            }
            cout<<"\n";
        }
        cout<<"___"<<endl;
    }
};


int main()
{
   vector<vector<char>> board = {{'A','A','A','A'},{'A','B','V','A'},{'A','A','A','A'}};
   
   Graph g(3,4);
  cout<<g.colors_cycle(board);
}

