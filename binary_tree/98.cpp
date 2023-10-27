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
    bool helper(TreeNode* temp, long long min, long long max){
        if(temp == NULL){return true;}
        if(temp->val <= min || temp->val >= max){
            return false;
        }
        return helper(temp->left, min, temp->val) && helper(temp->right,temp->val,max);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL){return true;}
        return helper(root,LONG_MIN,LONG_MAX);
    }
};
