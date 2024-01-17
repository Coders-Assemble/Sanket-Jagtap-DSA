#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> mpp;
        unordered_set<int> st;

        for (int i = 0; i < arr.size(); i++)
        {
            mpp[arr[i]]++;
        }

        for (auto it = mpp.begin(); it != mpp.end(); it++)
        {
            st.insert(it->second);
        }

        return mpp.size() == st.size();
    }
};