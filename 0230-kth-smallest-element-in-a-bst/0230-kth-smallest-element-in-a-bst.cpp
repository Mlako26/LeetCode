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
    int solve(TreeNode* root, int &k) {
        int val = root->val;
        if (!root->left) {
            k--;
        if (k == 0) return val;
        } else {
            val = solve(root->left, k);
            if (k == 0) return val;
            k--;
            if (k == 0) return root->val;
        }
        if (k == 0) return val;
        if (root->right) val = solve(root->right, k);
        return val;
    }
    int kthSmallest(TreeNode* root, int k) {
        return solve(root, k);
    }
};