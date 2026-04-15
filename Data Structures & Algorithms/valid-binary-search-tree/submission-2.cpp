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
    vector<int> nums;

    void traverse(TreeNode* node) {
        if (!node)
            return;
        traverse(node->left);
        nums.push_back(node->val);
        traverse(node->right);
    }

    bool isValidBST(TreeNode* root) {
        traverse(root);
        int n = nums.size();
        for(int i=1;i<n;i++) {
            if (nums[i] <= nums[i-1])
                return false;
        }
        return true;
    }
};
