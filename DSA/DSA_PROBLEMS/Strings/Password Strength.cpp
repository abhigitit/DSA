/*
Password Strength geeksforgeeks
*/

#include<bits/stdc++.h>
#include <cctype>
#include <cstring>
using namespace std;

vector<bool> res;
bool password_strength(string input)
{
    if(input.size()<8) return false;
    res.resize(4);
    string spec_chars = "!@#$%^&*()-+";

   	for (int i = 0; i < input.size(); i++) {
		if (islower(input[i]))
			res[0] = true;
		if (isupper(input[i]))
			res[1] = true;
		if (isdigit(input[i]))
			res[2] = true;
	}
    
    for(auto k: spec_chars)
    {
        size_t found = input.find(k);
        if(found!=string::npos)
        {
        res[3] = 1;
        break;
         }
   
    }
    bool flag = 0;
    for(auto b:res)
    {
    if(b==0)
    flag=1;
    }
    return flag ? false : true;
}


int main()
{
   string pass = "hhhkhrthibiv2!";
   cout<<password_strength(pass);
  
}
