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
    bool isBalanced(TreeNode* root) {
        return DFS(root) != -1;
    }
    int DFS(TreeNode* node){
        if(node == nullptr) return 0;
        int leftheight = DFS(node->left);
        if(leftheight == -1) return -1;
        int rightheight = DFS(node->right);
        if(rightheight == -1) return -1;
        if(abs(leftheight-rightheight) > 1) return -1;
        return max(leftheight,rightheight) + 1;
    }
};