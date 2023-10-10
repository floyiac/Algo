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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if(root == NULL) {return res;}
        TreeNode* cur = root;
        while(cur != NULL || !stk.empty()){
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
