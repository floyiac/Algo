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
    int DFS(TreeNode* node, int sum){
        if(node == nullptr) return 0;
        sum = 10 * sum + node->val;
        if(node->left == nullptr && node->right == nullptr){
            return sum;
        }
        return DFS(node->left,sum) + DFS(node->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        return DFS(root,0);
    }
};