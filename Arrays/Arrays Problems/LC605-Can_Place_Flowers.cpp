#include <iostream>
#include <vector>
using namespace std;

// TC => O(m)
// SC => O(1)

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int m = flowerbed.size();

        if (m == 1 && flowerbed[0] == 0)
        {
            if (n == 1 || n == 0)
                return true;
            return false;
        }

        if (m == 1 && flowerbed[0] == 1)
        {
            if (n == 0)
                return true;
            return false;
        }

        if (flowerbed[0] == 0 && flowerbed[1] != 1)
        {
            n--;
            flowerbed[0] = 1;
        }

        if (flowerbed[m - 1] == 0 && flowerbed[m - 2] != 1)
        {
            n--;
            flowerbed[m - 1] = 1;
        }

        for (int i = 1; i < m - 1; i++)
        {
            if (flowerbed[i] == 0 && (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0))
            {
                n--;
                flowerbed[i] = 1;
            }
        }

        cout << n << endl;
        for (auto it : flowerbed)
        {
            cout << it << " ";
        }

        return n <= 0;
    }
};

// TC => O(m)
// SC => O(1)

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int m = flowerbed.size();

        for (int i = 0; i < m; i++)
        {
            if ((flowerbed[i] == 0) &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == m - 1 || flowerbed[i + 1] == 0))
            {
                n--;
                flowerbed[i] = 1;
            }
        }
        return n <= 0;
    }
};