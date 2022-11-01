/*
Unique Email Addresses

*/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int> unique;
        for(auto& email : emails)
        {
            string localName = getLocalName(email);
            string domainName = getDomainName(email);
            string full_email = localName + ',' + domainName;
            unique[full_email]++;
        }
        return unique.size();
    }
    
    string getLocalName(string& email)
    {
        string temp = "";
        int i=0;
          while(email[i]!='@')
        {
             if(email[i]=='+')
                break;
            if(email[i]=='.')
            {
                i++;
                continue;
            }
              
            temp+=email[i];
            i++;
           
        }
        return temp;
    }
    
    string getDomainName(string& email)
    {
        string temp ="";
        int i=0;
        while(email[i]!='@')
            i++;
        
        for(int j=i+1;j<email.size();++j)
        {
           temp+=email[j]; 
        }
        
        return temp;
    }
};
