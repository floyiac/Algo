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
    void trav(vector<int>& res, TreeNode* node){
        if(node == nullptr) return ;
        trav(res,node->left);
        res.push_back(node->val);
        trav(res,node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        //recursion method
        vector<int> res;
        trav(res,root);
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if(root == nullptr) return res;
        TreeNode* cur =root;
        while(!stk.empty() || cur){
            if(cur != NULL){
                stk.push(cur);
                cur = cur->left;
            }
            else{
                TreeNode* temp = stk.top();
                stk.pop();
                res.push_back(temp->val);
                cur = temp->right;
            }
        }
        return res;
    }
};