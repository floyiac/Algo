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
    bool isJudge(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL) return true;
        if(left == NULL && right != NULL) return false;
        if(left != NULL && right == NULL) return false;
        if(left != NULL && right != NULL){
            if(left->val != right->val) return false;
        }
        bool A = isJudge(left->left,right->right);
        bool B = isJudge(left->right,right->left);
        return A && B;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isJudge(root->left,root->right);
    }
};