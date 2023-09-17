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
    void solve(vector<int>& preorder, vector<int>& inorder, vector<TreeNode*>& nodes, int cur, int i, int j) {
        if (j == i) return;

        int k = i;
        while (k < j && inorder[k] != preorder[cur]) k++;
        int left = k - i;
        int right = j - k;
        if (left) {
            nodes[cur]->left = nodes[cur+1];
            solve(preorder, inorder, nodes, cur+1, i, k-1);
        }
        if (right) {
            nodes[cur]->right = nodes[cur+left+1];
            solve(preorder, inorder, nodes, cur+left+1, k+1, j);
        }
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        vector<TreeNode*> nodes;
        for(auto n:preorder){
            TreeNode* node = new TreeNode(n);
            nodes.push_back(node);
        }
        solve(preorder, inorder, nodes, 0, 0, preorder.size()-1);
        return nodes[0];
    }
};