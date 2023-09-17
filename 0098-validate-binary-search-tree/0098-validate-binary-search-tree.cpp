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
    bool solve(TreeNode* root, int& mx, int& mn) {
        if (!root) return true;
        bool res = true;
        int newmn, newmx;
        if (root->left) {
            res &= solve(root->left, mx, mn);
            res &= mx < root->val;
            newmn = mn;
        } else newmn = root->val;
        
        if (root->right) {
            res &= solve(root->right, mx, mn);
            res &= mn > root->val;
            newmx = mx;
        } else newmx = root->val;
        mn = newmn;
        mx = newmx;
        return res;
    }

    bool isValidBST(TreeNode* root) {
        int mx = 0, mn = 0;
        return solve(root, mx, mn);
    }
};