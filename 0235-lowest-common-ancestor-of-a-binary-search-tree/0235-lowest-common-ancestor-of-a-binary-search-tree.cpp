/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* aux(TreeNode* root, TreeNode* p, TreeNode* q, bool& fp, bool& fq) {
        if (!root) return nullptr;
        
        TreeNode* ans = aux(root->left, p, q, fp, fq);
        bool lp = fp, lq = fq;
        fp = false; fq = false;
        if (!ans) ans = aux(root->right, p, q, fp, fq);
        if (ans) return ans;
        fp |= lp;
        fq |= lq;
        if (root == q) fq = true;       
        if (root == p) fp = true;
        
        return fp && fq ? root : nullptr;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool foundP = false, foundQ = false;
        return aux(root,p,q, foundP, foundQ);    
    }
};