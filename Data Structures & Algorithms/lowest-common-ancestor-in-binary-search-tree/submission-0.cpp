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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return root;
        if (root->val == p->val || root->val == q->val)
            return root;
        TreeNode* LCA;
        if (p->val < q->val) {
            if (p->val < root->val && root->val < q->val)
                LCA = root;
            else if (q->val < root->val)
                LCA = lowestCommonAncestor(root->left, p, q);
            else if (root->val < p->val)
                LCA = lowestCommonAncestor(root->right, p, q);
        } else {
            if (q->val < root->val && root->val < p->val)
                LCA = root;
            else if (p->val < root->val)
                LCA = lowestCommonAncestor(root->left, p, q);
            else if (root->val < q->val)
                LCA = lowestCommonAncestor(root->right, p, q);
        }
        return LCA;
    }
};
