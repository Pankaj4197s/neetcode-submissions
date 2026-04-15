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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (!root)
            return {};
        q.push(root);
        vector<vector<int>> res;
        vector<int> ans;
        int count = q.size();
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
            count--;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            if (count == 0) {
                res.push_back(ans);
                ans = {};
                count = q.size();
            }
        }
        return res;
    }
};
