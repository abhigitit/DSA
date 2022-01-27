
/* Longest Palindrome Substring

TC : O(n^2)
Algorithm: 
Check palindrome from centre character:
aba
We can start from b and traverse on both sides to check if this is a palindrome.

For even characters strings like abba
We start with second b and check if i is equal to i-1 and increment,decrement pointers accordingly.

Loop through string, at every point, find the longest palindrome passing two functions for odd characters palindrome and even characters palindrome.

*/


#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;
vector<int> getLongest(string str, int i, int j);
string longestPalindromicSubstring(string str) {
  vector<int> currentLongest{0,1};
	for(int i=0;i<str.length();i++){
		vector<int> odd = getLongest(str,i-1,i+1);
	vector<int> even = getLongest(str,i-1,i);
	vector<int> longest = odd[1]-odd[0]>even[1]-even[0] ? odd : even;
	currentLongest = currentLongest[1]-currentLongest[0] > longest[1]-longest[0] ? currentLongest : longest;
	}
	return str.substr(currentLongest[0], currentLongest[1]-currentLongest[0]);

}

vector<int> getLongest(string str, int i, int j){
	while(i>=0&&j<str.length())
	{
		if(str[i]!=str[j])
			break;
		i--;
		j++;
	}
	return vector<int>{i+1,j};
}

int main()
{
    
    string res = longestPalindromicSubstring("abahgytucferefcooiuyt");
    cout<<res<<"\n";
    return 0;
}
