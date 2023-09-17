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
    int solve(TreeNode* root, int val) {
        if (!root) return 0;
        int ans = 0;
        if (val <= root->val)  {
            val = root->val;
            ans++;
        }
        ans += solve(root->left, val) + solve(root->right, val);
        return ans;
    }

    int goodNodes(TreeNode* root) {
        return solve(root, root->val);
    }
};