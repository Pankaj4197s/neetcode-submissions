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
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        findMaxPath(root, globalMax);
        return globalMax;
    }
    
private:
    int findMaxPath(TreeNode* node, int &globalMax) {
        if (!node) return 0;

        // Recursively find the max path sum for left and right subtrees
        int leftSum = max(0, findMaxPath(node->left, globalMax));
        int rightSum = max(0, findMaxPath(node->right, globalMax));
        
        // Update the global maximum considering the current node as a root
        globalMax = max(globalMax, node->val + leftSum + rightSum);

        // Return the maximum path sum *including this node* to its parent
        return node->val + max(leftSum, rightSum);
    }
};
