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
    //Recursion method
public:
    bool judge(TreeNode* left, TreeNode* right){
        if(left == NULL && right != NULL){
            return false;
        }
        else if(right == NULL && left != NULL){
            return false;
        }
        else if(left == NULL && right == NULL){
            return true;
        }
        else if(left->val != right->val){
            return false;
        }
        bool A = judge(left->left,right->right);
        bool B = judge(left->right,right->left);
        return A&&B;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){return true;}
        return judge(root->left,root->right);
    }
};
