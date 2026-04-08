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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfs_serialise(root,res);
        return join(res,",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data,',');
        int i = 0;
        return dfs_deserialise(vals,i);
    }

private:

    void dfs_serialise( TreeNode* root, vector<string>& res) {
        if(!root) {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(root->val));
        dfs_serialise(root->left, res);
        dfs_serialise(root->right, res);
    }

    string join( const vector<string> & r, const string& delim) {
        string final;
        for( int i = 0; i < r.size(); ++i) {
            if ( i > 0)
                final += delim;
            final+=r[i];
        }

        return final;
    }

    vector<string> split(const string d, const char delim) {
        vector<string> final;
        string current;
        for( char c:d) {
            if ( c == delim) {
                final.push_back(current);
                current.clear();
            } else {
                current +=c;
            }

        }
        final.push_back(current);
        return final;
    }

    TreeNode* dfs_deserialise ( vector<string> & val, int & i) {
        if( val[i] == "N") {
            i++;
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(val[i]));
        i++;
        node->left = dfs_deserialise(val,i);
        node->right = dfs_deserialise(val,i); // i will get updated after left is completed - so no need to calc the i
        return node;

    }

};
