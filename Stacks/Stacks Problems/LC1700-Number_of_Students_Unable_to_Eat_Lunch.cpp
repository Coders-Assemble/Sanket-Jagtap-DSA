#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();

        int arr[2] = {0};

        for (auto st : students)
        {
            arr[st]++;
        }

        for (int i = 0; i < n; i++)
        {
            int sand = sandwiches[i];
            if (arr[sand] == 0)
            {
                return n - i;
            }

            arr[sand]--;
        }

        return 0;
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();

        int arr[2] = {0};

        for (auto st : students)
        {
            arr[st]++;
        }

        for (int i = 0; i < n; i++)
        {
            int sand = sandwiches[i];
            if (arr[sand] == 0)
            {
                return n - i;
            }

            arr[sand]--;
        }

        return 0;
    }
};