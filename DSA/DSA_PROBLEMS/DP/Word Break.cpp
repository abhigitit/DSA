/*
Word Break

Brute Force Intuition : We can check each substring if its there in the dictionary. O(n^2)

We can also check if the dictionary word is part of the string..For every word in dictionary(word size m), we loop through the string to find the first charcater
that matces(string size n) and if the first character is found, we compare(n). O(n*m*n)


Intuition : If we start at index 0, check if dictionary words equal the substring starting from 0, if yes, jump to next the index after 
the matched substring and solve the subproblem.

if we reach end of the string, we return true.

dp[sizeof_string]=true
Bottom up approach






