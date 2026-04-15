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
    int count = 0;
    int goodNodes(TreeNode* root) {
        if (!root)
            return 0;
        dfs(root, root->val);
        return count;
    }

    void dfs(TreeNode* root, int mx) {
        if (!root)
            return;
        if (root->val >= mx) {
            mx = root->val;
            count++;
        }
        dfs(root->left, mx);
        dfs(root->right, mx);
    }
};
