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
private:
    int res = INT_MAX;
    TreeNode* pre = NULL;
public:
    void traverse(TreeNode* cur){
        //trick to record the previous node
        if(cur == NULL){return ;}
        traverse(cur->left);
        if(pre != NULL){
            res = min(res,cur->val - pre->val);
        }
        pre = cur;
        traverse(cur->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traverse(root);
        return res;
    }
};
