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
    pair<int,int> solve(TreeNode* root) {
        pair<int,int> ans, l = {0,0}, r = {0,0};

        if (root->left) {
            l = solve(root->left);
        }
        if (root->right) {
            r = solve(root->right);
        }

        ans.second = max(root->val, max(l.second + root->val, r.second+root->val));
        ans.first = max(ans.second, root->val + r.second + l.second);

        if (root->left) ans.first = max(ans.first, l.first);
        if (root->right) ans.first = max(ans.first, r.first);

        return ans;
    }
    
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        return solve(root).first;
    }
};