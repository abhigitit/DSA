/* Encryption

Giiven a non-empty string of lower case letters and non negative integer representing a key.
We should return new string by shifting every letter in the given string by k positions. 
z is shifted to a if key = 1.

input = 'abc', key = 2
output = 'cde'

TC = O(n)
*/

#include <bits/stdc++.h>
#include <string>
using namespace std;
char getCipherChar(char c, int key);
string caesarCypherEncryptor(string str, int key) {
	vector<char> cipher;
	int newKey= key%26; // if key > 26-> basically key =26 is one complete round of alphabet shift
	for(auto i:str){
		cipher.push_back(getCipherChar(i,newKey));
	}
	return string(cipher.begin(),cipher.end());
}
	char getCipherChar(char c, int key){
		int cipherCode = c + key;
		return cipherCode <=122 ? cipherCode : 96 + cipherCode % 122;
	}


int main()
{
    
    string res = caesarCypherEncryptor("aba",2);
    cout<<res<<"\n";
    return 0;
}
