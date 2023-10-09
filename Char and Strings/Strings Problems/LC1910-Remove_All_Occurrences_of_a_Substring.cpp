#include <iostream>
#include <string>
using namespace std;

// TC => O(N * M) // N -> size of string s ans M -> size of string part
// SC => O(1)

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int ind = s.find(part);
        while(ind != string::npos){
            s.erase(ind, part.length());
            ind = s.find(part);
        }
        return s;
    }
};

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        int ind = s.find(part);
        while (ind < s.length())
        {
            s.erase(ind, part.length());
            ind = s.find(part);
        }
        return s;
    }
};