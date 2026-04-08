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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*,int>> st;
        if (!root) return 0;
        st.push({root,1});
        int res = 1;
        while (!st.empty()) {
            pair<TreeNode*,int> node = st.top();
            st.pop();
            TreeNode* parent = node.first;
            res = max(res,node.second);
            if (parent->left) st.push({parent->left,node.second+1});
            if(parent->right) st.push({parent->right,node.second+1});

        }
        return res;
    }
};
