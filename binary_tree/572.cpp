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
    bool judge(TreeNode* A, TreeNode* B){
        if(!A && !B){
            return true;
        }
        if(A && B && A->val == B->val){
            return judge(A->left, B->left) && judge(A->right,B->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr){return false;}
        if(judge(root,subRoot)){return true;}
        return isSubtree(root->right,subRoot) || isSubtree(root->left,subRoot);
    }
};
