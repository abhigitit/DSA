/*
Reverse words in string : AlgoExpert

Intuition: Reverse entire string and reverse word by word

*/
using namespace std;
void reverse(int left,int right,string &s);
string reverseWordsInString(string str) {
  reverse(0,str.size()-1,str);
int left =0,right =0;
  while(left<str.size())
    {
      right = left;
      while(right<str.size() and str[right]!=' ')
        {
          right++;
        }
      reverse(left,right-1,str);
      left = right + 1;
    
    }
  
  return str;
}

void reverse(int left,int right,string &s)
{
  while(left<right)
    {
      swap(s[left],s[right]);
      left++;
      right--;
    }
}
