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
    void helper(TreeNode* root, vector<string>& res, string s){
        s += to_string(root->val);
        if(root->left == NULL && root->right == NULL){res.push_back(s); return ;}
        if(root->left){
            helper(root->left,res,s+"->");
        }
        if(root->right){
            helper(root->right,res,s+"->");
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s;
        if(!root){return res;}
        helper(root,res,s);
        return res;
    }
};
