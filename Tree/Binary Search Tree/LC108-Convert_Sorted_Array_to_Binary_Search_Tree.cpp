#include <iostream>
#include <vector>
using namespace std;

// TC => O(N)
// SC => O(logn)

// 108. Convert Sorted Array to Binary Search Tree
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *createBST(vector<int> &nums, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }

        int mid = (start + end) / 2;
        TreeNode *newNode = new TreeNode(nums[mid]);
        newNode->left = createBST(nums, start, mid - 1);
        newNode->right = createBST(nums, mid + 1, end);
        return newNode;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return createBST(nums, 0, nums.size() - 1);
    }
};