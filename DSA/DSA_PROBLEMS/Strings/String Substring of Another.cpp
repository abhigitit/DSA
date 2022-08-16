/*
Substring of another string
TC:O(N)
*/



using namespace std;

bool substring(const string &a, const string &b)
{
    int M = a.size();
    int N = b.size();
    
    for(int i=0;i<=N-M;++i) // can be run only once but there could be extra characters 
    //for which inner loop breaks hence iterating for extra characters + 1 times
    {
        int j;
        for(j=0;j<M;++j)
        {
            if(a[j]!=b[i+j])
            break;
            
        }
        if(j==M)
            return true;
    }
    return false;
    
}
