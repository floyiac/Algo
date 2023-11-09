/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val){
            // all in left subtree
            return lowestCommonAncestor(root->left,p,q);
        }
        if(root->val < p->val && root->val < q->val){
            // all in right subtree
            return lowestCommonAncestor(root->right,p,q);
        }
        // one in left, one in right, return root
        return root;
    }
};;
