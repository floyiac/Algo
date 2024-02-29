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
    bool recur(TreeNode* node, int targetSum){
        if(node == nullptr) return false;
        int v = node->val;
        targetSum -= v;
        if(targetSum == 0 && node->left == nullptr && node->right == nullptr){
            return true;
        }
        return recur(node->left,targetSum) || recur(node->right,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recur(root,targetSum);
    }
};