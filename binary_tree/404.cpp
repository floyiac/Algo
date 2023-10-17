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
    bool isLeaf(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void helper(TreeNode* root, int& count){
        if(root->left!=NULL){
            if(isLeaf(root->left)){
                count += root->left->val;
            }
            else{
                helper(root->left,count);
            }
        }
        if(root->right != NULL){
            if(isLeaf(root->right)){
            }
            else{
                helper(root->right,count);
            }
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int count = 0;
        if(!root){return count;}
        helper(root,count);
        return count;
    }
};
