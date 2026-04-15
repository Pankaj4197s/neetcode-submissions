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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 1});
        int res = 0;
        while(!stk.empty()) {
            int depth = stk.top().second;
            TreeNode* node = stk.top().first;
            stk.pop();
            if (node != nullptr) {
                res = max(res, depth);
                stk.push({node->left, depth+1});
                stk.push({node->right, depth+1});
            }
        }
        return res;
    }
};
