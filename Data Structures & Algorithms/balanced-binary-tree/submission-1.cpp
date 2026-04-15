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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        bool isBalanced = true;
        height(root, &isBalanced);
        return isBalanced;
    }

    int height(TreeNode* node, bool *isBalanced) {
        if(!node)
            return 0;
        int hl = height(node->left, isBalanced);
        int hr = height(node->right, isBalanced);
        if (abs(hl - hr) > 1)
            *isBalanced = false;
        cout<<isBalanced<<endl;
        return 1 + max(hl, hr);
    }
};
