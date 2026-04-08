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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if ( !p && !q)
            return true;
        
        
        queue<TreeNode*> pu;
        queue<TreeNode*> qu;
        pu.push(p);
        qu.push(q);
        while (!qu.empty() && !pu.empty()) {
            TreeNode* nodeq = qu.front();
            qu.pop();
            TreeNode* nodep = pu.front();
            pu.pop();
            if (!nodep && !nodeq) continue;
            if( !nodep || !nodeq || nodep->val != nodeq->val) {
                return false;
            }
            pu.push(nodep->left);
            pu.push(nodep->right);
            qu.push(nodeq->left);
            qu.push(nodeq->right);
        }
        return true;

    }
};
