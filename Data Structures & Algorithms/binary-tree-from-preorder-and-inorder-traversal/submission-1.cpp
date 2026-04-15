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
    int curr = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> node_map;  // Node, index
        int n = inorder.size();
        for(int i=0;i<n;i++)
            node_map[inorder[i]] = i;
        int l = 0,  r = n - 1;
        return dfs(preorder, inorder, node_map, l, r);
    }

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& node_map,
    int l, int r) {
        if (l > r)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[curr]);
        int inorder_ind = node_map[preorder[curr]];
        curr++;
        node->left = dfs(preorder, inorder, node_map, l, inorder_ind - 1);
        node->right = dfs(preorder, inorder, node_map, inorder_ind + 1, r);
        return node;
    }
};
