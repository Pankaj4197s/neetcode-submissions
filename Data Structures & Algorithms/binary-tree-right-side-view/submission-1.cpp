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
    vector<int> res;

    void dfs(TreeNode* node, int depth) {
        if (!node)
            return;

        if (res.size() == depth)
            res.push_back(node->val);

        dfs(node->right, 1 + depth);
        dfs(node->left, 1 + depth);
    }
    
    vector<int> rightSideView(TreeNode* root) {
         dfs(root, 0);
        return res;
    }
};
