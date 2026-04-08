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
private:
    unordered_map<int,int> find_pos;
    int preorder_idx = 0;

    TreeNode* helper_dfs(vector<int>& preorder,int l, int r) {

        if( l > r)
            return nullptr;
        
        int root_val = preorder[preorder_idx++];
        TreeNode* root = new TreeNode(root_val);
        int mid = find_pos[root->val];
        root->left = helper_dfs(preorder,l,mid-1);
        root->right = helper_dfs(preorder,mid+1,r);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if( preorder.size() != inorder.size())
            return nullptr;
        for(int i = 0; i < inorder.size(); ++i) {
            find_pos[inorder[i]] = i;
        }

        return helper_dfs(preorder,0,inorder.size()-1);
    }
};
