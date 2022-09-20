/*
Swap two variables without temp variable
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 10;
    int y = 13;
    cout<<x<<" "<<y<<endl;
    x=x^y;
    y=y^x;
    x=x^y;
     cout<<x<<" "<<y<<endl;

    return 0;
}
