/*
Common elements

Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.

*/

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            set <int>  res;
       ;
            int a = 0;
            int b = 0;
            int c = 0;
            
            while(a<n1 and b<n2 and c<n3)
            {
                int temp = min({A[a],B[b],C[c]});
                if(A[a]==temp and B[b]==temp and C[c]==temp)
                {
                  res.insert(temp);
                  a++;
                  b++;
                  c++;
                  continue;
                }
                
                if(A[a]==temp) a++;
                else if(B[b]==temp) b++;
                else if(C[c]==temp) c++;
            }
          vector<int> ret(res.begin(),res.end()) ;
            return ret;
        }

};
