/*
One Edit AE
*/

int len1 = stringOne.size();
  int len2 = stringTwo.size();

  for(int i=0;i<min(len1,len2);i++)
    {
      if(stringOne[i]!=stringTwo[i])
      {
        if(len1>len2)
          return stringOne.substr(i+1,len1-i+1) == stringTwo.substr(i,len2-i);
        else if(len2>len1)
          return stringOne.substr(i,len1-i) == stringTwo.substr(i+1,len2-i+1);
        else
          return stringOne.substr(i+1,len1-i+1) == stringTwo.substr(i+1,len2-i+1);
          
      }
    }
  return true;
}
