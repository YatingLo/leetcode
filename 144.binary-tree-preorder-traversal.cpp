// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem144.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        if (!root)
            return result;

        stack<TreeNode*> memo;
        TreeNode *cur = root;
        while (cur != nullptr || memo.empty() == false)
        {
            if (cur) {
                result.push_back(cur->val);
                memo.push(cur);
                cur = cur->left;
            } else {
                cur = memo.top()->right;
                memo.pop();
            }
        }

        return result;
    }
};
// @lc code=end
