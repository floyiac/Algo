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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if(root == nullptr){return res;}
        stk.push(root);
        while(!stk.empty()){
            TreeNode* temp = stk.top();
            stk.pop();
            res.push_back(temp->val);
            if(temp->left){stk.push(temp->left);}
            if(temp->right){stk.push(temp->right);}
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
