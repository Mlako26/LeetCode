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
        vector<vector<int>> res;
        if (!root) return res;
        vector<TreeNode*> cur = {root};
        while (cur.size()) {
            vector<TreeNode*> aux;
            vector<int> vals;
            for (auto node : cur) {
                vals.push_back(node->val);
                if (node->left) aux.push_back(node->left);
                if (node->right) aux.push_back(node->right);
            }
            cur = aux;
            res.push_back(vals);
        }
        return res;
    }
};