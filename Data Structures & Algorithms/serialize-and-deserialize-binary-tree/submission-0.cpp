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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "N";
        queue<TreeNode*> q;
        q.push(root);
        string res = "";
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node)
                res += "N,";
            else {
                res += to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "N")
            return nullptr;
        int i = 0;
        string temp = "";
        while(data[i] != ',') {
            temp += data[i++];
        }
        i++;
        int val = stoi(temp);
        TreeNode* root = new TreeNode(val);
        queue<TreeNode*> q;
        q.push(root);
        int len = data.size();
        while(i < len) {
            TreeNode* node = q.front();
            q.pop();
            temp = "";
            while(i < len && data[i] != ',') {
                temp += data[i++];
            }
            i++;
            if (temp != "N") {
                int val = stoi(temp);
                node->left = new TreeNode(val);
                q.push(node->left);
            }
            temp = "";
            while(i < len && data[i] != ',') {
                temp += data[i++];
            }
            i++;
            if (temp != "N") {
                int val = stoi(temp);
                node->right = new TreeNode(val);
                q.push(node->right);
            }
        }
        return root;
    }
};
