
/*
Form n digit number divisible by k
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> res;
void function_name(int n,int k)
{
int low = pow(10,n-1);
int high = pow(10,n);
low=low+1;
for(int i=low;i<high;++i)
{
   if(i%k==0) 
   res.push_back(i);
}
}


int main()
{
   
    function_name(4,77);
    for(auto i:res)
    {
        cout<<i<<endl;
    }
}
