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
    void recur(TreeNode* node, vector<int>& res){
        if(node == nullptr) return ;
        res.push_back(node->val);
        recur(node->left,res);
        recur(node->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        recur(root,res);
        return res;
    }
};

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        if(root == nullptr) return res;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* temp = stk.top();
            stk.pop();
            res.push_back(temp->val);
            if(temp->right) stk.push(temp->right);
            if(temp->left) stk.push(temp->left);
        }
        return res;
    }
};