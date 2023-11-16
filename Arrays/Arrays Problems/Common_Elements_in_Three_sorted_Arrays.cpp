#include <iostream>
#include <vector>
#include <set>
using namespace std;

// TC => O(n1 + n2 + n3)
// SC => O(n1) if size of arrays is same, then set will contain all common elements

class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        vector<int> v;
        set<int> st;

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < n1 && j < n2 && k < n3)
        {
            if (A[i] == B[j] && B[j] == C[k])
            {
                st.insert(A[i]);
                i++;
                j++;
                k++;
            }
            else if (A[i] < B[j])
            {
                i++;
            }
            else if (B[j] < C[k])
            {
                j++;
            }
            else
            {
                k++;
            }
        }

        for (int it : st)
        {
            v.push_back(it);
        }

        return v;
    }
};