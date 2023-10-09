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
    void traverse(TreeNode* temp, vector<int>& res){
        if(temp == nullptr){
            return ;
        }
        res.push_back(temp->val);
        traverse(temp->left,res);
        traverse(temp->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root,res);
        return res;
    }
};
