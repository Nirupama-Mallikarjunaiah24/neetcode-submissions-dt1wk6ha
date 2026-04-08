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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res(2);
        res[0] = k;
        dfs(root,res);
        return res[1];
    }

    void dfs(TreeNode* node, vector<int>& res) {
        if(!node) return;
        dfs(node->left,res);
        res[0]--;
        if(res[0] == 0) {
            res[1] = node->val;
            return;
        }
        dfs(node->right,res);
    }
};
