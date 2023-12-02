#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> uniqueEmails;

        for (auto email : emails)
        {
            string normalizeLocalName;

            for (char c : email)
            {
                if (c == '+' || c == '@')
                    break;
                if (c == '.')
                    continue;
                normalizeLocalName += c;
            }

            normalizeLocalName += email.substr(email.find('@'));
            uniqueEmails.insert(normalizeLocalName);
        }
        return uniqueEmails.size();
    }
};

/*
class Solution {
public:

    string normalizeLocalName(string localName){
        int i = 0;
        string newLocalName;

        while(i < localName.size()){
            if(localName[i] == '.'){
                i++;
            }
            else if(localName[i] == '+'){
                return newLocalName;
            }
            else{
                newLocalName += localName[i];
            }
        }
        return newLocalName;
    }

    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
        for(int i=0; i<emails.size(); i++){
            string email = emails[i];
            string localName = email.substr(0,email.find('@'));
            string domainName = email.substr(email.find('@') + 1);

            string s = normalizeLocalName(localName);
            string validEmail = s + domainName;
            uniqueEmails.insert(validEmail);
        }
        return uniqueEmails.size();
    }
};
*/